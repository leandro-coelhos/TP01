#include <bits/stdc++.h>
#include "container.hpp"
#include "entidades.hpp"

using namespace std;

ContainerConta* ContainerConta::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerConta();
     }
     return instancia;
}

bool ContainerConta::hasConta(string codigo, string senha){
    for(int i = 0; i < contas.size(); i++){
        if(contas[i][0] == codigo){
            return true;
        }
    return false;
}
}

bool ContainerConta::createConta(string codigo, string senha){
    if(hasConta(codigo, senha)){
        return false;
    }
    Conta* conta = new Conta();
    try{
        Codigo codigo_;
        Senha senha_;
        codigo_.setCodigo(codigo);
        senha_.setSenha(senha);
        conta->setCodigo(codigo_);
        conta->setSenha(senha_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        return false;
    }

    contas[contas.size()] = {codigo, senha};

    delete conta;

    return true;
}

bool ContainerConta::hasContaLogin(string codigo, string senha){
    for(int i = 0; i < contas.size(); i++){
        if(contas[i][0] == codigo && contas[i][1] == senha){
            return true;
        }
    return false;
    }
}

int ContainerConta::logarConta(string codigo, string senha){
    if(hasConta(codigo, senha)){
        int codigo_ = stoi(codigo);
        return codigo_;
    }
    else {
        cout << "As credenciais da conta estão incorretas\n";
    }
    return 0;
}

