//
// Created by alexander on 10/05/2021.
//

#include "CorrecaoDeErros.hpp"

bool checkHammingParity(const std::bitset<8> &byte_);

std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros) {
    bitStream quadrosEmBits = toBinary(quadros);
    bitStream encodedFrames;

    for (auto byte_ : quadrosEmBits) {
        bitStream encodedByte = hammingEncodeByte(byte_);
        encodedFrames.insert(encodedFrames.end(), encodedByte.begin(), encodedByte.end());
    }

    return fromBinary(encodedFrames);
}


bool makeSum(std::bitset<4> n) {
    bool parity = false;

    for (int c=0; c<4; c++)
        parity ^= n[c];

    return parity;
}

bool makeSum(std::bitset<8> n) {
    bool parity = false;

    for (int c=0; c<8; c++)
        parity ^= n[c];

    return parity;
}

std::string CamadaDeEnlaceReceptoraControleDeErroHamming(std::string quadros) {
    bitStream binaryFrames = toBinary(quadros);
    bitStream decodedFrames;

    for (int i=0; i < binaryFrames.size(); i += 2)
        decodedFrames.insert(decodedFrames.end(), hammingDecodeByte(binaryFrames[i],
                                                                    binaryFrames[i+1]));

    return fromBinary(decodedFrames);
}

std::bitset<8> hammingDecodeByte(std::bitset<8> highByte, std::bitset<8> lowByte){
    std::bitset<8> decodedByte;

    hammingCheckByteErrors(highByte);
    decodedByte = hammingDecodeHalfByte(decodedByte, highByte, true);

    hammingCheckByteErrors(lowByte);
    decodedByte = hammingDecodeHalfByte(decodedByte, lowByte, false);

    return decodedByte;
}

std::bitset<8> hammingDecodeHalfByte(std::bitset<8> &decodedByte,
                                        std::bitset<8> byte_, bool isHighHalf){
    std::bitset<8> messageMatrix[] = {0b00100000, 0b00001000, 0b00000100, 0b00000010};
    int bitIndex = isHighHalf ? 7 : 3;

    for(size_t i = 0; i < 4; i++)
        decodedByte[bitIndex - i] = makeSum(messageMatrix[i] & byte_);

    return decodedByte;
}

void hammingCheckByteErrors(std::bitset<8> byte_){
    if (checkHammingParity(byte_) == 0)
        std::cout << "Erro detectado!" << std::endl;
}
//TODO mesmo com porcentagem de erro igual a 0 ainda existem erros independente da condição( == 0 ou != 0)
bool checkHammingParity(const std::bitset<8> &byte_) {
    std::bitset<8> parityMatrix[] = {0b10101010, 0b01100110, 0b00011110, 0b11111111};
    std::bitset<4> verificationNyble;

    for (size_t i = 0; i < 4; i++)
        verificationNyble[3 - i] = makeSum(parityMatrix[i] & byte_);

    return verificationNyble == 0;
}

std::bitset<8> hammingEncodeHalfByte(std::bitset<4> halfByte){
    std::bitset<4> matrizGeradora[] = {0b1101, 0b1011, 0b1000, 0b0111, 0b0100, 0b0010, 0b0001, 0b1110};
    std::bitset<8> encodedHalfByte;
    for(size_t i = 0; i < 8; i++)
        encodedHalfByte[i] = makeSum(halfByte & matrizGeradora[7 - i]);
    return encodedHalfByte;
}

bitStream hammingEncodeByte(std::bitset<8> byte_){
    std::bitset<4> lowHalf;
    std::bitset<4> highHalf;
    bitStream encodedByte;

    for(size_t i = 0; i < 4; i++) {
        lowHalf[i] = byte_[i];
        highHalf[i] = byte_[i + 4];
    }

    encodedByte.insert(encodedByte.end(), hammingEncodeHalfByte(highHalf));
    encodedByte.insert(encodedByte.end(), hammingEncodeHalfByte(lowHalf));
    return encodedByte;
}


