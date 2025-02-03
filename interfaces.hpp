/**
 * @file interfaces.hpp
 * @brief Declaração das interfaces para os serviços e apresentações do sistema.
 */

#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

/**
 * Declaração das interfaces de serviços.
 * Cada interface define métodos para gerenciar diferentes funcionalidades do sistema.
 */
class IServicoConta;       ///< Interface para o serviço de conta.
class IServicoViagem;      ///< Interface para o serviço de viagem.
class IServicoDestino;     ///< Interface para o serviço de destino.
class IServicoHospedagem;  ///< Interface para o serviço de hospedagem.
class IServicoAtividade;   ///< Interface para o serviço de atividade.

/**
 * Declaração das interfaces de apresentação.
 * As classes de apresentação são responsáveis por intermediar a comunicação entre usuário e sistema.
 */
class IApresentacaoViagem;     ///< Interface para a apresentação de viagens.
class IApresentacaoConta;      ///< Interface para a apresentação de contas.
class IApresentacaoDestino;    ///< Interface para a apresentação de destinos.
class IApresentacaoHospedagem; ///< Interface para a apresentação de hospedagens.
class IApresentacaoAtividade;  ///< Interface para a apresentação de atividades.

class CntrApresentacaoControle;
class CntrApresentacaoConta;

/**
 * @class IApresentacaoConta
 * @brief Interface para a apresentação de conta.
 */
class IApresentacaoConta {
     public:
          virtual void criarConta() = 0; ///< Cria uma nova conta.
          virtual void acessarConta() = 0; ///< Acessa uma conta existente.
          virtual void viagensConta(string codigo) = 0; ///< Gerencia viagens associadas à conta.
          virtual void setCntrServicoConta(IServicoConta*) = 0; ///< Define o serviço de conta.
          virtual void setCntrApresentacaoControle(CntrApresentacaoControle*) = 0; ///< Define o controle da apresentação principal.
          virtual void setCntrApresentacaoViagem(IApresentacaoViagem*) = 0; ///< Define a apresentação de viagens.
          virtual ~IApresentacaoConta(){}; ///< Destrutor virtual.
};

/**
 * @class IApresentacaoViagem
 * @brief Interface para a apresentação de viagens.
 */
class IApresentacaoViagem {
     public:
          virtual void executar(string codigo) = 0; ///< Executa o menu de viagens.
          virtual void criarViagem(string codigo) = 0; ///< Cria uma nova viagem.
          virtual void listarViagens(string codigo) = 0; ///< Lista as viagens associadas à conta.
          virtual void setCntrServicoViagem(IServicoViagem*) = 0; ///< Define o serviço de viagem.
          virtual void setCntrApresentacaoConta(IApresentacaoConta*) = 0; ///< Define a apresentação de conta.
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0; ///< Define a apresentação de destinos.
          virtual ~IApresentacaoViagem(){}; ///< Destrutor virtual.
};

/**
 * @class IApresentacaoDestino
 * @brief Interface para a apresentação de destinos.
 */
class IApresentacaoDestino {
     public:
          virtual void executar(string codigo) = 0; ///< Executa o menu de destinos.
          virtual void criarDestino(string codigo) = 0; ///< Cria um novo destino.
          virtual void listarDestinos(string codigo) = 0; ///< Lista os destinos associados a uma viagem.
          virtual void showDestino(string codigo) = 0; ///< Exibe detalhes de um destino.
          virtual void setCntrServicoDestino(IServicoDestino*) = 0; ///< Define o serviço de destino.
          virtual void setCntrApresentacaoViagem(IApresentacaoViagem*) = 0; ///< Define a apresentação de viagens.
          virtual void setCntrApresentacaoHospedagem(IApresentacaoHospedagem*) = 0; ///< Define a apresentação de hospedagens.
          virtual void setCntrApresentacaoAtividade(IApresentacaoAtividade*) = 0; ///< Define a apresentação de atividades.
          virtual void setCntrServicoViagem(IServicoViagem*) = 0; ///< Define o serviço de viagem.
          virtual ~IApresentacaoDestino(){}; ///< Destrutor virtual.
};

/**
 * @class IApresentacaoHospedagem
 * @brief Interface para a apresentação de hospedagens.
 */
class IApresentacaoHospedagem {
     public:
          virtual void criarHospedagem(string codigo) = 0; ///< Cria uma nova hospedagem.
          virtual void listarHospedagens(string codigo) = 0; ///< Lista as hospedagens associadas a um destino.
          virtual void setCntrServicoHospedagem(IServicoHospedagem*) = 0; ///< Define o serviço de hospedagem.
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0; ///< Define a apresentação de destinos.
          virtual ~IApresentacaoHospedagem(){}; ///< Destrutor virtual.
};

/**
 * @class IApresentacaoAtividade
 * @brief Interface para a apresentação de atividades.
 */
class IApresentacaoAtividade {
     public:
          virtual void criarAtividade(string codigo) = 0; ///< Cria uma nova atividade.
          virtual void listarAtividades(string codigo) = 0; ///< Lista as atividades associadas a um destino.
          virtual void setCntrServicoAtividade(IServicoAtividade*) = 0; ///< Define o serviço de atividade.
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0; ///< Define a apresentação de destinos.
          virtual ~IApresentacaoAtividade(){}; ///< Destrutor virtual.
};

//--------------------------------------------

/**
 * @class IServicoConta
 * @brief Interface para o serviço de conta.
 */
class IServicoConta {
     public:
          virtual bool createConta(string, string) = 0; ///< Cria uma conta com credenciais.
          virtual int logarConta(string, string) = 0; ///< Realiza login na conta.
          virtual ~IServicoConta(){}; ///< Destrutor virtual.
};

/**
 * @class IServicoViagem
 * @brief Interface para o serviço de viagem.
 */
class IServicoViagem {
     public:
          virtual bool createViagem(string, string, string, string) = 0; ///< Cria uma nova viagem.
          virtual void listarViagens(string) = 0; ///< Lista viagens associadas a uma conta.
          virtual ~IServicoViagem(){}; ///< Destrutor virtual.
};

/**
 * @class IServicoDestino
 * @brief Interface para o serviço de destino.
 */
class IServicoDestino {
     public:
          virtual bool createDestino(string, string, string, string, string, string) = 0; ///< Cria um novo destino.
          virtual void listarDestinos(string) = 0; ///< Lista os destinos associados a uma viagem.
          virtual string getConta(string) = 0; ///< Retorna a conta associada ao destino.
          virtual string getViagem(string) = 0; ///< Retorna a viagem associada ao destino.
          virtual ~IServicoDestino(){}; ///< Destrutor virtual.
};

/**
 * @class IServicoHospedagem
 * @brief Interface para o serviço de hospedagem.
 */
class IServicoHospedagem {
     public:
          virtual bool createHospedagem(string, string, string, string, string) = 0; ///< Cria uma nova hospedagem.
          virtual void listarHospedagens(string) = 0; ///< Lista hospedagens associadas a um destino.
          virtual ~IServicoHospedagem(){}; ///< Destrutor virtual.
};

/**
 * @class IServicoAtividade
 * @brief Interface para o serviço de atividade.
 */
class IServicoAtividade {
     public:
          virtual bool createAtividade(string, string, string, string, string, string, string, string) = 0; ///< Cria uma nova atividade.
          virtual void listarAtividades(string) = 0; ///< Lista atividades associadas a um destino.
          virtual ~IServicoAtividade(){}; ///< Destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
