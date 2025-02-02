/**
 * @file utils.hpp
 * @brief Cabeçalho contendo funções utilitárias para operações comuns.
 *
 * Este arquivo contém declarações de funções úteis para limpar o buffer de entrada,
 * limpar a tela do terminal e pausar a execução do programa por um curto período.
 */
#ifndef UTILS_HPP
#define UTILS_HPP

/**
 * @brief Limpa o buffer de entrada do teclado.
 *
 * Esta função é útil para evitar problemas com entradas indesejadas no buffer de entrada,
 * como quando se usa `std::cin` e há caracteres residuais no buffer.
 */
void limpaBuffer();

/**
 * @brief Limpa a tela do terminal.
 *
 * Esta função limpa a tela do terminal, proporcionando uma interface mais limpa para o usuário.
 * A implementação pode variar dependendo do sistema operacional (Windows, Linux, etc.).
 */
void limpaTela();

/**
 * @brief Pausa a execução do programa por um curto período.
 *
 * Esta função é útil para dar tempo ao usuário de ler mensagens na tela antes de continuar.
 * A implementação pode usar `sleep`, `usleep`, ou outras funções dependendo do sistema.
 */
void espera();

#endif
