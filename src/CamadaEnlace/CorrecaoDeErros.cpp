//
// Created by alexander on 10/05/2021.
//

#include "CorrecaoDeErros.hpp"

#include <utility>


std::string CamadaDeEnlaceTransmissoraControleDeErroHamming(std::string quadros) {
    bitStream binaryFrames = toBinary(std::move(quadros));
    bitStream encodedFrames;

    for (auto byte_ : binaryFrames) {
        auto encodedByte = hammingEncodeByte(byte_);
        encodedFrames.insert(encodedFrames.end(),
                             encodedByte.begin(), encodedByte.end());
    }

    return fromBinary(encodedFrames);
}

std::string CamadaDeEnlaceReceptoraControleDeErroHamming(std::string quadros) {
    bitStream binaryFrames = toBinary(std::move(quadros));
    bitStream decodedFrames;

    for (int i=0; i < binaryFrames.size(); i += 2)
        decodedFrames.insert(decodedFrames.end(),
                             hammingDecodeByte(binaryFrames[i],
                                               binaryFrames[i + 1]));

    return fromBinary(decodedFrames);
}

bitStream hammingEncodeByte(std::bitset<8> byte_){
    std::bitset<4> lowHalf;
    std::bitset<4> highHalf;
    bitStream encodedByte;

    splitByte(byte_, lowHalf, highHalf);

    encodedByte.insert(encodedByte.end(), hammingEncodeHalfByte(highHalf));
    encodedByte.insert(encodedByte.end(), hammingEncodeHalfByte(lowHalf));
    return encodedByte;
}

std::bitset<8> hammingEncodeHalfByte(std::bitset<4> halfByte){
    std::bitset<8> encodedHalfByte;

    for(size_t i = 0; i < 8; i++)
        encodedHalfByte[i] = makeSum(halfByte & generatorMatrix[7 - i]);

    return encodedHalfByte;
}

std::bitset<8> hammingDecodeByte(std::bitset<8> highByte, std::bitset<8> lowByte){
    std::bitset<8> decodedByte;

    hammingCheckByteErrors(&highByte);
    decodedByte = hammingDecodeHalfByte(decodedByte, highByte, HIGH_BYTE_HALF);

    hammingCheckByteErrors(&lowByte);
    decodedByte = hammingDecodeHalfByte(decodedByte, lowByte, LOW_BYTE_HALF);

    return decodedByte;
}

std::bitset<8> hammingDecodeHalfByte(std::bitset<8> decodedByte,
                                     std::bitset<8> byte_, bool isHighHalf){
    int bitIndex = isHighHalf ? 7 : 3;

    for(size_t i = 0; i < 4; i++)
        decodedByte[bitIndex - i] = makeSum(messageMatrix[i] & byte_);

    return decodedByte;
}

void hammingCheckByteErrors(std::bitset<8> *byte_){
    auto syndrome = calculateSyndrome(*byte_);

    if (syndrome != 0) {
        const auto hasOddParity = makeSum(*byte_);

        if(!hasOddParity){
            std::cout << "Erro duplo detectado!" << std::endl;
        } else {
            std::cout << "Tentando corrigir um erro!" << std::endl;
            unsigned long errorPosition = (syndrome&std::bitset<4>(0b0111)).to_ulong() - 1;
            byte_->flip((7 - errorPosition)%7);
        }
    }
}

std::bitset<4> calculateSyndrome(const std::bitset<8> &byte_) {
    std::bitset<4> verificationNyble;

    for (size_t i = 0; i < 4; i++)
        verificationNyble[i] = makeSum(parityMatrix[i] & byte_);

    return verificationNyble;
}

void splitByte(const std::bitset<8> &byte_, std::bitset<4> &lowHalf,
               std::bitset<4> &highHalf) {
    for(size_t i = 0; i < 4; i++) {
        lowHalf[i] = byte_[i];
        highHalf[i] = byte_[i + 4];
    }
}


template<std::size_t N>
bool makeSum(std::bitset<N> n) {
    bool parity = false;

    for (int c=0; c<N; c++)
        parity ^= n[c];

    return parity;
}
