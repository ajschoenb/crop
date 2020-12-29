#include "crop/Operand.h"

#include <sstream>

Operand::Operand() : Operand(Type::INVALID, 0) {
}

Operand::Operand(Type _type, value_t _value) : type(_type) {
    if (_type != Type::INVALID && !(_type == Type::REGISTER && _value > REG_MAX)) {
        value = _value;
    }
}

Operand::Type Operand::getType() {
    return type;
}

value_t Operand::getValue() {
    return value;
}

std::string Operand::toString() {
    std::stringstream ret;
    ret << "OP {";
    switch (type) {
        case Type::INVALID: {
            ret << "INVALID ";
            break;
        }
        case Type::REGISTER: {
            ret << "REGISTER ";
            break;
        }
        case Type::IMMEDIATE: {
            ret << "IMMEDIATE ";
            break;
        }
        case Type::MEMORY: {
            ret << "MEMORY ";
            break;
        }
        case Type::LABEL: {
            ret << "LABEL ";
            break;
        }
    }
    ret << value << "}";
    return ret.str();
}
