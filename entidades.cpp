/**
 * @file entidades.hpp
 * @brief Implementação de métodos das entidades do sistema.
 *
 * Este arquivo contém a implementação dos métodos das classes
 * relacionadas as entidades do sistema, como Conta, Viagem,
 * Hospedagem, Atividade e Destino. Cada entidade utiliza domínios com
 * atributos, que são acessados e modificados por meio de métodos
 * 'set e 'get'.
 */

/**
 * @include "entidades.hpp"
 * Arquivo que define as classes das entidades do sistema.
 */
#include "entidades.hpp"

/**
 * @include "dominios.hpp"
 * Arquivo que define os domínios usados como atributos nas entidades.
 */
#include "dominios.hpp"

/**
 * @class Conta
 * @brief Representa uma conta com código e senha.
 */

/**
 * @brief Define o código da conta.
 * @param codigo Objeto do tipo Codigo.
 */

//CONTA - FEITO POR LEANDRO COELHO DA SILVA, MAT:232011396
void Conta::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
};

/**
 * @brief Retorna o código da conta.
 * @return Objeto do tipo Codigo.
 */
Codigo Conta::getCodigo() const {
    return this->codigo;
}

/**
 * @brief Define a senha da conta.
 * @param senha Objeto do tipo Senha.
 */
void Conta::setSenha(const Senha& senha){
    this->senha = senha;
}

/**
 * @brief Retorna a senha da conta.
 * @return Objeto do tipo Senha.
 */
Senha Conta::getSenha() const {
    return this->senha;
}

/**
 * @class Viagem
 * @brief Representa uma viagem com atributos como código, avaliação e nome.
 *
 * A classe Viagem utiliza diversos domínios para armazenar informações relacionadas à viagem.
 * Os valores podem ser configurados e acessados por meio de métodos 'set' e 'get'.
 */

/**
 * @brief Define o código da viagem.
 * @param codigo Objeto do tipo Codigo que representa o código da viagem.
 */

//VIAGEM - FEITO POR LEANDRO COELHO DA SILVA, MAT:232011396
void Viagem::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
};

/**
 * @brief Retorna o código da viagem.
 * @return Objeto do tipo Codigo associado à viagem.
 */
Codigo Viagem::getCodigo() const {
    return this->codigo;
}

/**
 * @brief Define a avaliação da viagem.
 * @param avaliacao Objeto do tipo Avaliacao que representa a avaliação da viagem.
 */
void Viagem::setAvaliacao(const Avaliacao& avaliacao){
    this->avaliacao = avaliacao;
}

/**
 * @brief Retorna a avaliação da viagem.
 * @return Objeto do tipo Avaliacao associado à viagem.
 */
Avaliacao Viagem::getAvaliacao() const {
    return this->avaliacao;
}

/**
 * @brief Define o nome da viagem.
 * @param nome Objeto do tipo Nome que representa o nome da viagem.
 */
void Viagem::setNome(const Nome& nome) {
    this->nome = nome;
}

/**
 * @brief Retorna o nome da viagem.
 * @return Objeto do tipo Nome associado à viagem.
 */
Nome Viagem::getNome() const {
    return this->nome;
}

/**
 * @class Hospedagem
 * @brief Representa uma hospedagem com código, avaliação, nome e diária.
 *
 * A classe Hospedagem utiliza os domínios Codigo, Avaliacao, Nome e Dinheiro
 * para armazenar informações associadas à hospedagem. Os valores podem
 * ser configurados e acessados por meio de métodos 'set' e 'get'.
 */

/**
 * @brief Define o código da hospedagem.
 * @param codigo Objeto do tipo Codigo que representa o código da hospedagem.
 */

//HOSPEDAGEM - FEITO POR LEANDRO COELHO DA SILVA, MAT:232011396
void Hospedagem::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

/**
 * @brief Retorna o código da hospedagem.
 * @return Objeto do tipo Codigo associado à hospedagem.
 */
Codigo Hospedagem::getCodigo() const {
    return this->codigo;
}

/**
 * @brief Define a avaliação da hospedagem.
 * @param avaliacao Objeto do tipo Avaliacao que representa a avaliação da hospedagem.
 */
void Hospedagem::setAvaliacao(const Avaliacao& avaliacao){
    this->avaliacao = avaliacao;
}

/**
 * @brief Retorna a avaliação da hospedagem.
 * @return Objeto do tipo Avaliacao associado à hospedagem.
 */
Avaliacao Hospedagem::getAvaliacao() const {
    return this->avaliacao;
}

/**
 * @brief Define o nome da hospedagem.
 * @param nome Objeto do tipo Nome que representa o nome da hospedagem.
 */
void Hospedagem::setNome(const Nome& nome){
    this->nome = nome;
}

/**
 * @brief Retorna o nome da hospedagem.
 * @return Objeto do tipo Nome associado à hospedagem.
 */
Nome Hospedagem::getNome() const {
    return this->nome;
}

/**
 * @brief Define o valor da diária da hospedagem.
 * @param diaria Objeto do tipo Dinheiro que representa o valor da diária.
 */
void Hospedagem::setDiaria(const Dinheiro& diaria){
    this->diaria = diaria;
}

/**
 * @brief Retorna o valor da diária da hospedagem.
 * @return Objeto do tipo Dinheiro associado à hospedagem.
 */
Dinheiro Hospedagem::getDiaria() const {
    return this->diaria;
}

/**
 * @class Destino
 * @brief Representa um destino com código, avaliação, data de início e data de fim.
 *
 * A classe Destino utiliza os domínios Codigo, Avaliacao e Data para armazenar
 * informações relacionadas ao destino. Os valores podem ser configurados e acessados
 * por meio de métodos 'set' e 'get'.
 */

/**
 * @brief Define o código do destino.
 * @param codigo Objeto do tipo Codigo que representa o código do destino.
 */

//DESTINO - FEITO POR LEANDRO COELHO DA SILVA, MAT:232011396
void Destino::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

/**
 * @brief Retorna o código do destino.
 * @return Objeto do tipo Codigo associado ao destino.
 */
Codigo Destino::getCodigo() const {
    return this->codigo;
}

/**
 * @brief Define o nome do destino.
 * @param nome Objeto do tipo Nome que representa o nome do destino.
 */
void Destino::setNome(const Nome& nome){
    this->nome = nome;
}

/**
 * @brief Retorna o nome do destino.
 * @return Objeto do tipo Nome associado ao destino.
 */
Nome Destino::getNome() const {
    return this->nome;
}


/**
 * @brief Define a avaliação do destino.
 * @param avaliacao Objeto do tipo Avaliacao que representa a avaliação do destino.
 */
void Destino::setAvaliacao(const Avaliacao& avaliacao){
    this->avaliacao = avaliacao;
}

/**
 * @brief Retorna a avaliação do destino.
 * @return Objeto do tipo Avaliacao associado ao destino.
 */
Avaliacao Destino::getAvaliacao() const {
    return this->avaliacao;
}

/**
 * @brief Define a data de início do destino.
 * @param data_inicio Objeto do tipo Data que representa a data de início do destino.
 */
void Destino::setDataInicio(const Data& data_inicio){
    this->data_inicio = data_inicio;
}

/**
 * @brief Retorna a data de início do destino.
 * @return Objeto do tipo Data associado à data de início.
 */
Data Destino::getDataInicio() const {
    return this->data_inicio;
}

/**
 * @brief Define a data de fim do destino.
 * @param data_fim Objeto do tipo Data que representa a data de fim do destino.
 */
void Destino::setDataFim(const Data& data_fim){
    this->data_fim = data_fim;
}

/**
 * @brief Retorna a data de fim do destino.
 * @return Objeto do tipo Data associado à data de fim.
 */
Data Destino::getDataFim() const {
    return this->data_fim;
}

/**
 * @class Atividade
 * @brief Representa uma atividade com atributos como código, nome, avaliação, data,
 * horário, duração e preço.
 *
 * A classe Atividade utiliza diversos domínios para armazenar informações relacionadas à atividade.
 * Os valores podem ser configurados e acessados por meio de métodos 'set' e 'get'.
 */

/**
 * @brief Define o código da atividade.
 * @param codigo Objeto do tipo Codigo que representa o código da atividade.
 */
 
//ATIVIDADE - FEITO POR LEANDRO COELHO DA SILVA, MAT:232011396
void Atividade::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
/**
 * @brief Retorna o código da atividade.
 * @return Objeto do tipo Codigo associado à atividade.
 */
Codigo Atividade::getCodigo() const {
    return this->codigo;
}

/**
 * @brief Define o nome da atividade.
 * @param nome Objeto do tipo Nome que representa o nome da atividade.
 */
void Atividade::setNome(const Nome& nome){
    this->nome = nome;
}

/**
 * @brief Retorna o nome da atividade.
 * @return Objeto do tipo Nome associado à atividade.
 */
Nome Atividade::getNome() const {
    return this->nome;
}

/**
 * @brief Define a avaliação da atividade.
 * @param avaliacao Objeto do tipo Avaliacao que representa a avaliação da atividade.
 */
void Atividade::setAvaliacao(const Avaliacao& avaliacao){
    this->avaliacao = avaliacao;
}

/**
 * @brief Retorna a avaliação da atividade.
 * @return Objeto do tipo Avaliacao associado à atividade.
 */
Avaliacao Atividade::getAvaliacao() const {
    return this->avaliacao;
}

/**
 * @brief Define a data da atividade.
 * @param data Objeto do tipo Data que representa a data da atividade.
 */
void Atividade::setData(const Data& data){
    this->data = data;
}

/**
 * @brief Retorna o data da atividade.
 * @return Objeto do tipo Data associado À atividade.
 */
Data Atividade::getData() const {
    return this->data;
}

/**
 * @brief Define o horário da atividade.
 * @param horario Objeto do tipo Horario que representa o horário da atividade.
 */
void Atividade::setHorario(const Horario& horario){
    this->horario=horario;
}

/**
 * @brief Retorna o horário da atividade.
 * @return Objeto do tipo Horario associado à atividade.
 */
Horario Atividade::getHorario() const {
    return this->horario;
}

/**
 * @brief Define a duração da atividade.
 * @param duracao Objeto do tipo Duracao que representa a duração da atividade.
 */
void Atividade::setDuracao(const Duracao& duracao){
    this->duracao=duracao;
}

/**
 * @brief Retorna a duração da atividade.
 * @return Objeto do tipo Duracao associado à atividade.
 */
Duracao Atividade::getDuracao() const {
    return this->duracao;
}

/**
 * @brief Define o preço da atividade.
 * @param preco Objeto do tipo Dinheiro que representa o preço da atividade.
 */
void Atividade::setPreco(const Dinheiro& preco){
    this->preco = preco;
}

/**
 * @brief Retorna o preço da atividade.
 * @return Objeto do tipo Dinheiro associado à atividade.
 */
Dinheiro Atividade::getPreco() const {
    return this->preco;
}
