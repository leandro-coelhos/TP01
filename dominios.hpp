#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Horario {
    private:
        unsigned short hora;
        unsigned short minuto;
        void validateHora(unsigned short h, unsigned short m);

    public:
        void setHora(string h);
        string getHora() const;

};

class Dinheiro {
    private:
        float dinheiro; //dinheiro em centavos (CALCULOS INTERNOS SERAO FEITOS TODOS EM CENTAVOS usando esse atributo)
        string dinheiroView; //dinheiro em "R$reais,centavos" (A EXIBICAO DO DINHEIRO SERA COMO USUAL)
        void validateDinheiro(string dinheiro);

    public:
        void setDinheiro(string dinheiro);//recebe o input do usuario na formatacao "R$reais,centavos" e converte para centavos
        double getDinheiro() const; //retorna o dinheiro em reais (Valor visual)
        string getDinheiroView() const;
};

class Nome {
    private:
        string nome;
        void validateNome(string nome);

    public:
        void setNome(string nome);
        string getNome() const;
};

class Duracao {
     private:
          int duracao;
          void validateDuracao(int duracao);
     public:
          void setDuracao(string duracao);
          string getDuracao() const;
};

class Avaliacao {
    private:
        int avaliacao;
        void validateAvaliacao(int avaliacao);
    public:
        bool setAvaliacao(string avaliacao);
        string getAvaliacao() const;
};

class Data {
    private:
        unsigned short dia;
        unsigned short mes;
        unsigned short ano;
        void validateData(unsigned short d, unsigned short m, unsigned short a);
    public:
        void setData(string data);
        string getData() const;
};

class Senha {
    private:
        string senha;
        void validateSenha(string senha);
    public:
        //Senha() = default;
        void setSenha(string senha);
        string getSenha() const;
        // Senha(const string& senha){
        //     try {
        //         setSenha(senha);
        //     }
        //     catch(invalid_argument &exp){
        //         throw invalid_argument("Argumento invalido");
        //     }
        // }
};

class Codigo {
    private:
        string codigo;
        void validateCodigo(string codigo);
    public:
        void setCodigo(string codigo);
        string getCodigo() const;
};

#endif // DOMINIOS_HPP_INCLUDED
