#ifndef CODIFICACAO_BIPOLAR_H
#define CODIFICACAO_BIPOLAR_H

#define HIGH_BYTE_HALF true

#define LOW_BYTE_HALF false

#include "BinaryUtils.h"

bitStream CamadaFisicaTransmissoraCodificacaoBipolar(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoBipolar(bitStream bits);

std::bitset<8> &
addOneBipolarRepresentation(std::bitset<8> &input, bool positive, int bitIndex);

std::bitset<8> &
addZeroBipolarRepresentation(std::bitset<8> &input, int bitIndex);

void addBitBipolarRepresentation(bool bit, int bitIndex, bool &positive,
                                 std::bitset<8> &output);

std::bitset<8>
bipolarEncodeHalfByte(std::bitset<8> &byte, bool &positive, bool high);

#endif