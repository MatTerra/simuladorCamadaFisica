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
            std::cout << "Utilizando protocolo de inserção de bytes!" << std::endl;
            quadros = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(mensagem);
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
                        getFrameSize(quantidadeDeQuadros, lastFrameSize, i));
    }
    return mensagem;
}



unsigned int getLastFrameSize(const std::string &mensagem) {
    return (mensagem.length() % EFFECTIVE_FRAME_SIZE != 0)
           ? ((mensagem.length() % EFFECTIVE_FRAME_SIZE) + (FRAME_SIZE-EFFECTIVE_FRAME_SIZE))
           : FRAME_SIZE;
}

bool isLastFrame(unsigned int quantidadeDeQuadros, int i) {
    return i == quantidadeDeQuadros - 1;
}

unsigned int getAmountOfFrames(const std::string &mensagem) {
    unsigned int fullFrames = mensagem.length() / EFFECTIVE_FRAME_SIZE;
    bool hasPartialFrame = mensagem.length() % EFFECTIVE_FRAME_SIZE > 0;
    return fullFrames + (hasPartialFrame);
}

unsigned int getAmountOfProcessedFrames(const std::string &mensagem) {
    unsigned int fullFrames = mensagem.length() / FRAME_SIZE;
    bool hasPartialFrame = mensagem.length() % FRAME_SIZE > 0;
    return fullFrames + (hasPartialFrame);
}


void mostrarQuadros(std::string quadros) {
    unsigned int quantidadeDeQuadros = getAmountOfProcessedFrames(quadros);
    unsigned int lastFrameSize = getLastFrameSize(quadros);
    for (int i = 0; i < quantidadeDeQuadros - 1; i++) {
        std::cout << quadros.substr(i * FRAME_SIZE, getFrameSize(quantidadeDeQuadros, lastFrameSize, i)) << " ";
    }

    std::cout << quadros.substr((quantidadeDeQuadros - 1) * FRAME_SIZE) << std::endl;
}

void mostrarProcessamentoCamadaEnlaceTransmissora(std::string quadros) {
    std::cout << "Camada de enlace transmitindo os seguintes quadros: ";
    mostrarQuadros(quadros);
}

void mostrarProcessamentoCamadaEnlaceReceptora(std::string quadros) {
    std::cout << "Camada de enlace recebeu os seguintes quadros: ";
    mostrarQuadros(quadros);
}

unsigned short getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i) {
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
            std::cout << "Utilizando protocolo de contagem de caracteres!" << std::endl;
            mensagem = CamadaEnlaceDadosReceptoraDesenquadramentoInsercaoDeBytes(quadros);
            break;
    }
    // Verificacao de erros

    CamadaDeAplicacaoReceptora(mensagem);
}

std::string CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(
        std::string quadros) {
    for (int i = 0; i < quadros.length(); i--) {
        unsigned short len = quadros.substr(i, 1)[0];
        quadros.erase(i, 1);
        i += len;
        bool hasMorePackets = quadros.c_str()[i - 1];
        if(!hasMorePackets)
            break;
    }
    return quadros;
}

std::string CamadaEnlaceDadosReceptoraDesenquadramentoInsercaoDeBytes(
        std::string quadros) {
    for (int i = 0; i < quadros.length();) {
        quadros.erase(i, 1);
        quadros.erase(getNextSeparatorIndex(i, quadros), 1);
        i += EFFECTIVE_FRAME_SIZE;
        bool hasMorePackets = quadros.c_str()[i - 1];
        if(!hasMorePackets)
            break;
    }
    return quadros;
}

int getNextSeparatorIndex(int i, std::string quadros) {
    int nextSeparator = quadros.find(GROUP_SEPARATOR, i);
    i += EFFECTIVE_FRAME_SIZE;
    return i > nextSeparator ? nextSeparator : i;
}


std::string CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem) {
    unsigned int frameAmount = getAmountOfFrames(mensagem);
    unsigned int lastFrameSize = getLastFrameSize(mensagem);
    mensagem += GROUP_SEPARATOR;
    for (int i = 0; i < frameAmount; i++) {
        auto frameStart = mensagem.begin() + (i * FRAME_SIZE);
        mensagem.insert(frameStart, GROUP_SEPARATOR);
        if((i + 1) == frameAmount)
            break;
        mensagem.insert(frameStart + (getFrameSize(frameAmount, lastFrameSize, i) - 1),
                GROUP_SEPARATOR);
    }

    return mensagem;
};