#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class ContainerConta{
     private:
          map<int, vector<string>> contas;
          static ContainerConta *instancia;
          ContainerConta(){};
     public:
          static ContainerConta* getInstancia();
          bool hasConta(string codigo, string senha);
          bool createConta(string codigo, string senha);
          bool hasContaLogin(string codigo, string senha);
          int logarConta(string codigo, string senha);
};

#endif // CONTAINER_HPP_INCLUDED