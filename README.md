# Simulador de Camada Física e Enlace

Esse projeto realiza uma simulação do funcionamento da camada física e da camada de enlace de redes de comunicação.

Serão implementados os seguintes protocolos de camada física:

 1. Binário
 2. Manchester
 3. Bipolar

Serão implementadas as seguintes técnicas de enquadramento:

 1. Contagem de caracteres
 1. Inserção de bytes

Serão implementados os seguintes protocolos de detecção de erros:

 1. Bit de paridade par
 1. CRC32 IEEE

Será implementado também o código de Hamming para detecção e correção de erros.

É possível incluir erros aleatórios de transmissão alterando o parâmetro
PORCENTAGEM_ERRO no arquivo [CamadaFisica](src/CamadaFisica.hpp). No
arquivo de cada camada é possível alterar os protocolos utilizados por meio
das macros.

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
cd src && ls simuladorRedes
```

Você pode copiar o executável para a pasta que deseja utilizar o simulador e executá-lo com o comando abaixo:
```
./simuladorRedes
```

## Ferramentas de build

* [CMake](https://cmake.org/)
* [Make](https://www.gnu.org/software/make/)


## Autores

* **Mateus Berardo** - *Autor* - [MatTerra](https://github.com/MatTerra)
* **Estevan Alexander** - *Autor* - [alexander-p30](https://github.com/alexander-p30)
* **Lucas Azuma** - *Autor* - [lucasazuma](https://github.com/lucasazuma)

Veja também os [contribuidores](graphs/contributors).

## License

Os autores reservam-se todos os direitos ao código aqui fornecido.
É estritamente proibido copiar ou modificar o código fornecido.
É permitido o uso do código apenas para fins educacionais e somente
se os autores forem creditados. Para qualquer outro uso ou condições mais
permissivas, entre em contato com os autores. Quaisquer exceções feitas pelos
autores para terceiros não significam mudanças nos termos desta licença
para outras pessoas.

## Agradecimentos

* **Billie Thompson** - *README template* - [PurpleBooth](https://github.com/PurpleBooth)

