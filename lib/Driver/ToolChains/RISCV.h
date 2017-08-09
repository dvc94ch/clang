//===--- RISCV.h - RISCV Tool and ToolChain Implementations ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_RISCV_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_RISCV_H

#include "Gnu.h"
#include "InputInfo.h"
#include "clang/Driver/ToolChain.h"
#include "clang/Driver/Tool.h"

namespace clang {
namespace driver {
namespace toolchains {

class LLVM_LIBRARY_VISIBILITY RISCVToolChain : public Generic_ELF {
protected:
  Tool *buildLinker() const override;
public:
  RISCVToolChain(const Driver &D, const llvm::Triple &Triple,
                 const llvm::opt::ArgList &Args);
  bool IsIntegratedAssemblerDefault() const override { return true; }
};

} // end namespace toolchains

namespace tools {
namespace RISCV {
class LLVM_LIBRARY_VISIBILITY Linker : public GnuTool {
public:
  Linker(const ToolChain &TC) : GnuTool("RISCV::Linker", "ld.lld", TC) {}
  bool hasIntegratedCPP() const override { return false; }
  bool isLinkJob() const override { return true; }
  void ConstructJob(Compilation &C, const JobAction &JA,
                    const InputInfo &Output, const InputInfoList &Inputs,
                    const llvm::opt::ArgList &TCArgs,
                    const char *LinkingOutput) const override;
};
} // end namespace RISCV
} // end namespace tools
} // end namespace driver
} // end namespace clang

#endif // LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_AVR_H
