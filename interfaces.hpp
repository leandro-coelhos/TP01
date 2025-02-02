#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

class IServicoConta;
class IServicoViagem;

class IApresentacaoViagem;
class IApresentacaoConta;

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
          virtual ~IApresentacaoViagem(){};
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

#endif // INTERFACES_H_INCLUDED