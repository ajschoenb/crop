#ifndef INCLUDE_CROP_OPERAND_H_
#define INCLUDE_CROP_OPERAND_H_

#include <cstdint>
#include <string>

typedef uintptr_t value_t;

constexpr value_t REG_MAX = 16;

class Operand {
public:
    enum Type {
        INVALID = 0, REGISTER, IMMEDIATE, MEMORY, LABEL
    };  // enum Type

private:
    Type type;
    value_t value;

public:
    Operand();
    Operand(Type _type, value_t _value);

    Type getType();
    value_t getValue();

    std::string toString();
};  // class Operand

#endif  // INCLUDE_CROP_OPERAND_H_
