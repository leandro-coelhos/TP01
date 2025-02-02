#include "interfaces.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"

class Builder {
     private:
          CntrApresentacaoControle *cntrApresentacaoControle;
          IApresentacaoConta *cntrApresentacaoConta;
          IApresentacaoViagem *cntrApresentacaoViagem;
          IApresentacaoDestino *cntrApresentacaoDestino;
          IApresentacaoHospedagem *cntrApresentacaoHospedagem;
          IApresentacaoAtividade *cntrApresentacaoAtividade;
          
          IServicoConta *cntrServicoConta;
          IServicoViagem *cntrServicoViagem;
          IServicoDestino *cntrServicoDestino;
          IServicoHospedagem *cntrServicoHospedagem;
          IServicoAtividade *cntrServicoAtividade;
     public:
          CntrApresentacaoControle* construir();
          ~Builder();
};