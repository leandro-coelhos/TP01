#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

class IServicoConta;
class IServicoViagem;
class IServicoDestino;
class IServicoHospedagem;
class IServicoAtividade;

class IApresentacaoViagem;
class IApresentacaoConta;
class IApresentacaoDestino;
class IApresentacaoHospedagem;
class IApresentacaoAtividade;

class CntrApresentacaoControle;
class CntrApresentacaoConta;

class IApresentacaoConta {
     public:
          virtual void criarConta() = 0;
          virtual void acessarConta() = 0;
          virtual void viagensConta(string codigo) = 0;
          virtual void setCntrServicoConta(IServicoConta*) = 0;
          virtual void setCntrApresentacaoControle(CntrApresentacaoControle*) = 0;
          virtual void setCntrApresentacaoViagem(IApresentacaoViagem*) = 0;
          virtual ~IApresentacaoConta(){};
};

class IApresentacaoViagem {
     public:
          virtual void executar(string codigo) = 0;
          virtual void criarViagem(string codigo) = 0;
          virtual void listarViagens(string codigo) = 0;
          virtual void setCntrServicoViagem(IServicoViagem*) = 0;
          virtual void setCntrApresentacaoConta(IApresentacaoConta*) = 0;
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0;
          virtual ~IApresentacaoViagem(){};
};

class IApresentacaoDestino {
     public:
          virtual void executar(string codigo) = 0;
          virtual void criarDestino(string codigo) = 0;
          virtual void listarDestinos(string codigo) = 0;
          virtual void showDestino(string codigo) = 0;
          virtual void setCntrServicoDestino(IServicoDestino*) = 0;
          virtual void setCntrApresentacaoViagem(IApresentacaoViagem*) = 0;
          virtual void setCntrApresentacaoHospedagem(IApresentacaoHospedagem*) = 0;
          virtual void setCntrApresentacaoAtividade(IApresentacaoAtividade*) = 0;
          virtual void setCntrServicoViagem(IServicoViagem*) = 0;
          virtual ~IApresentacaoDestino(){};
};

class IApresentacaoHospedagem {
     public:
          virtual void criarHospedagem(string codigo) = 0;
          virtual void listarHospedagens(string codigo) = 0;
          virtual void setCntrServicoHospedagem(IServicoHospedagem*) = 0;
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0;
          virtual ~IApresentacaoHospedagem(){};
};

class IApresentacaoAtividade {
     public:
          virtual void criarAtividade(string codigo) = 0;
          virtual void listarAtividades(string codigo) = 0;
          virtual void setCntrServicoAtividade(IServicoAtividade*) = 0;
          virtual void setCntrApresentacaoDestino(IApresentacaoDestino*) = 0;
          virtual ~IApresentacaoAtividade(){};
};

//--------------------------------------------

class IServicoConta {
     public:
          virtual bool createConta(string, string) = 0;
          virtual int logarConta(string, string) = 0;
          virtual ~IServicoConta(){};
};

class IServicoViagem {
     public:
          virtual bool createViagem(string, string, string, string) = 0;
          virtual void listarViagens(string) = 0;
          virtual ~IServicoViagem(){};
};

class IServicoDestino {
     public:
          virtual bool createDestino(string, string, string, string, string, string) = 0;
          virtual void listarDestinos(string) = 0;
          virtual string getConta(string) = 0;
          virtual string getViagem(string) = 0;
          virtual ~IServicoDestino(){};
};

class IServicoHospedagem {
     public:
          virtual bool createHospedagem(string, string, string, string, string) = 0;
          virtual void listarHospedagens(string) = 0;
          virtual ~IServicoHospedagem(){};
};

class IServicoAtividade {
     public:
          virtual bool createAtividade(string, string, string, string, string, string, string, string) = 0;
          virtual void listarAtividades(string) = 0;
          virtual ~IServicoAtividade(){};
};

#endif // INTERFACES_H_INCLUDED