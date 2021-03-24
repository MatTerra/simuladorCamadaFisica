#include "CamadaFisica.hpp"


void CamadaDeAplicacaoReceptora(std::string mensagem);

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits);

std::string CamadaFisicaReceptoraDecodificacaoBinaria();

void CamadaFisicaReceptora(bitStream fluxoBrutoDeBits) {
    int tipoDeDecodificacao = 0;
    std::string mensagemDecodificada;
    
    std::cout << "Camada física receptora recebeu o seguinte fluxo de bits: ";
    for (auto &byte : fluxoBrutoDeBits)
        std::cout << byte << " ";
    std::cout << std::endl;

    switch (tipoDeDecodificacao) {
        case CODIFICACAO_BINARIA:
            mensagemDecodificada = CamadaFisicaReceptoraDecodificacaoBinaria(
                    fluxoBrutoDeBits);
            break;
        case CODIFICACAO_MANCHESTER:
            break;
        case CODIFICACAO_BIPOLAR:
            break;
    }

    CamadaDeAplicacaoReceptora(mensagemDecodificada);
}

void CamadaDeAplicacaoReceptora(std::string mensagem) {
    std::cout << "Aplicação receptora recebeu a seguinte mensagem: <"
              << mensagem << std::endl;
}

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB) {
    std::copy(fluxoBrutoDeBitsPontoA.begin(),
              fluxoBrutoDeBitsPontoA.end(),
              fluxoBrutoDeBitsPontoB);
}

void MeioDeComunicacao(bitStream bits) {
    bitStream fluxoBrutoDeBitsPontoB;

    transmit(bits, fluxoBrutoDeBitsPontoB);

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

bitStream toBinary(std::string input) {
    bitStream output;

    for (char &_char : input)
        output.insert(output.end(), std::bitset<8>(_char));

    return output;
}

std::string fromBinary(bitStream bits){
    std::string output;

    for (auto &byte : bits)
        output.append(byte.to_string());

    return output;
}


void CamadaFisicaTransmissora(std::string quadro) {
    int tipoDeCodificacao = 0;
    bitStream fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case CODIFICACAO_BINARIA:
            std::cout << "Utilizando codificação binária!" << std::endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case CODIFICACAO_MANCHESTER:
            break;
        case CODIFICACAO_BIPOLAR:
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

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro) {
    return toBinary(quadro);
}
