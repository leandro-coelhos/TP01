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
    return this->dinheiroView; //Retorna o valor escrito pelo usuário
}

float Dinheiro::getDinheiro() const {
    return this->dinheiro; //Retorna o valor em float
}

// NOME

bool Nome::validateNome(string n) {
    return n.length() >= 1 && n.length() <= 30; // Valida se o nome tem entre 1 e 30 caracteres
}

bool Nome::setName(string n) {
    if (!validateNome(n)) // Verifica se o nome � v�lido
        return false;
    this->nome = n; // Atribui o nome se for v�lido
    return true;
}

string Nome::getName() const {
    return nome; // Retorna o nome armazenado
}

// AVALIAÇÃO

bool Avaliacao::validateAvaliacao(int avaliacao){
    if (avaliacao < 0 || avaliacao > 5){
        return false;
    }
    else {
        return true;
    }
}

bool Avaliacao::setAvaliacao(int avaliacao){
    if (!validateAvaliacao(avaliacao)){
        return false;
    }
    else {
        this->avaliacao = avaliacao;
        return true;
    }
}

string Avaliacao::getAvaliacao() const {
    string avaliacao;
    avaliacao = to_string(this->avaliacao);
    return avaliacao;
}

// DURACAO

bool Duracao::validateDuracao(int duracao){
    if (duracao < 0 || duracao > 360){
        return false;
    }
    else {
        return true;
    }
}

bool Duracao::setDuracao(int duracao){
    if (!validateDuracao(duracao)){
        return false;
    }
    else {
        this->duracao = duracao;
        return true;
    }
}

string Duracao::getDuracao() const {
    string duracao;
    duracao = to_string(this->duracao);
    return duracao;
}

// DATA

bool Data::validateData(unsigned short dia, unsigned short mes, unsigned short ano){
    if (ano >= 0 && ano <= 99){ //Analise para o padrão do ano
        if(mes < 1 || mes > 12){ // Analise para quantidade de mês
            return false;
        }
        else {
            if ((ano % 4) == 0){  //Analise de ano bissexto
                if (mes == 2){
                    if (dia < 1 || dia > 29){ //Analise dos dias de fevereiro 
                        return false;
                    }
                    else {
                        return true;
                    }   
                }
                else {
                    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                        if(dia < 1 || dia > 31){ //Meses com 31 dias
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                else {
                    if(dia < 1 || dia > 30){ // Meses com 30 dias
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            }
            else {
                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if(dia < 1 || dia > 31){ //Meses com 31 dias
                        return false;
                    }
                    else {
                        return true;
                    }
                }
                else {
                    if(dia < 1 || dia > 30){ //Meses com 30 dias
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
        }
        }
    else {
        return false;
    }
}

bool Data::setData(string data){
    if (data[2] != '-' || data[5] != '-'){
        return false; //Se a data não for escrita corretamente
    }
    int data_final = data.size();
    unsigned short DD = stoi(data.substr(0,2));
    unsigned short MM = stoi(data.substr(3,2));
    unsigned short AA = stoi(data.substr(6,3));
    if(!validateData(DD, MM, AA)){
        return false;
    }
    else {
        this->dia = DD;
        this->mes = MM;
        this->ano = AA;
        return true;
    }
}

string Data::getData() const {
    string data;
    string dia;
    string mes;
    string ano;
    if (this->dia < 10){
        dia = "0"+ to_string(this->dia);
    }
    if (this->mes < 10){
        mes = "0"+ to_string(this->mes);
    }
    if (this->ano < 10){
        ano = "0"+ to_string(this->ano);
    }
    data = dia + "-" + mes + "-" + ano;
    return data;
}

// CODIGO

// SENHA

// Senha::Senha() : senha(""){}

// bool Senha::validasenha(const string& s){

//     if (s.length() < 8)return false;

//     bool upper = false, lower = false, digit = false;

//     for (char ch:s){
//         if (isupper(ch)) upper = true;
//         if (islower(ch)) lower = true;
//         if (isdigit(ch)) digit = true;
//     }
//      return upper && lower && digit;


// }

// bool Senha::asdsc(const string& s){
//     int cont = 1;
//     for (size_t i = 1; i < s.length(); i++){
//         if (s[i] == s[i-1] + 1){
//             cont++;

//         }
//         else{
//             cont = 1;
//         }


// }
//     if (cont >= 6){
//         return false;

//     return true;
// }
