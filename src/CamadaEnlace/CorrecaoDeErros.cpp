//
// Created by alexander on 10/05/2021.
//

#include "CorrecaoDeErros.hpp"

std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros) {
    bitStream quadrosEmBits = toBinary(quadros);
    std::bitset<8> quadroComHamming;

    for (auto & quadroEmBits : quadrosEmBits) {
        for (int i = 0; i < HAMMING_TAMANHO_DA_MENSAGEM; i++) {
            if (i && !(i & (i - 1)))
                quadroComHamming[i] = quadroEmBits[i];
        }
        quadroComHamming[7] = false;
    }

    for (int i = 1; i < HAMMING_QUANTIDADE_DE_BITS_DE_DADOS; i = i * 2)
        quadroComHamming[i] = calcularBitParidadeHamming(quadroComHamming, i);

    return quadros;
}

int calcularBitParidadeHamming(std::bitset<8> quadroComHamming, int i) {

}

std::string CamadaDeEnlaceReceptoraControleDeErroHamming(std::string quadros) {
    return quadros;
}
