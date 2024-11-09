#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Horario {
    private:
        unsigned short hora;
        unsigned short minuto;
        bool validateHora(unsigned short h, unsigned short m);
    
    public:
        bool setHora(string h);
        string getHora() const;
        
};

class Dinheiro {
    private:
        float dinheiro;
        string dinheiroView;
        bool validateDinheiro(string dinheiro);

    public:
        bool setDinheiro(string dinheiro);
        float getDinheiro() const;
        string getDinheiroView() const;
};

class Nome {
    private:
        string nome;  
        bool validateNome(string nome); 

    public:
        bool setName(string nome);  
        string getName() const;   
};

class Duracao {
     private:
          int duracao;
          bool validateDuracao(int duracao);
     public:
          bool setDuracao(int duracao);
          string getDuracao() const;
};

class Avaliacao {
    private: 
        int avaliacao;
        bool validateAvaliacao(int avaliacao);
    public:
        bool setAvaliacao(int avaliacao);
        string getAvaliacao() const;
};

class Data {
    private:
        unsigned short dia;
        unsigned short mes;
        unsigned short ano;
        bool validateData(unsigned short d, unsigned short m, unsigned short a);
    public:
        bool setData(string data);
        string getData() const; 
};

class Senha {
    private:
        string senha;
        bool validateSenha(string senha);
    public:
        bool setSenha(string senha);
        string getSenha() const;
};

class Codigo {
    private:
        string codigo;
        bool validateCodigo(string codigo);
    public:
        bool setCodigo(string codigo);
        string getCodigo() const;
};

#endif // DOMINIOS_HPP_INCLUDED