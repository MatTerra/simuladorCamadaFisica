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
    std::bitset<8> decodedByte;

    int bitIndex = 7;


    for(auto &byte : bytes) {
        for(int i = 7; i >= 0; i -= 2) {
            decodedByte[bitIndex--] = byte[i];
        }
        if(bitIndex<=0){
            decoded.insert(decoded.end(), decodedByte);
            bitIndex = 7;
        }
    }

    return fromBinary(decoded);
}

s
