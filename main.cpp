#include <iostream>
#include <stdio.h>
#include <limits>
#include "dominios.hpp"
using namespace std;

int main()
{
    cout << "1: Horario\n2: Dinheiro\n3: Nome\n4: Duracao\n5: Avaliacao\n6: Data\n7: Senha\n8: Codigo\n";
    cout << "Escolha o servico desejado de: ";
    int opcao;
    scanf("%d", &opcao);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado

    if (opcao == 1){
        Horario horario;
        string hora_valor;
        printf("Formato: HH:MM\n");
        printf("Digite o horario: ");
        getline(cin, hora_valor);
        if (horario.setHora(hora_valor)){
            printf("Valor = %s\n", horario.getHora().c_str());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 2){
        Dinheiro dinheiro;
        string dinheiro_valor;
        printf("Formato: 1.000,00\n");
        printf("Digite a quantidade dinheiro: ");
        getline(cin, dinheiro_valor);
        if (dinheiro.setDinheiro(dinheiro_valor)){
            printf("Valor = %s\nValor computacional = %.2f\n", dinheiro.getDinheiroView().c_str(), dinheiro.getDinheiro());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 3){
        Nome nome;
        string nome_valor;
        printf("Formato: Ate 30 caracteres, somente letras.\n");
        printf("Digite o nome: ");
        getline(cin, nome_valor);
        if (nome.setName(nome_valor)){                                                          // Tenta definir o nome
            printf("Nome definido: %s\n", nome.getName().c_str()); // Exibe o nome definido
        }
        else{
            printf("Invalido.\n");
        }
    }
    else if (opcao == 4){
        Duracao duracao;
        int duracao_valor;
        printf("Formato: de 0 ate 360\n");
        printf("Digite a duracao: ");
        cin >> duracao_valor;
        if (duracao.setDuracao(duracao_valor)){
            printf("Duracao = %s\n", duracao.getDuracao().c_str());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 5){
        Avaliacao avaliacao;
        int avaliacao_valor;
        printf("Formato: de 0 ate 5\n");
        printf("Digite a avaliacao: ");
        cin >> avaliacao_valor;
        if (avaliacao.setAvaliacao(avaliacao_valor)){
            printf("Avaliacao = %s\n", avaliacao.getAvaliacao().c_str());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 6){
        Data data;
        string data_valor;
        printf("Formato: DD/MM/AA, sendo AA de 00 até 99\n");
        printf("Digite a data: ");
        cin >> data_valor;
        if (data.setData(data_valor)){
            printf("Data = %s\n", data.getData().c_str());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 7){
        Senha senha;
        string senha_valor;
        printf("Formato: Somente numeros que não se repitam e não ordenados\n");
        printf("Digite a senha: ");
        cin >> senha_valor;
        if (senha.setSenha(senha_valor)){
            printf("Senha = %s\n", senha.getSenha().c_str());
        }
        else{
            printf("Invalido\n");
        }
    }
    else if (opcao == 8){
        Codigo codigo;
        string codigo_valor;
        printf("Formato: numero e letras maiúsculas e minúsculas\n");
        printf("Digite o codigo: ");
        cin >> codigo_valor;
        if (codigo.setCodigo(codigo_valor)){
            printf("Codigo = %s\n", codigo.getCodigo().c_str());
        }
        else{
            printf("Invalido");
        }
    }
    else{
        printf("Opcao invalida\n");
    }
    return 0;
}
