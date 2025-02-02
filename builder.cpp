/**
 * @file builder.cpp
 * @brief Implementação da classe Builder para construção dos componentes principais do sistema.
 */

#include "builder.hpp"
#include "controlaApresentacao.hpp"

/**
 * @brief Constrói e configura os componentes principais do sistema.
 * 
 * Instancia os controladores de apresentação e serviços, estabelecendo as conexões necessárias entre eles.
 * @return Ponteiro para a instância de CntrApresentacaoControle, que gerencia a interface principal.
 */
CntrApresentacaoControle* Builder::construir(){
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrApresentacaoViagem = new CntrApresentacaoViagem();

    cntrServicoConta = new CntrServicoAutenticacaoConta();
    cntrServicoViagem = new CntrServicoViagem();

    // Configuração das dependências entre os módulos
    cntrApresentacaoControle->setCntrApresentacaoConta(cntrApresentacaoConta);

    cntrApresentacaoConta->setCntrApresentacaoControle(cntrApresentacaoControle);
    cntrApresentacaoConta->setCntrApresentacaoViagem(cntrApresentacaoViagem);

    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoViagem->setCntrApresentacaoConta(cntrApresentacaoConta);
    
    cntrApresentacaoConta->setCntrServicoConta(cntrServicoConta);
    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);

    return cntrApresentacaoControle;
}

/**
 * @brief Destrutor da classe Builder.
 * 
 * Libera a memória alocada para os componentes instanciados, garantindo a remoção correta dos objetos.
 */
Builder::~Builder(){
    delete cntrApresentacaoControle;
    delete cntrApresentacaoConta;
    delete cntrApresentacaoViagem;

    delete cntrServicoConta;
    delete cntrServicoViagem;
}
