// A basic clang -cc1 command-line.

// RUN: %clang %s -### -no-canonical-prefixes -target riscv32 2>&1 | FileCheck -check-prefix=CC1 %s
// CC1: clang{{.*}} "-cc1" "-triple" "riscv32"
