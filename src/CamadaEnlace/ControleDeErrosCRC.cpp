//
// Created by mateusberardo on 03/05/2021.
//
#include "ControleDeErrosCRC.hpp"
#include "../BinaryUtils.h"


std::string CamadaDeEnlaceTransmissoraControleDeErroBitCRC(std::string quadro) {
    crc_t crc = crcCalc(quadro);
    quadro += (0xff000000 & crc) >> 24;
    quadro += (0xff0000 & crc) >> 16;
    quadro += (0xff00 & crc) >> 8;
    quadro += 0xff & crc;
    return quadro;
};

std::string CamadaDeEnlaceReceptoraControleDeErroBitCRC(std::string quadro) {
    crc_t crc = crcCalc(quadro);

    if (crc)
        std::cout << "Detectado erro de transmissão!" << std::endl;

    return quadro.substr(0, quadro.size() - 4);
}

crc_t crcCalc(const std::string& message){
    crc_t crc = 0xffffffff;

    for (char byte : message)
    {
        int j;
        crc_t c;

        uint8_t partial = (crc >> 24) ^ byte;
        for (c = partial << 24, j = 8; j > 0; --j)
            c = c & 0x80000000 ? (c << 1) ^ POLINOMIO_CRC_32 : (c << 1);
        crc = (crc << 8) ^ c;
    }
    return crc;
}