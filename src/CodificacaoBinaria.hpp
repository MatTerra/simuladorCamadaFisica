#ifndef CODIFICACAO_BINARIA_H
#define CODIFICACAO_BINARIA_H

#include "BinaryUtils.h"

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoBinaria(bitStream bits);

#endif