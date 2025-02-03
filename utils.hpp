/**
 * @file utils.hpp
 * @brief Declaração de funções utilitárias para manipulação de entrada, limpeza de tela e espera.
 */

#ifndef UTILS_HPP
#define UTILS_HPP

/**
 * @brief Limpa o buffer de entrada do usuário.
 * 
 * Esta função verifica se houve erro na entrada padrão (`std::cin.fail()`)
 * e, se necessário, limpa o estado do `std::cin` e descarta qualquer entrada inválida no buffer.
 */
void limpaBuffer();

/**
 * @brief Limpa a tela do terminal.
 * 
 * A função detecta o sistema operacional e executa o comando adequado para limpar a tela:
 * - `clear` para Linux, macOS e Unix.
 * - `cls` para Windows.
 */
void limpaTela();

/**
 * @brief Aguarda por 3 segundos antes de prosseguir.
 * 
 * A função faz uma pausa no programa por 3 segundos utilizando:
 * - `sleep(3)` em sistemas Linux, macOS e Unix.
 * - `Sleep(3000)` em sistemas Windows.
 */
void espera();

#endif // UTILS_HPP
