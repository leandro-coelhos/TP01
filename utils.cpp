/**
 * @file utils.cpp
 * @brief Implementação de funções utilitárias para manipulação de entrada, limpeza de tela e espera.
 */

#include "utils.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
#include <windows.h>

/**
 * @brief Limpa o buffer de entrada do usuário caso ocorra um erro.
 * 
 * Esta função verifica se houve falha na entrada padrão (`std::cin.fail()`).
 * Se houver erro, limpa o estado de `std::cin` e descarta qualquer entrada inválida no buffer.
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
 * A função detecta o sistema operacional e executa o comando correspondente para limpar a tela:
 * - `clear` para Linux, macOS e Unix.
 * - `cls` para Windows.
 */
void limpaTela() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        system("clear");
    #elif defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

/**
 * @brief Aguarda por 3 segundos antes de prosseguir.
 * 
 * A função faz uma pausa no programa por 3 segundos utilizando:
 * - `sleep(3)` em sistemas Linux, macOS e Unix.
 * - `Sleep(3000)` em sistemas Windows.
 */
void espera() { 
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        sleep(3);
    #elif defined(_WIN32) || defined(_WIN64)
        Sleep(3000);
    #endif
}
