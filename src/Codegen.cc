#include "crop/Codegen.h"

#include "crop/CIR.h"

#include <iostream>
#include <vector>
#include <cassert>

void codegen(std::vector<CIRNode*> nodes) {
    for (CIRNode* node : nodes) {
        switch (node->getType()) {
            case CIRNode::Type::INVALID: {
                std::cerr << "Invalid node reached" << std::endl;
                std::cerr << "\t" << node->toString() << std::endl;
                return;
            }
            case CIRNode::Type::STORE: {
                visitStoreNode(node);
                break;
            }
            case CIRNode::Type::LOAD: {
                visitLoadNode(node);
                break;
            }
            case CIRNode::Type::MOVE: {
                visitMoveNode(node);
                break;
            }
            case CIRNode::Type::JUMP: {
                visitJumpNode(node);
                break;
            }
            case CIRNode::Type::SYSCALL: {
                visitSyscallNode(node);
                break;
            }
            case CIRNode::Type::RAW: {
                visitRawNode(node);
                break;
            }
            case CIRNode::Type::ADD: {
                visitAddNode(node);
                break;
            }
            case CIRNode::Type::ADDR: {
                visitAddrNode(node);
                break;
            }
        }
    }
}

void visitStoreNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::STORE);

    std::cout << "Visiting store node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitLoadNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::LOAD);

    std::cout << "Visiting load node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitMoveNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::MOVE);

    std::cout << "Visiting move node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitJumpNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::JUMP);

    std::cout << "Visiting jump node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitSyscallNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::SYSCALL);

    std::cout << "Visiting syscall node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitRawNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::RAW);

    std::cout << "Visiting raw node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitAddNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::ADD);

    std::cout << "Visiting add node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}

void visitAddrNode(CIRNode* node) {
    assert(node->getType() == CIRNode::Type::ADDR);

    std::cout << "Visiting addr node" << std::endl;
    std::cout << "\t" << node->toString() << std::endl;
}
