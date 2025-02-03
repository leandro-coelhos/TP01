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
 * @brief Executa o menu principal do sistema.
 *
 * Este método exibe o menu principal e redireciona o usuário para as funcionalidades
 * correspondentes, como criar conta, acessar conta ou fechar o sistema.
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

/**
 * @brief Cria uma nova conta no sistema.
 *
 * Este método solicita ao usuário o código e a senha da nova conta e tenta criá-la
 * utilizando o serviço de conta.
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

/**
 * @brief Permite o acesso a uma conta existente.
 *
 * Este método solicita ao usuário o código e a senha da conta e tenta realizar o login
 * utilizando o serviço de conta.
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

/**
 * @brief Finaliza a aplicação.
 *
 * Este método exibe uma mensagem de encerramento e fecha o programa.
 */
void CntrApresentacaoControle:: exitCardapio(){
    cout << "Finalizando a aplicacao\n";
    espera();
    exit(0);
}

/**
 * @brief Exibe o menu de viagens associadas a uma conta.
 *
 * @param codigo O código da conta logada.
 */
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
        cntrApresentacaoControle->executar();
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        viagensConta(codigo);
    }
}

/**
 * @brief Executa o menu de viagens.
 *
 * @param codigo O código da conta logada.
 */
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

/**
 * @brief Cria uma nova viagem.
 *
 * @param codigo O código da conta logada.
 */
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

/**
 * @brief Lista as viagens associadas a uma conta.
 *
 * @param codigo O código da conta logada.
 */
void CntrApresentacaoViagem::listarViagens(string codigo){
    limpaTela();
    cout << "Listando viagens\n-----------------\n\n";
    cntrServicoViagem->listarViagens(codigo);
    cout << "1: Acessar viagem(Ex:1 - <codigo da viagem>)\n2: Voltar\n\n";
    int opcao;
    string codigo_;
    cin >> opcao;
    limpaBuffer();
    if(opcao==1){
        cin >> codigo_;
        limpaBuffer();
        cntrApresentacaoDestino->executar(codigo_);
    }
    else if(opcao==2){
        executar(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        executar(codigo);
    }
    executar(codigo);
}

/**
 * @brief Executa o menu de destinos.
 *
 * @param codigo O código da viagem selecionada.
 */
void CntrApresentacaoDestino::executar(string codigo){
    limpaTela();
    int opcao;
    cout << "1: Criar destino\n2: Listar destinos\n3: Voltar\n\n";
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        criarDestino(codigo);
    }
    else if(opcao==2){
        listarDestinos(codigo);
    }
    else if(opcao==3){
        cout << "Voltando para o menu\n";
        espera();
        codigo = cntrServicoDestino->getConta(codigo);
        cntrApresentacaoViagem->executar(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        executar(codigo);
    }
}

/**
 * @brief Cria um novo destino.
 *
 * @param codigo O código da viagem associada ao destino.
 */
void CntrApresentacaoDestino::criarDestino(string codigo){
    limpaTela();
    cout << "Criando destino\n-----------------\n\n";
    string codigo_, nome, data_inicio, data_final, avaliacao;
    cout << "Digite o codigo: ";
    cin >> codigo_;
    limpaBuffer();
    cout << "Digite a nome: ";
    cin >> nome;
    limpaBuffer();
    cout << "Digite a data de inicio: ";
    cin >> data_inicio;
    limpaBuffer();
    cout << "Digite a data de termino: ";
    cin >> data_final;
    limpaBuffer();
    cout << "Digite a avaliacao: ";
    cin >> avaliacao;
    limpaBuffer();
    if(cntrServicoDestino->createDestino(codigo_, nome, data_inicio, data_final, avaliacao ,codigo)){
        cout << "\nDestino criado\nEspere 3 segundos...\n";
        espera();
        executar(codigo);
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        executar(codigo);
    }
}

/**
 * @brief Lista os destinos associados a uma viagem.
 *
 * @param codigo O código da viagem selecionada.
 */
void CntrApresentacaoDestino::listarDestinos(string codigo){
    limpaTela();
    cntrServicoDestino->listarDestinos(codigo);
    cout << "1: Acessar destino(Ex:1 - <codigo do destino>)\n2: Voltar\n\n";
    int opcao;
    string codigo_;
    cin >> opcao;
    limpaBuffer();
    if(opcao==1){
        cin >> codigo_;
        limpaBuffer();
        showDestino(codigo_);
    }
    else if(opcao==2){
        executar(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        executar(codigo);
    }
    executar(codigo);
}

/**
 * @brief Exibe o menu de detalhes de um destino.
 *
 * @param codigo O código do destino selecionado.
 */
void CntrApresentacaoDestino::showDestino(string codigo){
    limpaTela();
    cout << "Mostrando destino\n-----------------\n\n";
    cout << "1: Criar Hospedagens\n2: Listar Hospedagens\n3: Criar Atividades\n4: Listar Atividades\n5: Voltar\n\n";
    int opcao;
    cin >> opcao;
    limpaBuffer();
    cout << "\n";
    if(opcao==1){
        cntrApresentacaoHospedagem->criarHospedagem(codigo);
    }
    else if(opcao==2){
        cntrApresentacaoHospedagem->listarHospedagens(codigo);
    }
    else if(opcao==3){
        cntrApresentacaoAtividade->criarAtividade(codigo);
    }
    else if(opcao==4){
        cntrApresentacaoAtividade->listarAtividades(codigo);
    }
    else if(opcao==5){
        codigo = cntrServicoDestino->getViagem(codigo);
        codigo = cntrServicoDestino->getConta(codigo);
        cntrApresentacaoViagem->executar(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        showDestino(codigo);
    }
}

/**
 * @brief Cria uma nova hospedagem.
 *
 * @param codigo O código do destino associado à hospedagem.
 */
void CntrApresentacaoHospedagem::criarHospedagem(string codigo){
    limpaTela();
    cout << "Criando hospedagem\n-----------------\n\n";
    string codigo_, nome, diaria, data_final, avaliacao;
    cout << "Digite o codigo: ";
    cin >> codigo_;
    limpaBuffer();
    cout << "Digite a nome: ";
    cin >> nome;
    limpaBuffer();
    cout << "Digite a diaria: ";
    cin >> diaria;
    limpaBuffer();
    cout << "Digite a avaliacao: ";
    cin >> avaliacao;
    limpaBuffer();
    if(cntrServicoHospedagem->createHospedagem(codigo_, nome, diaria, avaliacao, codigo)){
        cout << "\nHospedagem criada\nEspere 3 segundos...\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
}

/**
 * @brief Lista as hospedagens associadas a um destino.
 *
 * @param codigo O código do destino selecionado.
 */
void CntrApresentacaoHospedagem::listarHospedagens(string codigo){
    limpaTela();
    cout << "Listando hospedagens\n-----------------\n\n";
    cntrServicoHospedagem->listarHospedagens(codigo);
    cout << "1: Voltar\n\n";
    int opcao;
    cin >> opcao;
    limpaBuffer();
    if(opcao==1){
        cntrApresentacaoDestino->showDestino(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
    cntrApresentacaoDestino->showDestino(codigo);
}

/**
 * @brief Cria uma nova atividade.
 *
 * @param codigo O código do destino associado à atividade.
 */
void CntrApresentacaoAtividade::criarAtividade(string codigo){
    limpaTela();
    cout << "Criando atividade\n-----------------\n\n";
    string codigo_, nome, data, horario, duracao, preco, avaliacao;
    cout << "Digite o codigo: ";
    cin >> codigo_;
    limpaBuffer();
    cout << "Digite a nome: ";
    cin >> nome;
    limpaBuffer();
    cout << "Digite a data: ";
    cin >> data;
    limpaBuffer();
    cout << "Digite o horario: ";
    cin >> horario;
    limpaBuffer();
    cout << "Digite a duracao: ";
    cin >> duracao;
    limpaBuffer();
    cout << "Digite o preco: ";
    cin >> preco;
    limpaBuffer();
    cout << "Digite a avaliacao: ";
    cin >> avaliacao;
    limpaBuffer();
    if(cntrServicoAtividade->createAtividade(codigo_, nome, data, horario, duracao, preco, avaliacao, codigo)){
        cout << "\nAtividade criada\nEspere 3 segundos...\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
    else {
        cout << "Voltando para o menu\nEspere 3 segundos..\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
}

/**
 * @brief Lista as atividades associadas a um destino.
 *
 * @param codigo O código do destino selecionado.
 */
void CntrApresentacaoAtividade::listarAtividades(string codigo){
    limpaTela();
    cout << "Listando atividades\n-----------------\n\n";
    cntrServicoAtividade->listarAtividades(codigo);
    cout << "1: Voltar\n\n";
    int opcao;
    cin >> opcao;
    limpaBuffer();
    if(opcao==1){
        cntrApresentacaoDestino->showDestino(codigo);
    }
    else{
        cout << "Opcao invalida\nEspere 3 segundos para voltar ao menu\n";
        espera();
        cntrApresentacaoDestino->showDestino(codigo);
    }
    cntrApresentacaoDestino->showDestino(codigo);
}
