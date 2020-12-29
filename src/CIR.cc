#include "crop/CIR.h"

#include <sstream>

CIRNode::CIRNode() : CIRNode(Type::INVALID, nullptr) {
}

CIRNode::CIRNode(Type type, Operand* operands) : type(type), operands(operands) {
}

CIRNode::~CIRNode() {
    if (operands) {
        delete[] operands;
        operands = nullptr;
    }
}

std::string CIRNode::toString() {
    std::stringstream ret;
    ret << "CIRNode {";
    switch (type) {
        case INVALID: {
            ret << "INVALID ";
            break;
        }
        case STORE: {
            ret << "STORE ";
            break;
        }
        case LOAD: {
            ret << "LOAD ";
            break;
        }
        case MOVE: {
            ret << "MOVE ";
            break;
        }
        case JUMP: {
            ret << "JUMP ";
            break;
        }
        case SYSCALL: {
            ret << "SYSCALL ";
            break;
        }
        case RAW: {
            ret << "RAW ";
            break;
        }
        case ADD: {
            ret << "ADD ";
            break;
        }
        case ADDR: {
            ret << "ADDR ";
            break;
        }
    }
    Operand* tmp = operands;
    while (tmp != nullptr) {
        ret << tmp->toString();
        tmp++;
    }
    ret << "}";
    return ret.str();
}
