#include <iostream>
#include <string>
#include <stdio.h>
#include "dominios.hpp"
using namespace std;

int main()
{
    Horario teste;
    string hora;
    printf("Digite o horário: ");
    getline(cin, hora);
    if(teste.setHora(hora)){
        printf("Valor = %s\n", teste.getHora().c_str());
    }
    else{
        printf("Invalido\n");
    }
    return 0;
}
