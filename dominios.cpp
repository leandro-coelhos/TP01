#include "dominios.hpp"
#include <stdexcept> 

using namespace std;

// HORARIO

bool Horario::validateHora(unsigned short hora, unsigned short minuto){
    //Valida se as horas e minutos estão dentro do padrão
    if (hora > 23 || hora < 0){
        return false;
    }
    else if (minuto > 59 || minuto < 0){
        return false;
    }
    return true;
}

bool Horario::setHora(string horario){
    if (horario[2] != ':'){
        return false; //Se o horário não separar o valor corretamente será inválido
    }
    unsigned short HH = stoi(horario.substr(0,2)); //Converte horas string para inteiro
    unsigned short MM = stoi(horario.substr(3 ,2)); //Converte minutos string para inteiro
    if (validateHora(HH, MM)){ //Atribui valores se forem válidos
        this->hora=HH;
        this->minuto=MM;
        return true;
    }
    return false;
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

bool Dinheiro::validateDinheiro(string dinheiro){ //Valida se o dinheiro está no padrão correto
    try {
        this->dinheiro = stof(dinheiro); //Converte para float
    }
    catch (invalid_argument &e){
        return false;
    }
    if (Dinheiro::dinheiro < 0){
        return false;
    }
    else if (Dinheiro::dinheiro > 200000){
        return false;
    }
    return true;
}

bool Dinheiro::setDinheiro(string dinheiro){ //Coloca no padrão de calculo da linguagem
    this->dinheiroView = dinheiro; //Salva o valor escrito pelo usuário para ser mostrado depois
    for(int i=0; i<dinheiro.size(); i++){
        if (dinheiro[i] == '.'){
            dinheiro.erase(i, 1); //Tira os pontos
        }
        else if (dinheiro[i] == ','){
            dinheiro.replace(i, 1, "."); //Troca os virgulas por pontos
        }
    }
    if (Dinheiro::validateDinheiro(dinheiro)){
        return true;
    }
    else {
        this->dinheiroView = ""; //Se não for um número, o valor é inválido
        return false;
    }
}

string Dinheiro::getDinheiroView() const {
    return Dinheiro::dinheiroView; //Retorna o valor escrito pelo usuário
}

float Dinheiro::getDinheiro() const {
    return Dinheiro::dinheiro; //Retorna o valor em float
}

// NOME

bool Nome::validar(string n) {
    return true;
}
bool Nome::validar(string n) {
    return n.length() >= 1 && n.length() <= 30; // Valida se o nome tem entre 1 e 30 caracteres
}

bool Nome::setName(string n) {
    if (!validar(n)) // Verifica se o nome � v�lido
        return false;
    this->nome = n; // Atribui o nome se for v�lido
    return true;
}

string Nome::getName() const {
    return nome; // Retorna o nome armazenado
}

// AVALIAÇÃO

// DURACAO

// DATA

// CODIGO

// SENHA
