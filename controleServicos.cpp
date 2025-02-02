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
 * @brief Classe responsável pelos serviços de autenticação de conta.
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

/**
 * @class CntrServicoViagem
 * @brief Classe responsável pelos serviços de gerenciamento de viagens.
 */

/**
 * @brief Cria uma nova viagem.
 * 
 * @param codigo Código da viagem.
 * @param nome Nome da viagem.
 * @param avaliacao Avaliação da viagem.
 * @param codigoConta Código da conta do usuário.
 * @return bool Retorna verdadeiro se a viagem foi criada com sucesso, falso caso contrário.
 */
bool CntrServicoViagem::createViagem(string codigo, string nome, string avaliacao, string codigoConta){
    ContainerViagem* container = ContainerViagem::getInstancia();
    return container->createViagem(codigo, nome, avaliacao, codigoConta);
}

/**
 * @brief Lista todas as viagens associadas a uma conta.
 * 
 * @param codigoConta Código da conta do usuário.
 */
void CntrServicoViagem::listarViagens(string codigoConta){
    ContainerViagem* container = ContainerViagem::getInstancia();
    container->listarViagens(codigoConta);
}
