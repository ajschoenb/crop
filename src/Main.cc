#include "crop/CIR.h"
#include "crop/Codegen.h"
#include "crop/Operand.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<CIRNode*> loadCIR(std::string filename) {
    std::vector<CIRNode*> ret;
    std::ifstream fin(filename);
    if (fin.is_open()) {
        std::string line;

        while (getline(fin, line)) {
            // ignore comments
            if (line[0] == '\"') continue;

            // read everything out of the CIR line
            std::stringstream buf(line);
            std::string opcode;
            buf >> opcode;
            if (opcode == "") continue;  // skip blank lines

            std::vector<std::string> str_operands;
            while (buf) {
                std::string operand;
                buf >> operand;
                if (operand != "") {
                    str_operands.push_back(operand);
                }
            }

            // determine the instruction type
            CIRNode::Type ins_type = CIRNode::Type::INVALID;
            if (opcode == "STORE") {
                ins_type = CIRNode::Type::STORE;
            } else if (opcode == "LOAD") {
                ins_type = CIRNode::Type::LOAD;
            } else if (opcode == "MOVE") {
                ins_type = CIRNode::Type::MOVE;
            } else if (opcode == "JUMP") {
                ins_type = CIRNode::Type::JUMP;
            } else if (opcode == "SYSCALL") {
                ins_type = CIRNode::Type::SYSCALL;
            } else if (opcode == "RAW") {
                ins_type = CIRNode::Type::RAW;
            } else if (opcode == "ADD") {
                ins_type = CIRNode::Type::ADD;
            } else if (opcode == "ADDR") {
                ins_type = CIRNode::Type::ADDR;
            } else {
                std::cerr << "Invalid instruction type: " << opcode << std::endl;
                exit(1);
            }

            // parse the operands
            size_t num_operands = str_operands.size();
            Operand* operands = new Operand[num_operands];
            for (size_t i = 0; i < num_operands; i++) {
                std::string str_operand = str_operands[i];
                Operand::Type type = Operand::Type::INVALID;
                value_t value = 0;

                switch (str_operand[0]) {
                    case '%': {
                        type = Operand::Type::REGISTER;
                        value = std::stoi(str_operand.substr(1));
                        break;
                    }
                    case '$': {
                        type = Operand::Type::IMMEDIATE;
                        value = std::stoi(str_operand.substr(1));
                        break;
                    }
                    case '&': {
                        type = Operand::Type::MEMORY;
                        value = std::stoi(str_operand.substr(1));
                        break;
                    }
                    case '_': {
                        type = Operand::Type::LABEL;
                        value = -1;  // TODO fix label values
                        break;
                    }
                    default: {
                        std::cerr << "Invalid operand: " << str_operand << std::endl;
                        exit(1);
                    }
                }

                operands[i] = Operand(type, value);
            }

            // insert the CIRNode
            ret.push_back(new CIRNode(ins_type, num_operands, operands));
        }
        fin.close();
    } else {
        std::cerr << "Unable to open CIR file " << filename << std::endl;
        exit(1);
    }
    return ret;
}

void help() {
    std::cout << "CROP Help" << std::endl;
    std::cout << "Available options:" << std::endl;
    std::cout << "\t     --cir : compile from CIR" << std::endl;
    std::cout << "\t-h, --help : show help" << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Incorrect number of arguments!" << std::endl;
        std::cerr << "Example usage: " << argv[0] << " [options] <program>" << std::endl;
        exit(1);
    }

    std::vector<std::string> options(0);
    for (int i = 1; i < argc - 1; i++) {
        std::string option = argv[i];
        if (option == "-h" || option == "--help") {
            help();
            exit(0);
        }
        options.push_back(option);
    }

    std::string program = argv[argc - 1];
    if (program == "-h" || program == "--help") {
        help();
        exit(0);
    }

    std::cout << "Compiling \"" << program << "\"";
    if (options.size() > 0) {
        std::cout << " with options \"" << options[0] << "\"";
        for (unsigned int i = 1; i < options.size(); i++) {
            std::cout << ", \"" << options[i] << "\"";
        }
    }
    std::cout << "..." << std::endl;

    std::cout << "Loading CIRNode list..." << std::endl;
    std::vector<CIRNode*> cir_nodes = loadCIR(program);
    for (CIRNode* node : cir_nodes) {
        std::cout << node->toString() << std::endl;
    }

    std::cout << "Generating code..." << std::endl;
    codegen(cir_nodes);
    return 0;
}
