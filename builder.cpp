#include "builder.hpp"
#include "controlaApresentacao.hpp"

/**
 * @brief Constrói e configura todos os controladores de apresentação e serviço.
 *
 * Este método é responsável por instanciar e configurar todos os controladores de apresentação
 * e serviço necessários para o funcionamento do sistema. Ele também estabelece as dependências
 * entre os controladores, garantindo que eles possam se comunicar corretamente.
 *
 * @return Retorna um ponteiro para o controlador de apresentação de controle, que é o ponto de entrada
 * principal do sistema.
 */
CntrApresentacaoControle* Builder::construir(){
    // Instancia os controladores de apresentação
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrApresentacaoViagem = new CntrApresentacaoViagem();
    cntrApresentacaoDestino = new CntrApresentacaoDestino();
    cntrApresentacaoHospedagem = new CntrApresentacaoHospedagem();
    cntrApresentacaoAtividade = new CntrApresentacaoAtividade();

    // Instancia os controladores de serviço
    cntrServicoConta = new CntrServicoAutenticacaoConta();
    cntrServicoViagem = new CntrServicoViagem();
    cntrServicoDestino = new CntrServicoDestino();
    cntrServicoHospedagem = new CntrServicoHospedagem();
    cntrServicoAtividade = new CntrServicoAtividade();

    // Configura as dependências entre os controladores de apresentação
    cntrApresentacaoControle->setCntrApresentacaoConta(cntrApresentacaoConta);

    cntrApresentacaoConta->setCntrApresentacaoControle(cntrApresentacaoControle);
    cntrApresentacaoConta->setCntrApresentacaoViagem(cntrApresentacaoViagem);

    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoViagem->setCntrApresentacaoConta(cntrApresentacaoConta);
    cntrApresentacaoViagem->setCntrApresentacaoDestino(cntrApresentacaoDestino);

    cntrApresentacaoDestino->setCntrServicoDestino(cntrServicoDestino);
    cntrApresentacaoDestino->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoDestino->setCntrApresentacaoViagem(cntrApresentacaoViagem);
    cntrApresentacaoDestino->setCntrApresentacaoHospedagem(cntrApresentacaoHospedagem);
    cntrApresentacaoDestino->setCntrApresentacaoAtividade(cntrApresentacaoAtividade);

    cntrApresentacaoHospedagem->setCntrServicoHospedagem(cntrServicoHospedagem);
    cntrApresentacaoHospedagem->setCntrApresentacaoDestino(cntrApresentacaoDestino);

    cntrApresentacaoAtividade->setCntrServicoAtividade(cntrServicoAtividade);
    cntrApresentacaoAtividade->setCntrApresentacaoDestino(cntrApresentacaoDestino);

    // Configura as dependências entre os controladores de apresentação e serviço
    cntrApresentacaoConta->setCntrServicoConta(cntrServicoConta);
    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoDestino->setCntrServicoDestino(cntrServicoDestino);
    cntrApresentacaoHospedagem->setCntrServicoHospedagem(cntrServicoHospedagem);
    cntrApresentacaoAtividade->setCntrServicoAtividade(cntrServicoAtividade);

    // Retorna o controlador de apresentação de controle, que é o ponto de entrada do sistema
    return cntrApresentacaoControle;
}

/**
 * @brief Destrutor da classe Builder.
 *
 * Este destrutor é responsável por liberar a memória alocada para todos os controladores
 * de apresentação e serviço instanciados durante a execução do programa.
 */
Builder::~Builder(){
    // Libera a memória dos controladores de apresentação
    delete cntrApresentacaoControle;
    delete cntrApresentacaoConta;
    delete cntrApresentacaoViagem;
    delete cntrApresentacaoDestino;
    delete cntrApresentacaoHospedagem;
    delete cntrApresentacaoAtividade;

    // Libera a memória dos controladores de serviço
    delete cntrServicoConta;
    delete cntrServicoViagem;
    delete cntrServicoDestino;
    delete cntrServicoHospedagem;
    delete cntrServicoAtividade;
}
