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
    
    public:
        /**
         * @brief Inicia a execução do menu principal.
         */
        void executar();
        
        /**
         * @brief Finaliza a aplicação.
         */
        void exitCardapio();
        
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
};

// Implementações inline
inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

/**
 * @class CntrApresentacaoConta
 * @brief Classe de controle para operações relacionadas a contas de usuário.
 * 
 * Implementa funcionalidades de criação e acesso a contas.
 */
class CntrApresentacaoConta: public IApresentacaoConta {
    private:
        IServicoConta *cntrServicoConta;               ///< Interface para serviços de conta.
        CntrApresentacaoControle *cntrApresentacaoControle; ///< Referência ao controlador principal.
    
    public:
        /**
         * @brief Cria uma nova conta de usuário.
         */
        void criarConta();
        
        /**
         * @brief Permite o acesso a uma conta existente.
         */
        void acessarConta();
        
        /**
         * @brief Define o controlador de serviço de contas.
         * @param cntr Ponteiro para a interface IServicoConta.
         */
        void setCntrServicoConta(IServicoConta* cntr);
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

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

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
