/**
 * @file controleServicos.cpp
 * @brief Implementação dos serviços de controle do sistema.
 */

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
 * @brief Realiza o login de uma conta.
 *
 * @param codigo Código da conta.
 * @param senha Senha da conta.
 * @return int Código do status do login.
 */
int CntrServicoAutenticacaoConta::logarConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->logarConta(codigo, senha);
}

/**
 * @brief Cria uma nova conta.
 *
 * @param codigo Código único da conta.
 * @param senha Senha associada à conta.
 * @return true Se a conta foi criada com sucesso.
 * @return false Se a criação da conta falhou.
 */
bool CntrServicoAutenticacaoConta::createConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->createConta(codigo, senha);
}

/**
 * @brief Cria uma nova viagem associada a uma conta.
 *
 * @param codigo Código único da viagem.
 * @param nome Nome da viagem.
 * @param avaliacao Avaliação da viagem.
 * @param codigoConta Código da conta do usuário que criou a viagem.
 * @return true Se a viagem foi criada com sucesso.
 * @return false Se a criação da viagem falhou.
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

/**
 * @brief Obtém a conta associada a uma viagem.
 *
 * @param codigoViagem Código da viagem.
 * @return string Código da conta associada à viagem.
 */
string CntrServicoDestino::getConta(string codigoViagem){
    ContainerViagem* container = ContainerViagem::getInstancia();
    return container->getConta(codigoViagem);
}

/**
 * @brief Obtém a viagem associada a um destino.
 *
 * @param codigoDestino Código do destino.
 * @return string Código da viagem associada ao destino.
 */
string CntrServicoDestino::getViagem(string codigoDestino){
    ContainerDestino* container = ContainerDestino::getInstancia();
    return container->getViagem(codigoDestino);
}

/**
 * @brief Cria um novo destino associado a uma viagem.
 *
 * @param codigo Código único do destino.
 * @param nome Nome do destino.
 * @param data_inicio Data de início da viagem ao destino.
 * @param data_final Data de término da viagem ao destino.
 * @param avaliacao Avaliação do destino.
 * @param codigoViagem Código da viagem associada ao destino.
 * @return true Se o destino foi criado com sucesso.
 * @return false Se a criação do destino falhou.
 */
bool CntrServicoDestino::createDestino(string codigo, string nome, string data_inicio, string data_final, string avaliacao, string codigoViagem){
    ContainerDestino* container = ContainerDestino::getInstancia();
    return container->createDestino(codigo, nome, data_inicio, data_final, avaliacao, codigoViagem);
}

/**
 * @brief Lista todos os destinos associados a uma viagem.
 *
 * @param codigoViagem Código da viagem.
 */
void CntrServicoDestino::listarDestinos(string codigoViagem){
    ContainerDestino* container = ContainerDestino::getInstancia();
    container->listarDestinos(codigoViagem);
}

/**
 * @brief Cria uma nova hospedagem associada a um destino.
 *
 * @param codigo Código único da hospedagem.
 * @param nome Nome da hospedagem.
 * @param diaria Valor da diária da hospedagem.
 * @param avaliacao Avaliação da hospedagem.
 * @param codigoDestino Código do destino associado à hospedagem.
 * @return true Se a hospedagem foi criada com sucesso.
 * @return false Se a criação da hospedagem falhou.
 */
bool CntrServicoHospedagem::createHospedagem(string codigo, string nome, string diaria, string avaliacao, string codigoDestino){
    ContainerHospedagem* container = ContainerHospedagem::getInstancia();
    return container->createHospedagem(codigo, nome, diaria, avaliacao, codigoDestino);
}

/**
 * @brief Lista todas as hospedagens associadas a um destino.
 *
 * @param codigoDestino Código do destino.
 */
void CntrServicoHospedagem::listarHospedagens(string codigoDestino){
    ContainerHospedagem* container = ContainerHospedagem::getInstancia();
    container->listarHospedagens(codigoDestino);
}

/**
 * @brief Cria uma nova atividade associada a um destino.
 *
 * @param codigo Código único da atividade.
 * @param nome Nome da atividade.
 * @param data Data em que a atividade ocorrerá.
 * @param horario Horário da atividade.
 * @param duracao Duração da atividade.
 * @param preco Preço da atividade.
 * @param avaliacao Avaliação da atividade.
 * @param codigoDestino Código do destino associado à atividade.
 * @return true Se a atividade foi criada com sucesso.
 * @return false Se a criação da atividade falhou.
 */
bool CntrServicoAtividade::createAtividade(string codigo, string nome, string data, string horario, string duracao, string preco, string avaliacao, string codigoDestino){
    ContainerAtividade* container = ContainerAtividade::getInstancia();
    return container->createAtividade(codigo, nome, data, horario, duracao, preco, avaliacao, codigoDestino);
}

/**
 * @brief Lista todas as atividades associadas a um destino.
 *
 * @param codigoDestino Código do destino.
 */
void CntrServicoAtividade::listarAtividades(string codigoDestino){
    ContainerAtividade* container = ContainerAtividade::getInstancia();
    container->listarAtividades(codigoDestino);
}
