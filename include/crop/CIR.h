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
    int num_operands;
    Operand* operands;

public:
    CIRNode();
    CIRNode(Type type, int num_operands, Operand* operands);
    virtual ~CIRNode();

    Type getType();
    int getNumOperands();
    Operand* getOperands();

    std::string toString();
};  // class CIRNode

#endif  // INCLUDE_CROP_CIR_H_
