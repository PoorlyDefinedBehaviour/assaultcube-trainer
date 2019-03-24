#include <iostream>
#include <windows.h>
#include <cstdarg>

#include "functions.h"

void print(){}
template<typename T, typename... Args>
void print(T head, Args... tail){
    std::cout << head << " ";
    print(tail...);
}

HANDLE hProc;

int main()
{
    HWND gameWindow = nullptr;
    do{
        gameWindow = FindWindowA(nullptr, "AssaultCube");
        if(!gameWindow)
            print("Waiting for window...");
        Sleep(100);
        system("cls");
    }while(!gameWindow);

    DWORD procID;
    GetWindowThreadProcessId(gameWindow, &procID);
    if(!procID){
        print("Couldn't get process id");
        exit(EXIT_FAILURE);
    }

    hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
    if(!hProc){
        print("Couldn't open a handle to the process");
        exit(EXIT_FAILURE);
    }

    while(true){
        functions::setHealth(420);
        Sleep(10);
    }
}
