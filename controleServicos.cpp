#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "utils.cpp"
#include "entidades.hpp"
#include "controleServicos.hpp"
#include "data.cpp"

using namespace std;

bool CntrServicoAutenticacaoCriarConta::hasConta(string codigo, string senha){
    for(int i = 0; i < contas.size(); i++){
        if(contas["id"] == codigo){
            return true;
        }
    return false;
}
}

bool CntrServicoAutenticacaoCriarConta::createConta(string codigo, string senha){
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

    contas["id"] = codigo;
    contas["senha"] = senha;

    delete conta;

    return true;
}

bool CntrServicoAutenticacaoLogarConta::hasConta(string codigo, string senha){
    for(int i = 0; i < contas.size(); i++){
        if(contas["id"] == codigo && contas["senha"] == senha){
            return true;
        }
    return false;
    }
}

int CntrServicoAutenticacaoLogarConta::logarConta(string codigo, string senha){
    if(hasConta(codigo, senha)){
        int codigo_ = stoi(codigo);
        return codigo_;
    }
    return 0;
}