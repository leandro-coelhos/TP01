/**
 * @file builder.hpp
 * @brief Declaração da classe Builder para construção dos componentes principais do sistema.
 */

#ifndef BUILDER_HPP_INCLUDED
#define BUILDER_HPP_INCLUDED

#include "interfaces.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"

/**
 * @class Builder
 * @brief Classe responsável por construir e gerenciar as instâncias dos componentes principais do sistema.
 * 
 * O Builder facilita a criação das instâncias das classes de controle de apresentação e serviços.
 */
class Builder {
     private:
          CntrApresentacaoControle *cntrApresentacaoControle; ///< Controlador principal da apresentação.
          IApresentacaoConta *cntrApresentacaoConta; ///< Interface para apresentação de conta.
          IApresentacaoViagem *cntrApresentacaoViagem; ///< Interface para apresentação de viagens.
          
          IServicoConta *cntrServicoConta; ///< Serviço de gerenciamento de contas.
          IServicoViagem *cntrServicoViagem; ///< Serviço de gerenciamento de viagens.
     public:
          /**
           * @brief Constrói e retorna o controlador principal da apresentação.
           * 
           * Responsável por instanciar os componentes necessários e retornar a instância do controlador principal.
           * @return Ponteiro para a instância de CntrApresentacaoControle.
           */
          CntrApresentacaoControle* construir();

          /**
           * @brief Destrutor da classe Builder.
           * 
           * Libera a memória alocada para os componentes instanciados.
           */
          ~Builder();
};

#endif // BUILDER_HPP_INCLUDED
