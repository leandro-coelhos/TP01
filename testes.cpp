#include "entidades.hpp"
#include "testes.hpp"
#include "dominios.hpp"

//DINHERIO E CODIGO FALHARAM NOS TESTES

const string TUHorario::horario_valido = "12:35";
const string TUHorario::horario_invalido = "99:99";

const string TUDinheiro::dinheiro_valido = "13,00";
const string TUDinheiro::dinheiro_invalido = "999.999,99";

const string TUNome::nome_valido = "joao";
const string TUNome::nome_invalido = "hjkhiguhgihunijnjinjijkhjkhkhkj";

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

//*****************HORARIO*****************
void TUHorario::setUp() {
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown() {
    delete horario;
}

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

int TUHorario::run() {
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}



//****************DINHEIRO*****************


void TUDinheiro::setUp() {
  dinheiro = new Dinheiro();
  estado = SUCESSO;
}

void TUDinheiro::tearDown() {
  delete dinheiro;
}

void TUDinheiro::testarCenarioValorValido() {
  try {
      dinheiro->setDinheiro(dinheiro_valido);
      if (dinheiro->getDinheiro() != dinheiro_valido)
          estado = FALHA;
  }
  catch(invalid_argument &excecao){
      estado = FALHA;
  }
}

void TUDinheiro::testarCenarioValorInvalido() {
  try {
    dinheiro->setDinheiro(dinheiro_invalido);
    estado = FALHA;
  }
  catch(invalid_argument &excecao) {
      if (dinheiro->getDinheiro() == dinheiro_invalido)
          estado = FALHA;
  }
}

int TUDinheiro::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//******************NOME************************


void TUNome::setUp() {
  nome = new Nome();
  estado = SUCESSO;
}

void TUNome::tearDown() {
  delete nome;
}

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

int TUNome::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}

//*********************DURACAO********************


void TUDuracao::setUp() {
  duracao = new Duracao();
  estado = SUCESSO;
}

void TUDuracao::tearDown() {
  delete duracao;
}

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

int TUDuracao::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//********************AVALIACAO********************

void TUAvaliacao::setUp() {
  avaliacao = new Avaliacao();
  estado = SUCESSO;
}

void TUAvaliacao::tearDown() {
  delete avaliacao;
}

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

int TUAvaliacao::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//********************DATA********************

void TUData::setUp() {
  data = new Data();
  estado = SUCESSO;
}

void TUData::tearDown() {
  delete data;
}

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

int TUData::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}



//***********************SENHA*********************


void TUSenha::setUp() {
  senha = new Senha();
  estado = SUCESSO;
}

void TUSenha::tearDown() {
  delete senha;
}

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

int TUSenha::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}


//***************************CODIGO************************


void TUCodigo::setUp() {
  codigo = new Codigo();
  estado = SUCESSO;
}

void TUCodigo::tearDown() {
  delete codigo;
}

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

int TUCodigo::run() {
  setUp();
  testarCenarioValorValido();
  testarCenarioValorInvalido();
  tearDown();
  return estado;
}

// ********************CONTA********************

void TUConta::setUp(){
    Conta * conta = new Conta();
    estado = SUCESSO;
    }

void TUConta::tearDown(){
    delete conta;
}

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

int TUConta::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************VIAGEM************************

void TUViagem::setUp(){
    Viagem * viagem = new Viagem();
    estado = SUCESSO;
    }

void TUViagem::tearDown(){
    delete viagem;
}

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
    if(viagem->getAvalicao().getAvaliacao() != avaliacao_valida ) estado = FALHA;
    //Nome
    Nome nome;
    nome.setNome(nome_valido);
    viagem->setNome(nome);
    if(viagem->getNome().getNome() != nome_valido ) estado = FALHA;
}

int TUViagem::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Destino************************

void TUDestino::setUp(){
    Destino * destino = new Destino();
    estado = SUCESSO;
    }

void TUDestino::tearDown(){
    delete destino;
}

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
    estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    destino->setAvaliacao(avaliacao);
    if(destino->getAvalicao().getAvaliacao() != avaliacao_valida) estado = FALHA;
    // Teste de data valida
    Data data_fim;
    data_fim.setData(data_fim_valida);
    destino->setDataFim(data_fim);
    if(destino->getDataFim().getData() != data_fim_valida) estado = FALHA;
    // Teste de data valida
    Data data_inicio;
    data_inicio.setData(data_inicio_valida);
    destino->setDataFim(data_inicio);
    if(destino->getDataInicio().getData() != data_inicio_valida) estado = FALHA;
}

int TUDestino::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Hospedagem************************

void TUHospedagem::setUp(){
    Hospedagem * hospedagem = new Hospedagem();
    estado = SUCESSO;
    }

void TUHospedagem::tearDown(){
    delete hospedagem;
}

void TUHospedagem::testarCenario(){
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    hospedagem->setCodigo(codigo);
    if(hospedagem->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de codigo valido
    Nome nome;
    nome.setNome(nome_valido);
    hospedagem->setNome(nome);
    if(hospedagem->getNome().getNome() != nome_valido) estado = FALHA; estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    hospedagem->setAvaliacao(avaliacao);
    if(hospedagem->getAvalicao().getAvaliacao() != avaliacao_valida ) estado = FALHA;
    // Teste de dinheiro valido
    Dinheiro dinheiro;
    dinheiro.setDinheiro(dinheiro_valido);
    hospedagem->setDiaria(dinheiro);
    if(hospedagem->getDiaria().getDinheiro() != dinheiro_valido ) estado = FALHA;
}

int TUHospedagem::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}

//***************************Atividade************************

void TUAtividade::setUp(){
    Atividade * atividade = new Atividade();
    estado = SUCESSO;
    }

void TUAtividade::tearDown(){
    delete atividade;
}

void TUAtividade::testarCenario(){
    Codigo codigo;
    codigo.setCodigo(codigo_valido);
    atividade->setCodigo(codigo);
    if(atividade->getCodigo().getCodigo() != codigo_valido) estado = FALHA;
    // Teste de codigo valido
    Nome nome;
    nome.setNome(nome_valido);
    atividade->setNome(nome);
    if(atividade->getNome().getNome() != nome_valido) estado = FALHA; estado = FALHA;
    // Teste de avaliacao valida
    Avaliacao avaliacao;
    avaliacao.setAvaliacao(avaliacao_valida);
    atividade->setAvaliacao(avaliacao);
    if(atividade->getAvalicao().getAvaliacao() != avaliacao_valida) estado = FALHA;
    // Teste de dinheiro valido
    Dinheiro dinheiro;
    dinheiro.setDinheiro(dinheiro_valido);
    atividade->setPreco(dinheiro);
    if(atividade->getPreco().getDinheiro() != dinheiro_valido) estado = FALHA;
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

int TUAtividade::run() {
  setUp();
  testarCenario();
  tearDown();
  return estado;
}
