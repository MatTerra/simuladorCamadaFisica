# Simulador de Camada Física

Esse projeto realiza uma simulação do funcionamento da camada física de redes de comunicação. Serão implementados os seguintes protocolos:

 1. Binário
 2. Manchester
 3. Bipolar

## Primeiros Passos

Esse programa depende do cmake, make e g++ para compilação. Ele foi desenvolvido utilizando C++11. Por favor instale as dependências de build antes de continuar.

### Compilando

Para compilar o projeto, siga os passos abaixo.

Primeiramente, execute o CMake para gerar os Makefiles:
```
cmake -B build
```

Em seguida, entre no diretório de build e execute o make(Você pode adicionar `-j<cores>` para acelerar a compilação):
```
cd build && make
```

Depois, o programa está compilado e pronto para uso. Você pode verificar executando os comandos abaixo a partir do diretório de build.
```
cd src && ls simuladorCamadaFisica
```

Você pode copiar o executável para a pasta que deseja utilizar o simulador e executá-lo com o comando abaixo:
```
./simuladorCamadaFisica
```
<!--
## Running Unit Tests

The project was developed through an TDD approach, thus, it contains a thorough test suite, which is built with the executable. To run it, access the tests folder in the build directory and run the following command:

```
./simulador_tst
```
-->
## Ferramentas de build

* [CMake](https://cmake.org/)
* [Make](https://www.gnu.org/software/make/)


## Autores

* **Mateus Berardo** - *Autor* - [MatTerra](https://github.com/MatTerra)
* ...

Also check out the [contributors](graphs/contributors).

## License

O autor reserva-se todos os direitos ao código aqui fornecido. É estritamente proibido copiar ou modificar o código fornecido. É permitido o uso do código apenas para fins educacionais e somente se o autor for creditado. Para qualquer outro uso ou condições mais permissivas, entre em contato com o autor. Quaisquer exceções feitas pelo autor para terceiros não significam mudanças nos termos desta licença para outras pessoas.

## Agradecimentos

* **Billie Thompson** - *README template* - [PurpleBooth](https://github.com/PurpleBooth)

