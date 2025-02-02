#include "interfaces.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"

class Builder {
     private:
          CntrApresentacaoControle *cntrApresentacaoControle;
          IApresentacaoConta *cntrApresentacaoConta;
          IApresentacaoViagem *cntrApresentacaoViagem;
          
          IServicoConta *cntrServicoConta;
          IServicoViagem *cntrServicoViagem;
     public:
          CntrApresentacaoControle* construir();
          ~Builder();
};