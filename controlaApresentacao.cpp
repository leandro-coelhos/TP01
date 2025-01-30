#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "controlaApresentacao.hpp"
#include "utils.cpp"
#include "entidades.hpp"
#include "controleServicos.hpp"

using namespace std;

void CntrApresentacaoCardapio:: menu(){
    limpaTela();
    int opcao;
    cout << "1: Criar conta\n2: Acessar conta\n3: Fechar\n\n";
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        createConta();
    }
    else if(opcao==2){
        accessConta();
    }
    else if(opcao==3){
        exitCardapio();
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        menu();
    }
}

void CntrApresentacaoCardapio:: createConta(){
    limpaTela();
    cout << "Criando conta\n-----------------\n\n";
    string codigo, senha;
    cout << "Digite o codigo: ";
    cin >> codigo;
    limpaBuffer();
    cout << "Digite a senha: ";
    cin >> senha;
    limpaBuffer();
    CntrServicoAutenticacaoConta criaConta;
    if(criaConta.createConta(codigo, senha)){
        cout << "Conta criada\nEspere 3 segundos...\n";
        espera();
        menu();
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        menu();
    }
}

void CntrApresentacaoCardapio:: accessConta(){
    limpaTela();
    cout << "Acessando conta\n-----------------\n\n";
    string codigo, senha;
    cout << "Digite o codigo: ";
    cin >> codigo;
    limpaBuffer();
    cout << "Digite a senha: ";
    cin >> senha;
    limpaBuffer();
    CntrServicoAutenticacaoConta logaConta;
    if(logaConta.loginConta(codigo, senha)){
        cout << "Conta logada com sucesso\n";
        espera();
        //cardapioConta()
    }
    else{
        cout << "Conta nao encontrada\nEspere 3 segundos...\n";
        espera();
        menu();
    }
}

void CntrApresentacaoCardapio:: exitCardapio(){
    cout << "Finalizando a aplicacao\n";
    espera();
    exit(0);
}
