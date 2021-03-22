#include "CamadaFisica.hpp"


void CamadaFisicaReceptora(bitStream bits) {

}

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB) {
    std::copy(fluxoBrutoDeBitsPontoA.begin(),
              fluxoBrutoDeBitsPontoA.end(),
              fluxoBrutoDeBitsPontoB);
}

void MeioDeComunicacao(bitStream bits) {
    bitStream fluxoBrutoDeBitsPontoB;

    transmit(bits, fluxoBrutoDeBitsPontoB);

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

bitStream toBinary(std::string input) {
    bitStream output;
    for (char &_char : input)
    {
        output.insert(output.end(), std::bitset<8>(_char));
    }
    return output;
}


void CamadaFisicaTransmissora(std::string quadro) {
    int tipoDeCodificacao = 0;
    bitStream fluxoBrutoDeBits ;

    switch (tipoDeCodificacao) {
        case CODIFICACAO_BINARIA:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case CODIFICACAO_MANCHESTER:
            break;
        case CODIFICACAO_BIPOLAR:
            break;
    }

    MeioDeComunicacao(fluxoBrutoDeBits);
}

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro) {
    bitStream binaryFrame = toBinary(quadro);
    // encode
    return binaryFrame;
}
