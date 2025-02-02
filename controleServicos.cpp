#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "utils.hpp"
#include "entidades.hpp"
#include "controleServicos.hpp"
#include "container.hpp"

using namespace std;

int CntrServicoAutenticacaoConta::logarConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->logarConta(codigo, senha);
}

bool CntrServicoAutenticacaoConta::createConta(string codigo, string senha){
    ContainerConta* container = ContainerConta::getInstancia();
    return container->createConta(codigo, senha);
}

bool CntrServicoViagem::createViagem(string codigo, string nome, string avaliacao, string codigoConta){
    ContainerViagem* container = ContainerViagem::getInstancia();
    return container->createViagem(codigo, nome, avaliacao, codigoConta);
}

void CntrServicoViagem::listarViagens(string codigoConta){
    ContainerViagem* container = ContainerViagem::getInstancia();
    container->listarViagens(codigoConta);
}

string CntrServicoDestino::getConta(string codigoViagem){
    ContainerViagem* container = ContainerViagem::getInstancia();
    return container->getConta(codigoViagem);
}

string CntrServicoDestino::getViagem(string codigoDestino){
    ContainerDestino* container = ContainerDestino::getInstancia();
    return container->getViagem(codigoDestino);
}

bool CntrServicoDestino::createDestino(string codigo, string nome, string data_inicio, string data_final, string avaliacao, string codigoViagem){
    ContainerDestino* container = ContainerDestino::getInstancia();
    return container->createDestino(codigo, nome, data_inicio, data_final, avaliacao, codigoViagem);
}

void CntrServicoDestino::listarDestinos(string codigoViagem){
    ContainerDestino* container = ContainerDestino::getInstancia();
    container->listarDestinos(codigoViagem);
}

bool CntrServicoHospedagem::createHospedagem(string codigo, string nome, string diaria, string avaliacao, string codigoDestino){
    ContainerHospedagem* container = ContainerHospedagem::getInstancia();
    return container->createHospedagem(codigo, nome, diaria, avaliacao, codigoDestino);
}

void CntrServicoHospedagem::listarHospedagens(string codigoDestino){
    ContainerHospedagem* container = ContainerHospedagem::getInstancia();
    container->listarHospedagens(codigoDestino);
}

bool CntrServicoAtividade::createAtividade(string codigo, string nome, string data, string horario, string duracao, string preco, string avaliacao, string codigoDestino){
    ContainerAtividade* container = ContainerAtividade::getInstancia();
    return container->createAtividade(codigo, nome, data, horario, duracao, preco, avaliacao, codigoDestino);
}

void CntrServicoAtividade::listarAtividades(string codigoDestino){
    ContainerAtividade* container = ContainerAtividade::getInstancia();
    container->listarAtividades(codigoDestino);
}
