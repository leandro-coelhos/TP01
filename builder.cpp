#include "builder.hpp"
#include "controlaApresentacao.hpp"

CntrApresentacaoControle* Builder::construir(){
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrApresentacaoViagem = new CntrApresentacaoViagem();

    cntrServicoConta = new CntrServicoAutenticacaoConta();
    cntrServicoViagem = new CntrServicoViagem();

    cntrApresentacaoControle->setCntrApresentacaoConta(cntrApresentacaoConta);

    cntrApresentacaoConta->setCntrApresentacaoControle(cntrApresentacaoControle);
    cntrApresentacaoConta->setCntrApresentacaoViagem(cntrApresentacaoViagem);

    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);
    cntrApresentacaoViagem->setCntrApresentacaoConta(cntrApresentacaoConta);
    
    cntrApresentacaoConta->setCntrServicoConta(cntrServicoConta);
    cntrApresentacaoViagem->setCntrServicoViagem(cntrServicoViagem);



    return cntrApresentacaoControle;
}
 
Builder::~Builder(){
    delete cntrApresentacaoControle;
    delete cntrApresentacaoConta;
    delete cntrApresentacaoViagem;

    delete cntrServicoConta;
    delete cntrServicoViagem;
}