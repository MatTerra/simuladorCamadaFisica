#include "CamadaEnlace.hpp"


void CamadaEnlaceDadosTransmissora(const std::string& mensagem) {
    std::string quadros = CamadaEnlaceDadosTransmissoraEnquadramento(mensagem);

    mostrarProcessamentoCamadaEnlaceTransmissora(quadros);

    quadros = CamadaDeEnlaceTransmissoraControleDeErro(quadros);

    CamadaFisicaTransmissora(quadros);
};

void CamadaEnlaceDadosReceptora(std::string quadros){
    quadros = CamadaEnlaceDadosReceptoraControleDeErro(quadros);

    mostrarProcessamentoCamadaEnlaceReceptora(quadros);

    std::string mensagem = CamadaEnlaceDadosReceptoraEnquadramento(quadros);

    CamadaDeAplicacaoReceptora(mensagem);
}

std::string CamadaEnlaceDadosTransmissoraEnquadramento(const std::string& mensagem) {
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
    return quadros;
}

std::string CamadaDeEnlaceTransmissoraControleDeErro(std::string quadros) {
    switch (CONTROLE_DE_ERRO_ESCOLHIDO) {
        case CONTROLE_DE_ERRO_BIT_PARIDADE_PAR:
            std::cout << "Utilizando controle de erro paridade par!" << std::endl;
            quadros = CamadaDeEnlaceTransmissoraControleDeErroBitParidadePar(quadros);
            break;
        case CONTROLE_DE_ERRO_CRC:
            std::cout << "Utilizando controle de erro CRC!" << std::endl;
            quadros = CamadaDeEnlaceTransmissoraControleDeErroBitCRC(quadros);
            break;
        case CONTROLE_DE_ERRO_HAMMING:
            std::cout << "Utilizando o código de Hamming!" << std::endl;
            quadros = CamadaDeEnlaceTransmissoraControleDeErroHamming(quadros);
            break;
    }
    return quadros;
}

std::string CamadaEnlaceDadosReceptoraEnquadramento(const std::string& quadros) {
    std::string mensagem;

    switch (PROTOCOLO_ENLACE_ESCOLHIDO) {
        case PROTOCOLO_CONTAGEM_DE_CARACTERES:
            std::cout << "Utilizando protocolo de contagem de caracteres!" << std::endl;
            mensagem = CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(quadros);
            break;
        case PROTOCOLO_INSERCAO_DE_BYTES:
            std::cout << "Utilizando protocolo de inserção de bytes!" << std::endl;
            mensagem = CamadaEnlaceDadosReceptoraDesenquadramentoInsercaoDeBytes(quadros);
            break;
    }

    return mensagem;
}

std::string CamadaEnlaceDadosReceptoraControleDeErro(std::string quadros) {
    switch (CONTROLE_DE_ERRO_ESCOLHIDO) {
        case CONTROLE_DE_ERRO_BIT_PARIDADE_PAR:
            std::cout << "Utilizando controle de erro paridade par!" << std::endl;
            quadros = CamadaDeEnlaceReceptoraControleDeErroBitParidadePar(quadros);
            break;
        case CONTROLE_DE_ERRO_CRC:
            std::cout << "Utilizando controle de erro CRC!" << std::endl;
            quadros = CamadaDeEnlaceReceptoraControleDeErroBitCRC(quadros);
            break;
        case CONTROLE_DE_ERRO_HAMMING:
            std::cout << "Utilizando o código de Hamming!" << std::endl;
            quadros = CamadaDeEnlaceReceptoraControleDeErroHamming(quadros);
            break;
    }

    return quadros;
}



unsigned int getLastFrameSize(const std::string &mensagem) {
    return (mensagem.length() % EFFECTIVE_FRAME_SIZE != 0)
           ? ((mensagem.length() % EFFECTIVE_FRAME_SIZE) + (FRAME_SIZE-EFFECTIVE_FRAME_SIZE))
           : FRAME_SIZE;
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


void mostrarQuadros(const std::string& quadros) {
    unsigned int quantidadeDeQuadros = getAmountOfProcessedFrames(quadros);
    unsigned int lastFrameSize = getLastFrameSize(quadros);
    for (int i = 0; i < quantidadeDeQuadros - 1; i++) {
        std::cout << quadros.substr(i * FRAME_SIZE, getFrameSize(quantidadeDeQuadros, lastFrameSize, i)) << " ";
    }

    std::cout << quadros.substr((quantidadeDeQuadros - 1) * FRAME_SIZE) << std::endl;
}

void mostrarProcessamentoCamadaEnlaceTransmissora(const std::string& quadros) {
    std::cout << "Camada de enlace transmitindo os seguintes quadros: ";
    mostrarQuadros(quadros);
}

void mostrarProcessamentoCamadaEnlaceReceptora(const std::string& quadros) {
    std::cout << "Camada de enlace recebeu os seguintes quadros: ";
    mostrarQuadros(quadros);
}

unsigned short getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i) {
    return (isLastFrame(quantidadeDeQuadros, i)
            ? lastFrameSize : FRAME_SIZE);
}

bool isLastFrame(unsigned int quantidadeDeQuadros, int i) {
    return i == quantidadeDeQuadros - 1;
}
