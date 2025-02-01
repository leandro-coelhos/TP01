#ifndef CONTROLESERVICOS_HPP_INCLUDED
#define CONTROLESERVICOS_HPP_INCLUDED

#include <iostream>
#include <string>

#include "interfaces.hpp"

using namespace std;

/**
 * @class CntrServicoAutenticacaoConta
 * @brief Classe responsável pelos serviços de autenticação de conta.
 */
class CntrServicoAutenticacaoConta: public IServicoConta {
    public:
        /**
         * @brief Realiza o login de uma conta.
         * 
         * @param codigo Código da conta.
         * @param senha Senha da conta.
         * @return int Retorna um código de status do login.
         */
        int logarConta(string, string);

        /**
         * @brief Cria uma nova conta.
         * 
         * @param codigo Código da conta.
         * @param senha Senha da conta.
         * @return bool Retorna verdadeiro se a conta foi criada com sucesso, falso caso contrário.
         */
        bool createConta(string, string);
};

#endif // CONTROLESERVICOS_HPP_INCLUDED