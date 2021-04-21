#include "CamadaEnlace.hpp"

void CamadaEnlaceDadosTransmissora(std::string mensagem) {
    CamadaEnlaceDadosTransmissoraEnquadramento(mensagem);
    // CamadaEnlaceTransmissoraControleDeErro(quadro);

    // CamadaFisicaTransmissora(quadro);
};

void CamadaEnlaceDadosTransmissoraEnquadramento(std::string mensagem) {
    switch (PROTOCOLO_ENLACE_ESCOLHIDO) {
        case PROTOCOLO_CONTAGEM_DE_CARACTERES:
            frame *quadro = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(mensagem)
            break;
        case PROTOCOLO_INSERCAO_DE_BYTES:
            // inserção de bytes
            break;
    }
}

void CamadaEnlaceDadosReceptora(std::vector<frame> quadros);

void CamadaEnlaceDadosReceptoraEnquadramento(std::vector<frame> quadros);

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem) {

}

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);
