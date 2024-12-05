#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

#include <string>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class TUHorario {
    private:
        const static string horario_valido;
        const static string horario_invalido;
        Horario *horario;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUDinheiro {
    private:
        const static string dinheiro_valido;
        const static string dinheiro_invalido;
        Dinheiro *dinheiro;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


class TUNome {
    private:
        const static string nome_valido;
        const static string nome_invalido;
        Nome *nome;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUDuracao {
    private:
        const static string duracao_valida;
        const static string duracao_invalida;
        Duracao *duracao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUAvaliacao {
    private:
        const static string avaliacao_valida;
        const static string avaliacao_invalida;
        Avaliacao *avaliacao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUData {
    private:
        const static string data_valida;
        const static string data_invalida;

        Data *data;

        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUSenha {
    private:
        const static string senha_valida;
        const static string senha_invalida;
        Senha *senha;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUCodigo {
    private:
        const static string codigo_valido;
        const static string codigo_invalido;
        Codigo *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};



//Entidades Teste

class TUConta {
    private:
        const static string senha_valida; // Defini��o de uma senha v�lida
        const static string codigo_valido;
        Conta *conta; // Refer�ncia para unidade em teste.
        int estado; // Estado do teste. void setUp(); // M�todo para criar unidade em teste.
        void setUp();
        void tearDown(); // M�todo para destruir unidade em teste.
        void testarCenario(); // Cen�rio de teste.
    public:
        const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
        const static int FALHA = -1; // Defini��o de constante para reportar resultado.
        int run();
};

class TUViagem {
    private:
        const static string codigo_valido;
        const static string nome_valido;
        const static string avaliacao_valida;
        Viagem *viagem; // Refer�ncia para unidade em teste.
        int estado; // Estado do teste. void setUp(); // M�todo para criar unidade em teste.
        void setUp();
        void tearDown(); // M�todo para destruir unidade em teste.
        void testarCenario(); // Cen�rio de teste.
    public:
        const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
        const static int FALHA = -1; // Defini��o de constante para reportar resultado.
        int run();
};

class TUDestino {
    private:
        const static string codigo_valido;
        const static string nome_valido;
        const static string data_inicio_valida;
        const static string data_fim_valida;
        const static string avaliacao_valida;
        Destino *destino; // Refer�ncia para unidade em teste.
        int estado; // Estado do teste. void setUp(); // M�todo para criar unidade em teste.
        void setUp();
        void tearDown(); // M�todo para destruir unidade em teste.
        void testarCenario(); // Cen�rio de teste.
    public:
        const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
        const static int FALHA = -1; // Defini��o de constante para reportar resultado.
        int run();
};

class TUAtividade {
    private:
        const static string codigo_valido;
        const static string nome_valido;
        const static string horario_valido;
        const static string data_valida;
        const static string duracao_valida;
        const static string dinheiro_valido;
        const static string avaliacao_valida;
        Atividade *atividade; // Refer�ncia para unidade em teste.
        int estado; // Estado do teste. void setUp(); // M�todo para criar unidade em teste.
        void setUp();
        void tearDown(); // M�todo para destruir unidade em teste.
        void testarCenario(); // Cen�rio de teste.
    public:
        const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
        const static int FALHA = -1; // Defini��o de constante para reportar resultado.
        int run();
};

class TUHospedagem {
    private:
        const static string codigo_valido;
        const static string nome_valido;
        const static string dinheiro_valido;
        const static string avaliacao_valida;
        Hospedagem *hospedagem; // Refer�ncia para unidade em teste.
        int estado; // Estado do teste. void setUp(); // M�todo para criar unidade em teste.
        void setUp();
        void tearDown(); // M�todo para destruir unidade em teste.
        void testarCenario(); // Cen�rio de teste.
    public:
        const static int SUCESSO = 0; // Defini��o de constante para reportar resultado.
        const static int FALHA = -1; // Defini��o de constante para reportar resultado.
        int run();
};
#endif // TESTES_HPP_INCLUDED;
