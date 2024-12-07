#include <iostream>
#include <limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"


void inputHorario();

int main()
{
    int opcao = 0;
    int labs = 0;
    int ent = 0;

    while (opcao != 9) {
        std::cout << "1: Entidades\n2: Dominios\n\n";
        std::cin >> labs;
        if (std::cin.fail()) {
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
            std::cout << "Entrada invalida. Por favor, insira 1 ou 2.\n";
            continue; // Retorna ao início do loop
        }
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado

        if (labs == 1) {
            std::cout << "\n1: Conta\n2: Viagem\n3: Hospedagem\n4: Destino\n5: Atividade\n6: Parar\n\n";
            std::cin >> ent;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cout << "Entrada invalida. Por favor, insira um numero entre 1 e 6.\n";
                continue; // Retorna ao início do loop
            }
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado

            if (ent == 1) {
                TUConta testeConta;
                switch(testeConta.run()){
                    case TUConta::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUConta::FALHA: std::cout<<"FALHA\n";
                    break;
                }
                Conta conta;
                Codigo codigo;
                Senha senha;
                codigo.setCodigo("123456"); // Define o dominio codigo
                senha.setSenha("53419"); // Define o dominio senha
                conta.setCodigo(codigo); // Atribui o dominio codigo para a entidade
                conta.setSenha(senha); // Atribui o dominio senha para a entidade
                std::cout << "\nCodigo: " << conta.getCodigo().getCodigo() << "\n"
                     << "Senha: " << conta.getSenha().getSenha() << "\n\n";
            }
            else if (ent == 2) {
                TUViagem testeViagem;
                switch(testeViagem.run()){
                    case TUViagem::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUViagem::FALHA: std::cout<<"FALHA\n";
                    break;
                Viagem viagem;
                Codigo codigo;
                Avaliacao avaliacao;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao("3");
                viagem.setCodigo(codigo);
                viagem.setAvaliacao(avaliacao);
                std::cout << "\nCodigo: " << viagem.getCodigo().getCodigo() << "\n"
                     << "Avaliacao: " << viagem.getAvalicao().getAvaliacao() << "\n\n";
            }
            }
            else if (ent == 3) {
                TUHospedagem testeHospedagem;
                switch(testeHospedagem.run()){
                    case TUHospedagem::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUHospedagem::FALHA: std::cout<<"FALHA\n";
                    break;
                Hospedagem hospedagem;
                Codigo codigo;
                Avaliacao avaliacao;
                Dinheiro diaria;
                Nome nome;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao("3");
                diaria.setDinheiro("13.573,95");
                nome.setName("Flamingo");
                hospedagem.setCodigo(codigo);
                hospedagem.setAvaliacao(avaliacao);
                hospedagem.setDiaria(diaria);
                hospedagem.setNome(nome);
                std::cout << "\nCodigo: " << hospedagem.getCodigo().getCodigo() << "\n"
                     << "Avaliacao: " << hospedagem.getAvalicao().getAvaliacao() << "\n"
                     << "Nome: " << hospedagem.getNome().getName() << "\n"
                     << "Diaria: " << hospedagem.getDiaria().getDinheiroView() << "\n\n";
            }
            }
            else if (ent == 4) {
                TUDestino testeDestino;
                switch(testeDestino.run()){
                    case TUDestino::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUDestino::FALHA: std::cout<<"FALHA\n";
                    break;
                Destino destino;
                Codigo codigo;
                Avaliacao avaliacao;
                Data data_inicio;
                Data data_fim;
                codigo.setCodigo("123456");
                avaliacao.setAvaliacao("3");
                data_inicio.setData("12-02-05");
                data_fim.setData("13-03-05");
                destino.setCodigo(codigo);
                destino.setAvaliacao(avaliacao);
                destino.setDataInicio(data_inicio);
                destino.setDataFim(data_fim);
                std::cout << "\nCodigo: " << destino.getCodigo().getCodigo() << "\n"
                     << "Avaliacao: " << destino.getAvalicao().getAvaliacao() << "\n"
                     << "Data de inicio: " << destino.getDataInicio().getData() << "\n"
                     << "Data de fim: " << destino.getDataFim().getData() << "\n\n";
            }
            }
            else if (ent == 5) {
                TUAtividade testeAtividade;
                switch(testeAtividade.run()){
                    case TUAtividade::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUAtividade::FALHA: std::cout<<"FALHA\n";
                    break;
                Atividade atividade;
                Codigo codigo;
                Nome nome;
                Data data;
                //Horario horario;
                void inputHorario();
                Duracao duracao;
                Dinheiro preco;
                Avaliacao avaliacao;
                codigo.setCodigo("123456");
                nome.setName("Passeio Ao Parque");
                data.setData("12-02-05");
                //horario.setHora("16:30");
                duracao.setDuracao("180");
                preco.setDinheiro("50,53");
                avaliacao.setAvaliacao("3");
                atividade.setCodigo(codigo);
                atividade.setNome(nome);
                atividade.setData(data);
                //atividade.setHorario(horario);
                atividade.setDuracao(duracao);
                atividade.setPreco(preco);
                atividade.setAvaliacao(avaliacao);
                std::cout << "\nCodigo: " << atividade.getCodigo().getCodigo() << "\n"
                     << "Nome: " << atividade.getNome().getName() << "\n"
                     << "Data: " << atividade.getData().getData() << "\n"
                     << "Horario: " << atividade.getHorario().getHora() << "\n"
                     << "Duracao: " << atividade.getDuracao().getDuracao() << "\n"
                     << "Preco: " << atividade.getPreco().getDinheiroView() << "\n"
                     << "Avaliacao: " << atividade.getAvalicao().getAvaliacao() << "\n\n";
            }
            }
            else if (ent == 6) {
                std::cout << "\nParando\n";
                break;
            }
            else {
                std::cout << "Entidade invalida\n";
            }
        }      
        else if (labs == 2) {
            std::cout << "\n1: Horario\n2: Dinheiro\n3: Nome\n4: Duracao\n5: Avaliacao\n6: Data\n7: Senha\n8: Codigo\n9: Parar\n\n";
            std::cout << "\nEscolha o servico desejado de: ";
            std::cin >> opcao;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cout << "Entrada invalida. Por favor, insira um numero entre 1 e 9.\n";
                continue; // Retorna ao início do loop
            }
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado

            if (opcao == 1) {
                inputHorario();
            }
            else if (opcao == 2) {
                TUDinheiro testeDinheiro;

                switch(testeDinheiro.run()){
                    case TUDinheiro::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUDinheiro::FALHA: std::cout<<"FALHA\n";
                    break;

                }

                Dinheiro dinheiro;
                string dinheiro_valor;
                std::cout << "Formato: 1.000,00\n";
                std::cout << "Digite a quantidade dinheiro: ";
                getline(std::cin, dinheiro_valor);
                try{
                    dinheiro.setDinheiro(dinheiro_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Dinheiro *ptrD;
                ptrD = new Dinheiro();

                if(ptrD->setDinheiro(dinheiro_valor))
                    std::cout << "Valor: " << ptrD->getDinheiroView()<< "\nValor computacional = " << ptrD->getDinheiro() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrD;
            }
            else if (opcao == 3) {
                TUNome testeNome;

                switch(testeNome.run()){
                    case TUNome::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUNome::FALHA: std::cout<<"FALHA\n";
                    break;

                }

                Nome nome;
                string nome_valor;
                std::cout << "Formato: Ate 30 caracteres, somente letras.\n";
                std::cout << "Digite o nome: ";
                getline(std::cin, nome_valor);
                try {
                    nome.setName(nome_valor);
                }
                catch(invalid_argument &exp) {
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Nome *ptrN;
                ptrN = new Nome();

                if(ptrN->setName(nome_valor))
                    std::cout << "Valor: " << ptrN->getName() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrN;
            }
            else if (opcao == 4) {
                TUDuracao testeDuracao;

                switch(testeDuracao.run()){
                    case TUDuracao::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUDuracao::FALHA: std::cout<<"FALHA\n";
                    break;

                }

                Duracao duracao;
                string duracao_valor;
                std::cout << "Formato: de 0 ate 360\n";
                std::cout << "Digite a duracao: ";
                std::cin >> duracao_valor;
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
                try {
                    duracao.setDuracao(duracao_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Duracao *ptrDu;
                ptrDu = new Duracao();

                if(ptrDu->setDuracao(duracao_valor))
                    std::cout << "Valor: " << ptrDu->getDuracao() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrDu;
            }
            else if (opcao == 5) {
                TUAvaliacao testeAvaliacao;

                switch(testeAvaliacao.run()){
                    case TUAvaliacao::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUAvaliacao::FALHA: std::cout<<"FALHA\n";
                    break;

                }
                Avaliacao avaliacao;
                string avaliacao_valor;
                std::cout << "Formato: de 0 ate 5\n";
                std::cout << "Digite a avaliacao: ";
                std::cin >> avaliacao_valor;
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
                try{
                    avaliacao.setAvaliacao(avaliacao_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Avaliacao *ptrA;
                ptrA = new Avaliacao();

                if(ptrA->setAvaliacao(avaliacao_valor))
                    std::cout << "Valor: " << ptrA->getAvaliacao() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrA;

            }
            else if (opcao == 6) {
                TUData testeData;

                switch(testeData.run()){
                    case TUData::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUData::FALHA: std::cout<<"FALHA\n";
                    break;

                }
                Data data;
                string data_valor;
                std::cout << "Formato: DD-MM-AA, sendo AA de 00 ate 99\n";
                std::cout << "Digite a data: ";
                std::cin >> data_valor;
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
                try {
                    data.setData(data_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Data *ptrDa;
                ptrDa = new Data();

                if(ptrDa->setData(data_valor))
                    std::cout << "Valor: " << ptrDa->getData() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrDa;
            }
            else if (opcao == 7) {
                TUSenha testeSenha;

                switch(testeSenha.run()){
                    case TUSenha::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUSenha::FALHA: std::cout<<"FALHA\n";
                    break;

                }
                Senha senha;
                string senha_valor;
                std::cout << "Formato: Senha de 5 caracteres contendo somente numeros que nao se repitam e nao ordenados\n";
                std::cout << "Digite a senha: ";
                std::cin >> senha_valor;
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
                try {
                    senha.setSenha(senha_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Senha *ptrS;
                ptrS = new Senha();

                if(ptrS->setSenha(senha_valor))
                    std::cout << "Valor: " << ptrS->getSenha() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrS;
            }
            else if (opcao == 8) {
                TUCodigo testeCodigo;

                switch(testeCodigo.run()){
                    case TUCodigo::SUCESSO: std::cout<<"SUCESSO\n";
                    break;
                    case TUCodigo::FALHA: std::cout<<"FALHA\n";
                    break;

                }
                Codigo codigo;
                string codigo_valor;
                std::cout << "Formato: codigo de 6 caracteres contendo numeros e letras (maiusculas e minusculas)\n";
                std::cout << "Digite o codigo: ";
                std::cin >> codigo_valor;
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado
                try {
                    codigo.setCodigo(codigo_valor);
                }
                catch(invalid_argument &exp){
                    std::cout << "Excecao: " << exp.what() << "\n\n";
                }

                Codigo *ptrC;
                ptrC = new Codigo();

                if(ptrC->setCodigo(codigo_valor))
                    std::cout << "Valor: " << ptrC->getCodigo() << "\n\n";
                else
                    std::cout << "Valor invalido \n\n";

                delete ptrC;

            }
            else if (opcao == 9) {
                std::cout << "Finalizando operacao\n";
            } else {
                std::cout << "Opcao invalida\n";
            }
        }
    }
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

