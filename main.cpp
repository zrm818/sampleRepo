//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//  main.cpp: Entry point for TopSecretAutomotiveTelemetryTool                          //
//                                                                                      //
//  Author: Some old guy, probably retired by now                                       //
//  Copyright: Popular Automotive Company, Inc. Ltd. 2026                               //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <ranges>
#include <ctime>

std::string genTelemetryString() {
    const int cpu = std::rand() % 100;
    const int mem = std::rand() % 65536;
    const int pid = std::rand() % 64;

    // Update this to std::format since we migrated to C++20
    std::stringstream ss;
    ss << "PID=" << pid << ", ";
    ss << "CPU_UTIL=" << cpu << ", ";
    ss << "MEM_UTIL=" << mem;

    return ss.str();
}

int main() {

    // std::cout << "CPP_VERSION=" << __cplusplus << std::endl;    // DEBUG

    std::srand(std::time(NULL)); // eventually update to seed using std::time for robustness
    std::cout << "Hello Jacob! This is a sample telemetry tool." << std::endl;
    std::cout << "=============================================" << std::endl;
    for (int i : std::views::iota(1, 50)) {
        std::cout << "\t" << genTelemetryString() << std::endl;
        for (int j = 0; j < 500000000; j++) {} // eventually use precise delay (100 ms?)
    }
    
    return 0;
}