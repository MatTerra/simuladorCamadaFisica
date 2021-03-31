#ifndef CAMADAFISICA_H
#define CAMADAFISICA_H

#include <string>
#include <bitset>
#include <vector>
#include <iostream>

#include "binary_utils.h"

#define CODIFICACAO_BINARIA 0
#define CODIFICACAO_MANCHESTER 1
#define CODIFICACAO_BIPOLAR 2


#define HIGH_BYTE_HALF true

#define LOW_BYTE_HALF false

void CamadaDeAplicacaoReceptora(std::string mensagem);

void CamadaFisicaTransmissora(std::string quadro);

void CamadaFisicaReceptora(bitStream fluxoBrutoDeBits);

void MeioDeComunicacao(bitStream bits);

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB);

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro);
bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro);
bitStream CamadaFisicaTransmissoraCodificacaoBipolar(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoBinaria(bitStream bits);
std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream bits);
std::string CamadaFisicaReceptoraDecodificacaoBipolar(bitStream bits);

unsigned long getStringBinarySize(const std::string &quadro);
void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits);

void CamadaDeAplicacaoReceptora(std::string mensagem);

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits);

std::bitset<8> &
addOneBipolarRepresentation(std::bitset<8> &input, bool positive, int bitIndex);

std::bitset<8> &
addZeroBipolarRepresentation(std::bitset<8> &input, int bitIndex);

void addBitBipolarRepresentation(bool bit, int bitIndex, bool &positive,
                                 std::bitset<8> &output);

std::bitset<8>
bipolarEncodeHalfByte(std::bitset<8> &byte, bool &positive, bool high);

#endif