#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"
#include "utils.hpp"
#include "builder.hpp"
#include "interfaces.hpp"

//Feito por Eduardo Luna Scalassara, MAT:232011289
//Feito por Leandro Coelho da Silva, MAT:232011396
//Feito por Lucas Santana Camilo Alves, MAT:211060666

using namespace std;

int main(){
    Builder *builder = new Builder();

    CntrApresentacaoControle *CntrApresentacaoControle = builder->construir();

    CntrApresentacaoControle->executar();

    delete builder;

    return 0;
}

/*
void inputConta();
void inputViagem();
void inputHospedagem();
void inputDestino();
void inputAtividade();

void inputHorario();
void inputDinheiro();
void inputNome();
void inputDuracao();
void inputAvaliacao();
void inputData();
void inputSenha();
void inputCodigo();

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
    cout << '\n';
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
            else if(entidades==3) inputHospedagem();
            else if(entidades==4) inputDestino();
            else if(entidades==5) inputAtividade();
            else if(entidades==6){
                cout << "Finalizando a aplicacao\n";
                break;
            }
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
//-------------------------Conta-----------------------------------

void inputConta(){
    cout << testeConta();

    Conta* conta = new Conta();
    Codigo codigo;
    codigo.setCodigo("123456");
    cout << '\n' << testeCodigo();
    try {
    conta->setCodigo(codigo);
        cout << "Valor: " << conta->getCodigo().getCodigo() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    Senha senha;
    senha.setSenha("53692");
    cout << '\n' << testeSenha();
    try {
        conta->setSenha(senha);
        cout << "Valor: " << conta->getSenha().getSenha() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";}
    // Libere a memória alocada

    delete conta;
}
//-------------------------Viagem-----------------------------------

void inputViagem(){
    cout << testeViagem();

    // Usando ponteiro para Viagem
    Viagem* viagem = new Viagem;

    Codigo codigo;
    codigo.setCodigo("123456");
    cout << '\n' << testeCodigo();
    try{
        viagem->setCodigo(codigo);
        cout << "Valor: " << viagem->getCodigo().getCodigo() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }
    Avaliacao avaliacao;
    avaliacao.setAvaliacao("3");
    cout << '\n' << testeAvaliacao();
    try {
        viagem->setAvaliacao(avaliacao);
        cout << "Valor: " << viagem->getAvaliacao().getAvaliacao() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    Nome nome;
    nome.setNome("Viagem a Paris");
    cout << '\n' << testeNome();
    try {
        viagem->setNome(nome);
        cout << "Valor: " << viagem->getNome().getNome() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    delete viagem;
}

//-------------------------Hospedagem-----------------------------------

void inputHospedagem(){
    cout << testeHospedagem();

    // Usando ponteiro para Hospedagem
    Hospedagem* hospedagem = new Hospedagem;

    Codigo codigo;
    codigo.setCodigo("123456");
    cout << '\n' << testeCodigo();
    try{
        hospedagem->setCodigo(codigo);
        cout << "Valor: " << hospedagem->getCodigo().getCodigo() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n"; }

    Avaliacao avaliacao;
    avaliacao.setAvaliacao("3");
    cout << '\n' << testeAvaliacao();
    try {
        hospedagem->setAvaliacao(avaliacao);
        cout << "Valor: " << hospedagem->getAvaliacao().getAvaliacao() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    Nome nome;
    nome.setNome("Hotel Paris");
    cout << '\n' << testeNome();
    try {
        hospedagem->setNome(nome);
        cout << "Valor: " << hospedagem->getNome().getNome() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    Dinheiro diaria;
    diaria.setDinheiro("1000,00");
    cout << '\n' << testeDinheiro();
    try {
        hospedagem->setDiaria(diaria);
        cout << "Valor: " << hospedagem->getDiaria().getDinheiroView() << '\n'
        << "Valor computacional: " << hospedagem->getDiaria().getDinheiro() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    delete hospedagem;
}

//-------------------------Destino-----------------------------------


void inputDestino(){
    cout << testeDestino();

    // Usando ponteiro para Destino
    Destino* destino = new Destino;

    Codigo codigo;
    codigo.setCodigo("123456");
    cout << '\n' << testeCodigo();

    try{
        destino->setCodigo(codigo);
        cout << "Valor: " << destino->getCodigo().getCodigo() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n"; }

    cout << "\n";

    Avaliacao avaliacao;
    avaliacao.setAvaliacao("3");
    cout << '\n' << testeAvaliacao();

    try {
        destino->setAvaliacao(avaliacao);
        cout << "Valor: " << destino->getAvaliacao().getAvaliacao() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";
    Nome nome;
    nome.setNome("Paris");
    cout << '\n' << testeNome();

    try {
        destino->setNome(nome);
        cout << "Valor: " << destino->getNome().getNome() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";
    Data dataInicio;
    dataInicio.setData("01-01-21");
    cout << '\n' << testeData();

    try {
        destino->setDataInicio(dataInicio);
        cout << "Valor: " << destino->getDataInicio().getData() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";
    Data dataFim;
    dataFim.setData("05-01-21");
    cout << '\n' << testeData();

    try {
        destino->setDataFim(dataFim);
        cout << "Valor: " << destino->getDataFim().getData() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";}

    delete destino;
    }

//-------------------------Atividade-----------------------------------

void inputAtividade(){
    cout << testeAtividade();

    // Usando ponteiro para Atividade
    Atividade* atividade = new Atividade;

    Codigo codigo;
    codigo.setCodigo("123456");
    cout << '\n' << testeCodigo();

    try{
        atividade->setCodigo(codigo);
        cout << "Valor: " << atividade->getCodigo().getCodigo() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n"; }

    cout << "\n";

    Avaliacao avaliacao;
    avaliacao.setAvaliacao("3");
    cout << '\n' << testeAvaliacao();

    try {
        atividade->setAvaliacao(avaliacao);
        cout << "Valor: " << atividade->getAvaliacao().getAvaliacao() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";

    Nome nome;
    nome.setNome("Torre Eiffel");
    cout << '\n' << testeNome();

    try {
        atividade->setNome(nome);
        cout << "Valor: " << atividade->getNome().getNome() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";

    Data data;
    data.setData("01-01-21");
    cout << '\n' << testeData();

    try {
        atividade->setData(data);
        cout << "Valor: " << atividade->getData().getData() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";

    Horario horario;
    horario.setHora("12:00");
    cout << '\n' << testeHorario();

    try {
        atividade->setHorario(horario);
        cout << "Valor: " << atividade->getHorario().getHora() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";

    Duracao duracao;
    duracao.setDuracao("60");
    cout << '\n' << testeDuracao();

    try {
        atividade->setDuracao(duracao);
        cout << "Valor: " << atividade->getDuracao().getDuracao() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    cout << "\n";

    Dinheiro preco;
    preco.setDinheiro("100,00");
    cout << '\n' << testeDinheiro();

    try {
        atividade->setPreco(preco);
        cout << "Valor: " << atividade->getPreco().getDinheiroView() << '\n'
        << "Valor computacional: " << atividade->getPreco().getDinheiro() << "\n\n";
    } catch (invalid_argument &exp) {
        cout << "Excecao: " << exp.what() << "\n\n";
    }

    delete atividade;
}
//-------------------------Dominios-----------------------------------

void inputHorario(){
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

void inputDinheiro(){
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

void inputNome(){
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

void inputAvaliacao(){
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

void inputDuracao(){
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

void inputData(){
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

void inputSenha(){
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

void inputCodigo(){
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
*/
