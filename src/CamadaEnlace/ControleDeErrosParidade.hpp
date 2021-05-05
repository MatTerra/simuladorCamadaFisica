//
// Created by mateusberardo on 03/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CONTROLEDEERROSPARIDADE_HPP
#define SIMULADORCAMADAFISICA_CONTROLEDEERROSPARIDADE_HPP

#include <string>
#include <algorithm>
#include <iostream>


std::string CamadaDeEnlaceTransmissoraControleDeErroBitParidadePar(std::string quadros);
std::string CamadaDeEnlaceReceptoraControleDeErroBitParidadePar(std::string quadros);
char getParity(unsigned char n);


#endif //SIMULADORCAMADAFISICA_CONTROLEDEERROSPARIDADE_HPP
