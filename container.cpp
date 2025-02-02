#include <bits/stdc++.h>
#include "container.hpp"
#include "entidades.hpp"

using namespace std;

// Inicialização das instâncias estáticas dos containers
ContainerConta* ContainerConta::instancia = nullptr;
ContainerViagem* ContainerViagem::instancia = nullptr;
ContainerDestino* ContainerDestino::instancia = nullptr;
ContainerHospedagem* ContainerHospedagem::instancia = nullptr;
ContainerAtividade* ContainerAtividade::instancia = nullptr;

/**
 * @brief Obtém a instância única do ContainerConta (Singleton).
 *
 * Este método garante que apenas uma instância do ContainerConta seja criada.
 * Se a instância já existir, retorna a mesma; caso contrário, cria uma nova.
 *
 * @return Retorna um ponteiro para a instância única do ContainerConta.
 */
ContainerConta* ContainerConta::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerConta();
     }
     return instancia;
}

/**
 * @brief Verifica se uma conta com o código fornecido já existe.
 *
 * @param codigo O código da conta a ser verificada.
 * @return Retorna true se a conta existir, false caso contrário.
 */
bool ContainerConta::hasConta(string codigo){
    return contas.find(codigo) != contas.end();
}

/**
 * @brief Cria uma nova conta no sistema.
 *
 * @param codigo O código da nova conta.
 * @param senha A senha da nova conta.
 * @return Retorna true se a conta foi criada com sucesso, false caso contrário.
 */
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

/**
 * @brief Realiza o login de uma conta.
 *
 * @param codigo O código da conta.
 * @param senha A senha da conta.
 * @return Retorna o código da conta convertido para inteiro se o login for bem-sucedido, 0 caso contrário.
 */
int ContainerConta::logarConta(string codigo, string senha){
    if(hasConta(codigo) && contas[codigo] == senha){
        return stoi(codigo);
    }
    else {
        cout << "As credenciais da conta estão incorretas\n";
        return 0;
    }
}

/**
 * @brief Obtém a instância única do ContainerViagem (Singleton).
 *
 * Este método garante que apenas uma instância do ContainerViagem seja criada.
 * Se a instância já existir, retorna a mesma; caso contrário, cria uma nova.
 *
 * @return Retorna um ponteiro para a instância única do ContainerViagem.
 */
ContainerViagem* ContainerViagem::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerViagem();
     }
     return instancia;
}

/**
 * @brief Verifica se uma viagem com o código fornecido já existe.
 *
 * @param codigo O código da viagem a ser verificada.
 * @return Retorna true se a viagem existir, false caso contrário.
 */
bool ContainerViagem::hasViagem(string codigo){
    return viagens.find(codigo) != viagens.end();
}

/**
 * @brief Cria uma nova viagem no sistema.
 *
 * @param codigo O código da nova viagem.
 * @param nome O nome da nova viagem.
 * @param avaliacao A avaliação da nova viagem.
 * @param codigoConta O código da conta associada à viagem.
 * @return Retorna true se a viagem foi criada com sucesso, false caso contrário.
 */
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

/**
 * @brief Lista todas as viagens associadas a uma conta.
 *
 * @param codigoConta O código da conta para a qual as viagens serão listadas.
 */
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

/**
 * @brief Obtém o código da conta associada a uma viagem.
 *
 * @param codigoViagem O código da viagem.
 * @return Retorna o código da conta associada à viagem.
 */
string ContainerViagem::getConta(string codigoViagem){
    for(const auto& viagem: viagens){
        if(viagem.first == codigoViagem){
            return viagem.second[2];
        }
    }
}

/**
 * @brief Obtém a instância única do ContainerDestino (Singleton).
 *
 * Este método garante que apenas uma instância do ContainerDestino seja criada.
 * Se a instância já existir, retorna a mesma; caso contrário, cria uma nova.
 *
 * @return Retorna um ponteiro para a instância única do ContainerDestino.
 */
ContainerDestino* ContainerDestino::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerDestino();
     }
     return instancia;
}

/**
 * @brief Verifica se um destino com o código fornecido já existe.
 *
 * @param codigo O código do destino a ser verificado.
 * @return Retorna true se o destino existir, false caso contrário.
 */
bool ContainerDestino::hasDestino(string codigo){
    return destinos.find(codigo) != destinos.end();
}

/**
 * @brief Cria um novo destino no sistema.
 *
 * @param codigo O código do novo destino.
 * @param nome O nome do novo destino.
 * @param data_inicio A data de início do destino.
 * @param data_final A data final do destino.
 * @param avaliacao A avaliação do destino.
 * @param codigoViagem O código da viagem associada ao destino.
 * @return Retorna true se o destino foi criado com sucesso, false caso contrário.
 */
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

/**
 * @brief Lista todos os destinos associados a uma viagem.
 *
 * @param codigoViagem O código da viagem para a qual os destinos serão listados.
 */
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

/**
 * @brief Obtém o código da viagem associada a um destino.
 *
 * @param codigoDestino O código do destino.
 * @return Retorna o código da viagem associada ao destino.
 */
string ContainerDestino::getViagem(string codigoDestino){
    for(const auto& destino: destinos){
        if(destino.first == codigoDestino){
            return destino.second[4];
        }
    }
}

/**
 * @brief Obtém a instância única do ContainerHospedagem (Singleton).
 *
 * Este método garante que apenas uma instância do ContainerHospedagem seja criada.
 * Se a instância já existir, retorna a mesma; caso contrário, cria uma nova.
 *
 * @return Retorna um ponteiro para a instância única do ContainerHospedagem.
 */
ContainerHospedagem* ContainerHospedagem::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerHospedagem();
     }
     return instancia;
}

/**
 * @brief Verifica se uma hospedagem com o código fornecido já existe.
 *
 * @param codigo O código da hospedagem a ser verificada.
 * @return Retorna true se a hospedagem existir, false caso contrário.
 */
bool ContainerHospedagem::hasHospedagem(string codigo){
    return hospedagens.find(codigo) != hospedagens.end();
}

/**
 * @brief Cria uma nova hospedagem no sistema.
 *
 * @param codigo O código da nova hospedagem.
 * @param nome O nome da nova hospedagem.
 * @param diaria O valor da diária da hospedagem.
 * @param avaliacao A avaliação da hospedagem.
 * @param codigoDestino O código do destino associado à hospedagem.
 * @return Retorna true se a hospedagem foi criada com sucesso, false caso contrário.
 */
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

/**
 * @brief Lista todas as hospedagens associadas a um destino.
 *
 * @param codigoDestino O código do destino para o qual as hospedagens serão listadas.
 */
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

/**
 * @brief Obtém a instância única do ContainerAtividade (Singleton).
 *
 * Este método garante que apenas uma instância do ContainerAtividade seja criada.
 * Se a instância já existir, retorna a mesma; caso contrário, cria uma nova.
 *
 * @return Retorna um ponteiro para a instância única do ContainerAtividade.
 */
ContainerAtividade* ContainerAtividade::getInstancia(){
     if(instancia == nullptr){
          instancia = new ContainerAtividade();
     }
     return instancia;
}

/**
 * @brief Verifica se uma atividade com o código fornecido já existe.
 *
 * @param codigo O código da atividade a ser verificada.
 * @return Retorna true se a atividade existir, false caso contrário.
 */
bool ContainerAtividade::hasAtividade(string codigo){
    return atividades.find(codigo) != atividades.end();
}

/**
 * @brief Cria uma nova atividade no sistema.
 *
 * @param codigo O código da nova atividade.
 * @param nome O nome da nova atividade.
 * @param data A data da atividade.
 * @param horario O horário da atividade.
 * @param duracao A duração da atividade.
 * @param preco O preço da atividade.
 * @param avaliacao A avaliação da atividade.
 * @param codigoDestino O código do destino associado à atividade.
 * @return Retorna true se a atividade foi criada com sucesso, false caso contrário.
 */
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

/**
 * @brief Lista todas as atividades associadas a um destino.
 *
 * @param codigoDestino O código do destino para o qual as atividades serão listadas.
 */
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
