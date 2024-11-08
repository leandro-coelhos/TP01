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
            printf("Digite o horario: ");
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
    else if (opcao == 3){
        Nome nome;
        string nome_valor;
        printf("Se atente ao numero maximo de 30 letras.\n");
        printf("Digite o nome:");
        getline(cin,nome_valor);
        if (nome.setName(nome_valor)) { // Tenta definir o nome
            printf("Nome definido: %s\n", nome.getName().c_str()); // Exibe o nome definido
        } 
        else {
            printf("Nome invalido! O nome deve ter entre 1 e 30 caracteres.\n");
            }
        }
     else if (opcao == 4){
          Duracao duracao;
          int duracao_valor;
          printf("Digite a duracao: ");
          cin >> duracao_valor;
          if(duracao.setDuracao(duracao_valor)){
               printf("Duracao = %s\n", duracao.getDuracao().c_str());
          }
          else {
               printf("Invalido\n");
          }

     }
     else if (opcao == 5){
          Avaliacao avaliacao;
          int avaliacao_valor;
          printf("Digite a avaliacao: ");
          cin >> avaliacao_valor;
          if(avaliacao.setAvaliacao(avaliacao_valor)){
               printf("Avaliacao = %s\n", avaliacao.getAvaliacao().c_str());
          }
          else {
               printf("Invalido\n");
          }
     }
     else if (opcao == 6){
         Data data;
         string data_valor;
         printf("Digite a data: ");
         cin >> data_valor;
         if(data.setData(data_valor)){
               printf("Data = %s\n", data.getData().c_str());
          }
          else {
               printf("Invalido\n");
          }
     }
    return 0;
}
