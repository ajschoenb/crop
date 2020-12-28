# CROP Intermediate Representation (CIR) Documentation

## CIR Overview

The CIR for a given program/exploit consists of a sequence of instructions which roughly correspond to ROP gadgets. Each instruction is of the form `OPCODE [OPERANDS...]`, where `OPCODE` is the name of the instruction and `[OPERANDS...]` is a list of operands, which may be optional or variable-length depending on the particular instruction. Operands fall under four main types - immediate, register, memory, and label. Immediate value operands are prefixed with a `$`, registers with a `%`, memory with a `&`, and labels with a `_`. As CROP is designed for x86-64, there are 16 available registers (rax, rbx, rcx, rdx, rbp, rsp, rsi, rdi, r8-r15). For x86-32, which only provides 8 system registers, the others will be backed by virtual registers (<b>WIP</b>).

## CIR Instructions and Descriptions
- `STORE [DEST] [SRC]`
    - Stores the value in `SRC` into the memory addressed by `DEST`
- `LOAD [DEST] [SRC]`
    - Loads the value at the memory addressed by `SRC` into `DEST`
    - `DEST` cannot be of immediate type
- `MOVE [DEST] [SRC]`
    - Moves the value in `SRC` to `DEST`
    - `DEST` cannot be of immediate type
- `JUMP [DEST]`
    - Transitions the program execution to `DEST`
    - In practice, this consists of writing the stack pointer
- `SYSCALL [NUMBER]`
    - Moves `NUMBER` into the proper register and then triggers a syscall
- `RAW [DATA]`
    - Instead of a gadget, place `DATA` as a raw value on the stack
    - `DATA` must be of immediate type
- `ADD [DEST] [SRC1] [SRC2]`
    - Places the result of `SRC1 + SRC2` into `DEST`
    - This instruction is likely to cause compilation issues if `SRC2` is not an immediate constant like a power of 2
- `ADDR [DEST] [SRC]`
    - Loads the address of the label `SRC` into `DEST`
    - `DEST` cannot be of immediate type
    - `SRC` must be of label type

## Example Usage
- Exit

        MOVE %7 $0   // argument to exit() syscall
        SYSCALL $1   // call exit()

- Shell

        ADDR %6 _raw             // store a pointer to a pointer to "/bin/sh" in rsi (argument 2)
        ADD %7 %6 $8             // store a pointer to "/bin/sh" in rdi (argument 1)
        STORE %6 %7              // fill *(rsi) with the correct pointer
        MOVE %4 $0               // set rdx to 0 (argument 4 = NULL)
        SYSCALL $11              // call execve()
        raw :                    // define the label raw
        RAW $0                   // empty word, will be filled with a pointer to "/bin/sh"
        RAW $0x0068732f6e69622f  // "/bin/sh\0"
