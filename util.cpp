#include "util.h"

uintptr_t util::getAddress(const uintptr_t& baseAddress, const std::vector<uintptr_t>& offsets){
    uintptr_t pointerAddress = baseAddress;
    for(const auto& offset : offsets){
        ReadProcessMemory(hProc, reinterpret_cast<BYTE*>(pointerAddress), &pointerAddress, sizeof(pointerAddress), nullptr);
        pointerAddress += offset;
    }
    return pointerAddress;
}
