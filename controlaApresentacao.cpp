#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "controlaApresentacao.hpp"
#include "utils.hpp"
#include "entidades.hpp"
#include "controleServicos.hpp"

using namespace std;

void CntrApresentacaoControle::executar(){
    limpaTela();
    int opcao;
    cout << "1: Criar conta\n2: Acessar conta\n3: Fechar\n\n";
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        cntrApresentacaoConta->criarConta();
    }
    else if(opcao==2){
        cntrApresentacaoConta->acessarConta();
    }
    else if(opcao==3){
        exitCardapio();
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        executar();
    }
}

void CntrApresentacaoConta::criarConta(){
    limpaTela();
    cout << "Criando conta\n-----------------\n\n";
    string codigo, senha;
    cout << "Digite o codigo: ";
    cin >> codigo;
    limpaBuffer();
    cout << "Digite a senha: ";
    cin >> senha;
    limpaBuffer();
    if(cntrServicoConta->createConta(codigo, senha)){
        cout << "Conta criada\nEspere 3 segundos...\n";
        espera();
        cntrApresentacaoControle->executar();
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        cntrApresentacaoControle->executar();
    }
}

void CntrApresentacaoConta:: acessarConta(){
    limpaTela();
    cout << "Acessando conta\n-----------------\n\n";
    string codigo, senha;
    cout << "Digite o codigo: ";
    cin >> codigo;
    limpaBuffer();
    cout << "Digite a senha: ";
    cin >> senha;
    limpaBuffer();
    if(cntrServicoConta->logarConta(codigo, senha)){
        cout << "Conta logada com sucesso\n";
        espera();
        //cardapioConta()
    }
    else{
        cout << "Conta nao encontrada\nEspere 3 segundos...\n";
        espera();
        cntrApresentacaoControle->executar();
    }
}

void CntrApresentacaoControle:: exitCardapio(){
    cout << "Finalizando a aplicacao\n";
    espera();
    exit(0);
}
