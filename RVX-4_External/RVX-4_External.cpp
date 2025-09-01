/*
* Hi i'm back :)
*/
#include <Windows.h>
#include <iostream>
#include <string>
#include "Memory.hpp"


using namespace std;

class ProcessHandler {
public:
    const char* TARGET_PROCESS_NAME = "RobloxPlayerBeta.exe";
    std::string checkIfProcessOpen(std::string processName);
};

std::string ProcessHandler::checkIfProcessOpen(std::string processName) {
    std::cout << "Todo process handler" << std::endl;
    return "true";
}


class Roblox {

};

int main()
{
    std::string s;

    SetConsoleTitle("RVX-4 - Executor");
    ProcessHandler process;

    process.checkIfProcessOpen(process.TARGET_PROCESS_NAME);

    Memory Memory;
    Memory.GetDebugPrivileges();
    int processId = Memory.GetProcessId(process.TARGET_PROCESS_NAME);
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);


    int baseAddress = Memory.GetModuleBase(processHandle, (std::string)process.TARGET_PROCESS_NAME);
    std::cout << "Base address for module \"" << process.TARGET_PROCESS_NAME << "\" is " << hex << baseAddress << " (Decompiler)..." << std::endl;

    int gameVersionAddress = baseAddress + 0x0598d;

    string gameVersion = Memory.ReadText(processHandle, gameVersionAddress);
    std::cout << "Game version: " << gameVersionAddress << std::endl;

    std::cout << "Hello World!\n";

    std::cin >> s;
}


