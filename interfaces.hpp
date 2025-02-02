/**
 * @file interfaces.hpp
 * @brief Declaração das interfaces para os serviços e apresentações do sistema.
 */

#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

/**
 * @class IServicoConta
 * @brief Interface para o serviço de conta.
 * 
 * Define operações para criação e autenticação de contas de usuário.
 */
class IServicoConta;

/**
 * @class IServicoViagem
 * @brief Interface para o serviço de viagem.
 * 
 * Define operações para gerenciamento de viagens.
 */
class IServicoViagem;

/**
 * @class IApresentacaoConta
 * @brief Interface para a apresentação da conta do usuário.
 * 
 * Define os métodos necessários para interação do usuário com o sistema de contas.
 */
class IApresentacaoConta {
     public:
          /**
           * @brief Método para criar uma nova conta.
           * 
           * Solicita as credenciais do usuário e realiza a criação da conta.
           */
          virtual void criarConta() = 0;

          /**
           * @brief Método para acessar uma conta existente.
           * 
           * Valida as credenciais do usuário e permite o acesso ao sistema.
           */
          virtual void acessarConta() = 0;

          /**
           * @brief Exibe as viagens associadas à conta do usuário.
           * 
           * @param codigo Código identificador da conta.
           */
          virtual void viagensConta(string codigo) = 0;

          /**
           * @brief Define o serviço de conta a ser utilizado.
           * @param servico Ponteiro para a implementação do serviço de conta.
           */
          virtual void setCntrServicoConta(IServicoConta* servico) = 0;

          /**
           * @brief Define o controlador da apresentação principal.
           * @param controle Ponteiro para a implementação do controlador principal.
           */
          virtual void setCntrApresentacaoControle(CntrApresentacaoControle* controle) = 0;

          /**
           * @brief Define a interface de apresentação de viagens.
           * @param viagem Ponteiro para a implementação da interface de viagens.
           */
          virtual void setCntrApresentacaoViagem(IApresentacaoViagem* viagem) = 0;

          /// Destrutor virtual.
          virtual ~IApresentacaoConta(){};
};

/**
 * @class IApresentacaoViagem
 * @brief Interface para a apresentação das funcionalidades de viagem.
 * 
 * Define os métodos para interação do usuário com o gerenciamento de viagens.
 */
class IApresentacaoViagem {
     public:
          /**
           * @brief Executa o menu principal das funcionalidades de viagem.
           * 
           * @param codigo Código identificador da conta do usuário.
           */
          virtual void executar(string codigo) = 0;

          /**
           * @brief Cria uma nova viagem associada ao usuário.
           * 
           * @param codigo Código identificador da conta do usuário.
           */
          virtual void criarViagem(string codigo) = 0;

          /**
           * @brief Lista todas as viagens do usuário.
           * 
           * @param codigo Código identificador da conta do usuário.
           */
          virtual void listarViagens(string codigo) = 0;

          /**
           * @brief Define o serviço de viagem a ser utilizado.
           * @param servico Ponteiro para a implementação do serviço de viagem.
           */
          virtual void setCntrServicoViagem(IServicoViagem* servico) = 0;

          /**
           * @brief Define a interface de apresentação de conta.
           * @param conta Ponteiro para a implementação da interface de conta.
           */
          virtual void setCntrApresentacaoConta(IApresentacaoConta* conta) = 0;

          /// Destrutor virtual.
          virtual ~IApresentacaoViagem(){};
};

//--------------------------------------------

/**
 * @class IServicoConta
 * @brief Interface para o serviço de conta.
 * 
 * Define as operações para criação e autenticação de contas de usuário.
 */
class IServicoConta {
     public:
          /**
           * @brief Cria uma nova conta com as credenciais fornecidas.
           * 
           * @param usuario Nome de usuário.
           * @param senha Senha do usuário.
           * @return true se a conta for criada com sucesso, false caso contrário.
           */
          virtual bool createConta(string usuario, string senha) = 0;

          /**
           * @brief Realiza o login de um usuário.
           * 
           * @param usuario Nome de usuário.
           * @param senha Senha do usuário.
           * @return Um identificador numérico do usuário se o login for bem-sucedido, -1 caso contrário.
           */
          virtual int logarConta(string usuario, string senha) = 0;

          /// Destrutor virtual.
          virtual ~IServicoConta(){};
};

/**
 * @class IServicoViagem
 * @brief Interface para o serviço de viagem.
 * 
 * Define as operações para gerenciamento de viagens associadas a um usuário.
 */
class IServicoViagem {
     public:
          /**
           * @brief Cria uma nova viagem associada a um usuário.
           * 
           * @param codigo Código do usuário.
           * @param destino Destino da viagem.
           * @param data Data da viagem.
           * @param descricao Descrição da viagem.
           * @return true se a viagem for criada com sucesso, false caso contrário.
           */
          virtual bool createViagem(string codigo, string destino, string data, string descricao) = 0;

          /**
           * @brief Lista todas as viagens associadas a um usuário.
           * 
           * @param codigo Código do usuário.
           */
          virtual void listarViagens(string codigo) = 0;

          /// Destrutor virtual.
          virtual ~IServicoViagem(){};
};

#endif // INTERFACES_H_INCLUDED
