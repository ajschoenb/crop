#ifndef INCLUDE_CROP_CODEGEN_H_
#define INCLUDE_CROP_CODEGEN_H_

#include "crop/CIR.h"

#include <vector>

void codegen(std::vector<CIRNode*> nodes);

void visitStoreNode     (CIRNode* node);
void visitLoadNode      (CIRNode* node);
void visitMoveNode      (CIRNode* node);
void visitJumpNode      (CIRNode* node);
void visitSyscallNode   (CIRNode* node);
void visitRawNode       (CIRNode* node);
void visitAddNode       (CIRNode* node);
void visitAddrNode      (CIRNode* node);

#endif  // INCLUDE_CROP_CODEGEN_H_
