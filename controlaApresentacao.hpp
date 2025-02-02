/**
 * @file controlaApresentacao.hpp
 * @brief Declaração das classes de controle da camada de apresentação.
 */

#ifndef CONTROLAAPRESENTACAO_HPP_INCLUDED
#define CONTROLAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string> 
#include "utils.hpp"
#include "interfaces.hpp"

using namespace std;

<<<<<<< HEAD
/**
 * @class CntrApresentacaoControle
 * @brief Classe responsável pelo controle geral da apresentação.
 * 
 * Gerencia a navegação entre os módulos de conta, viagem e outros serviços.
 */
class CntrApresentacaoControle {
    private:
        IApresentacaoConta *cntrApresentacaoConta;    ///< Interface para controle de contas.
        IApresentacaoViagem *cntrApresentacaoViagem;  ///< Interface para controle de viagens.
    
=======
class CntrApresentacaoViagem;

class CntrApresentacaoControle {
    private:
        IApresentacaoConta *cntrApresentacaoConta;
>>>>>>> 5c46bf8c9d24168f3830c0818652f5b2a5d2c87c
    public:
        /**
         * @brief Inicia a execução do menu principal.
         */
        void executar();
        
        /**
         * @brief Finaliza a aplicação.
         */
        void exitCardapio();
<<<<<<< HEAD
        
        /**
         * @brief Define o controlador de apresentação de contas.
         * @param cntr Ponteiro para a interface IApresentacaoConta.
         */
        void setCntrApresentacaoConta(IApresentacaoConta* cntr);
        
        /**
         * @brief Define o controlador de apresentação de viagens.
         * @param cntr Ponteiro para a interface IApresentacaoViagem.
         */
        void setCntrApresentacaoViagem(IApresentacaoViagem* cntr);
=======
        void setCntrApresentacaoConta(IApresentacaoConta*);
>>>>>>> 5c46bf8c9d24168f3830c0818652f5b2a5d2c87c
};

// Implementações inline
inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}


/**
 * @class CntrApresentacaoConta
 * @brief Classe de controle para operações relacionadas a contas de usuário.
 * 
 * Implementa funcionalidades de criação e acesso a contas.
 */
class CntrApresentacaoConta: public IApresentacaoConta {
    private:
<<<<<<< HEAD
        IServicoConta *cntrServicoConta;               ///< Interface para serviços de conta.
        CntrApresentacaoControle *cntrApresentacaoControle; ///< Referência ao controlador principal.
    
=======
        IServicoConta *cntrServicoConta;
        CntrApresentacaoControle *cntrApresentacaoControle;
        IApresentacaoViagem *cntrApresentacaoViagem;
>>>>>>> 5c46bf8c9d24168f3830c0818652f5b2a5d2c87c
    public:
        /**
         * @brief Cria uma nova conta de usuário.
         */
        void criarConta();
        
        /**
         * @brief Permite o acesso a uma conta existente.
         */
        void acessarConta();
<<<<<<< HEAD
        
        /**
         * @brief Define o controlador de serviço de contas.
         * @param cntr Ponteiro para a interface IServicoConta.
         */
        void setCntrServicoConta(IServicoConta* cntr);
=======
        void viagensConta(string codigo);
        void setCntrServicoConta(IServicoConta*);
        void setCntrApresentacaoControle(CntrApresentacaoControle*);
        void setCntrApresentacaoViagem(IApresentacaoViagem*);
>>>>>>> 5c46bf8c9d24168f3830c0818652f5b2a5d2c87c
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

<<<<<<< HEAD
/**
 * @class CntrApresentacaoCardapio
 * @brief Classe para controle do menu principal.
 * 
 * Gerencia opções como criação de conta, acesso e saída.
 */
class CntrApresentacaoCardapio{
    public:
        /**
         * @brief Exibe o menu principal.
         */
        void menu();
        
        /**
         * @brief Direciona para a criação de conta.
         */
        void createConta();
        
        /**
         * @brief Direciona para o acesso à conta.
         */
        void accessConta();
        
        /**
         * @brief Finaliza a aplicação.
         */
        void exitCardapio();
};

/**
 * @class CntrApresentacaoCardapioConta
 * @brief Classe para controle do menu de conta logada.
 * 
 * Gerencia opções como viagens, hospedagens, destinos e atividades.
 */
class CntrApresentacaoCardapioConta{
    public:
        /**
         * @brief Exibe o menu da conta logada.
         */
        void menu();
        
        /**
         * @brief Gerencia operações relacionadas a viagens.
         */
        void viagem();
        
        /**
         * @brief Gerencia operações relacionadas a hospedagens.
         */
        void hospedagem();
        
        /**
         * @brief Gerencia operações relacionadas a destinos.
         */
        void destino();
        
        /**
         * @brief Gerencia operações relacionadas a atividades.
         */
        void atividade();
        
        /**
         * @brief Encerra a sessão da conta.
         */
        void exitCardapioConta();
};
=======
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

>>>>>>> 5c46bf8c9d24168f3830c0818652f5b2a5d2c87c

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
