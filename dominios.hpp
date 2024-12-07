#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Horario
 * @brief Representa um horário no formato HH:MM.
 */
class Horario { //Leandro Coelho da Silva, MAT:232011396
    private:
        /**
         * @brief Representa as horas (0-23).
         */
        unsigned short hora; 

        /**
         * @brief Representa os minutos (0-59).
         */
        unsigned short minuto; 

        /**
         * @brief Valida o horário informado.
         * @param h Hora a ser validada.
         * @param m Minuto a ser validado.
         * @throws invalid_argument Se a hora ou o minuto forem inválidos.
         */
        void validateHora(unsigned short h, unsigned short m);

    public:
        /**
         * @brief Define o horário a partir de uma string no formato HH:MM.
         * @param h String no formato HH:MM.
         * @throws invalid_argument Se o formato for inválido ou o horário for inválido.
         */
        void setHora(string h);

        /**
         * @brief Obtém o horário no formato HH:MM.
         * @return String representando o horário no formato HH:MM.
         */
        string getHora() const;
};

/**
 * @class Dinheiro
 * @brief Representa uma quantia em dinheiro.
 */
class Dinheiro { //Leandro Coelho da Silva, MAT:232011396
    private:

        /**
         * @brief Valor monetário do tipo double de 0 a 200000.
         */
        double dinheiro; 

        /**
         * @brief Valor monetário do tipo string no formato XXX.XXX,XX.
         */
        string dinheiroView; 

        /**
         * @brief Valida o valor monetário informado.
         * @param dinheiro String representando o valor.
         * @throws invalid_argument Se o valor for inválido.
         */
        void validateDinheiro(string dinheiro);

    public:
        /**
         * @brief Define o valor monetário.
         * @param dinheiro String representando o valor.
         * @throws invalid_argument Se o valor for inválido.
         */
        void setDinheiro(string dinheiro);

        /**
         * @brief Obtém o valor monetário como número.
         * @return Valor monetário em formato numérico double.
         */
        double getDinheiro() const;

        /**
         * @brief Obtém o valor monetário formatado como string.
         * @return Valor monetário em formato string.
         */
        string getDinheiroView() const;
};

/**
 * @class Nome
 * @brief Representa um nome.
 */
class Nome { //Leandro Coelho da Silva, MAT:232011396
    private:
        /**
         * @brief Nome armazenado do tipo string até 30 caracteres.
         */
        string nome;

        /**
         * @brief Valida o nome informado.
         * @param nome Nome a ser validado.
         * @throws invalid_argument Se o nome for inválido.
         */
        void validateNome(string nome);

    public:
        /**
         * @brief Define o nome.
         * @param nome String representando o nome.
         * @throws invalid_argument Se o nome for inválido.
         */
        void setNome(string nome);

        /**
         * @brief Obtém o nome armazenado.
         * @return String representando o nome.
         */
        string getNome() const;
};

/**
 * @class Duracao
 * @brief Representa uma duração em minutos.
 */
class Duracao { //Leandro Coelho da Silva, MAT:232011396
     private:

        /**
         * @brief Duração armazenada do tipo inteiro de 0 a 360.
         */
        int duracao;

        /**
         * @brief Valida a duração informada.
         * @param duracao Duração em minutos.
         * @throws invalid_argument Se a duração for inválida.
         */
        void validateDuracao(int duracao);

     public:
          /**
           * @brief Define a duração.
           * @param duracao Duração em minutos.
           * @throws invalid_argument Se a duração for inválida.
           */
          void setDuracao(string duracao);

          /**
           * @brief Obtém a duração armazenada como string.
           * @return String representando a duração.
           */
          string getDuracao() const;
};

/**
 * @class Avaliacao
 * @brief Representa uma avaliação de 0 a 5.
 */
class Avaliacao { //Leandro Coelho da Silva, MAT:232011396
    private:

        /**
         * @brief Avaliação armazenada do tipo inteiro de 0 a 5.
         */
        int avaliacao;

        /**
         * @brief Valida a avaliação informada.
         * @param avaliacao Avaliação entre 0 e 5.
         * @throws invalid_argument Se a avaliação for inválida.
         */
        void validateAvaliacao(int avaliacao);
    public:
    /**
         * @brief Define a avaliação.
         * @param avaliacao Avaliação entre 0 e 5.
         * @throws invalid_argument Se a avaliação for inválida.
         */
        void setAvaliacao(string avaliacao);

        /**
         * @brief Obtém a avaliação armazenada como string.
         * @return String representando a avaliação.
         */
        string getAvaliacao() const;
};

/**
 * @class Data
 * @brief Representa uma data no formato DD-MM-AA.
 */
class Data { //Leandro Coelho da Silva, MAT:232011396
    private:

        /**
         * @brief Dia armazenado (1-31).
         */
        unsigned short dia; 

        /**
         * @brief Mês armazenado (1-12).
         */
        unsigned short mes;

        /**
         * @brief Ano armazenado (00-99).
         */
        unsigned short ano;

        /**
         * @brief Valida a data informada.
         * @param d Dia a ser validado.
         * @param m Mês a ser validado.
         * @param a Ano a ser validado.
         * @throws invalid_argument Se a data for inválida.
         */
        void validateData(unsigned short d, unsigned short m, unsigned short a);
    public:
        /**
         * @brief Define a data a partir de uma string no formato DD-MM-AA.
         * @param data String no formato DD-MM-AA.
         * @throws invalid_argument Se o formato for inválido ou a data for inválida.
         */
        void setData(string data);
        
        /**
         * @brief Obtém a data no formato DD-MM-AA.
         * @return String representando a data no formato DD-MM-AA.
         */
        string getData() const;
};

/**
 * @class Senha
 * @brief Representa uma senha de 5 caracteres.
 */
class Senha { //Leandro Coelho da Silva, MAT:232011396
    private:

        /**
         * @brief Senha armazenada do tipo string de 5 caracteres.
         */
        string senha;

        /**
         * @brief Valida a senha informada.
         * @param senha String representando a senha.
         * @throws invalid_argument Se a senha for inválida.
         */
        void validateSenha(string senha);
    public:
        /**
         * @brief Define a senha.
         * @param senha String representando a senha.
         * @throws invalid_argument Se a senha for inválida.
         */
        void setSenha(string senha);

        /**
         * @brief Obtém a senha armazenada.
         * @return String representando a senha.
         */
        string getSenha() const;
};

/**
 * @class Codigo
 * @brief Representa um código de 6 dígitos.
 */
class Codigo { //Lucas Santana Camilo Alves, MAT:211060666
    private:

        /**
         * @brief Código armazenado do tipo string de 6 dígitos.
         */
        string codigo; 

        /**
         * @brief Valida o código informado.
         * @param codigo Código a ser validado.
         * @throws invalid_argument Se o código for inválido.
         */
        void validateCodigo(string codigo);
    public:
        /**
         * @brief Define o código.
         * @param codigo String representando o código.
         * @throws invalid_argument Se o código for inválido.
         */
        void setCodigo(string codigo);

        /**
         * @brief Obtém o código armazenado.
         * @return String representando o código.
         */
        string getCodigo() const;
};

#endif // DOMINIOS_HPP_INCLUDED;
