#include <iostream>
#include <limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"

void inputHorario();

int main(){
    //inputHorario();
    return 0;
}


void inputHorario(){

    TUHorario testeHorario;

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: std::cout<<"SUCESSO\n";
        break;
        case TUHorario::FALHA: std::cout<<"FALHA\n";
        break;
    }
    Horario horario;
    string hora_valor;
    std::cout << "Formato: HH:MM\n";
    std::cout << "Digite o horario: ";
    getline(std::cin, hora_valor);
    try {
        horario.setHora(hora_valor);
    }
    catch(invalid_argument &exp){
        std::cout << "Excecao: " << exp.what() << "\n\n";
    }

    //fazendo o ponteiro de cada classe (necessario para o teste.cpp)
    Horario *ptrH;
    ptrH = new Horario();

    if(ptrH->setHora(hora_valor))
        std::cout << "Valor: " << ptrH->getHora() << "\n\n";
    else
        std::cout << "Valor invalido \n\n";

    delete ptrH;
}

