#include "builder.hpp"
#include "controlaApresentacao.hpp"

CntrApresentacaoControle* Builder::construir(){
    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoConta = new CntrApresentacaoConta();
    cntrServicoConta = new CntrServicoAutenticacaoConta();
    
    return cntrApresentacaoControle;
}

Builder::~Builder(){
    delete cntrApresentacaoControle;
    delete cntrApresentacaoConta;
    delete cntrServicoConta;
}