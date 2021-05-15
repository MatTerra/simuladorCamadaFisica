//
// Created by alexander on 10/05/2021.
//

#ifndef SIMULADORCAMADAFISICA_CORRECAODEERROS_H
#define SIMULADORCAMADAFISICA_CORRECAODEERROS_H

#include <string>
#include <iostream>
#include "../BinaryUtils.h"

static std::bitset<4> generatorMatrix[] = {0b1101, 0b1011, 0b1000, 0b0111,
                                           0b0100, 0b0010, 0b0001, 0b1110};

static std::bitset<8> parityMatrix[] = {0b10101010, 0b01100110,
                                        0b00011110, 0b11111111};

static std::bitset<8> messageMatrix[] = {0b00100000, 0b00001000,
                                         0b00000100, 0b00000010};



std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros);
std::string CamadaDeEnlaceReceptoraControleDeErroHamming(std::string quadros);

bitStream hammingEncodeByte(std::bitset<8> byte_);
std::bitset<8> hammingDecodeByte(std::bitset<8> highByte, std::bitset<8> lowByte);

std::bitset<8> hammingEncodeHalfByte(std::bitset<4> halfByte);
std::bitset<8> hammingDecodeHalfByte(std::bitset<8> decodedByte,
                                     std::bitset<8> byte_, bool isHighHalf);

void hammingCheckByteErrors(std::bitset<8> *byte_);
std::bitset<4> calculateSyndrome(const std::bitset<8> &byte_);

template<std::size_t N>
bool makeSum(std::bitset<N> n);
void splitByte(const std::bitset<8> &byte_, std::bitset<4> &lowHalf,
               std::bitset<4> &highHalf);

#endif //SIMULADORCAMADAFISICA_CORRECAODEERROS_H
