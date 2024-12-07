#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"

using namespace std;

void inputConta();
Viagem inputViagem();
Hospedagem inputHospedagem();
Destino inputDestino();
Atividade inputAtividade();

Horario inputHorario();
Dinheiro inputDinheiro();
Nome inputNome();
Duracao inputDuracao();
Avaliacao inputAvaliacao();
Data inputData();
Senha inputSenha();
Codigo inputCodigo();

string testeConta();
string testeViagem();
string testeHospedagem();
string testeDestino();
string testeAtividade();

string testeHorario();
string testeDinheiro();
string testeNome();
string testeDuracao();
string testeAvaliacao();
string testeData();
string testeSenha();
string testeCodigo();

void limpabuffer();

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int cardapio;
    int dominios;
    int entidades;
    while(true){
        cout << "1: Entidades\n2: Dominios\n3: Testes\n4: Fechar\n\n";
        cin >> cardapio;
        limpabuffer();
        cout << "\n";
        if(cardapio==1){
            cout << "1: Conta\n2: Viagem\n3: Hospedagem\n4: Destino\n5: Atividade\n6: Fechar\n\n";
            cin >> entidades;
            limpabuffer();
            cout << '\n';
            if(entidades==1) inputConta();
            else if(entidades==2) inputViagem();
            // else if(entidades==3) inputHospedagem();
            // else if(entidades==4) inputDestino();
            // else if(entidades==5) inputAtividade();
            else if(entidades==6) break;
        }
        else if(cardapio==2){
            cout << "\n1: Horario\n2: Dinheiro\n3: Nome\n4: Duracao\n5: Avaliacao" 
            << "\n6: Data\n7: Senha\n8: Codigo\n9: Fechar\n\n";
            cin >> dominios;
            limpabuffer();
            cout << "\n";
            if(dominios==1) inputHorario();
            else if(dominios == 2) inputDinheiro();
            else if(dominios == 3) inputNome();
            else if(dominios == 4) inputDuracao();
            else if(dominios == 5) inputAvaliacao();
            else if(dominios == 6) inputData();
            else if(dominios == 7) inputSenha();
            else if(dominios == 8) inputCodigo();
            else if(dominios == 9){ 
                cout << "Finalizando a aplicacao\n";
                break;
            }
        }
        else if(cardapio==3){
            cout << "-----------------Entidades-----------------\n\n";
            cout << "Conta: "<< testeConta();
            cout << "Viagem: "<< testeViagem();
            cout << "Hospedagem: "<< testeHospedagem();
            cout << "Destino: "<< testeDestino();
            cout << "Atividade: "<< testeAtividade();
            cout << "-----------------Dominios-----------------\n\n";
            cout << "Horario: "<< testeHorario();
            cout << "Dinheiro: "<< testeDinheiro();
            cout << "Nome: "<< testeNome();
            cout << "Duracao: "<< testeDuracao();
            cout << "Avaliacao: "<< testeAvaliacao();
            cout << "Data: "<< testeData();
            cout << "Senha: "<< testeSenha();
            cout << "Codigo: "<< testeCodigo();
        }
        else if(cardapio==4){
            cout << "Finalizando a aplicacao\n";
            break;
        }
    }
    return 0;
}

//-------------------------Entidades-----------------------------------

void inputConta(){
    cout << testeConta();

    Conta conta;
    Codigo codigo = inputCodigo();
    try {
        conta.setCodigo(codigo);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    try{
        conta.setCodigo(codigo);
        cout << "Valor: " << conta.getCodigo().getCodigo() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    cout << "\n";
    Senha senha = inputSenha();

    try {
        conta.setSenha(senha);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    try{
        conta.setSenha(senha);
        cout << "Valor: " << conta.getSenha().getSenha() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
}

Viagem inputViagem(){
    cout << testeViagem();

    Viagem viagem;
    Codigo codigo = inputCodigo();
    try {
        viagem.setCodigo(codigo);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    Viagem *ptrV;
    ptrV = new Viagem();
    try{
        ptrV->setCodigo(codigo);
        cout << "Valor: " << ptrV->getCodigo().getCodigo() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }

    Avaliacao avaliacao = inputAvaliacao();
    try {
        viagem.setAvaliacao(avaliacao);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    try{
        ptrV->setAvaliacao(avaliacao);
        cout << "Valor: " << ptrV->getAvaliacao().getAvaliacao() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }

    Nome nome = inputNome();
    try {
        viagem.setNome(nome);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    try{
        ptrV->setNome(nome);
        cout << "Valor: " << ptrV->getNome().getNome() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }

    delete ptrV;
}



//-------------------------Dominios-----------------------------------

Horario inputHorario(){
    cout << testeHorario();

    Horario horario;
    string hora_valor;
    cout << "Formato: HH:MM\n";
    cout << "Digite o horario: ";
    cin >> hora_valor;
    limpabuffer();
    try {
        horario.setHora(hora_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }


    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Horario *ptrH;
    ptrH = new Horario();

    try{
        ptrH->setHora(hora_valor);
        cout << "Valor: " << ptrH->getHora() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrH;
}

Dinheiro inputDinheiro(){
    cout << testeDinheiro();

    Dinheiro dinheiro;
    string dinheiro_valor;
    cout << "Formato: 1.000,00, de 0 ate 200.000,00\n";
    cout << "Digite o dinheiro: ";
    cin >> dinheiro_valor;
    limpabuffer();
    try {
        dinheiro.setDinheiro(dinheiro_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }


    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Dinheiro *ptrD;
    ptrD = new Dinheiro();

    try{
        ptrD->setDinheiro(dinheiro_valor);
        cout << "Valor: " << ptrD->getDinheiroView() 
        << "\nValor computacional: " << fixed << setprecision(2) << ptrD->getDinheiro() <<"\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrD;
}

Nome inputNome(){
    cout << testeNome();

    Nome nome;
    string nome_valor;
    cout << "Formato: ate 30 caracteres\n";
    cout << "Digite o nome: ";
    cin >> nome_valor;
    limpabuffer();    
    try {
        nome.setNome(nome_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Nome *ptrN;
    ptrN = new Nome();

    try{
        ptrN->setNome(nome_valor);
        cout << "Valor: " << ptrN->getNome() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }

    delete ptrN;
}

Avaliacao inputAvaliacao(){
    cout << testeAvaliacao();

    Avaliacao avaliacao;
    string avaliacao_valor;
    cout << "Formato 0 ate 5\n";
    cout << "Digite a avaliacao: ";
    cin >> avaliacao_valor;
    limpabuffer();
    try {
        avaliacao.setAvaliacao(avaliacao_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Avaliacao *ptrA;
    ptrA = new Avaliacao();

    try{
        ptrA->setAvaliacao(avaliacao_valor);
        cout << "Valor: " << ptrA->getAvaliacao() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrA;
}

Duracao inputDuracao(){
    testeDuracao();

    Duracao duracao;
    string duracao_valor;
    cout << "Formato: 0 ate 360\n";
    cout << "Digite a duracao: ";
    cin >> duracao_valor;
    limpabuffer();
    try {
        duracao.setDuracao(duracao_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Duracao *ptrDur;
    ptrDur = new Duracao();

    try{
        ptrDur->setDuracao(duracao_valor);
        cout << "Valor: " << ptrDur->getDuracao() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrDur;

}

Data inputData(){
    testeData();

    Data data;
    string data_valor;
    cout << "Formato: DD-MM-AA, sendo AA de 00-99\n";
    cout << "Digite a data: ";
    cin >> data_valor;
    limpabuffer();
    try {
        data.setData(data_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Data *ptrData;
    ptrData = new Data();

    try{
        ptrData->setData(data_valor);
        cout << "Valor: " << ptrData->getData() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrData;
}

Senha inputSenha(){
    testeSenha();

    Senha senha;
    string senha_valor;
    cout << "Formato: 5 numeros desordenados e nao duplicados\n";
    cout << "Digite a senha: ";
    cin >> senha_valor;
    limpabuffer();
    try {
        senha.setSenha(senha_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Senha *ptrS;
    ptrS = new Senha();

    try{
        ptrS->setSenha(senha_valor);
        cout << "Valor: " << ptrS->getSenha() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrS;
}

Codigo inputCodigo(){
    testeCodigo();

    Codigo codigo;
    string codigo_valor;
    cout << "Formato: 6 caracteres, de a-z, A-Z, 0-9\n";
    cout << "Digite o codigo: ";
    cin >> codigo_valor;
    limpabuffer();
    try {
        codigo.setCodigo(codigo_valor);
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Codigo *ptrC;
    ptrC = new Codigo();
    try{
        ptrC->setCodigo(codigo_valor);
        cout << "Valor: " << ptrC->getCodigo() << "\n\n";
    }
    catch(invalid_argument &exp){
        cout << "Valor invalido \n\n";
    }
    delete ptrC;
}

//-------------------------TestesEntidades-----------------------------------

string testeConta(){
    TUConta testeConta;

    switch(testeConta.run())
    {
    case TUConta::SUCESSO: return "SUCESSO\n\n";
        break;
    
    case TUConta::FALHA: return "FALHA\n\n";
        break;
    }
    
}

string testeViagem(){
    TUViagem testeViagem;

    switch(testeViagem.run()){
        case TUViagem::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUViagem::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeHospedagem(){
    TUHospedagem testeHospedagem;

    switch(testeHospedagem.run()){
        case TUHospedagem::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUHospedagem::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeDestino(){
    TUDestino testeDestino;

    switch(testeDestino.run()){
        case TUDestino::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUDestino::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeAtividade(){
    TUAtividade testeAtividade;

    switch(testeAtividade.run()){
        case TUAtividade::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUAtividade::FALHA: return "FALHA\n\n";
        break;
    }
}

//-------------------------TestesDominio-----------------------------------
string testeHorario(){
    TUHorario testeHorario;

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUHorario::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeDinheiro(){
    TUDinheiro testedinheiro;

    switch(testedinheiro.run()){
        case TUDinheiro::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUDinheiro::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeNome(){
    TUNome testenome;

    switch(testenome.run()){
        case TUNome::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUNome::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeAvaliacao(){
    TUAvaliacao testeavalicao;

    switch (testeavalicao.run()){
    case TUAvaliacao::SUCESSO: return "SUCESSO\n\n";
        break;
    case TUAvaliacao::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeDuracao(){
    TUDuracao testeduracao;

    switch(testeduracao.run()){
        case TUDuracao::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUDuracao::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeData(){
    TUData testedata;

    switch(testedata.run()){
        case TUData::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUData::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeSenha(){
    TUSenha testesenha;

    switch(testesenha.run()){
        case TUSenha::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUSenha::FALHA: return "FALHA\n\n";
        break;
    }
}

string testeCodigo(){
    TUCodigo testecodigo;

    switch(testecodigo.run()){
        case TUCodigo::SUCESSO: return "SUCESSO\n\n";
        break;
        case TUCodigo::FALHA: return "FALHA\n\n";
        break;
    }
}

void limpabuffer(){
    if(cin.fail()) {
    cout << "Erro de entrada. Tente novamente.\n";
    cin.clear(); // Limpa o estado de erro do cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar a entrada inválida
}
}