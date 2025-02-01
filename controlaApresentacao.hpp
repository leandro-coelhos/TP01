#ifndef CONTROLAAPRESENTACAO_HPP_INCLUDED
#define CONTROLAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string> 

#include "utils.hpp"
#include "interfaces.hpp"

using namespace std;

class CntrApresentacaoControle {
    private:
        IApresentacaoConta *cntrApresentacaoConta;
        IApresentacaoViagem *cntrApresentacaoViagem;
    public:
        void executar();
        void exitCardapio();
        void setCntrApresentacaoConta(IApresentacaoConta*);
        void setCntrApresentacaoViagem(IApresentacaoViagem*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

class CntrApresentacaoConta: public IApresentacaoConta {
    private:
        IServicoConta *cntrServicoConta;
        CntrApresentacaoControle *cntrApresentacaoControle;
    public:
        void criarConta();
        void acessarConta();
        void setCntrServicoConta(IServicoConta*);
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

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
