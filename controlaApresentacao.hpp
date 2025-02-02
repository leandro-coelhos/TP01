#ifndef CONTROLAAPRESENTACAO_HPP_INCLUDED
#define CONTROLAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string> 

#include "utils.hpp"
#include "interfaces.hpp"

using namespace std;

class CntrApresentacaoViagem;

class CntrApresentacaoControle {
    private:
        IApresentacaoConta *cntrApresentacaoConta;
    public:
        void executar();
        void exitCardapio();
        void setCntrApresentacaoConta(IApresentacaoConta*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}


class CntrApresentacaoConta: public IApresentacaoConta {
    private:
        IServicoConta *cntrServicoConta;
        CntrApresentacaoControle *cntrApresentacaoControle;
        IApresentacaoViagem *cntrApresentacaoViagem;
    public:
        void criarConta();
        void acessarConta();
        void viagensConta(string codigo);
        void setCntrServicoConta(IServicoConta*);
        void setCntrApresentacaoControle(CntrApresentacaoControle*);
        void setCntrApresentacaoViagem(IApresentacaoViagem*);
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoControle(CntrApresentacaoControle *cntr){
    cntrApresentacaoControle = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

class CntrApresentacaoViagem: public IApresentacaoViagem {
    private:
        IServicoViagem *cntrServicoViagem;
        IApresentacaoConta *cntrApresentacaoConta;
        //CntrApresentacaoHospedagem *cntrApresentacaoHospedagem;
    public:
        void executar(string codigo);
        void criarViagem(string codigo);
        void listarViagens(string codigo);
        void setCntrServicoViagem(IServicoViagem*);
        void setCntrApresentacaoConta(IApresentacaoConta*);
        //void setCntrApresentacaoHospedagem(CntrApresentacaoHospedagem*);
};

inline void CntrApresentacaoViagem::setCntrServicoViagem(IServicoViagem *cntr) {
    cntrServicoViagem = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

// inline void CntrApresentacaoViagem::setCntrApresentacaoHospedagem(CntrApresentacaoHospedagem *cntr){
//     cntrApresentacaoHospedagem = cntr;
// }

// class CntrApresentacaoHospedagem{
//     private:
//         int teste = 0;
// };


#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
