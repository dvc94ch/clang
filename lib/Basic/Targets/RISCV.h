//===--- RISCV.h - Declare RISCV target feature support -------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares RISCV TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_RISCV_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_RISCV_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace targets {

// RISCV Target
// TODO: need to handle 64-bit as well as 32-bit
class LLVM_LIBRARY_VISIBILITY RISCVTargetInfo : public TargetInfo {
public:
  RISCVTargetInfo(const llvm::Triple &Triple, const TargetOptions &)
      : TargetInfo(Triple) {
    TLSSupported = false;
    resetDataLayout("e-m:e-p:32:32-i64:64-n32-S128");
  }

  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override { return None; }

  BuiltinVaListKind getBuiltinVaListKind() const override {
    return TargetInfo::VoidPtrBuiltinVaList;
  }

  const char *getClobbers() const override { return ""; }

  ArrayRef<const char *> getGCCRegNames() const override {
    static const char *const GCCRegNames[] = {
      "x0",  "x1",  "x2",  "x3",  "x4",  "x5",  "x6",  "x7",
      "x8",  "x9",  "x10", "x11", "x12", "x13", "x14", "x15",
      "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23",
      "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31"};
    return llvm::makeArrayRef(GCCRegNames);
  }

  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    static const TargetInfo::GCCRegAlias GCCRegAliases[] = {
      {{"zero"}, "x0"}, {{"ra"}, "x1"},  {{"sp"}, "x2"},   {{"gp"}, "x3"},
      {{"tp"}, "x4"},   {{"t0"}, "x5"},  {{"t1"}, "x6"},   {{"t2"}, "x7"},
      {{"s0"}, "x8"},   {{"s1"}, "x9"},  {{"a0"}, "x10"},  {{"a1"}, "x11"},
      {{"a2"}, "x12"},  {{"a3"}, "x13"}, {{"a4"}, "x15"},  {{"a5"}, "x15"},
      {{"a6"}, "x16"},  {{"a7"}, "x17"}, {{"s2"}, "x18"},  {{"s3"}, "x19"},
      {{"s4"}, "x20"},  {{"s5"}, "x21"}, {{"s6"}, "x22"},  {{"s7"}, "x23"},
      {{"s8"}, "x24"},  {{"s9"}, "x25"}, {{"s10"}, "x26"}, {{"s11"}, "x27"},
      {{"t3"}, "x28"},  {{"t4"}, "x29"}, {{"t5"}, "x30"},  {{"t6"}, "x31"}};
    return llvm::makeArrayRef(GCCRegAliases);
  }

  bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &Info) const override {
    return false;
  }
};

} // namespace targets
} // namespace clang

#endif // LLVM_CLANG_LIB_BASIC_TARGETS_RISCV_H
