/**
 * @file controleServicos.hpp
 * @brief Definição das classes de serviço do sistema.
 */

#ifndef CONTROLESERVICOS_HPP_INCLUDED
#define CONTROLESERVICOS_HPP_INCLUDED

#include <iostream>
#include <string>
#include "interfaces.hpp"

using namespace std;

/**
 * @brief Classe responsável pela autenticação e gerenciamento de contas.
 */
class CntrServicoAutenticacaoConta: public IServicoConta {
    public:
        /**
         * @brief Realiza o login de uma conta.
         * @param codigo Código da conta.
         * @param senha Senha da conta.
         * @return int Código de status do login.
         */
        int logarConta(string, string);

        /**
         * @brief Cria uma nova conta no sistema.
         * @param codigo Código único da conta.
         * @param senha Senha da conta.
         * @return true Se a conta foi criada com sucesso.
         * @return false Se a criação da conta falhou.
         */
        bool createConta(string, string);
};

/**
 * @brief Classe responsável pela gestão de viagens.
 */
class CntrServicoViagem: public IServicoViagem {
    public:
        /**
         * @brief Cria uma nova viagem associada a uma conta.
         * @param codigo Código único da viagem.
         * @param nome Nome da viagem.
         * @param avaliacao Avaliação da viagem.
         * @param codigoConta Código da conta do usuário criador.
         * @return true Se a viagem foi criada com sucesso.
         * @return false Se a criação da viagem falhou.
         */
        bool createViagem(string, string, string, string);

        /**
         * @brief Lista todas as viagens associadas a uma conta.
         * @param codigoConta Código da conta do usuário.
         */
        void listarViagens(string);
};

/**
 * @brief Classe responsável pela gestão de destinos dentro de viagens.
 */
class CntrServicoDestino: public IServicoDestino {
    public:
        /**
         * @brief Cria um novo destino dentro de uma viagem.
         * @param codigo Código único do destino.
         * @param nome Nome do destino.
         * @param data_inicio Data de início da estadia no destino.
         * @param data_final Data de término da estadia no destino.
         * @param avaliacao Avaliação do destino.
         * @param codigoViagem Código da viagem associada ao destino.
         * @return true Se o destino foi criado com sucesso.
         * @return false Se a criação do destino falhou.
         */
        bool createDestino(string, string, string, string, string, string);

        /**
         * @brief Lista todos os destinos dentro de uma viagem.
         * @param codigoViagem Código da viagem associada.
         */
        void listarDestinos(string);

        /**
         * @brief Obtém o código da conta associada a uma viagem.
         * @param codigoViagem Código da viagem.
         * @return string Código da conta do usuário.
         */
        string getConta(string);

        /**
         * @brief Obtém o código da viagem associada a um destino.
         * @param codigoDestino Código do destino.
         * @return string Código da viagem.
         */
        string getViagem(string);
};

/**
 * @brief Classe responsável pela gestão de hospedagens dentro de destinos.
 */
class CntrServicoHospedagem: public IServicoHospedagem {
    public:
        /**
         * @brief Cria uma nova hospedagem dentro de um destino.
         * @param codigo Código único da hospedagem.
         * @param nome Nome da hospedagem.
         * @param diaria Valor da diária da hospedagem.
         * @param avaliacao Avaliação da hospedagem.
         * @param codigoDestino Código do destino associado à hospedagem.
         * @return true Se a hospedagem foi criada com sucesso.
         * @return false Se a criação da hospedagem falhou.
         */
        bool createHospedagem(string, string, string, string, string);

        /**
         * @brief Lista todas as hospedagens dentro de um destino.
         * @param codigoDestino Código do destino associado.
         */
        void listarHospedagens(string);
};

/**
 * @brief Classe responsável pela gestão de atividades dentro de destinos.
 */
class CntrServicoAtividade: public IServicoAtividade {
    public:
        /**
         * @brief Cria uma nova atividade dentro de um destino.
         * @param codigo Código único da atividade.
         * @param nome Nome da atividade.
         * @param data Data da atividade.
         * @param horario Horário da atividade.
         * @param duracao Duração da atividade.
         * @param preco Preço da atividade.
         * @param avaliacao Avaliação da atividade.
         * @param codigoDestino Código do destino associado à atividade.
         * @return true Se a atividade foi criada com sucesso.
         * @return false Se a criação da atividade falhou.
         */
        bool createAtividade(string, string, string, string, string, string, string, string);

        /**
         * @brief Lista todas as atividades dentro de um destino.
         * @param codigoDestino Código do destino associado.
         */
        void listarAtividades(string);
};

#endif // CONTROLESERVICOS_HPP_INCLUDED
