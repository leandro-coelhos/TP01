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

#endif // CONTROLESERVICOS_HPP_INCLUDED
