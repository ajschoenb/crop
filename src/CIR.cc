#include "crop/CIR.h"

#include "crop/Operand.h"

#include <sstream>

CIRNode::CIRNode() : CIRNode(Type::INVALID, 0, nullptr) {
}

CIRNode::CIRNode(Type type, int num_operands, Operand* operands) : type(type), num_operands(num_operands), operands(operands) {
}

CIRNode::~CIRNode() {
    if (operands) {
        delete[] operands;
        operands = nullptr;
    }
}

CIRNode::Type CIRNode::getType() {
    return type;
}

int CIRNode::getNumOperands() {
    return num_operands;
}

Operand* CIRNode::getOperands() {
    return operands;
}

std::string CIRNode::toString() {
    std::stringstream ret;
    ret << "CIRNode {";
    switch (type) {
        case INVALID: {
            ret << "INVALID";
            break;
        }
        case STORE: {
            ret << "STORE";
            break;
        }
        case LOAD: {
            ret << "LOAD";
            break;
        }
        case MOVE: {
            ret << "MOVE";
            break;
        }
        case JUMP: {
            ret << "JUMP";
            break;
        }
        case SYSCALL: {
            ret << "SYSCALL";
            break;
        }
        case RAW: {
            ret << "RAW";
            break;
        }
        case ADD: {
            ret << "ADD";
            break;
        }
        case ADDR: {
            ret << "ADDR";
            break;
        }
    }
    
    for (int i = 0; i < num_operands; i++) {
        ret << " " << operands[i].toString();
    }
    ret << "}";
    return ret.str();
}
