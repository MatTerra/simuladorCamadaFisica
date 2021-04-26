#include "CamadaEnlace.hpp"

void CamadaEnlaceDadosTransmissora(std::string mensagem) {
    CamadaEnlaceDadosTransmissoraEnquadramento(mensagem);
    // CamadaEnlaceTransmissoraControleDeErro(quadro);
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
    bool hasPartialFrame = mensagem.length() % frameEffectiveSize > 0;
    return fullFrames + (hasPartialFrame);
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
    std::cout << "Camada de enlace transmitindo os seguintes quadros: ";
    mostrarQuadros(quadros);
}

void mostrarProcessamentoCamadaEnlaceReceptora(std::string quadros) {
    std::cout << "Camada de enlace recebeu os seguintes quadros: ";
    mostrarQuadros(quadros);
}

unsigned int getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i) {
    return (isLastFrame(quantidadeDeQuadros, i)
            ? lastFrameSize : FRAME_SIZE);
}

void CamadaEnlaceDadosReceptora(std::string quadros) {
    std::string mensagem;

    mostrarProcessamentoCamadaEnlaceReceptora(quadros);

    switch (PROTOCOLO_ENLACE_ESCOLHIDO) {
        case PROTOCOLO_CONTAGEM_DE_CARACTERES:
            std::cout << "Utilizando protocolo de contagem de caracteres!" << std::endl;
            mensagem = CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(quadros);
            break;
        case PROTOCOLO_INSERCAO_DE_BYTES:
            // inserção de bytes
            break;
    }
    // Verificacao de erros

    CamadaDeAplicacaoReceptora(mensagem);
}

std::string CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(
        std::string quadros) {
    for (int i = 0; i < quadros.length(); i--) {
        int len = std::stoi(quadros.substr(i, 1));
        quadros.erase(i, 1);''
        if(len < FRAME_SIZE)
            break;
        i += len;
    }
    return quadros;
}

std::string CamadaEnlaceDadosReceptoraDesenquadramentoInserçãoDeBits(
        std::string quadros) {
    for (int i = 0; i < quadros.length(); i--) {
        int len = std::stoi(quadros.substr(i, 1));
        quadros.erase(i, 1);
        if(len < FRAME_SIZE)
            break;
        i += len;
    }
    return quadros;
}

std::string CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);
