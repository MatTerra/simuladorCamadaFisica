//
// Created by mateusberardo on 31/03/2021.
//

#ifndef SIMULADORCAMADAFISICA_BINARY_UTILS_H
#define SIMULADORCAMADAFISICA_BINARY_UTILS_H

#include <bitset>
#include <vector>

typedef std::vector<std::bitset<8>> bitStream;

bitStream toBinary(std::string input);

std::string fromBinary(bitStream bits);

#endif //SIMULADORCAMADAFISICA_BINARY_UTILS_H
