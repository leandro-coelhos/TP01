#ifndef CONTROLAAPRESENTACAO_HPP_INCLUDED
#define CONTROLAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>

#include "utils.hpp"
#include "interfaces.hpp"

using namespace std;

class CntrApresentacaoViagem;

/**
 * @class CntrApresentacaoControle
 * @brief Controlador principal da apresentação do sistema.
 *
 * Responsável por gerenciar o fluxo principal da aplicação e interagir com outros controladores.
 */
class CntrApresentacaoControle {
    private:
        IApresentacaoConta *cntrApresentacaoConta; ///< Ponteiro para o controlador de apresentação de contas.
    public:
        /**
         * @brief Executa o fluxo principal da aplicação.
         */
        void executar();

        /**
         * @brief Finaliza o cardápio ou menu atual.
         */
        void exitCardapio();

        /**
         * @brief Define o controlador de apresentação de contas.
         * @param cntr Ponteiro para o controlador de apresentação de contas.
         */
        void setCntrApresentacaoConta(IApresentacaoConta*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

/**
 * @class CntrApresentacaoConta
 * @brief Controlador de apresentação para operações relacionadas a contas.
 *
 * Gerencia a criação, acesso e operações de viagens associadas a uma conta.
 */
class CntrApresentacaoConta: public IApresentacaoConta {
    private:
        IServicoConta *cntrServicoConta; ///< Ponteiro para o serviço de contas.
        CntrApresentacaoControle *cntrApresentacaoControle; ///< Ponteiro para o controlador de apresentação principal.
        IApresentacaoViagem *cntrApresentacaoViagem; ///< Ponteiro para o controlador de apresentação de viagens.
    public:
        /**
         * @brief Cria uma nova conta.
         */
        void criarConta();

        /**
         * @brief Acessa uma conta existente.
         */
        void acessarConta();

        /**
         * @brief Exibe as viagens associadas a uma conta.
         * @param codigo Código da conta.
         */
        void viagensConta(string codigo);

        /**
         * @brief Define o serviço de contas.
         * @param cntr Ponteiro para o serviço de contas.
         */
        void setCntrServicoConta(IServicoConta*);

        /**
         * @brief Define o controlador de apresentação principal.
         * @param cntr Ponteiro para o controlador de apresentação principal.
         */
        void setCntrApresentacaoControle(CntrApresentacaoControle*);

        /**
         * @brief Define o controlador de apresentação de viagens.
         * @param cntr Ponteiro para o controlador de apresentação de viagens.
         */
        void setCntrApresentacaoViagem(IApresentacaoViagem*);
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoControle(CntrApresentacaoControle *cntr){
    cntrApresentacaoControle = cntr;
}

inline void CntrApresentacaoConta::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

/**
 * @class CntrApresentacaoViagem
 * @brief Controlador de apresentação para operações relacionadas a viagens.
 *
 * Gerencia a criação e listagem de viagens associadas a uma conta.
 */
class CntrApresentacaoViagem: public IApresentacaoViagem {
    private:
        IServicoViagem *cntrServicoViagem; ///< Ponteiro para o serviço de viagens.
        IApresentacaoConta *cntrApresentacaoConta; ///< Ponteiro para o controlador de apresentação de contas.
        IApresentacaoDestino *cntrApresentacaoDestino; ///< Ponteiro para o controlador de apresentação de destinos.
    public:
        /**
         * @brief Executa o fluxo de operações de viagens.
         * @param codigo Código da conta.
         */
        void executar(string codigo);

        /**
         * @brief Cria uma nova viagem.
         * @param codigo Código da conta.
         */
        void criarViagem(string codigo);

        /**
         * @brief Lista as viagens associadas a uma conta.
         * @param codigo Código da conta.
         */
        void listarViagens(string codigo);

        /**
         * @brief Define o serviço de viagens.
         * @param cntr Ponteiro para o serviço de viagens.
         */
        void setCntrServicoViagem(IServicoViagem*);

        /**
         * @brief Define o controlador de apresentação de contas.
         * @param cntr Ponteiro para o controlador de apresentação de contas.
         */
        void setCntrApresentacaoConta(IApresentacaoConta*);

        /**
         * @brief Define o controlador de apresentação de destinos.
         * @param cntr Ponteiro para o controlador de apresentação de destinos.
         */
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoViagem::setCntrServicoViagem(IServicoViagem *cntr) {
    cntrServicoViagem = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoConta(IApresentacaoConta *cntr){
    cntrApresentacaoConta = cntr;
}

inline void CntrApresentacaoViagem::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

/**
 * @class CntrApresentacaoDestino
 * @brief Controlador de apresentação para operações relacionadas a destinos.
 *
 * Gerencia a criação, listagem e exibição de destinos associados a viagens.
 */
class CntrApresentacaoDestino: public IApresentacaoDestino {
    private:
        IServicoDestino *cntrServicoDestino; ///< Ponteiro para o serviço de destinos.
        IServicoViagem *cntrServicoViagem; ///< Ponteiro para o serviço de viagens.
        IApresentacaoViagem *cntrApresentacaoViagem; ///< Ponteiro para o controlador de apresentação de viagens.
        IApresentacaoHospedagem *cntrApresentacaoHospedagem; ///< Ponteiro para o controlador de apresentação de hospedagens.
        IApresentacaoAtividade *cntrApresentacaoAtividade; ///< Ponteiro para o controlador de apresentação de atividades.
    public:
        /**
         * @brief Executa o fluxo de operações de destinos.
         * @param codigo Código da viagem.
         */
        void executar(string codigo);

        /**
         * @brief Cria um novo destino.
         * @param codigo Código da viagem.
         */
        void criarDestino(string codigo);

        /**
         * @brief Lista os destinos associados a uma viagem.
         * @param codigo Código da viagem.
         */
        void listarDestinos(string codigo);

        /**
         * @brief Exibe detalhes de um destino.
         * @param codigo Código do destino.
         */
        void showDestino(string codigo);

        /**
         * @brief Define o serviço de destinos.
         * @param cntr Ponteiro para o serviço de destinos.
         */
        void setCntrServicoDestino(IServicoDestino*);

        /**
         * @brief Define o controlador de apresentação de viagens.
         * @param cntr Ponteiro para o controlador de apresentação de viagens.
         */
        void setCntrApresentacaoViagem(IApresentacaoViagem*);

        /**
         * @brief Define o controlador de apresentação de hospedagens.
         * @param cntr Ponteiro para o controlador de apresentação de hospedagens.
         */
        void setCntrApresentacaoHospedagem(IApresentacaoHospedagem*);

        /**
         * @brief Define o controlador de apresentação de atividades.
         * @param cntr Ponteiro para o controlador de apresentação de atividades.
         */
        void setCntrApresentacaoAtividade(IApresentacaoAtividade*);

        /**
         * @brief Define o serviço de viagens.
         * @param cntr Ponteiro para o serviço de viagens.
         */
        void setCntrServicoViagem(IServicoViagem*);
};

inline void CntrApresentacaoDestino::setCntrServicoDestino(IServicoDestino *cntr){
    cntrServicoDestino = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoViagem(IApresentacaoViagem *cntr){
    cntrApresentacaoViagem = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoHospedagem(IApresentacaoHospedagem *cntr){
    cntrApresentacaoHospedagem = cntr;
}

inline void CntrApresentacaoDestino::setCntrApresentacaoAtividade(IApresentacaoAtividade *cntr){
    cntrApresentacaoAtividade = cntr;
}

inline void CntrApresentacaoDestino::setCntrServicoViagem(IServicoViagem *cntr){
    cntrServicoViagem = cntr;
}

/**
 * @class CntrApresentacaoHospedagem
 * @brief Controlador de apresentação para operações relacionadas a hospedagens.
 *
 * Gerencia a criação e listagem de hospedagens associadas a destinos.
 */
class CntrApresentacaoHospedagem: public IApresentacaoHospedagem {
    private:
        IServicoHospedagem *cntrServicoHospedagem; ///< Ponteiro para o serviço de hospedagens.
        IApresentacaoDestino *cntrApresentacaoDestino; ///< Ponteiro para o controlador de apresentação de destinos.
    public:
        /**
         * @brief Cria uma nova hospedagem.
         * @param codigo Código do destino.
         */
        void criarHospedagem(string codigo);

        /**
         * @brief Lista as hospedagens associadas a um destino.
         * @param codigo Código do destino.
         */
        void listarHospedagens(string codigo);

        /**
         * @brief Define o serviço de hospedagens.
         * @param cntr Ponteiro para o serviço de hospedagens.
         */
        void setCntrServicoHospedagem(IServicoHospedagem*);

        /**
         * @brief Define o controlador de apresentação de destinos.
         * @param cntr Ponteiro para o controlador de apresentação de destinos.
         */
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoHospedagem::setCntrServicoHospedagem(IServicoHospedagem *cntr){
    cntrServicoHospedagem = cntr;
}

inline void CntrApresentacaoHospedagem::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

/**
 * @class CntrApresentacaoAtividade
 * @brief Controlador de apresentação para operações relacionadas a atividades.
 *
 * Gerencia a criação e listagem de atividades associadas a destinos.
 */
class CntrApresentacaoAtividade: public IApresentacaoAtividade {
    private:
        IServicoAtividade *cntrServicoAtividade; ///< Ponteiro para o serviço de atividades.
        IApresentacaoDestino *cntrApresentacaoDestino; ///< Ponteiro para o controlador de apresentação de destinos.
    public:
        /**
         * @brief Cria uma nova atividade.
         * @param codigo Código do destino.
         */
        void criarAtividade(string codigo);

        /**
         * @brief Lista as atividades associadas a um destino.
         * @param codigo Código do destino.
         */
        void listarAtividades(string codigo);

        /**
         * @brief Define o serviço de atividades.
         * @param cntr Ponteiro para o serviço de atividades.
         */
        void setCntrServicoAtividade(IServicoAtividade*);

        /**
         * @brief Define o controlador de apresentação de destinos.
         * @param cntr Ponteiro para o controlador de apresentação de destinos.
         */
        void setCntrApresentacaoDestino(IApresentacaoDestino*);
};

inline void CntrApresentacaoAtividade::setCntrServicoAtividade(IServicoAtividade *cntr){
    cntrServicoAtividade = cntr;
}

inline void CntrApresentacaoAtividade::setCntrApresentacaoDestino(IApresentacaoDestino *cntr){
    cntrApresentacaoDestino = cntr;
}

#endif // CONTROLAAPRESENTACAO_HPP_INCLUDED
