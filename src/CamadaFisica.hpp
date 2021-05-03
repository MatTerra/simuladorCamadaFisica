#ifndef CAMADAFISICA_H
#define CAMADAFISICA_H

#include <string>
#include <bitset>
#include <vector>
#include <iostream>

#include "BinaryUtils.h"
#include "CamadaFisica/CodificacaoBinaria.hpp"
#include "CamadaFisica/CodificacaoManchester.hpp"
#include "CamadaFisica/CodificacaoBipolar.hpp"

#define CODIFICACAO_BINARIA 0
#define CODIFICACAO_MANCHESTER 1
#define CODIFICACAO_BIPOLAR 2

#define CODIFICAO_ESCOLHIDA CODIFICACAO_BINARIA

void CamadaFisicaTransmissora(std::string quadro);

void CamadaFisicaReceptora(bitStream fluxoBrutoDeBits);

void MeioDeComunicacao(bitStream bits);

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB);

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits);

void mostrarProcessamentoCamadaFisicaReceptora(bitStream &fluxoBrutoDeBits);

void mostrarFluxoBrutoDeBits(bitStream &fluxoBrutoDeBits);

#endif
