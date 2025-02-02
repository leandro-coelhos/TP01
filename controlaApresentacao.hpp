/**
 * @file controlaApresentacao.hpp
 * @brief Declaração das classes de controle da camada de apresentação.
 * 
 * Este arquivo contém as declarações das classes responsáveis por gerenciar a interface
 * de usuário e a navegação entre as funcionalidades da aplicação.
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
         * 
         * Exibe as opções disponíveis e direciona o usuário para a funcionalidade escolhida.
         */
        void executar();
        
        /**
         * @brief Finaliza a aplicação.
         * 
         * Exibe uma mensagem de encerramento e fecha o programa.
         */
        void exitCardapio();
        
        /**
         * @brief Define o controlador de apresentação de contas.
         * 
         * @param cntr Ponteiro para a interface IApresentacaoConta.
         */
        void setCntrApresentacaoConta(IApresentacaoConta* cntr);
        
        /**
         * @brief Define o controlador de apresentação de viagens.
         * 
         * @param cntr Ponteiro para a interface IApresentacaoViagem.
         */
        void setCntrApresentacaoViagem(IApresentacaoViagem* cntr);
};

// Implementações inline
inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr) {
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
        IServicoConta *cntrServicoConta;               ///< Interface para serviços de conta.
        CntrApresentacaoControle *cntrApresentacaoControle; ///< Referência ao controlador principal.
        IApresentacaoViagem *cntrApresentacaoViagem;   ///< Interface para controle de viagens.
    
    public:
        /**
         * @brief Cria uma nova conta de usuário.
         * 
         * Solicita informações ao usuário e utiliza o serviço de conta para realizar o cadastro.
         */
        void criarConta();
        
        /**
         * @brief Permite o acesso a uma conta existente.
         * 
         * Valida as credenciais do usuário e, se bem-sucedido, direciona para o menu de viagens.
         */
        void acessarConta();
        
        /**
         * @brief Gerencia as opções relacionadas a viagens de uma conta.
         * 
         * @param codigo Código da conta logada.
         */
        void viagensConta(string codigo);
        
        /**
         * @brief Define o controlador de serviço de contas.
         * 
         * @param cntr Ponteiro para a interface IServicoConta.
         */
        void setCntrServicoConta(IServicoConta* cntr);
        
        /**
         * @brief Define o controlador de apresentação principal.
         * 
         * @param cntr Ponteiro para a interface CntrApresentacaoControle.
         */
        void setCntrApresentacaoControle(CntrApresentacaoControle* cntr);
        
        /**
         * @brief Define o controlador de apresentação de viagens.
         * 
         * @param cntr Ponteiro para a interface IApresentacaoViagem.
         */
        void setCntrApresentacaoViagem(IApresentacaoViagem* cntr);
};

// Implementações inline
inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr) {
    cntrServicoConta = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoControle(CntrApresentacaoControle *cntr) {
    cntrApresentacaoControle = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoViagem(IApresentacaoViagem *cntr) {
    cntrApresentacaoViagem = cntr;
}

/**
 * @class CntrApresentacaoViagem
 * @brief Classe de controle para operações relacionadas a viagens.
 * 
 * Implementa funcionalidades de criação e listagem de viagens.
 */
class CntrApresentacaoViagem: public IApresentacaoViagem {
    private:
        IServicoViagem *cntrServicoViagem;             ///< Interface para serviços de viagem.
        IApresentacaoConta *cntrApresentacaoConta;     ///< Referência ao controlador de conta.
    
    public:
        /**
         * @brief Executa o menu de viagens.
         * 
         * @param codigo Código da conta logada.
         */
        void executar(string codigo);
        
        /**
         * @brief Cria uma nova viagem.
         * 
         * @param codigo Código da conta logada.
         */
        void criarViagem(string codigo);
        
        /**
         * @brief Lista as viagens associadas a uma conta.
         * 
         * @param codigo Código da conta logada.
         */
        void listarViagens(string codigo);
        
        /**
         * @brief Define o controlador de serviço de viagens.
         * 
         * @param cntr Ponteiro para a interface IServicoViagem.
         */
        void setCntrServicoViagem(IServicoViagem* cntr);
        
        /**
         * @brief Define o controlador de apresentação de contas.
         * 
         * @param cntr Ponteiro para a interface IApresentacaoConta.
         */
        void setCntrApresentacaoConta(IApresentacaoConta* cntr);
};

// Implementações inline
inline void CntrApresentacaoViagem::setCntrServicoViagem(IServicoViagem *cntr) {
    cntrServicoViagem = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoConta(IApresentacaoConta *cntr) {
    cntrApresentacaoConta = cntr;
}

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED