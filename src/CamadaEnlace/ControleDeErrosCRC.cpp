//
// Created by mateusberardo on 03/05/2021.
//
#include "ControleDeErrosCRC.hpp"
#include "../BinaryUtils.h"


crc_t parseReceivedCRC(const std::string &crc);

std::string CamadaDeEnlaceTransmissoraControleDeErroBitCRC(std::string quadro) {
    crc_t crc = crcCalc(quadro);
    quadro += (0xff000000 & crc) >> 24;
    quadro += (0xff0000 & crc) >> 16;
    quadro += (0xff00 & crc) >> 8;
    quadro += 0xff & crc;
    std::cout << "CRC enviado é " << crc << std::endl;
    return quadro;
};

crc_t crcCalc(const std::string& message){
    crc_t crc = 0xffffffff;

    for (char byte : message)
    {
        int j;
        crc_t c;

        auto partial = ((crc >> 24) ^ byte) & 255;
        for (c = partial << 24, j = 8; j > 0; --j)
            c = c & 0x80000000 ? (c << 1) ^ POLINOMIO_CRC_32 : (c << 1);
        crc = (crc << 8) ^ c;
    }
    return crc;
}

std::string CamadaDeEnlaceReceptoraControleDeErroBitCRC(std::string quadro) {
    crc_t crc = crcCalc(quadro);
    quadro = quadro.substr(0, quadro.size() - 4);

    if (crc)
        std::cout << "Detectado erro de transmissão!" << std::endl;

    return quadro;
}

crc_t parseReceivedCRC(const std::string &crc) {
    crc_t receivedCRC = (unsigned char) crc[0];
    receivedCRC = (receivedCRC<<8) + (unsigned char) crc[1];
    receivedCRC = (receivedCRC<<8) + (unsigned char) crc[2];
    receivedCRC = (receivedCRC<<8) + (unsigned char) crc[3];
    return receivedCRC;
};
