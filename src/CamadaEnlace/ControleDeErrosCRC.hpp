//
// Created by mateusberardo on 03/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H
#define SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H

#define POLINOMIO_CRC_32 0b100000100110000010001110110110111

#include <string>

std::string CamadaDeEnlaceTransmissoraControleDeErroBitCRC(std::string quadro);
std::string CamadaDeEnlaceReceptoraControleDeErroBitCRC(std::string quadro);


#endif //SIMULADORCAMADAFISICA_CONTROLEDEERROSCRC_H
