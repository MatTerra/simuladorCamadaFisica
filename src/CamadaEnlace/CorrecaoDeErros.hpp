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
bool makeSum(std::bitset<4> n);
std::bitset<8> hammingEncodeHalfByte(std::bitset<4> halfByte);
bitStream hammingEncodeByte(std::bitset<8> byte_);
std::bitset<8> hammingDecodeByte(std::bitset<8> highByte, std::bitset<8> lowByte);
std::bitset<8> hammingDecodeHalfByte(std::bitset<8> &decodedByte,
                                     std::bitset<8> byte_, bool isHighHalf);
void hammingCheckByteErrors(std::bitset<8> byte_);

#endif //SIMULADORCAMADAFISICA_CORRECAODEERROS_H
