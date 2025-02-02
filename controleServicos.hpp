#ifndef CONTROLESERVICOS_HPP_INCLUDED
#define CONTROLESERVICOS_HPP_INCLUDED

#include <iostream>
#include <string>

#include "interfaces.hpp"

using namespace std;

class CntrServicoAutenticacaoConta: public IServicoConta {
    public:
        int logarConta(string, string);
        bool createConta(string, string);
};

class CntrServicoViagem: public IServicoViagem {
    public:
        bool createViagem(string, string, string, string);
        void listarViagens(string);
};

class CntrServicoDestino: public IServicoDestino {
    public:
        bool createDestino(string, string, string, string, string, string);
        void listarDestinos(string);
        string getConta(string);
        string getViagem(string);
};

class CntrServicoHospedagem: public IServicoHospedagem {
    public:
        bool createHospedagem(string, string, string, string, string);
        void listarHospedagens(string);
};

class CntrServicoAtividade: public IServicoAtividade {
    public:
        bool createAtividade(string, string, string, string, string, string, string, string);
        void listarAtividades(string);
};

#endif // CONTROLESERVICOS_HPP_INCLUDED
