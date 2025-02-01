/**
* @file utils.hpp
* @brief Utilitários para limpeza de buffer, tela e espera.
*/
#include "utils.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
#include <windows.h>
/**
* @brief Limpa o buffer de entrada do std::cin.
*
* Esta função verificar se houve um erro na entrada(por exemplo,entrada inválida) e limpa o buffer de entrada.
* Se um erro for detectado, uma mensagem de erro é exibida e o buffer é limpo.
*
* @note Use esta função após operações de entrada para garantir que o buffer esteja limpo.
*
* @example
* int numero;
* std::cin >> numero;
* limpaBuffer(); // Limpa o buffer em caso de entrada inválida.
*/
void limpaBuffer() {
    if (std::cin.fail()) {
        std::cout << "Erro de entrada. Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
* @brief Limpa a tela do terminal.
* Esta função limpa a tela do terminal, independentemente do sistema operacional.
* No Linux, Unix, macOS e sistemas semelhantes, o comando 'clear' é usado.
* No Windows, o comando 'cls' é usado.
*
* @example
* limpaTela(); // Limpa a tela do terminal.
*/
void limpaTela() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        system("clear");
    #elif defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

/**
* @brief Pausa a execução do programa por 3 segundos.
* 
* Esta função pausa a execução do programa por 3 segundos, utilizando a função 'sleep' em sistemas Unix-like
* e a função 'Sleep' no Windows.
*
* @example(); // Pausa a execução por 3 segundos.
*/
void espera() { 
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        sleep(3);
    #elif defined(_WIN32) || defined(_WIN64)
        Sleep(3000);
    #endif
}
