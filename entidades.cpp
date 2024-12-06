#include "entidades.hpp"
#include "dominios.hpp"

//Sistema básico, onde entidades recebem domínios como atributos, 
//pelo metodo set e são retornadas .elo get

//Conta
void Conta::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
};

Codigo Conta::getCodigo() const {
    return this->codigo;
}

void Conta::setSenha(const Senha& senha){
    this->senha = senha;
}

Senha Conta::getSenha() const {
    return this->senha;
}

//Viagem

void Viagem::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
};

Codigo Viagem::getCodigo() const {
    return this->codigo;
}

void Viagem::setAvaliacao(const Avaliacao& avaliacao){
    this->avalicao = avaliacao;
}

Avaliacao Viagem::getAvalicao() const {
    return this->avalicao;
}
void Viagem::setNome(const Nome& nome){
    this->nome = nome;
}

Nome Viagem::getNome() const {
    return this->nome;
}

//Hospedagem

void Hospedagem::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo Hospedagem::getCodigo() const {
    return this->codigo;
}

void Hospedagem::setAvaliacao(const Avaliacao& avaliacao){
    this->avalicao = avaliacao;
}

Avaliacao Hospedagem::getAvalicao() const {
    return this->avalicao;
}

void Hospedagem::setNome(const Nome& nome){
    this->nome = nome;
}

Nome Hospedagem::getNome() const {
    return this->nome;
}

void Hospedagem::setDiaria(const Dinheiro& diaria){
    this->diaria = diaria;
}

Dinheiro Hospedagem::getDiaria() const {
    return this->diaria;
}

//

void Destino::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo Destino::getCodigo() const {
    return this->codigo;
}

void Destino::setNome(const Nome& nome){
    this->nome = nome;
}

Nome Destino::getNome() const {
    return this->nome;
}

void Destino::setAvaliacao(const Avaliacao& avaliacao){
    this->avalicao = avaliacao;
}

Avaliacao Destino::getAvalicao() const {
    return this->avalicao;
}

void Destino::setDataInicio(const Data& data_inicio){
    this->data_inicio = data_inicio;
}

Data Destino::getDataInicio() const {
    return this->data_inicio;
}

void Destino::setDataFim(const Data& data_fim){
    this->data_fim = data_fim;
}

Data Destino::getDataFim() const {
    return this->data_fim;
}

//Atividade


void Atividade::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo Atividade::getCodigo() const {
    return this->codigo;
}

void Atividade::setNome(const Nome& nome){
    this->nome = nome;
}

Nome Atividade::getNome() const {
    return this->nome;
}

void Atividade::setAvaliacao(const Avaliacao& avaliacao){
    this->avalicao = avaliacao;
}

Avaliacao Atividade::getAvalicao() const {
    return this->avalicao;
}

void Atividade::setData(const Data& data){
    this->data = data;
}

Data Atividade::getData() const {
    return this->data;
}

void Atividade::setHorario(const Horario& horario){
    this->horario=horario;
}

Horario Atividade::getHorario() const {
    return this->horario;
}

void Atividade::setDuracao(const Duracao& duracao){
    this->duracao=duracao;
}

Duracao Atividade::getDuracao() const {
    return this->duracao;
}

void Atividade::setPreco(const Dinheiro& preco){
    this->preco = preco;
}

Dinheiro Atividade::getPreco() const {
    return this->preco;
}

