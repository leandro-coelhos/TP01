/**
 * @file controlaApresentacao.cpp
 * @brief Implementação das classes de controle de apresentação.
 */

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "controlaApresentacao.hpp"
#include "utils.hpp"
#include "entidades.hpp"
#include "controleServicos.hpp"

using namespace std;

/**
 * @class CntrApresentacaoControle
 * @brief Classe responsável por controlar o fluxo principal da aplicação.
 * 
 * Gerencia o menu inicial e direciona para as funcionalidades de criação e acesso à conta.
 */

/**
 * @brief Executa o menu principal da aplicação.
 * 
 * Apresenta as opções para criar conta, acessar conta ou fechar o programa.
 * Chama os métodos correspondentes conforme a escolha do usuário.
 */
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

/**
 * @class CntrApresentacaoConta
 * @brief Classe responsável por controlar a apresentação relacionada a contas de usuário.
 * 
 * Gerencia a interface para criação e acesso de contas.
 */

/**
 * @brief Cria uma nova conta de usuário.
 * 
 * Solicita código e senha ao usuário e utiliza o serviço de conta para realizar o cadastro.
 */
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

/**
 * @brief Realiza o acesso a uma conta existente.
 * 
 * Solicita código e senha ao usuário e utiliza o serviço de conta para validar o login.
 */
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

/**
 * @brief Finaliza a execução da aplicação.
 * 
 * Exibe mensagem de encerramento e termina o programa após uma breve espera.
 */
void CntrApresentacaoControle::exitCardapio(){
    cout << "Finalizando a aplicacao\n";
    espera();
    exit(0);
}