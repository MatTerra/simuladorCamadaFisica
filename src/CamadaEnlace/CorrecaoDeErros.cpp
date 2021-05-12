//
// Created by alexander on 10/05/2021.
//

#include "CorrecaoDeErros.hpp"

bool checkHammingParity(const std::bitset<8> &byte_);

std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros) {
    bitStream quadrosEmBits = toBinary(quadros);
    bitStream quadrosCodificados;
    std::bitset<4> matrizGeradora[] = {0b1101, 0b1011, 0b1000, 0b0111, 0b0100, 0b0010, 0b0001, 0b1110};
    std::bitset<8> quadroComHamming;

    for (auto byte_ : quadrosEmBits) {
        std::bitset<4> lowHalf;
        std::bitset<4> highHalf;

        for(size_t i = 0; i < 4; i++) {
            lowHalf[i] = byte_[i];
            highHalf[i] = byte_[i + 4];
        }

        for(size_t i = 0; i < 8; i++)
            quadroComHamming[i] = makeSum(highHalf & matrizGeradora[7 - i]);

        quadrosCodificados.insert(quadrosCodificados.end(), quadroComHamming);

        for(size_t i = 0; i < 8; i++)
            quadroComHamming[i] = makeSum(lowHalf & matrizGeradora[7 - i]);

        quadrosCodificados.insert(quadrosCodificados.end(), quadroComHamming);
    }

    return fromBinary(quadrosCodificados);
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
    std::bitset<8> messageMatrix[] = {0b00100000, 0b00001000, 0b00000100, 0b00000010};


    for (int i=0; i < binaryFrames.size(); i += 2) {
        std::bitset<8> byte_;
        std::bitset<8> messageByte;

        byte_ = binaryFrames[i];
        if (checkHammingParity(byte_) != 0)
            std::cout << "Erro detectado!" << std::endl;
        for(size_t i = 0; i < 4; i++)
            messageByte[7 - i] = makeSum(messageMatrix[i] & byte_);

        byte_ = binaryFrames[i + 1];
        if (checkHammingParity(byte_) != 0)
            std::cout << "Erro detectado!" << std::endl;
        for (size_t i = 0; i < 4; i++)
            messageByte[3 - i] = makeSum(messageMatrix[i] & byte_);


        decodedFrames.insert(decodedFrames.end(), messageByte);
    }

    return fromBinary(decodedFrames);
}

bool checkHammingParity(const std::bitset<8> &byte_) {
    std::bitset<8> parityMatrix[] = {0b10101010, 0b01100110, 0b00011110, 0b11111111};
    std::bitset<4> verificationNyble;

    for (size_t i = 0; i < 4; i++)
        verificationNyble[3 - i] = makeSum(parityMatrix[i] & byte_);

    return verificationNyble == 0;
}
