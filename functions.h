#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "util.h"
#include "addresses.h"
#include <windows.h>

extern HANDLE hProc;

namespace functions{
void setHealth(const unsigned int& healthValue);

int getHealth(const uintptr_t& entity = Addresses::localPlayer);
}

#endif // FUNCTIONS_H
