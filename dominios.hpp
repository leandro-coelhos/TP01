#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Horario { //Leandro Coelho da Silva, MAT:232011396
    private:
        unsigned short hora;
        unsigned short minuto;
        void validateHora(unsigned short h, unsigned short m);

    public:
        void setHora(string h);
        string getHora() const;

};

class Dinheiro { //Leandro Coelho da Silva, MAT:232011396
    private:
        float dinheiro; //dinheiro em centavos (CALCULOS INTERNOS SERAO FEITOS TODOS EM CENTAVOS usando esse atributo)
        string dinheiroView; //dinheiro em "R$reais,centavos" (A EXIBICAO DO DINHEIRO SERA COMO USUAL)
        void validateDinheiro(string dinheiro);

    public:
        void setDinheiro(string dinheiro);//recebe o input do usuario na formatacao "R$reais,centavos" e converte para centavos
        double getDinheiro() const; //retorna o dinheiro em reais (Valor visual)
        string getDinheiroView() const;
};

class Nome { //Lucas Santana Camilo Alves, MAT:211060666
    private:
        string nome;
        void validateNome(string nome);

    public:
        void setNome(string nome);
        string getNome() const;
};

class Duracao { //Leandro Coelho da Silva, MAT:232011396
     private:
          int duracao;
          void validateDuracao(int duracao);
     public:
          void setDuracao(string duracao);
          string getDuracao() const;
};

class Avaliacao { //Leandro Coelho da Silva, MAT:232011396
    private:
        int avaliacao;
        void validateAvaliacao(int avaliacao);
    public:
        bool setAvaliacao(string avaliacao);
        string getAvaliacao() const;
};

class Data { //Leandro Coelho da Silva, MAT:232011396
    private:
        unsigned short dia;
        unsigned short mes;
        unsigned short ano;
        void validateData(unsigned short d, unsigned short m, unsigned short a);
    public:
        void setData(string data);
        string getData() const;
};

class Senha { //Leandro Coelho da Silva, MAT:232011396
    private:
        string senha;
        void validateSenha(string senha);
    public:
        void setSenha(string senha);
        string getSenha() const;
};

class Codigo { //Lucas Santana Camilo Alves, MAT:211060666
    private:
        string codigo;
        void validateCodigo(string codigo);
    public:
        void setCodigo(string codigo);
        string getCodigo() const;
};

#endif // DOMINIOS_HPP_INCLUDED
