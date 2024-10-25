#include <iostream>
#include <stdio.h>
#include <limits>
#include "dominios.hpp"
using namespace std;

int main()
{
    cout << "Escolha o serviço desejado: ";
    int opcao;
    scanf("%d", &opcao);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Limpa o buffer do teclado

    if(opcao == 1){
            Horario horario;
            string hora;
            printf("Digite o horário: ");
            getline(cin, hora);
            if(horario.setHora(hora)){
                printf("Valor = %s\n", horario.getHora().c_str());
            }
            else{
                printf("Invalido\n");
            }
    }
    else if (opcao == 2){
            Dinheiro dinheiro;
            string valor;
            printf("Digite o valor: ");
            getline(cin, valor);
            if(dinheiro.setDinheiro(valor)){
                printf("Valor = %s\nValor computacional = %.2f\n", dinheiro.getDinheiroView().c_str() ,dinheiro.getDinheiro());
            }
            else{
                printf("Invalido\n");
            }
    }
    return 0;
}
