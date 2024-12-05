#include "dominios.hpp"
#include <stdexcept>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// HORARIO

void Horario::validateHora(unsigned short hora, unsigned short minuto){
    //Valida se as horas e minutos estão dentro do padrão
    if (hora > 23 || hora < 0){
        throw invalid_argument("Argumento invalido");
    }
    else if (minuto > 59 || minuto < 0){
        throw invalid_argument("Argumento invalido");
    }
}

bool Horario::setHora(string horario){
    if (horario[2] != ':'){
        throw invalid_argument("Argumento invalido"); //Se o horário não separar o valor corretamente será inválido
    }
    unsigned short HH = stoi(horario.substr(0,2)); //Converte horas string para inteiro
    unsigned short MM = stoi(horario.substr(3 ,2)); //Converte minutos string para inteiro
    try {
        validateHora(HH, MM);            //Atribui valores se forem válidos
        this->hora=HH;
        this->minuto=MM;
    }
    catch(invalid_argument &exp) {
        throw invalid_argument("Argumento invalido");
    }
    return true;
}

string Horario::getHora() const { //Formata a string para o padrão HH:MM
    string horario;
    if (Horario::hora < 10 && Horario::minuto < 10){
        horario = "0" + to_string(Horario::hora) + ":0" + to_string(Horario::minuto);
    }
    else if (Horario::hora < 10){
        horario = "0" + to_string(Horario::hora) + ":" + to_string(Horario::minuto);
    }
    else if (Horario::minuto < 10){
        horario = to_string(Horario::hora) + ":0" + to_string(Horario::minuto);
    }
    else {
        horario = to_string(Horario::hora) + ":" + to_string(Horario::minuto);
    }
    return horario;
}

// DINHEIRO

void Dinheiro::validateDinheiro(string dinheiro){ //Valida se o dinheiro está no padrão correto
    double dinheiro_float = stod(dinheiro);
    if (dinheiro_float < 0){
        throw invalid_argument("Argumento invalido");
    }
    else if (dinheiro_float > 20000000){
        throw invalid_argument("Argumento invalido");
    }
    this->dinheiro = dinheiro_float;
}

bool Dinheiro::setDinheiro(string dinheiro){ //Coloca no padrão de calculo da linguagem
    if (dinheiro[dinheiro.size()-3] != ','){ //verifica se a virgula esta na posicao certa
        throw invalid_argument("Argumento Invalido");
    }
    int virgula_unica = 0;
    string dinheiro_formatado = "";
    for (char caractere : dinheiro){
        if (caractere == ','){
            virgula_unica++;
            continue;
        } else if (caractere == '.') {
            continue;
        } else if (isdigit(caractere)) {
            dinheiro_formatado += caractere;   
        } else {
            throw invalid_argument("Argumento Invalido");
        }
    }
    if (virgula_unica > 1) //retorna erro quando o usuario coloca mais de uma virgula no valor
        throw invalid_argument("Argumento Invalido");
    
    
    validateDinheiro(dinheiro_formatado);
    this->dinheiroView = dinheiro; //Salva o valor escrito pelo usuário para ser mostrado depois
    return true;
}

string Dinheiro::getDinheiro() const {
    return this->dinheiroView; //Retorna o valor em centavos
}

// NOME

void Nome::validateNome(string nome) {
    for (char n: nome){
        if(isdigit(n)){
            throw invalid_argument("Argumento invalido");
        }
    }
    if(nome.length() < 1 || nome.length() > 30) throw invalid_argument("Argumento invalido"); // Valida se o nome tem entre 1 e 30 caracteres
}

bool Nome::setName(string nome) {
    validateNome(nome);
    this->nome = nome;
    return true;
}

string Nome::getName() const {
    return this->nome; // Retorna o nome armazenado
}

// AVALIAÇÃO

void Avaliacao::validateAvaliacao(int avaliacao){
    if (avaliacao < 0 || avaliacao > 5){
        throw invalid_argument("Argumento invalido");
    }
}

bool Avaliacao::setAvaliacao(string avaliacao){
    int avaliacao_int = stoi(avaliacao);
    validateAvaliacao(avaliacao_int);
    this->avaliacao = avaliacao_int;
    return true;
}

string Avaliacao::getAvaliacao() const {
    return to_string(this->avaliacao);
}

// DURACAO

void Duracao::validateDuracao(int duracao){
    if (duracao < 0 || duracao > 360){
        throw invalid_argument("Argumento invalido");
    }
}

bool Duracao::setDuracao(string duracao){
    int duracao_int = std::stoi(duracao);
    validateDuracao(duracao_int);
    this->duracao = duracao_int;
    return true;
    
}

string Duracao::getDuracao() const {
    return to_string(this->duracao);
}

// DATA

void Data::validateData(unsigned short dia, unsigned short mes, unsigned short ano){
    if (ano >= 0 && ano <= 99){ //Analise para o padrão do ano
        if(mes < 1 || mes > 12){ // Analise para quantidade de mês
            throw invalid_argument("Argumento invalido");
        }
        else {
            if ((ano % 4) == 0){  //Analise de ano bissexto
                if (mes == 2){
                    if (dia < 1 || dia > 29){ //Analise dos dias de fevereiro
                        throw invalid_argument("Argumento invalido");
                    }
                }
                else {
                    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                        if(dia < 1 || dia > 31){ //Meses com 31 dias
                            throw invalid_argument("Argumento invalido");
                        }
                    }
                else {
                    if(dia < 1 || dia > 30){ // Meses com 30 dias
                        throw invalid_argument("Argumento invalido");
                    }
                }
            }
            }
            else {
                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if(dia < 1 || dia > 31){ //Meses com 31 dias
                        throw invalid_argument("Argumento invalido");
                    }
                }
                else {
                    if(dia < 1 || dia > 30){ //Meses com 30 dias
                        throw invalid_argument("Argumento invalido");
                    }
                }
            }
        }
        }
    else {
        throw invalid_argument("Argumento invalido");;
    }
}

bool Data::setData(string data){
    if (data[2] != '-' || data[5] != '-'){
        throw invalid_argument("Argumento invalido");
        return false;//Se a data não for escrita corretamente
    }
    unsigned short DD = stoi(data.substr(0,2));
    unsigned short MM = stoi(data.substr(3,2));
    unsigned short AA = stoi(data.substr(6,3));
    validateData(DD, MM, AA); 
    this->dia = DD;
    this->mes = MM;
    this->ano = AA;
    return true;
}

string Data::getData() const {
    string data;
    string dia;
    string mes;
    string ano;
    if (this->dia < 10){
        dia = "0"+ to_string(this->dia);
    }
    else {
        dia = to_string(this->dia);
    }
    if (this->mes < 10){
        mes = "0"+ to_string(this->mes);
    }
    else {
        mes = to_string(this->mes);
    }
    if (this->ano < 10){
        ano = "0"+ to_string(this->ano);
    }
    else {
        ano = to_string(this->ano);
    }
    data = dia + "-" + mes + "-" + ano;
    return data;
}

// CODIGO

void Codigo::validateCodigo(string codigo){
    if(codigo.size()!=6){
        throw invalid_argument("Argumento invalido");
    }
    vector<char> caracteres = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (char letra: codigo){
        if (count(caracteres.begin(), caracteres.end(), letra) == 0){ //Ver se tem os caracteres validos percorrendo pela string e pelo vector
            throw invalid_argument("Argumento invalido");
        }
    }
}

bool Codigo::setCodigo(string codigo){
    validateCodigo(codigo);
        this->codigo = codigo;
        return true;
}

string Codigo::getCodigo() const {
    return this->codigo;
}

// SENHA

void Senha::validateSenha(string senha){
    if (senha.size() != 5){
        throw invalid_argument("Argumento invalido");
    }
    for(int i = 0; i < 5; i++){ //Ver se tem numero
        if(!isdigit(senha[i])){
            throw invalid_argument("Argumento invalido");
        }
    }
    vector<char> caracteres;
    map<char, int> contagem;
    for (char c: senha){
        contagem[c]++;
        if(contagem[c] >= 2){ //Para descobrir se um numero se repete
            throw invalid_argument("Argumento invalido");
        }
        caracteres.push_back(c - '0'); //subtracao por ascii, para virar inteiro
    }
    int contador_cre = 0; //contador de numeros crescentes
    int contador_dec = 0; //contador de numeros decrescentes
    int n_anterior = caracteres.at(0);
    for(int n: caracteres){ //Lógica para ver se a senha é decresce ou crescente
        if(n==(n_anterior-1)){
            n_anterior = n;
            contador_dec++;
        }
        else if(n==(n_anterior +1)){
            n_anterior = n;
            contador_cre++;
        }
        if(contador_cre == 4 || contador_dec == 4){
            throw invalid_argument("Argumento invalido");
        }
    }
}

bool Senha::setSenha(string senha){
    validateSenha(senha);
    this->senha = senha;
    return true;
}

string Senha::getSenha() const {
    return this->senha;
}
