#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

class IServicoAutenticacao;
class IServicoConta;
class IServicoViagem;

class IApresentacaoConta {
     public:
          virtual void criarConta() = 0;
          virtual void acessarConta() = 0;
          virtual void setCntrServicoConta(IServicoConta*) = 0;
          virtual ~IApresentacaoConta(){};
};

class IApresentacaoViagem {
     public:
          virtual void executar() = 0;
          virtual void setServico(IServicoViagem*) = 0;
          virtual ~IApresentacaoViagem(){};
};

//--------------------------------------------

class IServicoConta {
     public:
          virtual bool createConta(string, string) = 0;
          virtual int logarConta(string, string) = 0;
          virtual ~IServicoConta(){};
};

#endif // INTERFACES_H_INCLUDED