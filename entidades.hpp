#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include "dominios.hpp"

using namespace std;

class Conta {
    private:
        Codigo codigo;
        Senha senha;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setSenha(const Senha&);
        Senha getSenha() const; 
};

class Viagem {
    private:
        Codigo codigo;
        Avaliacao avaliacao;
        Nome nome;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setAvaliacao(const Avaliacao&);
        Avaliacao getAvaliacao() const;
        void setNome(const Nome&);
        Nome getNome() const;
};

class Hospedagem {
    private:
        Codigo codigo;
        Avaliacao avaliacao;
        Nome nome;
        Dinheiro diaria;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setAvaliacao(const Avaliacao&);
        Avaliacao getAvaliacao() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setDiaria(const Dinheiro&);
        Dinheiro getDiaria() const;
};

class Destino {
    private:
        Codigo codigo;
        Nome nome;
        Avaliacao avaliacao;
        Data data_inicio;
        Data data_fim;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setAvaliacao(const Avaliacao&);
        Avaliacao getAvaliacao() const;
        void setDataInicio(const Data&);
        Data getDataInicio() const;
        void setDataFim(const Data&);
        Data getDataFim() const;
};

class Atividade {
    private:
        Codigo codigo;
        Nome nome;
        Data data;
        Horario horario;
        Duracao duracao;
        Dinheiro preco;
        Avaliacao avaliacao;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setAvaliacao(const Avaliacao&);
        Avaliacao getAvaliacao() const;
        void setData(const Data&);
        Data getData() const;
        void setHorario(const Horario&);
        Horario getHorario() const;
        void setDuracao(const Duracao&);
        Duracao getDuracao() const;
        void setPreco(const Dinheiro&);
        Dinheiro getPreco() const;
};

#endif // ENTIDADES_HPP_INCLUDED;
