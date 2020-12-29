#ifndef INCLUDE_CROP_CIR_H_
#define INCLUDE_CROP_CIR_H_

#include "crop/Operand.h"

#include <string>

class CIRNode {
public:
    enum Type {
        INVALID = 0,
        STORE,
        LOAD,
        MOVE,
        JUMP,
        SYSCALL,
        RAW,
        ADD,
        ADDR
    };  // enum Type

private:
    Type type;
    Operand* operands;

public:
    CIRNode();
    CIRNode(Type type, Operand* operands);
    virtual ~CIRNode();

    std::string toString();
};  // class CIRNode

#endif  // INCLUDE_CROP_CIR_H_
