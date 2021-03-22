#include <string>
#include <iostream>
#include "CamadaFisica.hpp"


std::string getUserMessage();

void CamadaDeAplicacaoTransmissora(const std::string& message);

void AplicacaoTransmissora(){
    std::string mensagem;
    mensagem = getUserMessage();

    CamadaDeAplicacaoTransmissora(mensagem);
}

std::string getUserMessage() {
    std::string message;
    std::cout << "Digite uma mensagem:" << std::endl;
    std::cin >> message;
    return message;
}

void CamadaDeAplicacaoTransmissora(const std::string& message) {
    CamadaFisicaTransmissora(message);
}

int main() {
    AplicacaoTransmissora();
    return 0;
}
