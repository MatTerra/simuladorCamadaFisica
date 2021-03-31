#include "CodificacaoBipolar.hpp"

std::string CamadaFisicaReceptoraDecodificacaoBipolar(bitStream encodedBytes) {
    bitStream decodedBytes;

    for(int i = 0; i < encodedBytes.size(); i += 2)
        decodedBytes.insert(decodedBytes.end(),
                            decodeByteBipolar(encodedBytes.at(i),
                                              encodedBytes.at(i + 1)));

    return fromBinary(decodedBytes);
}

std::bitset<8> decodeByteBipolar(std::bitset<8> highByte, std::bitset<8> lowByte){
    std::bitset<8> decodedByte;

    decodedByte = decodeHalfByteBipolar(decodedByte, highByte, HIGH_BYTE_HALF);
    decodedByte = decodeHalfByteBipolar(decodedByte, lowByte, LOW_BYTE_HALF);

    return decodedByte;
}

std::bitset<8> decodeHalfByteBipolar(std::bitset<8> &decodedByte,
                                     std::bitset<8> byte, bool isHighHalf){
    int bitIndex = isHighHalf ? 7 : 3;

    for(int i = 7; i >= 0; i -= 2)
        decodedByte[bitIndex--] = byte[i] || byte[i-1];

    return decodedByte;
}

bitStream CamadaFisicaTransmissoraCodificacaoBipolar(std::string quadro) {
    bitStream output;
    bitStream message = toBinary(quadro);
    bool positive= true;

    for (auto &byte : message) {
        output.insert(output.end(),
                      bipolarEncodeHalfByte(byte, positive, HIGH_BYTE_HALF));
        output.insert(output.end(),
                      bipolarEncodeHalfByte(byte, positive, LOW_BYTE_HALF));
    }

    return output;
}


std::bitset<8> bipolarEncodeHalfByte(std::bitset<8> &byte, bool &positive, bool high) {
    int bitIndex = 7;
    std::bitset<8> output;

    int startingIndex = high ? 7 : 3;
    int lastIndex = high ? 4 : 0;

    for (int i = startingIndex; i >= lastIndex; i--) {
        addBitBipolarRepresentation(byte[i], bitIndex, positive, output);
        bitIndex-=2;
    }

    return output;
}

void addBitBipolarRepresentation(bool bit, int bitIndex, bool &positive,
                                 std::bitset<8> &output) {
    if (bit) {
        output = addOneBipolarRepresentation(output, positive, bitIndex);
        positive = !positive;
    } else {
        output = addZeroBipolarRepresentation(output, bitIndex);
    }
}

std::bitset<8> &addZeroBipolarRepresentation(
        std::bitset<8> &input, int bitIndex) {
    input[bitIndex] = 0;
    input[bitIndex-1] = 0;
    return input;
}

std::bitset<8> &addOneBipolarRepresentation(
        std::bitset<8> &input, bool positive, int bitIndex) {
    input[bitIndex] = !positive;
    input[bitIndex - 1] = positive;
    return input;
}

