#ifndef CONTROLESERVICOS_HPP_INCLUDED
#define CONTROLESERVICOS_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class CntrServicoAutenticacaoConta{
    public:
        int loginConta(string codigo, string senha);
        bool createConta(string codigo, string senha);
};

#endif // CONTROLESERVICOS_HPP_INCLUDED
