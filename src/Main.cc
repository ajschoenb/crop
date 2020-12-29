#include <iostream>
#include <vector>

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
    std::cout << std::endl;
    return 0;
}
