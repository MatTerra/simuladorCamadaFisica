#include "CodificacaoManchester.hpp"

bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro) {
    bitStream output;
    bitStream message = toBinary(quadro);

    for (auto &byte : message) {
        std::bitset<8> highHalf;
        std::bitset<8> lowHalf;

        for (int i = 7; i >= 0; i--)
            highHalf[i] = i % 2 == byte[4 + i/2];

        for (int i = 7; i >= 0; i--)
            lowHalf[i] = i % 2 == byte[i/2];

        output.insert(output.end(), highHalf);
        output.insert(output.end(), lowHalf);
    }

    return output;
}

std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream bytes) {
    bitStream decoded;
    for(int i = 0; i < bytes.size(); i += 2){
        decoded.insert(decoded.end(), decodeByte(bytes.at(i), bytes.at(i+1)));
    }
    return fromBinary(decoded);
}

std::bitset<8> decodeByte(std::bitset<8> highByte, std::bitset<8> lowByte ){
    std::bitset<8> decodedByte;
    decodeHalfByte(decodedByte, highByte, 7);
    decodeHalfByte(decodedByte, lowByte, 3);
    return decodedByte;
}

std::bitset<8> decodeHalfByte(std::bitset<8> &decodedByte, std::bitset<8> byte, int bitIndex){
    for(int i = 7; i >= 0; i -= 2) {
        decodedByte[bitIndex--] = byte[i];
    }
    return decodedByte;
}


