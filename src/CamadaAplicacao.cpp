//
// Created by mateusberardo on 03/05/2021.
//

#include "CamadaAplicacao.hpp"

void AplicacaoTransmissora(){
    std::string mensagem;
    mensagem = getUserMessage();

    CamadaDeAplicacaoTransmissora(mensagem);
}

std::string getUserMessage(){
    std::string message;
    std::cout << "Digite uma mensagem:" << std::endl;
    std::cin >> message;
    return message;
}

void CamadaDeAplicacaoReceptora(std::string mensagem){
    std::cout << "Aplicação receptora recebeu a seguinte mensagem: "
              << '<'<< mensagem << '>' << std::endl;

}

void CamadaDeAplicacaoTransmissora(const std::string& message) {
    std::cout << "Aplicação Transmissora passando a seguinte mensagem "
              << "para a camada de enlace: <" << message << ">" << std::endl;
    CamadaEnlaceDadosTransmissora(message);
}
