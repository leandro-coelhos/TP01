#include "interfaces.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"

class Builder {
     private:
          CntrApresentacaoControle *cntrApresentacaoControle;
          IApresentacaoConta *cntrApresentacaoConta;
          IServicoConta *cntrServicoConta;
     public:
          CntrApresentacaoControle* construir();
          ~Builder();
};