//
// Created by mateusberardo on 03/05/2021.
//

#include "ProtocoloDeContagemDeCaracteres.hpp"


std::string CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem) {
    unsigned int quantidadeDeQuadros = getAmountOfFrames(mensagem);
    unsigned int lastFrameSize = getLastFrameSize(mensagem);
    for (int i = 0; i < quantidadeDeQuadros; i++) {
        mensagem.insert(mensagem.cbegin() + (i * FRAME_SIZE),
                        getFrameSize(quantidadeDeQuadros, lastFrameSize, i));
    }
    return mensagem;
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