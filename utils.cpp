#include "utils.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
#include <windows.h>

/**
 * @brief Limpa o buffer de entrada em caso de erro.
 *
 * Verifica se houve um erro na entrada (por exemplo, quando o usuário insere um valor inválido).
 * Se houver um erro, limpa o buffer de entrada e exibe uma mensagem de erro.
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
 *
 * Limpa a tela do terminal de forma compatível com sistemas Linux/Unix e Windows.
 * Utiliza o comando `clear` para sistemas baseados em Unix e `cls` para Windows.
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
 * Pausa a execução do programa por 3 segundos. Utiliza a função `sleep` para sistemas
 * baseados em Unix e `Sleep` para Windows.
 */
void espera() { 
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        sleep(3);
    #elif defined(_WIN32) || defined(_WIN64)
        Sleep(3000);
    #endif
}
