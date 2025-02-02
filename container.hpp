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
};

#endif // CONTAINER_HPP_INCLUDED