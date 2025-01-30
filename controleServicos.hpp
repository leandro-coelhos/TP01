#ifndef CONTROLESERVICOS_HPP_INCLUDED
#define CONTROLESERVICOS_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class CntrServicoAutenticacaoCriarConta{
    public:
        bool hasConta(string codigo, string senha);
        bool createConta(string codigo, string senha);
};

class CntrServicoAutenticacaoLogarConta{
    public:
        bool hasConta(string codigo, string senha);
        int logarConta(string codigo, string senha);
};

#endif // CONTROLESERVICOS_HPP_INCLUDED
