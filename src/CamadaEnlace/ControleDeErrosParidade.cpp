//
// Created by mateusberardo on 03/05/2021.
//

#include <algorithm>
#include "ControleDeErrosParidade.hpp"

std::string CamadaDeEnlaceTransmissoraControleDeErroBitParidadePar(std::string quadros) {
    std::transform(quadros.begin(), quadros.end(), quadros.begin(), [](char c){ return (c<<1)|getParity(c);});
    return quadros;
}
std::string CamadaDeEnlaceReceptoraControleDeErroBitParidadePar(std::string quadros){
    return quadros;
}
char getParity(char n) {
    bool parity = 0;
    while (n) {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity?1:0;
}
