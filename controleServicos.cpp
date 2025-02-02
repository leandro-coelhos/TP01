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