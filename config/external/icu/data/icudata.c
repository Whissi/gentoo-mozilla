/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifdef __APPLE__
#  define RODATA ".data\n.const"
#else
#  define RODATA ".section .rodata"
#endif

#if defined(__APPLE__) || (defined(_WIN32) && defined(__i386__))
#  define _PREFIXED(x) _##x
#else
#  define _PREFIXED(x) x
#endif
#define PREFIXED(x) _PREFIXED(x)

#define DATA(sym, file) DATA2(sym, file)
// clang-format off
#define DATA2(sym, file)              \
  __asm__(".global " #sym "\n"        \
          RODATA "\n"                 \
          ".balign 16\n"              \
          #sym ":\n"                  \
          "    .incbin " #file "\n")
// clang-format on

DATA(PREFIXED(ICU_DATA_SYMBOL), ICU_DATA_FILE);
