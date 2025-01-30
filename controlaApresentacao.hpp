#ifndef CONTROLAAPRESENTACAO_HPP_INCLUDED
#define CONTROLAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string> 

#include "utils.cpp"

using namespace std;

class CntrApresentacaoCardapio{
    public:
        void menu();
        void createConta();
        void accessConta();
        void exitCardapio();
};

class CntrApresentacaoCardapioConta{
    public:
        void menu();
        void viagem();
        void hospedagem();
        void destino();
        void atividade();
        void exitCardapioConta();
};

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
