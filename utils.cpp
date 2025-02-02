#include "utils.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
#include <windows.h>

void limpaBuffer() {
    if (std::cin.fail()) {
        std::cout << "Erro de entrada. Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void limpaTela() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        system("clear");
    #elif defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void espera() { 
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        sleep(3);
    #elif defined(_WIN32) || defined(_WIN64)
        Sleep(3000);
    #endif
}