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
        cout << "Acessando conta\n";
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
        cout << "\nConta criada\nEspere 3 segundos...\n";
        espera();
        cntrApresentacaoControle->executar();
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        cntrApresentacaoControle->executar();
    }
}

void CntrApresentacaoConta::acessarConta(){
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
        cout << "\nConta logada com sucesso\n";
        espera();
        viagensConta(codigo);
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

void CntrApresentacaoConta::viagensConta(string codigo){
    limpaTela();
    int opcao;
    cout << "1: Viagens\n2: Fechar\n\n";
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        cout << "Acessando viagens\n";
        cntrApresentacaoViagem->executar(codigo);   
    }
    else if(opcao==2){
        cout << "Voltando para o menu\n";
        espera();
        exit(0);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        viagensConta(codigo);
    }
}

void CntrApresentacaoViagem::executar(string codigo){
    limpaTela();
    int opcao;
    cout << "1: Criar viagem\n2: Listar viagens\n3: Voltar\n\n";
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        criarViagem(codigo);
    }
    else if(opcao==2){
        listarViagens(codigo);
    }
    else if(opcao==3){
        cout << "Voltando para o menu\n";
        espera();
        cntrApresentacaoConta->viagensConta(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        executar(codigo);
    }
}

void CntrApresentacaoViagem::criarViagem(string codigo){
    limpaTela();
    cout << "Criando viagem\n-----------------\n\n";
    string codigo_, nome, avaliacao;
    cout << "Digite o codigo: ";
    cin >> codigo_;
    limpaBuffer();
    cout << "Digite a nome: ";
    cin >> nome;
    limpaBuffer();
    cout << "Digite o avaliacao: ";
    cin >> avaliacao;
    limpaBuffer();
    if(cntrServicoViagem->createViagem(codigo_, nome, avaliacao, codigo)){
        cout << "\nViagem criada\nEspere 3 segundos...\n";
        espera();
        executar(codigo);
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        executar(codigo);
    }
}

void CntrApresentacaoViagem::listarViagens(string codigo){
    limpaTela();
    cout << "Listando viagens\n-----------------\n\n";
    cntrServicoViagem->listarViagens(codigo);
    cout << "Espere 3 segundos...\n";
    espera();
    executar(codigo);
}

