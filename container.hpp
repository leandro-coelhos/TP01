#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class ContainerConta {
    private:
        map<string, string> contas;
        static ContainerConta *instancia;
        ContainerConta() {};
    public:
        static ContainerConta* getInstancia();
        bool hasConta(string codigo);
        bool createConta(string codigo, string senha);
        int logarConta(string codigo, string senha);
};

class ContainerViagem {
    private:
        map<string, vector<string>> viagens;
        static ContainerViagem *instancia;
        ContainerViagem() {};
    public:
        static ContainerViagem* getInstancia();
        bool hasViagem(string codigo);
        bool createViagem(string codigo, string nome, string avaliacao, string codigoConta);
        void listarViagens(string codigoConta);
        string getConta(string codigoViagem);
};

class ContainerDestino {
    private:
        map<string, vector<string>> destinos;
        static ContainerDestino *instancia;
        ContainerDestino() {};
    public:
        static ContainerDestino* getInstancia();
        bool hasDestino(string codigo);
        bool createDestino(string codigo, string nome, string data_inicio, string data_final, string avaliacao, string codigoViagem);
        void listarDestinos(string codigoViagem);
        string getViagem(string codigoDestino);
};

class ContainerHospedagem {
    private:
        map<string, vector<string>> hospedagens;
        static ContainerHospedagem *instancia;
        ContainerHospedagem() {};
    public:
        static ContainerHospedagem* getInstancia();
        bool hasHospedagem(string codigo);
        bool createHospedagem(string codigo, string nome, string diaria, string avaliacao, string codigoDestino);
        void listarHospedagens(string codigoDestino);
};

class ContainerAtividade {
    private:
        map<string, vector<string>> atividades;
        static ContainerAtividade *instancia;
        ContainerAtividade() {};
    public:
        static ContainerAtividade* getInstancia();
        bool hasAtividade(string codigo);
        bool createAtividade(string codigo, string nome, string data, string horario, string duracao, string preco, string avaliacao, string codigoDestino);
        void listarAtividades(string codigoDestino);
};

#endif // CONTAINER_HPP_INCLUDED