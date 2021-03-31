#ifndef CODIFICACAO_MANCHESTER_H
#define CODIFICACAO_MANCHESTER_H

#include "BinaryUtils.h"

bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream bits);

std::bitset<8> decodeByte(std::bitset<8> highByte, std::bitset<8> lowByte );

std::bitset<8> decodeHalfByte(std::bitset<8> &decodedByte, std::bitset<8> byte, int bitIndex);

#endif