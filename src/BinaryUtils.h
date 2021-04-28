//
// Created by mateusberardo on 31/03/2021.
//

#ifndef SIMULADORCAMADAFISICA_BINARYUTILS_H
#define SIMULADORCAMADAFISICA_BINARYUTILS_H

#include <bitset>
#include <vector>

#define HIGH_BYTE_HALF true
#define LOW_BYTE_HALF false

#define FRAME_SIZE 8

typedef std::vector<std::bitset<8>> bitStream;

typedef std::bitset<8> frame[FRAME_SIZE];

bitStream toBinary(std::string input);

std::string fromBinary(bitStream bits);

#endif //SIMULADORCAMADAFISICA_BINARYUTILS_H
