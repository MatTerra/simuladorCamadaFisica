//
// Created by mateusberardo on 03/05/2021.
//
#include "ControleDeErrosParidade.hpp"

std::string CamadaDeEnlaceTransmissoraControleDeErroBitParidadePar(std::string quadros) {
    std::transform(quadros.begin(), quadros.end(), quadros.begin(),
                   [](char c){ return (c<<1)|getParity(c);});
    return quadros;
}
std::string CamadaDeEnlaceReceptoraControleDeErroBitParidadePar(std::string quadros){
    std::cout << "Verificando se ocorreram erros na transmissão" << std::endl;
    for (unsigned char c : quadros){
        if (getParity(c))
            std::cout << "Foi detectado um erro" << std::endl;
    }
    std::transform(quadros.begin(), quadros.end(), quadros.begin(),
                   [](unsigned char c){ return (c>>1); });
    return quadros;
}
char getParity(unsigned char n) {
    bool parity = 0;
    while (n) {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity?1:0;
}
