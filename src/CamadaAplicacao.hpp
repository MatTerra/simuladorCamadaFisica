//
// Created by mateusberardo on 03/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CAMADAAPLICACAO_HPP
#define SIMULADORCAMADAFISICA_CAMADAAPLICACAO_HPP

#include <string>
#include <iostream>
#include "CamadaEnlace.hpp"

std::string getUserMessage();

void AplicacaoTransmissora();

void CamadaDeAplicacaoReceptora(std::string mensagem);

void CamadaDeAplicacaoTransmissora(const std::string& message);



#endif //SIMULADORCAMADAFISICA_CAMADAAPLICACAO_HPP
