#include <iostream>
#include <stdio.h>
#include <limits>
#include "dominios.hpp"
#include "entidades.hpp"
using namespace std;

//Você precisa ajustar o seguite: 
//Todo o código está misturando cout com scanf, printf com cin, pois estava acontecendo um bug
//E eu estava sem tempo para resolver
//Você precisa manter um padrão, colocar só cin e cout ou scanf e printf
//Vale ressaltar que quando você estiver mexendo talvez o limpador de buffer dê problema
//Aqui ele: cin.ignore(numeric_limits<streamsize>::max(), '\n');
//Pode pedir para o gpt sei lá, mas me fala qual era o problema, tava sem tempo pra resolver.

int main()
{
    int opcao;
    int labs;
    int ent;
    while(opcao!=9 || ent!=6){
        cout << "1: Entidades\n2: Dominios\n";
        scanf("%d",&labs);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
        if(labs==1){
            cout << "\n1: Conta\n2: Viagem\n3: Hospedagem\n4: Destino\n5: Atividade\n6: Parar\n";
            scanf("%d", &ent);
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
            if (ent==1){
                Conta conta;
                Codigo codigo;
                Senha senha;
                codigo.setCodigo("123456"); //Define o dominio codigo
                senha.setSenha("53419"); //Define o dominio senha
                conta.setCodigo(codigo); //Atribui o dominio codigo para a entidade
                conta.setSenha(senha); //Atribui o dominio senha para a entidade
                cout << "\nCodigo: " << conta.getCodigo().getCodigo() << "\n" << "Senha: " << conta.getSenha().getSenha() << "\n\n";
                //Retorna os dominios da entidade
            }
            else if (ent==2){
                Viagem viagem;
                Codigo codigo;
                Avaliacao avaliacao;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao(3);
                viagem.setCodigo(codigo);
                viagem.setAvaliacao(avaliacao);
                cout << "\nCodigo: " << viagem.getCodigo().getCodigo() << "\n" << "Avaliacao: " << viagem.getAvalicao().getAvaliacao() << "\n\n";
            }
            else if (ent==3){
                Hospedagem hospedagem;
                Codigo codigo;
                Avaliacao avaliacao;
                Dinheiro diaria;
                Nome nome;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao(3);
                diaria.setDinheiro("13.573,95");
                nome.setName("Flamingo");
                hospedagem.setCodigo(codigo);
                hospedagem.setAvaliacao(avaliacao);
                hospedagem.setDiaria(diaria);
                hospedagem.setNome(nome);
                cout << "\nCodigo: " << hospedagem.getCodigo().getCodigo() << "\n" 
                << "Avaliacao: " << hospedagem.getAvalicao().getAvaliacao() << "\n" 
                << "Nome: " << hospedagem.getNome().getName() << "\n" << "Diaria: " 
                << hospedagem.getDiaria().getDinheiroView() << "\n\n";
            }
            else if (ent==4){
                Destino destino;
                Codigo codigo;
                Avaliacao avaliacao;
                Data data_inicio;
                Data data_fim;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao(3);
                data_inicio.setData("12-02-05");
                data_fim.setData("13-03-05");
                destino.setCodigo(codigo);
                destino.setAvaliacao(avaliacao);
                destino.setDataInicio(data_inicio);
                destino.setDataFim(data_fim);
                cout << "\nCodigo: " << destino.getCodigo().getCodigo() << "\n" 
                << "Avaliacao: " << destino.getAvalicao().getAvaliacao() << "\n" 
                << "Data de inicio: " << destino.getDataInicio().getData() << "\n" << "Data de fim: " 
                << destino.getDataFim().getData() << "\n\n";
            }
            else if (ent==5){
                Atividade atividade;
                Codigo codigo;
                Nome nome;
                Data data;
                Horario horario;
                Duracao duracao;
                Dinheiro preco;
                Avaliacao avaliacao;
                codigo.setCodigo("123456");
                nome.setName("Passeio Ao Parque");
                data.setData("12-02-05");
                horario.setHora("16:30");
                duracao.setDuracao(180);
                preco.setDinheiro("50,53");
                avaliacao.setAvaliacao(3);
                atividade.setCodigo(codigo);
                atividade.setNome(nome);
                atividade.setData(data);
                atividade.setHorario(horario);
                atividade.setDuracao(duracao);
                atividade.setPreco(preco);
                atividade.setAvaliacao(avaliacao);
                cout << "\nCodigo: " << atividade.getCodigo().getCodigo() << "\n" 
                << "Nome: " << atividade.getNome().getName() << "\n" 
                << "Data: " << atividade.getData().getData() << "\n" 
                << "Horario: " << atividade.getHorario().getHora() << "\n"
                << "Duracao: " << atividade.getDuracao().getDuracao() << "\n"
                << "Preco: " << atividade.getPreco().getDinheiroView() << "\n"
                << "Avaliacao: " << atividade.getAvalicao().getAvaliacao() << "\n\n";
            }
            else if (ent==6){
                cout << "Parando";
            }
            else {
                cout << "Entidade invalida";
            }
            }
        else if (labs == 2){
                cout << "1: Horario\n2: Dinheiro\n3: Nome\n4: Duracao\n5: Avaliacao\n6: Data\n7: Senha\n8: Codigo\n9: Parar\n";
                cout << "\nEscolha o servico desejado de: ";
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
                    printf("Formato: DD/MM/AA, sendo AA de 00 ate 99\n");
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
                    printf("Formato: Somente numeros que nao se repitam e nao ordenados\n");
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
                    printf("Formato: numero e letras maiusculas e minusculas\n");
                    printf("Digite o codigo: ");
                    cin >> codigo_valor;
                    if (codigo.setCodigo(codigo_valor)){
                        printf("Codigo = %s\n", codigo.getCodigo().c_str());
                    }
                    else{
                        printf("Invalido");
                    }
                }
                else if (opcao == 9){
                    printf("Finalizando operacao\n");
                }
                else{
                printf("Opcao invalida\n");
            }
            }
    }
    return 0;
}
