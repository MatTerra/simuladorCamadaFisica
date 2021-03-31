#include "CamadaFisica.hpp"

#define CODIFICAO_ESCOLHIDA 1


void CamadaDeAplicacaoReceptora(std::string mensagem);

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits);

void CamadaFisicaReceptora(bitStream fluxoBrutoDeBits) {
    int tipoDeDecodificacao = CODIFICAO_ESCOLHIDA;
    std::string mensagemDecodificada;

    std::cout << "Camada física receptora recebeu o seguinte fluxo de bits: ";
    for (auto &byte : fluxoBrutoDeBits)
        std::cout << byte << " ";
    std::cout << std::endl;

    switch (tipoDeDecodificacao) {
        case CODIFICACAO_BINARIA:
            std::cout << "Utilizando decodificação binária!" << std::endl;
            mensagemDecodificada = CamadaFisicaReceptoraDecodificacaoBinaria(
                    fluxoBrutoDeBits);
            break;
        case CODIFICACAO_MANCHESTER:
            std::cout << "Utilizando decodificação manchester!" << std::endl;
            mensagemDecodificada = CamadaFisicaReceptoraDecodificacaoManchester(
                    fluxoBrutoDeBits);
            break;
        case CODIFICACAO_BIPOLAR:
            std::cout << "Utilizando decodificação bipolar!" << std::endl;
            break;
    }

    CamadaDeAplicacaoReceptora(mensagemDecodificada);
}

void CamadaDeAplicacaoReceptora(std::string mensagem) {
    std::cout << "Aplicação receptora recebeu a seguinte mensagem: "
              << '<'<< mensagem << '>' << std::endl;
}

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB) {
    fluxoBrutoDeBitsPontoB = fluxoBrutoDeBitsPontoA;
}

void MeioDeComunicacao(bitStream bits) {
    bitStream fluxoBrutoDeBitsPontoB;

    transmit(bits, fluxoBrutoDeBitsPontoB);

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}



void CamadaFisicaTransmissora(std::string quadro) {
    int tipoDeCodificacao = CODIFICAO_ESCOLHIDA;
    bitStream fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case CODIFICACAO_BINARIA:
            std::cout << "Utilizando codificação binária!" << std::endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case CODIFICACAO_MANCHESTER:
            std::cout << "Utilizando codificação manchester!" << std::endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        case CODIFICACAO_BIPOLAR:
            std::cout << "Utilizando codificação bipolar!" << std::endl;
            break;
    }

    mostrarProcessamentoCamadaFisicaTransmissora(fluxoBrutoDeBits);

    MeioDeComunicacao(fluxoBrutoDeBits);
}

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits) {
    std::cout << "Camada física transmitindo o seguinte fluxo de bits: ";

    for (auto &byte : fluxoBrutoDeBits)
        std::cout << byte << " ";

    std::cout << std::endl;
}

std::string CamadaFisicaReceptoraDecodificacaoBinaria(bitStream bits) {
    return fromBinary(bits);
}

std::string CamadaFisicaReceptoraDecodificacaoManchester(bitStream bytes) {
    std::string output;
    bitStream decoded;
    bool high=true;
    std::bitset<8> decodedByte;

    int bitIndex = 7;


    for(auto &byte : bytes) {
        for(int i = 7; i >= 0; i -= 2) {
            decodedByte[bitIndex--] = byte[i];
        }
        if(!high){
            decoded.insert(decoded.end(), decodedByte);
            bitIndex = 7;
        }
        high = !high;
    }

    return fromBinary(decoded);
}

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro) {
    return toBinary(quadro);
}

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

bitStream CamadaFisicaTransmissoraCodificacaoBipolar(std::string quadro) {
    bitStream output;
    bitStream message = toBinary(quadro);
    bool positive= true;

    for (auto &byte : message) {
        std::bitset<8> highHalf;
        std::bitset<8> lowHalf;

        for (int i = 7; i >= 0; i--)
            if(byte[4 + i/2] == 1 && positive){
                highHalf[i] = 0;
                highHalf[i+1] = 1;
                positive = !positve;
            }


        for (int i = 7; i >= 0; i--)
            lowHalf[i] = i % 2 == byte[i/2];

        output.insert(output.end(), highHalf);
        output.insert(output.end(), lowHalf);
    }

    return output;
}

