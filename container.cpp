#include <bits/stdc++.h>
#include "container.hpp"
#include "entidades.hpp"

using namespace std;

ContainerConta* ContainerConta::instancia = nullptr;
ContainerViagem* ContainerViagem::instancia = nullptr;
ContainerDestino* ContainerDestino::instancia = nullptr;
ContainerHospedagem* ContainerHospedagem::instancia = nullptr;
ContainerAtividade* ContainerAtividade::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerConta();
     }
     return instancia;
}

bool ContainerConta::hasConta(string codigo){
    return contas.find(codigo) != contas.end();
}

bool ContainerConta::createConta(string codigo, string senha){
    if(hasConta(codigo)){
        cout << "\nConta ja existe\n\n";
        return false;
    }
    Conta* conta = new Conta();
    try{
        Codigo codigo_;
        Senha senha_;
        codigo_.setCodigo(codigo);
        senha_.setSenha(senha);
        conta->setCodigo(codigo_);
        conta->setSenha(senha_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete conta;
        return false;
    }

    contas[codigo] = senha;

    delete conta;

    return true;
}

int ContainerConta::logarConta(string codigo, string senha){
    if(hasConta(codigo) && contas[codigo] == senha){
        return stoi(codigo);
    }
    else {
        cout << "As credenciais da conta estão incorretas\n";
        return 0;
    }
}

ContainerViagem* ContainerViagem::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerViagem();
     }
     return instancia;
}

bool ContainerViagem::hasViagem(string codigo){
    return viagens.find(codigo) != viagens.end();
}

bool ContainerViagem::createViagem(string codigo, string nome, string avaliacao, string codigoConta){
    if(hasViagem(codigo)){
        cout << "\nViagem ja existe\n\n";
        return false;
    }
    Viagem* viagem = new Viagem();
    try{
        Codigo codigo_;
        Nome nome_;
        Avaliacao avaliacao_;
        codigo_.setCodigo(codigo);
        nome_.setNome(nome);
        avaliacao_.setAvaliacao(avaliacao);
        viagem->setCodigo(codigo_);
        viagem->setNome(nome_);
        viagem->setAvaliacao(avaliacao_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete viagem;
        return false;
    }

    viagens[codigo] = {nome, avaliacao, codigoConta};

    delete viagem;

    return true;
}   

void ContainerViagem::listarViagens(string codigoConta){
    cout << '\n';

    for(const auto& viagem: viagens){
        if(viagem.second[2] == codigoConta){
            cout << "Codigo: " << viagem.first << '\n';
            cout << "Nome: " << viagem.second[0] << '\n';
            cout << "Avaliacao: " << viagem.second[1] << '\n';
            cout << '\n';
        }
    }
}

string ContainerViagem::getConta(string codigoViagem){
    for(const auto& viagem: viagens){
        if(viagem.first == codigoViagem){
            return viagem.second[2];
        }
    }
}

ContainerDestino* ContainerDestino::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerDestino();
     }
     return instancia;
}

bool ContainerDestino::hasDestino(string codigo){
    return destinos.find(codigo) != destinos.end();
}

bool ContainerDestino::createDestino(string codigo, string nome, string data_inicio, string data_final, string avaliacao, string codigoViagem){
    if(hasDestino(codigo)){
        cout << "\nDestino ja existe\n\n";
        return false;
    }
    Destino* destino = new Destino();
    try{
        Codigo codigo_;
        Nome nome_;
        Data data_inicio_;
        Data data_final_;
        Avaliacao avaliacao_;
        codigo_.setCodigo(codigo);
        nome_.setNome(nome);
        data_inicio_.setData(data_inicio);
        data_final_.setData(data_final);
        avaliacao_.setAvaliacao(avaliacao);
        destino->setCodigo(codigo_);
        destino->setNome(nome_);
        destino->setDataInicio(data_inicio_);
        destino->setDataFim(data_final_);
        destino->setAvaliacao(avaliacao_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete destino;
        return false;
    }

    destinos[codigo] = {nome, data_inicio, data_final, avaliacao, codigoViagem};

    delete destino;

    return true;
}

void ContainerDestino::listarDestinos(string codigoViagem){
    cout << '\n';

    for(const auto& destino: destinos){
        if(destino.second[4] == codigoViagem){
            cout << "Codigo: " << destino.first << '\n';
            cout << "Nome: " << destino.second[0] << '\n';
            cout << "Data de inicio: " << destino.second[1] << '\n';
            cout << "Data final: " << destino.second[2] << '\n';
            cout << "Avaliacao: " << destino.second[3] << '\n';
            cout << '\n';
        }
    }
}

string ContainerDestino::getViagem(string codigoDestino){
    for(const auto& destino: destinos){
        if(destino.first == codigoDestino){
            return destino.second[4];
        }
    }
}

ContainerHospedagem* ContainerHospedagem::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerHospedagem();
     }
     return instancia;
}

bool ContainerHospedagem::hasHospedagem(string codigo){
    return hospedagens.find(codigo) != hospedagens.end();
}

bool ContainerHospedagem::createHospedagem(string codigo, string nome, string diaria, string avaliacao, string codigoDestino){
    if(hasHospedagem(codigo)){
        cout << "\nHospedagem ja existe\n\n";
        return false;
    }
    Hospedagem* hospedagem = new Hospedagem();
    try{
        Codigo codigo_;
        Nome nome_;
        Dinheiro diaria_;
        Avaliacao avaliacao_;
        codigo_.setCodigo(codigo);
        nome_.setNome(nome);
        diaria_.setDinheiro(diaria);
        avaliacao_.setAvaliacao(avaliacao);
        hospedagem->setCodigo(codigo_);
        hospedagem->setNome(nome_);
        hospedagem->setDiaria(diaria_);
        hospedagem->setAvaliacao(avaliacao_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete hospedagem;
        return false;
    }

    hospedagens[codigo] = {nome, diaria, avaliacao, codigoDestino};

    delete hospedagem;

    return true;
}

void ContainerHospedagem::listarHospedagens(string codigoDestino){
    cout << '\n';

    for(const auto& hospedagem: hospedagens){
        if(hospedagem.second[3] == codigoDestino){
            cout << "Codigo: " << hospedagem.first << '\n';
            cout << "Nome: " << hospedagem.second[0] << '\n';
            cout << "Diaria: " << hospedagem.second[1] << '\n';
            cout << "Avaliacao: " << hospedagem.second[2] << '\n';
            cout << '\n';
        }
    }
}

ContainerAtividade* ContainerAtividade::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerAtividade();
     }
     return instancia;
}

bool ContainerAtividade::hasAtividade(string codigo){
    return atividades.find(codigo) != atividades.end();
}

bool ContainerAtividade::createAtividade(string codigo, string nome, string data, string horario, string duracao, string preco, string avaliacao, string codigoDestino){
    if(hasAtividade(codigo)){
        cout << "\nAtividade ja existe\n\n";
        return false;
    }
    Atividade* atividade = new Atividade();
    try{
        Codigo codigo_;
        Nome nome_;
        Data data_;
        Horario horario_;
        Duracao duracao_;
        Dinheiro preco_;
        Avaliacao avaliacao_;
        codigo_.setCodigo(codigo);
        nome_.setNome(nome);
        data_.setData(data);
        horario_.setHora(horario);
        duracao_.setDuracao(duracao);
        preco_.setDinheiro(preco);
        avaliacao_.setAvaliacao(avaliacao);
        atividade->setCodigo(codigo_);
        atividade->setNome(nome_);
        atividade->setData(data_);
        atividade->setHorario(horario_);
        atividade->setDuracao(duracao_);
        atividade->setPreco(preco_);
        atividade->setAvaliacao(avaliacao_);
    }

    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << "\n\n";
        delete atividade;
        return false;
    }

    atividades[codigo] = {nome, data, horario, duracao, preco, avaliacao, codigoDestino};

    delete atividade;

    return true;
}

void ContainerAtividade::listarAtividades(string codigoDestino){
    cout << '\n';

    for(const auto& atividade: atividades){
        if(atividade.second[6] == codigoDestino){
            cout << "Codigo: " << atividade.first << '\n';
            cout << "Nome: " << atividade.second[0] << '\n';
            cout << "Data: " << atividade.second[1] << '\n';
            cout << "Horario: " << atividade.second[2] << '\n';
            cout << "Duracao: " << atividade.second[3] << '\n';
            cout << "Preco: " << atividade.second[4] << '\n';
            cout << "Avaliacao: " << atividade.second[5] << '\n';
            cout << '\n';
        }
    }
}
