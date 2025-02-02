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
        IApresentacaoDestino *cntrApresentacaoDestino;
    public:
        void executar(string codigo);
        void criarViagem(string codigo);
        void listarViagens(string codigo);
        void setCntrServicoViagem(IServicoViagem*);
        void setCntrApresentacaoConta(IApresentacaoConta*);
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoViagem::setCntrServicoViagem(IServicoViagem *cntr) {
    cntrServicoViagem = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

class CntrApresentacaoDestino: public IApresentacaoDestino {
    private:
        IServicoDestino *cntrServicoDestino;
        IServicoViagem *cntrServicoViagem;
        IApresentacaoViagem *cntrApresentacaoViagem;
        IApresentacaoHospedagem *cntrApresentacaoHospedagem;
        IApresentacaoAtividade *cntrApresentacaoAtividade;
    public:
        void executar(string codigo);
        void criarDestino(string codigo);
        void listarDestinos(string codigo);
        void showDestino(string codigo);
        void setCntrServicoDestino(IServicoDestino*);
        void setCntrApresentacaoViagem(IApresentacaoViagem*);
        void setCntrApresentacaoHospedagem(IApresentacaoHospedagem*);
        void setCntrApresentacaoAtividade(IApresentacaoAtividade*);
        void setCntrServicoViagem(IServicoViagem*);
};

inline void CntrApresentacaoDestino::setCntrServicoDestino(IServicoDestino *cntr){
    cntrServicoDestino = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoHospedagem(IApresentacaoHospedagem *cntr){
    cntrApresentacaoHospedagem = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoAtividade(IApresentacaoAtividade *cntr){
    cntrApresentacaoAtividade = cntr;
}

inline void CntrApresentacaoDestino::setCntrServicoViagem(IServicoViagem *cntr){
    cntrServicoViagem = cntr;
}

class CntrApresentacaoHospedagem: public IApresentacaoHospedagem {
    private:
        IServicoHospedagem *cntrServicoHospedagem;
        IApresentacaoDestino *cntrApresentacaoDestino;
    public:
        void criarHospedagem(string codigo);
        void listarHospedagens(string codigo);
        void setCntrServicoHospedagem(IServicoHospedagem*);
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoHospedagem::setCntrServicoHospedagem(IServicoHospedagem *cntr){
    cntrServicoHospedagem = cntr;
}

inline void CntrApresentacaoHospedagem::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

class CntrApresentacaoAtividade: public IApresentacaoAtividade {
    private:
        IServicoAtividade *cntrServicoAtividade;
        IApresentacaoDestino *cntrApresentacaoDestino;
    public:
        void criarAtividade(string codigo);
        void listarAtividades(string codigo);
        void setCntrServicoAtividade(IServicoAtividade*);
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoAtividade::setCntrServicoAtividade(IServicoAtividade *cntr){
    cntrServicoAtividade = cntr;
}

inline void CntrApresentacaoAtividade::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
