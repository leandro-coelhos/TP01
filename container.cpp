#include <bits/stdc++.h>
#include "container.hpp"
#include "entidades.hpp"

using namespace std;

ContainerConta* ContainerConta::instancia = nullptr;
ContainerViagem* ContainerViagem::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerConta();
     }
     return instancia;
}

bool ContainerConta::hasConta(string codigo){
    return contas.find(codigo) != contas.end();
}

bool ContainerConta::createConta(string codigo, string senha){
    if(hasConta(codigo)){
        cout << "\nConta ja existe\n\n";
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
        delete conta;
        return false;
    }

    contas[codigo] = senha;

    delete conta;

    return true;
}

int ContainerConta::logarConta(string codigo, string senha){
    if(hasConta(codigo) && contas[codigo] == senha){
        return stoi(codigo);
    }
    else {
        cout << "As credenciais da conta estão incorretas\n";
        return 0;
    }
}

ContainerViagem* ContainerViagem::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerViagem();
     }
     return instancia;
}

bool ContainerViagem::hasViagem(string codigo){
    return viagens.find(codigo) != viagens.end();
}

bool ContainerViagem::createViagem(string codigo, string nome, string avaliacao, string codigoConta){
    if(hasViagem(codigo)){
        cout << "\nViagem ja existe\n\n";
        return false;
    }
    Viagem* viagem = new Viagem();
    try{
        Codigo codigo_;
        Nome nome_;
        Avaliacao avaliacao_;
        codigo_.setCodigo(codigo);
        nome_.setNome(nome);
        avaliacao_.setAvaliacao(avaliacao);
        viagem->setCodigo(codigo_);
        viagem->setNome(nome_);
        viagem->setAvaliacao(avaliacao_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete viagem;
        return false;
    }

    viagens[codigo] = {nome, avaliacao, codigoConta};

    delete viagem;

    return true;
}   

void ContainerViagem::listarViagens(string codigoConta){
    cout << '\n';

    for(const auto& viagem: viagens){
        if(viagem.second[2] == codigoConta){
            cout << "Codigo: " << viagem.second[2] << '\n';
            cout << "Nome: " << viagem.second[0] << '\n';
            cout << "Avaliacao: " << viagem.second[1] << '\n';
            cout << '\n';
        }
    }
}