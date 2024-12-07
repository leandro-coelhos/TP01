#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

/**
 * @include <string>
 * Biblioteca usada para manipulação de strings.
 */
#include <string>

/**
 * @include <stdexcept>
 * Biblioteca usada para lançamento de exceções.
 */
#include <stdexcept>

/**
 * @include "dominios.hpp"
 * Arquivo que define os domínios usados como atributos nas entidades.
 */
#include "dominios.hpp"

/**
 * @include "entidades.hpp"
 * Arquivo que define as entidades do sistema.
 */
#include "entidades.hpp"

using namespace std;

//-------------------------TestesDomínio-----------------------------------

//FEITO POR EDUARDO LUNA SCALASSARA, MAT:232011289

//********************HORARIO********************

/**
 * @class TUHorario
 * @brief Classe de teste para a classe Horario.
 *
 * Esta classe contém os testes unitários para a classe Horario, verificando os cenários de valores válidos e inválidos.
 * A classe realiza a configuração inicial e a limpeza após a execução de cada teste.
 */
class TUHorario {
    private:

        /** @brief Valor de hora válido utilizado para testes. */
        const static string horario_valido;

        /** @brief Valor de hora inválido utilizado para testes. */
        const static string horario_invalido;

        /** @brief Ponteiro para o objeto Horario sendo testado. */
        Horario *horario;

        /** @brief Estado do teste (SUCESSO ou FALHA). */
        int estado;
        /**
        * @brief Configura o ambiente de teste inicializando o objeto Horario.
        *
        * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
        */
        void setUp();

        /**
         * @brief Libera a memória utilizada pelo objeto Horario após o teste.
         *
         * Este método é chamado após cada execução de teste para realizar a limpeza.
         */
        void tearDown();

        /**
         * @brief Testa o cenário com valor válido de hora.
         *
         * Este método configura o objeto Horario com um valor válido de hora e verifica se o valor foi corretamente armazenado.
         * Caso contrário, altera o estado para FALHA.
         */
        void testarCenarioValorValido();

        /**
         * @brief Testa o cenário com valor inválido de hora.
         *
         * Este método tenta configurar o objeto Horario com um valor inválido de hora e verifica se a exceção apropriada é lançada.
         * Caso contrário, altera o estado para FALHA.
         */
        void testarCenarioValorInvalido();
    public:
        /** @brief Constante que representa o estado de sucesso do teste. */
        const static int SUCESSO = 0;

        /** @brief Constante que representa o estado de falha do teste. */
        const static int FALHA = -1;

        /**
         * @brief Executa todos os testes da classe TUHorario.
         *
         * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
         *
         * @return int O estado final do teste (SUCESSO ou FALHA).
         */
        int run();
};

//********************DINHEIRO********************

/**
 * @class TUDinheiro
 * @brief Classe de teste para a classe Dinheiro.
 *
 * Esta classe contém os testes unitários para a classe Dinheiro, verificando os cenários de valores válidos e inválidos.
 * A classe realiza a configuração inicial e a limpeza após a execução de cada teste.
 */
class TUDinheiro
{
private:
    /** @brief Valor de dinheiro válido utilizado para testes. */
    const static string dinheiro_valido;

    /** @brief Valor de dinheiro inválido utilizado para testes. */
    const static string dinheiro_invalido;

    /** @brief Ponteiro para o objeto Dinheiro sendo testado. */
    Dinheiro *dinheiro;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Dinheiro.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Dinheiro após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido de dinheiro.
     *
     * Este método configura o objeto Dinheiro com um valor válido de dinheiro e verifica se o valor foi corretamente armazenado.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido de dinheiro.
     *
     * Este método tenta configurar o objeto Dinheiro com um valor inválido de dinheiro e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUDinheiro.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************NOME********************

/**
 * @class TUNome
 * @brief Classe de teste para a classe Nome.
 *
 * Esta classe contém os testes unitários para a classe Nome, verificando os cenários de valores válidos e inválidos.
 * A classe realiza a configuração inicial e a limpeza após a execução de cada teste.
 */
class TUNome
{
private:
    /** @brief Nome válido utilizado para testes. */
    const static string nome_valido;

    /** @brief Nome inválido utilizado para testes. */
    const static string nome_invalido;

    /** @brief Ponteiro para o objeto Nome sendo testado. */
    Nome *nome;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Nome.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Nome após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para o Nome.
     *
     * Este método configura o objeto Nome com um valor válido e verifica se o nome foi corretamente armazenado.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para o Nome.
     *
     * Este método tenta configurar o objeto Nome com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUNome.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************DURACAO********************

/**
 * @class TUDuracao
 * @brief Classe de teste para a classe Duracao.
 *
 * Esta classe realiza testes unitários para a classe Duracao, verificando se os cenários de valores válidos e inválidos são corretamente tratados.
 * A classe realiza a configuração do ambiente de teste antes da execução e a limpeza após a execução de cada teste.
 */
class TUDuracao
{
private:
    /** @brief Duracao válida utilizada para os testes. */
    const static string duracao_valida;

    /** @brief Duracao inválida utilizada para os testes. */
    const static string duracao_invalida;

    /** @brief Ponteiro para o objeto Duracao sendo testado. */
    Duracao *duracao;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Duracao.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Duracao após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para Duracao.
     *
     * Este método configura o objeto Duracao com um valor válido e verifica se a duração foi corretamente armazenada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para Duracao.
     *
     * Este método tenta configurar o objeto Duracao com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUDuracao.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************AVALIACAO********************

/**
 * @class TUAvaliacao
 * @brief Classe de teste para a classe Avaliacao.
 *
 * Esta classe realiza testes unitários para a classe Avaliacao, verificando se os cenários de valores válidos e inválidos são corretamente tratados.
 * A classe configura o ambiente de teste antes da execução e a limpeza após a execução de cada teste.
 */
class TUAvaliacao
{
private:
    /** @brief Avaliacao válida utilizada para os testes. */
    const static string avaliacao_valida;

    /** @brief Avaliacao inválida utilizada para os testes. */
    const static string avaliacao_invalida;

    /** @brief Ponteiro para o objeto Avaliacao sendo testado. */
    Avaliacao *avaliacao;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Avaliacao.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Avaliacao após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para Avaliacao.
     *
     * Este método configura o objeto Avaliacao com um valor válido e verifica se a avaliação foi corretamente armazenada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para Avaliacao.
     *
     * Este método tenta configurar o objeto Avaliacao com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUAvaliacao.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************DATA********************

/**
 * @class TUData
 * @brief Classe de teste para a classe Data.
 *
 * Esta classe realiza testes unitários para a classe Data, verificando se os cenários de valores válidos e inválidos são corretamente tratados.
 * A classe configura o ambiente de teste antes da execução e realiza a limpeza após a execução de cada teste.
 */
class TUData
{
private:
    /** @brief Data válida utilizada para os testes. */
    const static string data_valida;

    /** @brief Data inválida utilizada para os testes. */
    const static string data_invalida;

    /** @brief Ponteiro para o objeto Data sendo testado. */
    Data *data;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Data.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Data após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para Data.
     *
     * Este método configura o objeto Data com um valor válido e verifica se a data foi corretamente armazenada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para Data.
     *
     * Este método tenta configurar o objeto Data com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUData.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************SENHA********************

/**
 * @class TUSenha
 * @brief Classe de teste para a classe Senha.
 *
 * Esta classe realiza testes unitários para a classe Senha, verificando se os cenários de valores válidos e inválidos são corretamente tratados.
 * A classe configura o ambiente de teste antes da execução e realiza a limpeza após a execução de cada teste.
 */
class TUSenha
{
private:
    /** @brief Senha válida utilizada para os testes. */
    const static string senha_valida;

    /** @brief Senha inválida utilizada para os testes. */
    const static string senha_invalida;

    /** @brief Ponteiro para o objeto Senha sendo testado. */
    Senha *senha;

    /** @brief Estado do teste (SUCESSO ou FALHA). */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Senha.
     *
     * Este método é chamado antes de cada execução de teste para preparar o ambiente necessário.
     */
    void setUp();

    /**
     * @brief Libera a memória utilizada pelo objeto Senha após o teste.
     *
     * Este método é chamado após cada execução de teste para realizar a limpeza.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para Senha.
     *
     * Este método configura o objeto Senha com um valor válido e verifica se a senha foi corretamente armazenada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para Senha.
     *
     * Este método tenta configurar o objeto Senha com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para FALHA.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe TUSenha.
     *
     * Este método chama todos os testes de cenário de valor válido e inválido. Após a execução dos testes, o estado final é retornado.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************CÓDIGO********************

/**
 * @class TUCodigo
 * @brief Classe de teste para a classe Codigo.
 *
 * Esta classe realiza os testes unitários para a classe `Codigo`. O objetivo é garantir que a classe `Codigo` funcione corretamente
 * para valores válidos e inválidos. O teste inclui a configuração de um objeto `Codigo` com valores válidos e inválidos e a
 * verificação do comportamento esperado para cada cenário.
 */
class TUCodigo
{
private:
    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Código inválido para os testes. */
    const static string codigo_invalido;

    /** @brief Objeto de teste da classe Codigo. */
    Codigo *codigo;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Codigo.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valor válido para o Codigo.
     *
     * Configura a classe `Codigo` com um valor válido e verifica se o valor é corretamente armazenado.
     * Caso contrário, altera o estado para `FALHA`.
     */
    void testarCenarioValorValido();

    /**
     * @brief Testa o cenário com valor inválido para o Codigo.
     *
     * Configura a classe `Codigo` com um valor inválido e verifica se a exceção apropriada é lançada.
     * Caso contrário, altera o estado para `FALHA`.
     */
    void testarCenarioValorInvalido();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUCodigo`.
     *
     * Este método chama os métodos de teste para cenários de valores válidos e inválidos.
     * Após a execução, ele retorna o estado do teste, que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//-------------------------TestesEntidades-----------------------------------

//FEITO POR LUCAS SANTANA CAMILO ALVES, MAT:211060666

// ********************CONTA********************

/**
 * @class TUConta
 * @brief Classe de teste para a classe Conta.
 *
 * Esta classe realiza testes unitários para a classe `Conta`. O objetivo é garantir que a classe `Conta` funcione corretamente
 * quando associada a uma senha e a um código válidos. O teste inclui a configuração de uma `Conta` com valores válidos e a
 * verificação do comportamento esperado.
 */
class TUConta
{
private:
    /** @brief Senha válida para os testes. */
    const static string senha_valida;

    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Objeto de teste da classe Conta. */
    Conta *conta;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Conta.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valores válidos para Senha e Código na Conta.
     *
     * Configura a classe `Conta` com uma senha e um código válidos e verifica se os valores são corretamente armazenados.
     * Caso contrário, altera o estado para `FALHA`.
     */
    void testarCenario();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUConta`.
     *
     * Este método chama os métodos de teste para o cenário com valores válidos.
     * Após a execução, ele retorna o estado do teste, que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//********************VIAGEM********************

/**
 * @class TUViagem
 * @brief Classe de teste para a classe Viagem.
 *
 * Esta classe realiza testes unitários para a classe `Viagem`. O objetivo é garantir que a classe `Viagem` funcione corretamente
 * quando associada a valores válidos para código, nome e avaliação. O teste inclui a configuração de uma `Viagem` com esses valores
 * e a verificação do comportamento esperado.
 */
class TUViagem
{
private:
    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Nome válido para os testes. */
    const static string nome_valido;

    /** @brief Avaliação válida para os testes. */
    const static string avaliacao_valida;

    /** @brief Objeto de teste da classe Viagem. */
    Viagem *viagem;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Viagem.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valores válidos para Código, Nome e Avaliação na Viagem.
     *
     * Configura a classe `Viagem` com um código, nome e avaliação válidos e verifica se os valores são corretamente
     * armazenados. Caso contrário, altera o estado para `FALHA`.
     */
    void testarCenario();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUViagem`.
     *
     * Este método chama os métodos de teste para o cenário com valores válidos.
     * Após a execução, ele retorna o estado do teste, que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//***************************Destino************************

/**
 * @class TUDestino
 * @brief Classe de teste para a classe Destino.
 *
 * Esta classe realiza testes unitários para a classe `Destino`. O objetivo é garantir que a classe `Destino` funcione corretamente
 * quando associada a valores válidos para código, nome, datas de início e fim e avaliação. O teste inclui a configuração de um `Destino`
 * com esses valores e a verificação do comportamento esperado.
 */
class TUDestino
{
private:
    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Nome válido para os testes. */
    const static string nome_valido;

    /** @brief Data de início válida para os testes. */
    const static string data_inicio_valida;

    /** @brief Data de fim válida para os testes. */
    const static string data_fim_valida;

    /** @brief Avaliação válida para os testes. */
    const static string avaliacao_valida;

    /** @brief Objeto de teste da classe Destino. */
    Destino *destino;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Destino.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valores válidos para Código, Nome, Data de Início, Data de Fim e Avaliação no Destino.
     *
     * Configura a classe `Destino` com um código, nome, datas válidas e avaliação válida, e verifica se os valores são corretamente
     * armazenados. Caso contrário, altera o estado para `FALHA`.
     */
    void testarCenario();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUDestino`.
     *
     * Este método chama os métodos de teste para o cenário com valores válidos.
     * Após a execução, ele retorna o estado do teste, que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//***************************Atividade************************

/**
 * @class TUAtividade
 * @brief Classe de teste para a classe Atividade.
 *
 * Esta classe realiza testes unitários para a classe `Atividade`. O objetivo é garantir que a classe `Atividade` funcione corretamente
 * quando associada a valores válidos para código, nome, horário, data, duração, dinheiro e avaliação. O teste inclui a configuração
 * de um objeto `Atividade` com esses valores e a verificação do comportamento esperado.
 */
class TUAtividade
{
private:
    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Nome válido para os testes. */
    const static string nome_valido;

    /** @brief Horário válido para os testes. */
    const static string horario_valido;

    /** @brief Data válida para os testes. */
    const static string data_valida;

    /** @brief Duração válida para os testes. */
    const static string duracao_valida;

    /** @brief Dinheiro válido para os testes. */
    const static string dinheiro_valido;

    /** @brief Avaliação válida para os testes. */
    const static string avaliacao_valida;

    /** @brief Objeto de teste da classe Atividade. */
    Atividade *atividade;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Atividade.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valores válidos para Código, Nome, Horário, Data, Duração, Dinheiro e Avaliação na Atividade.
     *
     * Configura a classe `Atividade` com os valores válidos e verifica se os valores são corretamente armazenados. Caso contrário,
     * altera o estado para `FALHA`.
     */
    void testarCenario();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUAtividade`.
     *
     * Este método chama os métodos de teste para o cenário com valores válidos. Após a execução, ele retorna o estado do teste,
     * que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};

//***************************Hospedagem************************

/**
 * @class TUHospedagem
 * @brief Classe de teste para a classe Hospedagem.
 *
 * Esta classe realiza os testes unitários para a classe `Hospedagem`. O objetivo é verificar se a classe `Hospedagem` funciona corretamente
 * com valores válidos para código, nome, avaliação e dinheiro. O teste inclui a configuração de um objeto `Hospedagem` com esses valores e a
 * verificação do comportamento esperado.
 */
class TUHospedagem
{
private:
    /** @brief Código válido para os testes. */
    const static string codigo_valido;

    /** @brief Nome válido para os testes. */
    const static string nome_valido;

    /** @brief Dinheiro válido para os testes. */
    const static string dinheiro_valido;

    /** @brief Avaliação válida para os testes. */
    const static string avaliacao_valida;

    /** @brief Objeto de teste da classe Hospedagem. */
    Hospedagem *hospedagem;

    /** @brief Estado do teste, representando sucesso ou falha. */
    int estado;

    /**
     * @brief Configura o ambiente de teste inicializando o objeto Hospedagem.
     *
     * Este método é chamado antes de cada execução de teste para preparar o objeto necessário para o teste.
     */
    void setUp();

    /**
     * @brief Realiza a limpeza após o teste, liberando a memória alocada.
     *
     * Este método é chamado após a execução de cada teste para garantir que todos os recursos sejam liberados corretamente.
     */
    void tearDown();

    /**
     * @brief Testa o cenário com valores válidos para Código, Nome, Avaliação e Dinheiro na Hospedagem.
     *
     * Configura a classe `Hospedagem` com os valores válidos e verifica se os valores são corretamente armazenados. Caso contrário,
     * altera o estado para `FALHA`.
     */
    void testarCenario();

public:
    /** @brief Constante que representa o estado de sucesso do teste. */
    const static int SUCESSO = 0;

    /** @brief Constante que representa o estado de falha do teste. */
    const static int FALHA = -1;

    /**
     * @brief Executa todos os testes da classe `TUHospedagem`.
     *
     * Este método chama os métodos de teste para o cenário com valores válidos. Após a execução, ele retorna o estado do teste,
     * que pode ser `SUCESSO` ou `FALHA`.
     *
     * @return int O estado final do teste (SUCESSO ou FALHA).
     */
    int run();
};
#endif // TESTES_HPP_INCLUDED;
