#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Classe responsável por gerenciar as contas do sistema.
 *
 * Esta classe implementa um contêiner para armazenar e gerenciar contas de usuários.
 * Ela segue o padrão Singleton para garantir que apenas uma instância seja criada.
 */
class ContainerConta {
    private:
        map<string, string> contas; ///< Mapa que armazena as contas (código -> senha).
        static ContainerConta *instancia; ///< Instância única do ContainerConta (Singleton).
        ContainerConta() {};    ///< Construtor privado para evitar instanciação externa.

    public:
        /**
         * @brief Obtém a instância única do ContainerConta (Singleton).
         *
         * @return Retorna um ponteiro para a instância única do ContainerConta.
         */
        static ContainerConta* getInstancia();
        /**
         * @brief Verifica se uma conta com o código fornecido já existe.
         *
         * @param codigo O código da conta a ser verificada.
         * @return Retorna true se a conta existir, false caso contrário.
         */
        bool hasConta(string codigo);

        /**
         * @brief Cria uma nova conta no sistema.
         *
         * @param codigo O código da nova conta.
         * @param senha A senha da nova conta.
         * @return Retorna true se a conta foi criada com sucesso, false caso contrário.
         */
        bool createConta(string codigo, string senha);

         /**
          * @brief Realiza o login de uma conta.
          *
          * @param codigo O código da conta.
          * @param senha A senha da conta.
          * @return Retorna o código da conta convertido para inteiro se o login for bem-sucedido, 0 caso contrário.
          */
        int logarConta(string codigo, string senha);
};

/**
 * @brief Classe responsável por gerenciar as viagens do sistema.
 *
 * Esta classe implementa um contêiner para armazenar e gerenciar viagens.
 * Ela segue o padrão Singleton para garantir que apenas uma instância seja criada.
 */
class ContainerViagem {
    private:
        map<string, vector<string>> viagens; ///< Mapa que armazena as viagens (código -> {nome, avaliação, código da conta}).
        static ContainerViagem *instancia; ///< Instância única do ContainerViagem (Singleton).
        ContainerViagem() {}; ///< Construtor privado para evitar instancia
    public:
        /**
         * @brief Obtém a instância única do ContainerViagem (Singleton).
         *
         * @return Retorna um ponteiro para a instância única do ContainerViagem.
         */
        static ContainerViagem* getInstancia();
        /**
         * @brief Verifica se uma viagem com o código fornecido já existe.
         *
         * @param codigo O código da viagem a ser verificada.
         * @return Retorna true se a viagem existir, false caso contrário.
         */
        bool hasViagem(string codigo);

        /**
         * @brief Cria uma nova viagem no sistema.
         *
         * @param codigo O código da nova viagem.
         * @param nome O nome da nova viagem.
         * @param avaliacao A avaliação da nova viagem.
         * @param codigoConta O código da conta associada à viagem.
         * @return Retorna true se a viagem foi criada com sucesso, false caso contrário.
         */
        bool createViagem(string codigo, string nome, string avaliacao, string codigoConta);

        /**
         * @brief Lista todas as viagens associadas a uma conta.
         *
         * @param codigoConta O código da conta para a qual as viagens serão listadas.
         */
        void listarViagens(string codigoConta);

        /**
         * @brief Obtém o código da conta associada a uma viagem.
         *
         * @param codigoViagem O código da viagem.
         * @return Retorna o código da conta associada à viagem.
         */
        string getConta(string codigoViagem);
};

/**
 * @brief Classe responsável por gerenciar os destinos do sistema.
 *
 * Esta classe implementa um contêiner para armazenar e gerenciar destinos.
 * Ela segue o padrão Singleton para garantir que apenas uma instância seja criada.
 */
class ContainerDestino {
    private:
        map<string, vector<string>> destinos; ///< Mapa que armazena os destinos (código -> {nome, data_inicio, data_final, avaliação, código da viagem}).
        static ContainerDestino *instancia; ///< Instância única do ContainerDestino (Singleton).
        ContainerDestino() {}; ///< Construtor privado para evitar instanciação externa.

    public:
        /**
         * @brief Obtém a instância única do ContainerDestino (Singleton).
         *
         * @return Retorna um ponteiro para a instância única do ContainerDestino.
         */
        static ContainerDestino* getInstancia();

        /**
         * @brief Verifica se um destino com o código fornecido já existe.
         *
         * @param codigo O código do destino a ser verificado.
         * @return Retorna true se o destino existir, false caso contrário.
         */
        bool hasDestino(string codigo);

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
        bool createDestino(string codigo, string nome, string data_inicio, string data_final, string avaliacao, string codigoViagem);

        /**
         * @brief Lista todos os destinos associados a uma viagem.
         *
         * @param codigoViagem O código da viagem para a qual os destinos serão listados.
         */
        void listarDestinos(string codigoViagem);

        /**
         * @brief Obtém o código da viagem associada a um destino.
         *
         * @param codigoDestino O código do destino.
         * @return Retorna o código da viagem associada ao destino.
         */
        string getViagem(string codigoDestino);
};

/**
 * @brief Classe responsável por gerenciar as hospedagens do sistema.
 *
 * Esta classe implementa um contêiner para armazenar e gerenciar hospedagens.
 * Ela segue o padrão Singleton para garantir que apenas uma instância seja criada.
 */
class ContainerHospedagem {
    private:
        map<string, vector<string>> hospedagens; ///< Mapa que armazena as hospedagens (código -> {nome, diária, avaliação, código do destino}).
        static ContainerHospedagem *instancia; ///< Instância única do ContainerHospedagem (Singleton).
        ContainerHospedagem() {}; ///< Construtor privado para evitar instanciação externa.
    public:
        /**
         * @brief Obtém a instância única do ContainerHospedagem (Singleton).
         *
         * @return Retorna um ponteiro para a instância única do ContainerHospedagem.
         */
        static ContainerHospedagem* getInstancia();

        /**
         * @brief Verifica se uma hospedagem com o código fornecido já existe.
         *
         * @param codigo O código da hospedagem a ser verificada.
         * @return Retorna true se a hospedagem existir, false caso contrário.
         */
        bool hasHospedagem(string codigo);

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
        bool createHospedagem(string codigo, string nome, string diaria, string avaliacao, string codigoDestino);

        /**
         * @brief Lista todas as hospedagens associadas a um destino.
         *
         * @param codigoDestino O código do destino para o qual as hospedagens serão listadas.
         */
        void listarHospedagens(string codigoDestino);
};

/**
 * @brief Classe responsável por gerenciar as atividades do sistema.
 *
 * Esta classe implementa um contêiner para armazenar e gerenciar atividades.
 * Ela segue o padrão Singleton para garantir que apenas uma instância seja criada.
 */
class ContainerAtividade {
    private:
        map<string, vector<string>> atividades; ///< Mapa que armazena as atividades (código -> {nome, data, horário, duração, preço, avaliação, código do destino}).
        static ContainerAtividade *instancia; ///< Instância única do ContainerAtividade (Singleton).
        ContainerAtividade() {}; ///< Construtor privado para evitar instanciação externa.
    public:
        /**
         * @brief Obtém a instância única do ContainerAtividade (Singleton).
         *
         * @return Retorna um ponteiro para a instância única do ContainerAtividade.
         */
        static ContainerAtividade* getInstancia();

        /**
         * @brief Verifica se uma atividade com o código fornecido já existe.
         *
         * @param codigo O código da atividade a ser verificada.
         * @return Retorna true se a atividade existir, false caso contrário.
         */
        bool hasAtividade(string codigo);

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
        bool createAtividade(string codigo, string nome, string data, string horario, string duracao, string preco, string avaliacao, string codigoDestino);

        /**
         * @brief Lista todas as atividades associadas a um destino.
         *
         * @param codigoDestino O código do destino para o qual as atividades serão listadas.
         */
        void listarAtividades(string codigoDestino);
};

#endif // CONTAINER_HPP_INCLUDED
