//
// Created by alexander on 10/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CORRECAODEERROS_H
#define SIMULADORCAMADAFISICA_CORRECAODEERROS_H

#define HAMMING_QUANTIDADE_DE_BITS_DE_DADOS 4
#define HAMMING_QUANTIDADE_DE_BITS_DE_PARIDADE 3
#define HAMMING_TAMANHO_DA_MENSAGEM HAMMING_QUANTIDADE_DE_BITS_DE_DADOS + HAMMING_QUANTIDADE_DE_BITS_DE_PARIDADE

#include <string>
#include <iostream>
#include "../BinaryUtils.h"

std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros);
std::string CamadaDeEnlaceReceptoraControleDeErroHamming(std::string quadros);
int calcularBitParidadeHamming(std::bitset<8> quadroComHamming, int i);

#endif //SIMULADORCAMADAFISICA_CORRECAODEERROS_H
