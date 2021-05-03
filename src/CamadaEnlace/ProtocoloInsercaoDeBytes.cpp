//
// Created by mateusberardo on 03/05/2021.
//

#include "ProtocoloInsercaoDeBytes.hpp"


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