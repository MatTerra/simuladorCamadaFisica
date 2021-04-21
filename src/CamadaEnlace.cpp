#include "CamadaEnlace.hpp"

void CamadaEnlaceDadosTransmissora(std::string mensagem) {
    CamadaEnlaceDadosTransmissoraEnquadramento(mensagem);
    // CamadaEnlaceTransmissoraControleDeErro(quadro);

    // CamadaFisicaTransmissora(quadro);
};

void CamadaEnlaceDadosTransmissoraEnquadramento(std::string mensagem) {
    std::string quadros;
    switch (PROTOCOLO_ENLACE_ESCOLHIDO) {
        case PROTOCOLO_CONTAGEM_DE_CARACTERES:
            std::cout << "Utilizando protocolo de contagem de caracteres!" << std::endl;
            quadros = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(mensagem);
            break;
        case PROTOCOLO_INSERCAO_DE_BYTES:
            // inserção de bytes
            break;
    }
    // Verificacao de erros
    mostrarProcessamentoCamadaEnlaceTransmissora(quadros);
    CamadaFisicaTransmissora(quadros);
}

void CamadaEnlaceDadosReceptora(std::vector<frame> quadros);

void CamadaEnlaceDadosReceptoraEnquadramento(std::vector<frame> quadros);

unsigned int getAmountOfFrames(const std::string &mensagem);

bool isLastFrame(unsigned int quantidadeDeQuadros, int i);

unsigned int getLastFrameSize(const std::string &mensagem);

std::string CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem) {
    unsigned int quantidadeDeQuadros = getAmountOfFrames(mensagem);
    unsigned int lastFrameSize = getLastFrameSize(mensagem);
    for (int i = 0; i < quantidadeDeQuadros; i++) {
        mensagem.insert(mensagem.cbegin() + (i * FRAME_SIZE),
                        std::to_string(getFrameSize(quantidadeDeQuadros, lastFrameSize, i))[0]);
    }
    return mensagem;
}

unsigned int getLastFrameSize(const std::string &mensagem) {
    return (mensagem.length() % (FRAME_SIZE - 1) != 0)
           ? ((mensagem.length() % (FRAME_SIZE - 1)) + 1)
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
    return fullFrames + (hasPartialFrame ? 1 : 0);
}

void mostrarQuadros(std::string quadros) {
    unsigned int quantidadeDeQuadros = getAmountOfFrames(quadros);
    unsigned int lastFrameSize = getLastFrameSize(quadros);
    for (int i = 0; i < quantidadeDeQuadros - 1; i++) {
        std::cout << quadros.substr(i * FRAME_SIZE, getFrameSize(quantidadeDeQuadros, lastFrameSize, i)) << " ";
    }

    std::cout << std::endl;
}

void mostrarProcessamentoCamadaEnlaceTransmissora(std::string quadros) {
    std::cout << "Camada física transmitindo o seguinte fluxo de bits: ";
    mostrarQuadros(quadros);
}

unsigned int getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i) {
    return (isLastFrame(quantidadeDeQuadros, i)
            ? lastFrameSize : FRAME_SIZE);
}

std::string CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);
