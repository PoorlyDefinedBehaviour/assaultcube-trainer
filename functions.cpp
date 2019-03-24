#include "functions.h"

void functions::setHealth(const unsigned int& healthValue){
    const uintptr_t healthAddress = util::getAddress(Addresses::localPlayer, {Addresses::healthOffset});
    WriteProcessMemory(hProc, reinterpret_cast<BYTE*>(healthAddress), &healthValue, sizeof(healthValue), nullptr);
}

int functions::getHealth(const uintptr_t& entityAddress){
    const uintptr_t healthAddress = util::getAddress(entityAddress, {Addresses::healthOffset});
    int buffer;
    ReadProcessMemory(hProc, reinterpret_cast<BYTE*>(healthAddress), &buffer, sizeof(buffer), nullptr);
    return buffer;
}
