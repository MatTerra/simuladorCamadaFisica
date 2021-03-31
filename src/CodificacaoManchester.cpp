#include "CodificacaoManchester.hpp"

bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro) {
    bitStream output;
    bitStream message = toBinary(quadro);

    for (auto &byte : message) {
        output.insert(output.end(),
                      encodeHalfByte(byte, HIGH_BYTE_HALF));
        output.insert(output.end(),
                      encodeHalfByte(byte, LOW_BYTE_HALF));
    }

    return output;
}

std::bitset<8> encodeHalfByte(std::bitset<8> &byte, bool isHighHalf) {
    std::bitset<8> encodedByte;
    int bitOffset = isHighHalf ? 4 : 0;

    for (int i = 7; i >= 0; i--)
        encodedByte[i] = i % 2 == byte[bitOffset + i / 2];
    
    return encodedByte;
}

std::string CamadaFisicaReceptoraDecodificacaoManchester(
        bitStream encodedBytes) {
    bitStream decodedBytes;

    for(int i = 0; i < encodedBytes.size(); i += 2)
        decodedBytes.insert(decodedBytes.end(),
                            decodeByteManchester(encodedBytes.at(i),
                                                 encodedBytes.at(i + 1)));

    return fromBinary(decodedBytes);
}

std::bitset<8> decodeByteManchester(std::bitset<8> highByte, std::bitset<8> lowByte){
    std::bitset<8> decodedByte;

    decodedByte = decodeHalfByteManchester(decodedByte, highByte, HIGH_BYTE_HALF);
    decodedByte = decodeHalfByteManchester(decodedByte, lowByte, LOW_BYTE_HALF);

    return decodedByte;
}

std::bitset<8> decodeHalfByteManchester(std::bitset<8> &decodedByte,
                              std::bitset<8> byte, bool isHighHalf){
    int bitIndex = isHighHalf ? 7 : 3;

    for(int i = 7; i >= 0; i -= 2)
        decodedByte[bitIndex--] = byte[i];

    return decodedByte;
}
