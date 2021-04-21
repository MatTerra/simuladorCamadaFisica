#include <string>
#include <iostream>
#include "CamadaFisica.hpp"
#include "CamadaEnlace.hpp"


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
    std::cout << "Aplicação Transmissora passando a seguinte mensagem "
              << "para a camada física: <" << message << ">" << std::endl;
    CamadaEnlaceDadosTransmissora(message);
//    CamadaFisicaTransmissora(message);
}

int main() {
    AplicacaoTransmissora();
    return 0;
}
