#ifndef CAMADAENLACE_H
#define CAMADAENLACE_H

#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include "CamadaFisica.hpp"

#define PROTOCOLO_CONTAGEM_DE_CARACTERES 0
#define PROTOCOLO_INSERCAO_DE_BYTES 1

#define PROTOCOLO_ENLACE_ESCOLHIDO PROTOCOLO_CONTAGEM_DE_CARACTERES

void CamadaEnlaceDadosTransmissora(std::string mensagem);

void CamadaEnlaceDadosTransmissoraEnquadramento(std::string mensagem);

void CamadaEnlaceDadosReceptora(std::string mensagem);

void CamadaEnlaceDadosReceptoraEnquadramento(std::string mensagem);

std::string CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem);

std::string CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);

void mostrarQuadros(std::string quadros);

void mostrarProcessamentoCamadaEnlaceTransmissora(std::string quadros);

unsigned int getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i);

#endif
