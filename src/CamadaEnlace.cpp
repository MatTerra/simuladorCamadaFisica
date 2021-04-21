#include "CamadaEnlace.hpp"

void CamadaEnlaceDadosTransmissora(std::string mensagem) {
    CamadaEnlaceDadosTransmissoraEnquadramento(mensagem);
    // CamadaEnlaceTransmissoraControleDeErro(quadro);

    // CamadaFisicaTransmissora(quadro);
};

void CamadaEnlaceDadosTransmissoraEnquadramento(std::string mensagem) {
    std::vector<frame> quadros;
    switch (PROTOCOLO_ENLACE_ESCOLHIDO) {
        case PROTOCOLO_CONTAGEM_DE_CARACTERES:
            quadros = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(mensagem);
            break;
        case PROTOCOLO_INSERCAO_DE_BYTES:
            // inserção de bytes
            break;
    }
    // Verificacao de erros
//    CamadaFisicaTransmissora(quadros);
}

void CamadaEnlaceDadosReceptora(std::vector<frame> quadros);

void CamadaEnlaceDadosReceptoraEnquadramento(std::vector<frame> quadros);

unsigned int getAmountOfFrames(const std::string &mensagem);

bool isLastFrame(unsigned int quantidadeDeQuadros, int i);

unsigned int getLastFrameSize(const std::string &mensagem);

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem) {
    unsigned int quantidadeDeQuadros = getAmountOfFrames(mensagem);
    unsigned int lastFrameSize = getLastFrameSize(mensagem);

    for (int i=0; i<quantidadeDeQuadros; i++) {
        mensagem.insert(mensagem.cbegin() + (i * FRAME_SIZE),
                        std::to_string(isLastFrame(quantidadeDeQuadros, i)
                        ? lastFrameSize : FRAME_SIZE)[0]);
    }
    std::cout << mensagem;
    return std::vector<frame>();
}

unsigned int getLastFrameSize(const std::string &mensagem) {
    return (mensagem.length()%(FRAME_SIZE-1)!=0)
        ? ((mensagem.length() % (FRAME_SIZE-1)) + 1)
        : FRAME_SIZE;
}

bool isLastFrame(unsigned int quantidadeDeQuadros, int i) {
    return i == quantidadeDeQuadros - 1;
}

unsigned int getAmountOfFrames(const std::string &mensagem) {
    int frameEffectiveSize = FRAME_SIZE - 1;
    unsigned int fullFrames = mensagem.length() / frameEffectiveSize;
    std::cout << fullFrames << std::endl;
    bool hasPartialFrame = mensagem.length() % frameEffectiveSize > 0;
    return fullFrames + (hasPartialFrame?1:0);
}

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);
