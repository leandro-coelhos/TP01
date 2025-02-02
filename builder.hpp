#include "interfaces.hpp"
#include "controlaApresentacao.hpp"
#include "controleServicos.hpp"

/**
 * @brief Classe responsável por construir e configurar os controladores de apresentação e serviço.
 *
 * A classe Builder é responsável por instanciar e configurar todos os controladores de apresentação
 * e serviço necessários para o funcionamento do sistema. Ela também estabelece as dependências entre
 * esses controladores, garantindo que eles possam se comunicar corretamente.
 */
class Builder {
     private:
          CntrApresentacaoControle *cntrApresentacaoControle; ///< Controlador de apresentação de controle.
          IApresentacaoConta *cntrApresentacaoConta;          ///< Controlador de apresentação de conta.
          IApresentacaoViagem *cntrApresentacaoViagem;        ///< Controlador de apresentação de viagem.
          IApresentacaoDestino *cntrApresentacaoDestino;      ///< Controlador de apresentação de destino.
          IApresentacaoHospedagem *cntrApresentacaoHospedagem;///< Controlador de apresentação de hospedagem.
          IApresentacaoAtividade *cntrApresentacaoAtividade;  ///< Controlador de apresentação de atividade.
          
          IServicoConta *cntrServicoConta;                    ///< Controlador de serviço de conta.
          IServicoViagem *cntrServicoViagem;                  ///< Controlador de serviço de viagem.
          IServicoDestino *cntrServicoDestino;                ///< Controlador de serviço de destino.
          IServicoHospedagem *cntrServicoHospedagem;          ///< Controlador de serviço de hospedagem.
          IServicoAtividade *cntrServicoAtividade;            ///< Controlador de serviço de atividade.
     public:
         /**
          * @brief Constrói e configura todos os controladores de apresentação e serviço.
          *
          * Este método é responsável por instanciar e configurar todos os controladores de apresentação
          * e serviço necessários para o funcionamento do sistema. Ele também estabelece as dependências
          * entre os controladores, garantindo que eles possam se comunicar corretamente.
          *
          * @return Retorna um ponteiro para o controlador de apresentação de controle, que é o ponto de entrada
          * principal do sistema.
          */
          CntrApresentacaoControle* construir();
          /**
           * @brief Destrutor da classe Builder.
           *
           * Este destrutor é responsável por liberar a memória alocada para todos os controladores
           * de apresentação e serviço instanciados durante a execução do programa.
           */
          ~Builder();
};
