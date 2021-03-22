#include <string>
#include <bitset>
#include <vector>

#define CODIFICACAO_BINARIA 0
#define CODIFICACAO_MANCHESTER 1
#define CODIFICACAO_BIPOLAR 2

typedef std::vector<std::bitset<8>> bitStream;

void CamadaFisicaTransmissora(std::string quadro);

void CamadaFisicaReceptora(bitStream bits);

void MeioDeComunicacao(bitStream bits);

void transmit(bitStream &fluxoBrutoDeBitsPontoA,
              bitStream &fluxoBrutoDeBitsPontoB);

bitStream CamadaFisicaTransmissoraCodificacaoBinaria(std::string quadro);
bitStream CamadaFisicaTransmissoraCodificacaoManchester(std::string quadro);
bitStream CamadaFisicaTransmissoraCodificacaoBipolar(std::string quadro);

unsigned long getStringBinarySize(const std::string &quadro);

bitStream toBinary(std::string input);