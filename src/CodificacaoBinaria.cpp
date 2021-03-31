#include "CodificacaoBinaria.hpp"

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro) {
    return toBinary(quadro);
}

std::string CamadaFisicaReceptoraDecodificacaoBinaria(bitStream bits) {
    return fromBinary(bits);
}
