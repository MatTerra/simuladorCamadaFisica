//
// Created by mateusberardo on 31/03/2021.
//
#include "binary_utils.h"

bitStream toBinary(std::string input) {
    bitStream output;

    for (char &_char : input)
        output.insert(output.end(), std::bitset<8>(_char));

    return output;
}

std::string fromBinary(bitStream bits) {
    std::string output;

    for (auto &byte : bits) {
        const char c = char(byte.to_ulong());
        output += c;
    }

    return output;
}
