#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include "dominios.hpp"

using namespace std;

/**
 * @brief Classe que representa uma Conta no sistema.
 *
 * Contém os métodos e atributos que definem uma conta,
 * incluindo o codigo e a senha.
 */
class Conta { //LEANDRO COELHO DA SILVA, MAT:232011396
    private:
        /**
         * @brief Código identificador único da conta.
         */
        Codigo codigo;

        /**
         * @brief Senha associado à conta.
         */
        Senha senha;
    public:
        /**
         * @brief Define o código da conta.
         *
         * @param codigo Código que será associado à conta.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Recupera o código da conta.
         *
         * @return Código atual da conta.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define a senha da conta.
         *
         * @param senha Senha que será associada à conta.
         */
        void setSenha(const Senha&);

        /**
         * @brief Recupera a senha da conta.
         *
         * @return Senha atual da conta.
         */
        Senha getSenha() const;

        /**
         * @brief Cria uma conta.
         *
         * @param codigo Código que será associado à conta.
         * @param senha Senha que será associada à conta.
         */
        void setConta(const Codigo&, const Senha&);


        /**
         * @brief Loga em uma conta.
         *
         * @param codigo Código atual da conta.
         * @param senha Senha atual da conta.
         */
        void getConta(Codigo&, Senha&) const;
};

/**
 * @brief Classe que representa uma Viagem.
 *
 * Contém informações sobre a viagem, como cdigo, avaliação e nome.
 */
class Viagem { //LEANDRO COELHO DA SILVA, MAT:232011396
    private:
        /**
         * @brief C�digo identificador da viagem.
         */
        Codigo codigo;

        /**
         * @brief Avalia��o atribu�da � viagem.
         */
        Avaliacao avaliacao;

        /**
         * @brief Nome associado � viagem.
         */
        Nome nome;

    public:
        /**
         * @brief Define o c�digo da viagem.
         *
         * @param codigo C�digo que ser� associado � viagem.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Recupera o código da viagem.
         *
         * @return Código atual da viagem.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define a avaliação da viagem.
         *
         * @param avaliacao Avaliação que será associado à viagem.
         */
        void setAvaliacao(const Avaliacao&);

        /**
         * @brief Recupera a avaliação da viagem.
         *
         * @return Avaliação atual da viagem.
         */
        Avaliacao getAvaliacao() const;

        /**
         * @brief Define o nome da viagem.
         *
         * @param nome Nome que será associado à viagem.
         */
        void setNome(const Nome&);

        /**
         * @brief Recupera o nome da viagem.
         *
         * @return Nome atual da viagem.
         */
        Nome getNome() const;
};

/**
 * @brief Classe que representa uma Hospedagem.
 *
 * Contém informações sobre a hospedagem, incluindo código, avaliação, nome e valor da diária.
 */
class Hospedagem { //LEANDRO COELHO DA SILVA, MAT:232011396
    private:
        /**
         * @brief Código identificador da hospedagem.
         */
        Codigo codigo;

        /**
         * @brief Avaliação atribuída à hospedagem.
         */
        Avaliacao avaliacao;

        /**
         * @brief Nome associado à hospedagem.
         */
        Nome nome;

        /**
         * @brief Valor da diária da hospedagem.
         */
        Dinheiro diaria;
    public:
        /**
         * @brief Define o código da hospedagem.
         *
         * @param codigo Código que será associado à hospedagem.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Recupera o código da hospedagem.
         *
         * @return Código atual da hospedagem.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define a avaliação da hospedagem.
         *
         * @param avaliacao Avaliação que será associado à hospedagem.
         */
        void setAvaliacao(const Avaliacao&);

        /**
         * @brief Recupera a avaliação da hospedagem.
         *
         * @return Avaliação atual da hospedagem.
         */
        Avaliacao getAvaliacao() const;

        /**
         * @brief Define o nome da hospedagem.
         *
         * @param nome Nome que será associado à hospedagem.
         */
        void setNome(const Nome&);

        /**
         * @brief Recupera o nome da hospedagem.
         *
         * @return Nome atual da hospedagem.
         */
        Nome getNome() const;

        /**
         * @brief Define o valor da diária da hospedagem.
         *
         * @param diaria Valor da diária que será associado à hospedagem.
         */
        void setDiaria(const Dinheiro&);

        /**
         * @brief Recupera o valor da diária da hospedagem.
         *
         * @return Valor atual da diária da hospedagem.
         */
        Dinheiro getDiaria() const;
};

/**
 * @brief Classe que representa um Destino.
 *
 * Contém informações sobre um destino, com código, nome,
 * avaliação e período de viagem (data de início e término).
 */
class Destino {
    private:
        /**
         * @brief Código identificador do destino.
         */
        Codigo codigo;

        /**
         * @brief Nome do destino.
         */
        Nome nome;

        /**
         * @brief Avaliação atribuída ao destino.
         */
        Avaliacao avaliacao;

        /**
         * @ Data de início da viagem ao destino.
         */
        Data data_inicio;

        /**
         * @brief Data de término da viagem ao destino.
         */
        Data data_fim;
    public:
        /**
         * @brief Define o código do destino.
         *
         * @param codigo Código que será associado ao destino.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Recupera o código do destino.
         *
         * @return Código atual do destino.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define o nome do destino.
         *
         * @param nome Nome que será associado ao destino.
         */
        void setNome(const Nome&);

        /**
         * @brief Recupera o nome do destino.
         *
         * @return Nome atual do destino.
         */
        Nome getNome() const;

        /**
         * @brief Define a avaliação do destino.
         *
         * @param avaliacao Avaliação que será associado ao destino.
         */
        void setAvaliacao(const Avaliacao&);

        /**
         * @brief Recupera a avaliação do destino.
         *
         * @return Avalição atual do destino.
         */
        Avaliacao getAvaliacao() const;

        /**
         * @brief Define a data de início da viagem ao destino.
         *
         * @param data_inicio Data de início que será associado ao destino.
         */
        void setDataInicio(const Data&);

        /**
         * @brief Recupera a data de início da viagem ao destino.
         *
         * @return Data de início da viagem.
         */
        Data getDataInicio() const;

        /**
         * @brief Define a data de término da viagem ao destino.
         *
         * @param data_fim Data de término que será associado ao destino.
         */
        void setDataFim(const Data&);

        /**
         * @brief Recupera a data de término da viagem ao destino.
         *
         * @return Data de término da viagem.
         */
        Data getDataFim() const;
};
/**
 * @brief Classe que representa uma Atividade.
 *
 * Contém informações detalhadas sobre uma atividade, como código, nome, data,
 * horário, duração, preço e avaliação.
 */
class Atividade { //LEANDRO COELHO DA SILVA, MAT:232011396
    private:
        /**
         * @brief Código identificador da atividade.
         */
        Codigo codigo;

        /**
         * @brief Nome da atividade.
         */
        Nome nome;

        /**
         * @brief Avaliação atribuída à atividade.
         */
        Avaliacao avaliacao;

        /**
         * @brief Data da atividade.
         */
        Data data;

        /**
         * @brief Horário da atividade.
         */
        Horario horario;

        /**
         * @brief Duração da atividade.
         */
        Duracao duracao;

        /**
         * @brief Valor da atividade.
         */
        Dinheiro preco;
    public:
        /**
         * @brief Define o código da atividade.
         *
         * @param codigo Código que será associado à atividade.
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Recupera o código da atividade.
         *
         * @return Código atual da atividade.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define o nome da atividade.
         *
         * @param nome Nome que será associado à atividade.
         */
        void setNome(const Nome&);

        /**
         * @brief Recupera o nome da atividade.
         *
         * @return Nome atual da atividade.
         */
        Nome getNome() const;

        /**
         * @brief Define a avaliação da atividade.
         *
         * @param avaliacao Avaliação que será associada à atividade.
         */
        void setAvaliacao(const Avaliacao&);

        /**
         * @brief Recupera a avaliação da atividade.
         *
         * @return Avaliação atual da atividade.
         */
        Avaliacao getAvaliacao() const;

        /**
         * @brief Define a data da atividade.
         *
         * @param data Data que será associada à atividade.
         */
        void setData(const Data&);

        /**
         * @brief Recupera a data da atividade.
         *
         * @return Data atual da atividade.
         */
        Data getData() const;

        /**
         * @brief Define o horário da atividade.
         *
         * @param horario Horário que será associado à atividade.
         */
        void setHorario(const Horario&);

        /**
         * @brief Recupera o horário da atividade.
         *
         * @return Horário atual da atividade.
         */
        Horario getHorario() const;

        /**
         * @brief Define a duração da atividade.
         *
         * @param duracao Duração que será associada à atividade.
         */
        void setDuracao(const Duracao&);

        /**
         * @brief Recupera a duração da atividade.
         *
         * @return Duração atual da atividade.
         */
        Duracao getDuracao() const;

        /**
         * @brief Define o valor da atividade.
         *
         * @param preco Valor que será associado à atividade.
         */
        void setPreco(const Dinheiro&);

        /**
         * @brief Recupera o valor da atividade.
         *
         * @return Valor atual da atividade.
         */
        Dinheiro getPreco() const;
};

#endif // ENTIDADES_HPP_INCLUDED;
