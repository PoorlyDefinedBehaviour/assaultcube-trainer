#ifndef UTIL_H
#define UTIL_H

#include <cstdint>
#include <vector>
#include <windows.h>

extern HANDLE hProc;

namespace util {
uintptr_t getAddress(const uintptr_t& baseAddress, const std::vector<uintptr_t>& offsets);
}

#endif // UTIL_H
