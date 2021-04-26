#include "CamadaFisica.hpp"
#include "CamadaEnlace.hpp"

void CamadaFisicaReceptora(bitStream fluxoBrutoDeBits) {
    int tipoDeDecodificacao = CODIFICAO_ESCOLHIDA;
    std::string mensagemDecodificada;

    mostrarProcessamentoCamadaFisicaReceptora(fluxoBrutoDeBits);

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
            mensagemDecodificada = CamadaFisicaReceptoraDecodificacaoBipolar(
                    fluxoBrutoDeBits);
            break;
    }

    CamadaEnlaceDadosReceptora(mensagemDecodificada);
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
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
            break;
    }

    mostrarProcessamentoCamadaFisicaTransmissora(fluxoBrutoDeBits);

    MeioDeComunicacao(fluxoBrutoDeBits);
}

void mostrarFluxoBrutoDeBits(bitStream &fluxoBrutoDeBits) {
    for (auto &byte : fluxoBrutoDeBits)
        std::cout << byte << " ";

    std::cout << std::endl;
}

void mostrarProcessamentoCamadaFisicaTransmissora(bitStream &fluxoBrutoDeBits) {
    std::cout << "Camada física transmitindo o seguinte fluxo de bits: ";
    mostrarFluxoBrutoDeBits(fluxoBrutoDeBits);
}

void mostrarProcessamentoCamadaFisicaReceptora(bitStream &fluxoBrutoDeBits) {
    std::cout << "Camada física receptora recebeu o seguinte fluxo de bits: ";
    mostrarFluxoBrutoDeBits(fluxoBrutoDeBits);
}

