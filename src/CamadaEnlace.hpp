#ifndef CAMADAENLACE_H
#define CAMADAENLACE_H

#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include "CamadaFisica.hpp"
#include "CamadaEnlace/ProtocoloDeContagemDeCaracteres.hpp"
#include "CamadaEnlace/ProtocoloInsercaoDeBytes.hpp"
#include "CamadaEnlace/ControleDeErrosParidade.hpp"

#define GROUP_SEPARATOR 29
#define PROTOCOLO_CONTAGEM_DE_CARACTERES 0
#define PROTOCOLO_INSERCAO_DE_BYTES 1

#define PROTOCOLO_ENLACE_ESCOLHIDO PROTOCOLO_CONTAGEM_DE_CARACTERES

#define CONTROLE_DE_ERRO_BIT_PARIDADE_PAR 0
#define CONTROLE_DE_ERRO_CRC 1
#define CONTROLE_DE_ERRO_ESCOLHIDO CONTROLE_DE_ERRO_CRC

#if PROTOCOLO_ENLACE_ESCOLHIDO == PROTOCOLO_CONTAGEM_DE_CARACTERES
#   define EFFECTIVE_FRAME_SIZE (FRAME_SIZE - 1)
#elif PROTOCOLO_ENLACE_ESCOLHIDO == PROTOCOLO_INSERCAO_DE_BYTES
#   define EFFECTIVE_FRAME_SIZE (FRAME_SIZE - 2)
#endif

void CamadaEnlaceDadosTransmissora(std::string mensagem);

std::string CamadaEnlaceDadosTransmissoraEnquadramento(std::string mensagem);
std::string CamadaDeEnlaceTransmissoraControleDeErro(std::string quadros);
std::string CamadaEnlaceDadosReceptoraControleDeErro(std::string quadros);

void CamadaEnlaceDadosReceptora(std::string mensagem);

std::string CamadaEnlaceDadosReceptoraEnquadramento(std::string mensagem);

void mostrarQuadros(std::string quadros);

void mostrarProcessamentoCamadaEnlaceTransmissora(std::string quadros);

unsigned short getFrameSize(unsigned int quantidadeDeQuadros, unsigned int lastFrameSize, int i);

unsigned int getAmountOfFrames(const std::string &mensagem);

bool isLastFrame(unsigned int quantidadeDeQuadros, int i);

unsigned int getLastFrameSize(const std::string &mensagem);

int getNextSeparatorIndex(int i, std::string quadros);

#endif
