#ifndef CODIFICACAO_MANCHESTER_H
#define CODIFICACAO_MANCHESTER_H

#include "BinaryUtils.h"

bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream encodedBytes);

std::bitset<8> encodeHalfByte(std::bitset<8> &byte, bool isHighHalf);

std::bitset<8> decodeByteManchester(std::bitset<8> highByte, std::bitset<8> lowByte);

std::bitset<8> decodeHalfByteManchester(std::bitset<8> &decodedByte, std::bitset<8> byte,
                              bool isHighHalf);

#endif