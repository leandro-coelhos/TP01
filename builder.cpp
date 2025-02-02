#include "builder.hpp"
#include "controlaApresentacao.hpp"

CntrApresentacaoControle* Builder::construir(){
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrApresentacaoViagem = new CntrApresentacaoViagem();
    cntrApresentacaoDestino = new CntrApresentacaoDestino();
    cntrApresentacaoHospedagem = new CntrApresentacaoHospedagem();
    cntrApresentacaoAtividade = new CntrApresentacaoAtividade();

    cntrServicoConta = new CntrServicoAutenticacaoConta();
    cntrServicoViagem = new CntrServicoViagem();
    cntrServicoDestino = new CntrServicoDestino();
    cntrServicoHospedagem = new CntrServicoHospedagem();
    cntrServicoAtividade = new CntrServicoAtividade();

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
    
    cntrApresentacaoConta->setCntrServicoConta(cntrServicoConta);
    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoDestino->setCntrServicoDestino(cntrServicoDestino);
    cntrApresentacaoHospedagem->setCntrServicoHospedagem(cntrServicoHospedagem);
    cntrApresentacaoAtividade->setCntrServicoAtividade(cntrServicoAtividade);

    return cntrApresentacaoControle;
}
 
Builder::~Builder(){
    delete cntrApresentacaoControle;
    delete cntrApresentacaoConta;
    delete cntrApresentacaoViagem;
    delete cntrApresentacaoDestino;
    delete cntrApresentacaoHospedagem;
    delete cntrApresentacaoAtividade;

    delete cntrServicoConta;
    delete cntrServicoViagem;
    delete cntrServicoDestino;
    delete cntrServicoHospedagem;
    delete cntrServicoAtividade;
}