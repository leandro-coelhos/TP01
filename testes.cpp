/**
 * @file teste_unidade.cpp
 * @brief Implementação de testes unitários para diversas classes do sistema.
 * Este arquivo define classes de teste para validar as funcionalidades das classes
 */

/**
 * @include <string>
 * Biblioteca usada para manipulação de strings.
 */
#include <string>

/**
 * @include <iostream>
 * Biblioteca usada para entrada e saída de dados.
 */
#include <iostream>

/**
 * @include <stdexcept>
 * Biblioteca usada para lançamento de exceções.
 */
#include <stdexcept>

/**
 * @include "dominios.hpp"
 * Arquivo que define os domínios usados como atributos nas entidades.
 */
#include "entidades.hpp"

/**
 * @include "testes.hpp"
 * Arquivo que define as classes de teste unitário.
 */
#include "testes.hpp"

/**
 * @include "dominios.hpp"
 * Arquivo que define os domínios usados como atributos nas entidades.
 */
#include "dominios.hpp"

using namespace std;

const string TUHorario::horario_valido = "12:35";
const string TUHorario::horario_invalido = "99:99";

const string TUDinheiro::dinheiro_valido = "13,00";
const string TUDinheiro::dinheiro_invalido = "999.999,99";

const string TUNome::nome_valido = "joao";
const string TUNome::nome_invalido = "hjkhiguhgihunijnjinjijkhjkhkhkjjajja";

const string TUDuracao::duracao_valida = "99";
const string TUDuracao::duracao_invalida = "999";

const string TUAvaliacao::avaliacao_valida = "3";
const string TUAvaliacao::avaliacao_invalida = "9";

const string TUData::data_valida = "12-12-12";
const string TUData::data_invalida = "99-99-999";

const string TUSenha::senha_valida = "64785";
const string TUSenha::senha_invalida = "12345";

const string TUCodigo::codigo_valido = "215678";
const string TUCodigo::codigo_invalido = "Adaf12ugtyug67";

const string TUConta::codigo_valido = "215678";
const string TUConta::senha_valida = "64785";

const string TUViagem::codigo_valido = "215678";
const string TUViagem::nome_valido = "joao";
const string TUViagem::avaliacao_valida = "3";

const string TUDestino::codigo_valido = "215678";
const string TUDestino::nome_valido = "joao";
const string TUDestino::data_fim_valida = "12-12-12";
const string TUDestino::data_inicio_valida = "12-12-12";
const string TUDestino::avaliacao_valida = "3";

const string TUAtividade::codigo_valido = "215678";
const string TUAtividade::nome_valido = "joao";
const string TUAtividade::horario_valido = "12:35";
const string TUAtividade::data_valida = "12-12-12";
const string TUAtividade::duracao_valida = "99";
const string TUAtividade::dinheiro_valido = "13,00";
const string TUAtividade::avaliacao_valida = "3";

const string TUHospedagem::codigo_valido = "215678";
const string TUHospedagem::nome_valido = "joao";
const string TUHospedagem::dinheiro_valido = "13,00";
const string TUHospedagem::avaliacao_valida = "3";

//-------------------------TestesDomínio-----------------------------------

//FEITO POR EDUARDO LUNA SCALASSARA, MAT:232011289

//*****************HORARIO*****************

/**
 * @class TUHorario
 * @brief Classe de teste para a classe Horario.
 *
 * A classe `TUHorario` realiza testes unitários para a classe `Horario`,
 * verificando o comportamento dos métodos `setHora` e `getHora` quando são
 * fornecidos valores válidos e inválidos.
 */

/**
 * @brief Inicializa o horario com estado de SUCESSO.
 *
 * Este método prepara o ambiente de teste criando uma nova instância de
 * `Horario` e inicializando o estado do teste como `SUCESSO`.
 */
void TUHorario::setUp() {
    horario = new Horario();
    estado = SUCESSO;
}

/**
 * @brief Deleta o objeto horario para liberar memória.
 *
 * Este método é chamado após a execução de cada teste para liberar a memória
 * alocada para o objeto `horario`.
 */
void TUHorario::tearDown() {
    delete horario;
}

/**
 * @brief Testa cenário com valor válido para a hora.
 *
 * Este método verifica se a classe `Horario` consegue configurar e retornar
 * corretamente um valor de hora válido. Caso o valor não seja corretamente
 * configurado ou armazenado, o estado do teste é alterado para `FALHA`.
 *
 * @throws invalid_argument Se o valor de hora for inválido e a exceção for lançada.
 */
void TUHorario::testarCenarioValorValido() {
    try {
        horario->setHora(horario_valido);
        if (horario->getHora() != horario_valido)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

/**
 * @brief Verifica o comportamento da classe Horario ao tentar configurar um valor de hora inválido.
 *
 * Este método tenta configurar um valor inválido para o horário. Espera-se que uma exceção
 * do tipo `invalid_argument` seja lançada. Caso contrário, o teste falha.
 * Além disso, verifica se o valor de hora não foi alterado para o valor inválido.
 *
 * @throws invalid_argument Se o valor de hora fornecido for inválido.
 */
void TUHorario::testarCenarioValorInvalido() {
    try {
      horario->setHora(horario_invalido);
      estado = FALHA;
    }
    catch(invalid_argument &excecao) {
        if (horario->getHora() == horario_invalido)
            estado = FALHA;
    }
}

/**
 * @brief Executa os testes de valor válido e inválido.
 *
 * Este método executa os testes para os cenários de valor válido e inválido.
 * Ele configura o ambiente com o método `setUp`, executa os testes e, em seguida,
 * limpa os recursos com o método `tearDown`. O método retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUHorario::run() {
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}



//****************DINHEIRO*****************

/**
 * @class TUDinheiro
 * @brief Classe de teste para a classe Dinheiro.
 *
 * A classe `TUDinheiro` realiza os testes unitários da classe `Dinheiro`,
 * verificando como ela lida com valores válidos e inválidos, testando
 * os métodos `setDinheiro` e `getDinheiroView`.
 */

/**
 * @brief Inicializa o objeto `Dinheiro` e define os valores de teste.
 *
 * Este método configura o ambiente de teste, criando uma instância da classe `Dinheiro`,
 * e define os valores de teste tanto para valores válidos quanto inválidos de dinheiro.
 * Também inicializa o estado do teste como `SUCESSO`.
 */
void TUDinheiro::setUp() {
  dinheiro = new Dinheiro();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução de cada teste para liberar a memória alocada
 * para o objeto `dinheiro`, garantindo que não haja vazamento de memória.
 */
void TUDinheiro::tearDown() {
  delete dinheiro;
}

/**
 * @brief Testa cenário com valor válido para Dinheiro.
 *
 * Este método testa o comportamento da classe `Dinheiro` ao fornecer um valor válido para o método
 * `setDinheiro`. Verifica se o valor de dinheiro foi armazenado corretamente e se o método
 * `getDinheiroView` retorna a mesma string fornecida. Caso contrário, o estado do teste é alterado
 * para `FALHA`.
 *
 * @throws invalid_argument Se o valor de dinheiro fornecido for inválido.
 */
void TUDinheiro::testarCenarioValorValido() {
  try {
      dinheiro->setDinheiro(dinheiro_valido);
      if (dinheiro->getDinheiroView() != dinheiro_valido)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa cenário com valor inválido para Dinheiro.
 *
 * Este método testa o comportamento da classe `Dinheiro` ao fornecer um valor inválido para o método
 * `setDinheiro`. Espera-se que a classe lance uma exceção do tipo `invalid_argument` quando
 * um valor inválido é fornecido. Caso a exceção não seja lançada, o teste falha. Caso a exceção
 * seja corretamente lançada, o teste é considerado bem-sucedido.
 *
 * @throws invalid_argument Se o valor de dinheiro fornecido for inválido.
 */
void TUDinheiro::testarCenarioValorInvalido() {
  try {
    dinheiro->setDinheiro(dinheiro_invalido);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (dinheiro->getDinheiroView() == dinheiro_invalido) estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes para a classe Dinheiro.
 *
 * Primeiro, executa o teste com valor válido e, se este passar, executa o teste com valor inválido.
 * Após a execução de todos os testes, limpa os recursos alocados chamando o método `tearDown`.
 *
 * @return O estado final do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUDinheiro::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//******************NOME************************

/**
 * @class TUNome
 * @brief Classe de teste para a classe Nome.
 *
 * A classe `TUNome` realiza testes unitários para o método `setNome` e
 * `getNome` da classe `Nome`, verificando se os valores válidos e inválidos
 * são tratados corretamente.
 */

/**
 * @brief Inicializa o objeto `Nome` e o estado do teste como SUCESSO.
 *
 * Cria uma instância da classe `Nome` e define o estado inicial do teste
 * como `SUCESSO`.
 */
void TUNome::setUp() {
  nome = new Nome();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `nome`.
 */
void TUNome::tearDown() {
  delete nome;
}

/**
 * @brief Testa o comportamento com um valor válido para o nome.
 *
 * Este método verifica se o método `setNome` da classe `Nome` funciona corretamente
 * quando um valor válido de nome é fornecido. Se o valor armazenado no objeto
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para o nome for inválido.
 */
void TUNome::testarCenarioValorValido() {
  try {
      nome->setNome(nome_valido);
      if (nome->getNome() != nome_valido)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para o nome.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido de nome é fornecido. Caso o valor de nome seja alterado
 * mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para o nome for inválido.
 */
void TUNome::testarCenarioValorInvalido() {
  try {
    nome->setNome(nome_invalido);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (nome->getNome() == nome_invalido)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe `TUNome`.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUNome::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}

//*********************DURACAO********************

/**
 * @class TUDuracao
 * @brief Classe de teste para a classe Duracao.
 *
 * A classe `TUDuracao` realiza testes unitários para o método `setDuracao` e
 * `getDuracao` da classe `Duracao`, verificando se os valores válidos e inválidos
 * são tratados corretamente.
 */

/**
 * @brief Inicializa o objeto `Duracao` e o estado do teste como SUCESSO.
 *
 * Este método cria uma instância da classe `Duracao` e define o estado inicial do teste
 * como `SUCESSO`.
 */
void TUDuracao::setUp() {
  duracao = new Duracao();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `duracao`.
 */
void TUDuracao::tearDown() {
  delete duracao;
}

/**
 * @brief Testa o comportamento com um valor válido para a duração.
 *
 * Este método verifica se o método `setDuracao` da classe `Duracao` funciona corretamente
 * quando um valor válido de duração é fornecido. Se o valor armazenado no objeto
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a duração for inválido.
 */
void TUDuracao::testarCenarioValorValido() {
  try {
      duracao->setDuracao(duracao_valida);
      if (duracao->getDuracao() != duracao_valida)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para a duração.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido de duração é fornecido. Caso o valor de duração seja alterado
 * mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a duração for inválido.
 */
void TUDuracao::testarCenarioValorInvalido() {
  try {
    duracao->setDuracao(duracao_invalida);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (duracao->getDuracao() == duracao_invalida)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe `Duracao`.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUDuracao::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//********************AVALIACAO********************

/**
 * @class TUAvaliacao
 * @brief Classe de teste para a classe Avaliacao.
 *
 * A classe `TUAvaliacao` realiza testes unitários para os métodos `setAvaliacao`
 * e `getAvaliacao` da classe `Avaliacao`, verificando se os valores válidos e inválidos
 * são tratados corretamente.
 */

/**
 * @brief Inicializa o objeto `Avaliacao` e o estado do teste como SUCESSO.
 *
 * Este método cria uma instância da classe `Avaliacao` e define o estado inicial do teste
 * como `SUCESSO`.
 */
void TUAvaliacao::setUp() {
  avaliacao = new Avaliacao();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `avaliacao`.
 */
void TUAvaliacao::tearDown() {
  delete avaliacao;
}

/**
 * @brief Testa o comportamento com um valor válido para a avaliação.
 *
 * Este método verifica se o método `setAvaliacao` da classe `Avaliacao` funciona corretamente
 * quando um valor válido de avaliação é fornecido. Se o valor armazenado no objeto
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a avaliação for inválido.
 */
void TUAvaliacao::testarCenarioValorValido() {
  try {
      avaliacao->setAvaliacao(avaliacao_valida);
      if (avaliacao->getAvaliacao() != avaliacao_valida)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para a avaliação.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido de avaliação é fornecido. Caso o valor da avaliação seja alterado
 * mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a avaliação for inválido.
 */
void TUAvaliacao::testarCenarioValorInvalido() {
  try {
    avaliacao->setAvaliacao(avaliacao_invalida);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (avaliacao->getAvaliacao() == avaliacao_invalida)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe `Avaliacao`.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUAvaliacao::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//********************DATA********************

/**
 * @class TUData
 * @brief Classe de teste para a classe Data.
 *
 * A classe `TUData` realiza testes unitários para os métodos `setData` e `getData`
 * da classe `Data`, verificando se os valores válidos e inválidos são tratados corretamente.
 */

/**
 * @brief Inicializa o objeto `Data` e o estado do teste como SUCESSO.
 *
 * Este método cria uma instância da classe `Data` e define o estado inicial do teste
 * como `SUCESSO`.
 */
void TUData::setUp() {
  data = new Data();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `data`.
 */
void TUData::tearDown() {
  delete data;
}

/**
 * @brief Testa o comportamento com um valor válido para Data.
 *
 * Este método verifica se o método `setData` da classe `Data` funciona corretamente
 * quando um valor válido de data é fornecido. Se o valor armazenado no objeto
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a data for inválido.
 */
void TUData::testarCenarioValorValido() {
  try {
      data->setData(data_valida);
      if (data->getData() != data_valida)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para Data.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido de data é fornecido. Caso o valor da data seja alterado
 * mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a data for inválido.
 */
void TUData::testarCenarioValorInvalido() {
  try {
    data->setData(data_invalida);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (data->getData() == data_invalida)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe `Data`.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUData::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}



//***********************SENHA*********************

/**
 * @class TUSenha
 * @brief Classe de teste para a classe Senha.
 *
 * A classe `TUSenha` realiza testes unitários para os métodos `setSenha` e `getSenha`
 * da classe `Senha`, verificando o correto funcionamento para valores válidos e inválidos.
 */

/**
 * @brief Inicializa o objeto `Senha` e o estado do teste como SUCESSO.
 *
 * Este método cria uma instância da classe `Senha` e define o estado inicial do teste
 * como `SUCESSO`.
 */
void TUSenha::setUp() {
  senha = new Senha();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `senha`.
 */
void TUSenha::tearDown() {
  delete senha;
}

/**
 * @brief Testa o comportamento com um valor válido para Senha.
 *
 * Este método verifica se o método `setSenha` da classe `Senha` funciona corretamente
 * quando um valor válido de senha é fornecido. Se o valor armazenado no objeto
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a senha for inválido.
 */
void TUSenha::testarCenarioValorValido() {
  try {
      senha->setSenha(senha_valida);
      if (senha->getSenha() != senha_valida)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para Senha.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido de senha é fornecido. Caso o valor da senha seja alterado
 * mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para a senha for inválido.
 */
void TUSenha::testarCenarioValorInvalido() {
  try {
    senha->setSenha(senha_invalida);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (senha->getSenha() == senha_invalida)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe Senha.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUSenha::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//***************************CODIGO************************

/**
 * @class TUCodigo
 * @brief Classe de teste para a classe Codigo.
 *
 * A classe `TUCodigo` realiza testes unitários para os métodos `setCodigo` e `getCodigo`
 * da classe `Codigo`, verificando o comportamento quando valores válidos e inválidos são fornecidos.
 */

/**
 * @brief Inicializa o objeto `Codigo` e define o estado do teste como SUCESSO.
 *
 * Este método cria uma instância da classe `Codigo` e inicializa o estado do teste
 * como `SUCESSO`.
 */
void TUCodigo::setUp() {
  codigo = new Codigo();
  estado = SUCESSO;
}

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `codigo`.
 */
void TUCodigo::tearDown() {
  delete codigo;
}

/**
 * @brief Testa o comportamento com um valor válido para Codigo.
 *
 * Este método verifica se o método `setCodigo` da classe `Codigo` funciona corretamente
 * quando um valor válido é fornecido. Se o valor armazenado no objeto `codigo`
 * não for igual ao valor esperado, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para o código for inválido.
 */
void TUCodigo::testarCenarioValorValido() {
  try {
      codigo->setCodigo(codigo_valido);
      if (codigo->getCodigo() != codigo_valido)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

/**
 * @brief Testa o comportamento com um valor inválido para Codigo.
 *
 * Este método verifica se a exceção `invalid_argument` é lançada quando um
 * valor inválido é fornecido para o código. Caso o valor da variável `codigo`
 * seja alterado mesmo após a exceção, o teste falha.
 *
 * @throws invalid_argument Se o valor fornecido para o código for inválido.
 */
void TUCodigo::testarCenarioValorInvalido() {
  try {
    codigo->setCodigo(codigo_invalido);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (codigo->getCodigo() == codigo_invalido)
          estado = FALHA;
  }
}

/**
 * @brief Executa todos os testes da classe Codigo.
 *
 * Este método configura o ambiente de teste, executa os testes para valores válidos
 * e inválidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUCodigo::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}

//-------------------------TestesEntidades-----------------------------------

//FEITO POR LUCAS SANTANA CAMILO ALVES, MAT:211060666

//********************CONTA********************

/**
 * @class TUConta
 * @brief Classe de teste para a classe Conta.
 *
 * A classe `TUConta` realiza testes unitários para a classe `Conta`, verificando
 * o comportamento do armazenamento e recuperação da senha e do código da conta
 * por meio dos métodos `setSenha`, `getSenha`, `setCodigo` e `getCodigo`.
 */

/**
 * @brief Inicializa o objeto `Conta` e define o estado do teste como SUCESSO.
 *
 * Este método cria uma nova instância da classe `Conta` e define o estado do teste
 * como `SUCESSO`. É chamado antes de cada teste individual.
 */
void TUConta::setUp(){
    conta = new Conta();
    estado = SUCESSO;
    }

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `conta`. É chamado após cada teste individual.
 */
void TUConta::tearDown(){
    delete conta;
}

/**
 * @brief Testa o comportamento da conta com senha e código válidos.
 *
 * Este método realiza dois testes:
 * 1. Testa se a senha é configurada corretamente na conta e se a senha
 *    armazenada é igual à senha fornecida.
 * 2. Testa se o código é configurado corretamente na conta e se o código
 *    armazenado é igual ao código fornecido.
 *
 * Se algum dos testes falhar, o estado do teste é alterado para `FALHA`.
 */
void TUConta::testarCenario(){
    // Teste de senha valida
    Senha senha;
    senha.setSenha(senha_valida);
    conta->setSenha(senha);
    if(conta->getSenha().getSenha() != senha_valida) estado = FALHA;
    // Teste de Codigo valido
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    conta->setCodigo(codigo);
    if(conta->getCodigo().getCodigo() != codigo_valido ) estado = FALHA;
}

/**
 * @brief Executa todos os testes da classe Conta.
 *
 * Este método configura o ambiente de teste, executa os testes para a senha
 * e código válidos e depois limpa os recursos alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUConta::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************VIAGEM************************

/**
 * @class TUViagem
 * @brief Classe de teste para a classe Viagem.
 *
 * A classe `TUViagem` realiza testes unitários para a classe `Viagem`, verificando
 * o comportamento do armazenamento e recuperação do código, avaliação e nome de uma
 * viagem, utilizando os métodos `setCodigo`, `getCodigo`, `setAvaliacao`, `getAvaliacao`,
 * `setNome` e `getNome`.
 */

/**
 * @brief Inicializa o objeto `Viagem` e define o estado do teste como SUCESSO.
 *
 * Este método cria uma nova instância da classe `Viagem` e define o estado do teste
 * como `SUCESSO`. É chamado antes de cada teste individual.
 */
void TUViagem::setUp(){
    viagem = new Viagem();
    estado = SUCESSO;
    }

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `viagem`. É chamado após cada teste individual.
 */
void TUViagem::tearDown(){
    delete viagem;
}

/**
 * @brief Testa o comportamento da viagem com código, avaliação e nome válidos.
 *
 * Este método realiza três testes:
 * 1. Testa se o código é configurado corretamente na viagem e se o código
 *    armazenado é igual ao código fornecido.
 * 2. Testa se a avaliação é configurada corretamente na viagem e se a avaliação
 *    armazenada é igual à avaliação fornecida.
 * 3. Testa se o nome da viagem é configurado corretamente na viagem e se o nome
 *    armazenado é igual ao nome fornecido.
 *
 * Se algum dos testes falhar, o estado do teste é alterado para `FALHA`.
 */
void TUViagem::testarCenario(){
    // Teste de Codigo valido
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    viagem->setCodigo(codigo);
    if(viagem->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    viagem->setAvaliacao(avaliacao);
    if(viagem->getAvaliacao().getAvaliacao() != avaliacao_valida ) estado = FALHA;
    //Nome
    Nome nome;
    nome.setNome(nome_valido);
    viagem->setNome(nome);
    if(viagem->getNome().getNome() != nome_valido ) estado = FALHA;
}

/**
 * @brief Executa todos os testes da classe Viagem.
 *
 * Este método configura o ambiente de teste, executa os testes para código,
 * avaliação e nome válidos e depois limpa os recursos alocados. Retorna o
 * estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUViagem::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Destino************************

/**
 * @class TUDestino
 * @brief Classe de teste para a classe Destino.
 *
 * A classe `TUDestino` realiza testes unitários para os métodos de configuração de datas
 * da classe `Destino`, verificando se os valores de `DataInicio` e `DataFim` são
 * corretamente configurados e recuperados.
 */

/**
 * @brief Inicializa o objeto `Destino` e os valores de teste.
 *
 * Cria uma instância de `Destino`, define valores válidos para `DataInicio` e
 * `DataFim`, e inicializa o estado do teste como `SUCESSO`.
 */
void TUDestino::setUp(){
    destino = new Destino();
    estado = SUCESSO;
    }

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Libera a memória alocada para o objeto `destino` após a execução dos testes.
 */
void TUDestino::tearDown(){
    delete destino;
}

/**
 * @brief Testa os cenários de configuração de datas para o Destino.
 *
 * Testa se as datas de início e fim são configuradas corretamente, usando os
 * valores válidos definidos. Se as datas não forem configuradas corretamente,
 * o estado do teste é alterado para `FALHA`.
 *
 * @throws invalid_argument Se ocorrer um erro ao definir as datas.
 */
void TUDestino::testarCenario(){
    // Teste de Codigo valido
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    destino->setCodigo(codigo);
    if(destino->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de codigo valido
    Nome nome;
    nome.setNome(nome_valido);
    destino->setNome(nome);
    if(destino->getNome().getNome() != nome_valido) estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    destino->setAvaliacao(avaliacao);
    if(destino->getAvaliacao().getAvaliacao() != avaliacao_valida) estado = FALHA;
    // Teste de data valida
    Data data_fim;
    data_fim.setData(data_fim_valida);
    destino->setDataFim(data_fim);
    if(destino->getDataFim().getData() != data_fim_valida) estado = FALHA;
    // Teste de data valida
    Data data_inicio;
    data_inicio.setData(data_inicio_valida);
    destino->setDataInicio(data_inicio);
    if(destino->getDataInicio().getData() != data_inicio_valida) estado = FALHA;
}

/**
 * @brief Executa todos os testes para a classe Destino.
 *
 * Configura o ambiente de teste, executa o teste para as datas de início e fim,
 * e limpa os recursos após a execução. Retorna o estado final do teste.
 *
 * @return O estado do teste: `SUCESSO` ou `FALHA`.
 */
int TUDestino::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Hospedagem************************

/**
 * @class TUHospedagem
 * @brief Classe de teste para a classe Hospedagem.
 *
 * A classe `TUHospedagem` realiza testes unitários para a classe `Hospedagem`, verificando
 * o comportamento do armazenamento e recuperação do código, nome, avaliação e diária de uma
 * hospedagem, utilizando os métodos `setCodigo`, `getCodigo`, `setNome`, `getNome`,
 * `setAvaliacao`, `getAvaliacao`, `setDiaria` e `getDiaria`.
 */

/**
 * @brief Inicializa o objeto `Hospedagem` e define o estado do teste como SUCESSO.
 *
 * Este método cria uma nova instância da classe `Hospedagem` e define o estado do teste
 * como `SUCESSO`. É chamado antes de cada teste individual.
 */
void TUHospedagem::setUp(){
    hospedagem = new Hospedagem();
    estado = SUCESSO;
    }

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `hospedagem`. É chamado após cada teste individual.
 */
void TUHospedagem::tearDown(){
    delete hospedagem;
}

/**
 * @brief Testa o comportamento da hospedagem com código, nome, avaliação e diária válidos.
 *
 * Este método realiza quatro testes:
 * 1. Testa se o código é configurado corretamente na hospedagem e se o código
 *    armazenado é igual ao código fornecido.
 * 2. Testa se o nome é configurado corretamente na hospedagem e se o nome
 *    armazenado é igual ao nome fornecido.
 * 3. Testa se a avaliação é configurada corretamente na hospedagem e se a avaliação
 *    armazenada é igual à avaliação fornecida.
 * 4. Testa se a diária é configurada corretamente na hospedagem e se o valor
 *    armazenado da diária é igual ao valor fornecido.
 *
 * Se algum dos testes falhar, o estado do teste é alterado para `FALHA`.
 */
void TUHospedagem::testarCenario(){
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    hospedagem->setCodigo(codigo);
    if(hospedagem->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de codigo valido
    Nome nome;
    nome.setNome(nome_valido);
    hospedagem->setNome(nome);
    if(hospedagem->getNome().getNome() != nome_valido) estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    hospedagem->setAvaliacao(avaliacao);
    if(hospedagem->getAvaliacao().getAvaliacao() != avaliacao_valida ) estado = FALHA;
    // Teste de dinheiro valido
    Dinheiro dinheiro;
    dinheiro.setDinheiro(dinheiro_valido);
    hospedagem->setDiaria(dinheiro);
    if(hospedagem->getDiaria().getDinheiroView() != dinheiro_valido ) estado = FALHA;
}

/**
 * @brief Executa todos os testes da classe Hospedagem.
 *
 * Este método configura o ambiente de teste, executa os testes para código, nome,
 * avaliação e diária válidos e depois limpa os recursos alocados. Retorna o
 * estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUHospedagem::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Atividade************************

/**
 * @class TUAtividade
 * @brief Classe de teste para a classe Atividade.
 *
 * A classe `TUAtividade` realiza testes unitários para a classe `Atividade`, verificando
 * o comportamento do armazenamento e recuperação de código, nome, avaliação, preço,
 * duração, data e horário de uma atividade.
 */

/**
 * @brief Inicializa o objeto `Atividade` e define o estado do teste como SUCESSO.
 *
 * Este método cria uma nova instância da classe `Atividade` e define o estado do teste
 * como `SUCESSO`. É chamado antes de cada teste individual.
 */
void TUAtividade::setUp(){
    atividade = new Atividade();
    estado = SUCESSO;
    }

/**
 * @brief Destroi o objeto alocado durante os testes.
 *
 * Este método é chamado após a execução dos testes para liberar a memória
 * alocada para o objeto `atividade`. É chamado após cada teste individual.
 */
void TUAtividade::tearDown(){
    delete atividade;
}

/**
 * @brief Testa o comportamento da atividade com código, nome, avaliação, preço,
 *        duração, data e horário válidos.
 *
 * Este método realiza sete testes:
 * 1. Testa se o código é configurado corretamente na atividade e se o código
 *    armazenado é igual ao código fornecido.
 * 2. Testa se o nome é configurado corretamente na atividade e se o nome
 *    armazenado é igual ao nome fornecido.
 * 3. Testa se a avaliação é configurada corretamente na atividade e se a avaliação
 *    armazenada é igual à avaliação fornecida.
 * 4. Testa se o preço é configurado corretamente na atividade e se o valor
 *    armazenado do preço é igual ao valor fornecido.
 * 5. Testa se a duração é configurada corretamente na atividade e se a duração
 *    armazenada é igual à duração fornecida.
 * 6. Testa se a data é configurada corretamente na atividade e se a data
 *    armazenada é igual à data fornecida.
 * 7. Testa se o horário é configurado corretamente na atividade e se o horário
 *    armazenado é igual ao horário fornecido.
 *
 * Se algum dos testes falhar, o estado do teste é alterado para `FALHA`.
 */
void TUAtividade::testarCenario(){
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    atividade->setCodigo(codigo);
    if(atividade->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de codigo valido
    Nome nome;
    nome.setNome(nome_valido);
    atividade->setNome(nome);
    if(atividade->getNome().getNome() != nome_valido) estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    atividade->setAvaliacao(avaliacao);
    if(atividade->getAvaliacao().getAvaliacao() != avaliacao_valida) estado = FALHA;
    // Teste de dinheiro valido
    Dinheiro dinheiro;
    dinheiro.setDinheiro(dinheiro_valido);
    atividade->setPreco(dinheiro);
    if(atividade->getPreco().getDinheiroView() != dinheiro_valido) estado = FALHA;
    // Teste de duracao valida
    Duracao duracao;
    duracao.setDuracao(duracao_valida);
    atividade->setDuracao(duracao);
    if(atividade->getDuracao().getDuracao() != duracao_valida) estado = FALHA;
    // Teste de data valida
    Data data;
    data.setData(data_valida);
    atividade->setData(data);
    if(atividade->getData().getData() != data_valida ) estado = FALHA;
    Horario hora;
    hora.setHora(horario_valido);
    atividade->setHorario(hora);
    if(atividade->getHorario().getHora() != horario_valido) estado = FALHA;
    }

/**
 * @brief Executa todos os testes da classe Atividade.
 *
 * Este método configura o ambiente de teste, executa os testes para código, nome,
 * avaliação, preço, duração, data e horário válidos e depois limpa os recursos
 * alocados. Retorna o estado final do teste.
 *
 * @return O estado do teste, que pode ser `SUCESSO` ou `FALHA`.
 */
int TUAtividade::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}
