#ifndef CODIFICACAO_MANCHESTER_H
#define CODIFICACAO_MANCHESTER_H

#include "BinaryUtils.h"

bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro);

std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream bits);

#endif