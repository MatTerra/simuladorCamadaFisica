//
// Created by mateusberardo on 03/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H
#define SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H

#define POLINOMIO_CRC_32 0x04c11db7

#include <string>
#include <iostream>

typedef uint32_t crc_t;
crc_t crcCalc(const std::string& message);

std::string CamadaDeEnlaceTransmissoraControleDeErroBitCRC(std::string quadro);
std::string CamadaDeEnlaceReceptoraControleDeErroBitCRC(std::string quadro);


#endif //SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H
