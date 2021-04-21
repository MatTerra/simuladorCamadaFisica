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

void CamadaEnlaceDadosReceptora(std::vector<frame> quadros);

void CamadaEnlaceDadosReceptoraEnquadramento(std::vector<frame> quadros);

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(std::string mensagem);

std::vector<frame> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(std::string mensagem);

#endif
