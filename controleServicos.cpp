#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "utils.hpp"
#include "entidades.hpp"
#include "controleServicos.hpp"
#include "container.hpp"

using namespace std;

/**
 * @class CntrServicoAutenticacaoConta
 * @brief Classe responsável por serviços de autenticação de conta.
 */

/**
 * @brief Realiza o login de uma conta.
 * 
 * @param codigo Código da conta.
 * @param senha Senha da conta.
 * @return int Retorna um código de status do login.
 */
int CntrServicoAutenticacaoConta::logarConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->logarConta(codigo, senha);
}

/**
 * @brief Cria uma nova conta.
 * 
 * @param codigo Código da conta.
 * @param senha Senha da conta.
 * @return bool Retorna verdadeiro se a conta foi criada com sucesso, falso caso contrário.
 */
bool CntrServicoAutenticacaoConta::createConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->createConta(codigo, senha);
}
