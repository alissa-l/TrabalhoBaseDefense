# Trabalho Base Defense

# Componentes:
Alissa de Lima Araújo

Fagner Irineu de Medeiros

Filipe de Medeiros Alves

Pedro Lucas de Souza Martins

# Compilar e rodar (Debian):
```bash
sudo apt install libsfml-dev
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev \
sudo apt install cmake
cmake .
make
./TrabalhoBaseDefenseEXE
```


# Recursos extras implementados
- Níveis de dificuldade
- Tipos de inimigos
- Pause

## Listagem de diretórios
1. classes
    1. heroi.cpp
    2. heroi.hpp
    3. inimigo.cpp
    4. inimigo.hpp
    5. projetil.cpp
    6. projetil.hpp
2. trabalhoBaseDefense
    1. trabalhoBaseDefense.cpp
3. utils
    1. drawUtils.cpp
    2. drawUtils.hpp
    3. vectorUtils.cpp
    4. vectorUtils.hpp
4. resources
    1. font
        1. arial.ttf
    2. somTiro.mp3
5. src
    1. trabalhoBaseDefense
        1. game
            1. colisoes
                1. colisoes.cpp
                2. colisoes.h
            2. game.cpp
            3. game.h
            4. gameEntities
                1. actions
                    1. shooting
                        1. enemyShooting.cpp
                        2. enemyShooting.h
                        3. heroShooting.cpp
                        4. heroShooting.h
                    2. spawning
                        1. dropavelSpawn.cpp
                        2. dropavelSpawn.h
                        3. enemySpawn.cpp
                        4. enemySpawn.hpp
                2. gameEntity.h
                3. impl
                    1. base.cpp
                    2. base.hpp
                    3. dropaveis
                        1. dropavelContext.hpp
                        2. dropavelMunicao.cpp
                        3. dropavelMunicao.h
                        4. dropavelMunicaoStrategy.h
                        5. dropavelVidaBase.cpp
                        6. dropavelVidaBase.h
                        7. dropavelVidaBaseStrategy.h
                        8. dropavelVidaHeroi.cpp
                        9. dropavelVidaHeroi.h
                        10. dropavelVidaHeroiStrategy.h
                        11. iDropavelStrategy.h
                    4. dropavel.cpp
                    5. dropavel.h
                    6. heroi.cpp
                    7. heroi.hpp
                    8. inimigo.cpp
                    9. inimigo.h
                    10. inimigos
                        1. inimigoBoss.cpp
                        2. inimigoBoss.h
                        3. inimigoComum.cpp
                        4. inimigoComum.h
                        5. inimigoFortificado.cpp
                        6. inimigoFortificado.h
                        7. inimigoRapido.cpp
                        8. inimigoRapido.h
                    11. projetil.cpp
                    12. projetil.hpp
            5. gameUtils
                1. gameEnemyUtils.cpp
                2. gameEnemyUtils.h
            6. telas
                1. telaGameOver.cpp
                2. telaGameOver.h
                3. telaMenu.cpp
                4. telaMenu.h
            7. variables
                1. enemyVariables.hpp
                2. heroVariables.h
                3. variables.h
                4. windowConstants.h
        2. logger
            1. logLevel.h
            2. logger.cpp
            3. logger.hpp
        3. trabalhoBaseDefense.cpp
        4. util
            1. drawUtils.cpp
            2. drawUtils.hpp
            3. fileUtils.cpp
            4. fileUtils.h
            5. vectorUtils.cpp
            6. vectorUtils.hpp

## Explicando as funções mais importantes

### Classes

1. classes
    1. heroi.cpp
    2. heroi.hpp
    3. inimigo.cpp
    4. inimigo.hpp
    5. projetil.cpp
    6. projetil.hpp

> 1. heroi.cpp
> 2. heroi.hpp

O arquivo ```heroi.cpp``` é responsável basicamente pela construção do personagem tido como heroi. No primeiro método são inseridos os atributos do personagem, como posição, vida e munição. Já os construtores que estão a seguir são os que fazem a alteração dos valores dos atributos.
Já o arquivo ```heroi.hpp``` é responsável pela criação dos métodos utilizados pelo personagem heroi no jogo.

> 3. inimigo.cpp
> 4. inimigo.hpp

Os arquivos ```inimigo.cpp``` e ```inimigo.hpp``` têm atribuições muito parecidas com o "heroi.cpp" e "inimigos.hpp". As principais funções "Inimigo.cpp" são as de atualizar vida e imprimir o inimigo.

>    5. projetil.cpp
>    6. projetil.hpp

A Classe "projétil" armazena a forma de impressão do projétil e, além disso, fornece métodos para fazer o controle dos projéteis disparados. Essa classe define basicamente as direções que esse projétil pode seguir e os métodos que essa classe disponibiliza.

### TrabalhoBaseDefense
>1. trabalhoBaseDefense.cpp

Esse arquivo é responsável basicamente pela construção do ambiente que será jogado, ou seja, a janela que ele aparecerá e as demais funções.
- Método de atualização da janela
    - nesse método nós teremos o que fará a janela ser atualizada, para, assim, o jogo poder ser jogável.
- Configurações da janela
    - Nessas configurações estarão inseridas as dimensões da janela que estamos criando e a taxa de atualização.
- Shape do heroi
    - desenha o heroi
- inimigos
    - Define a velocidade dos inimigos e a frequencia que eles aparecem
- Projéteis
    - define a velocidade dos projéteis
- Mouse
    - É a funcionalidade responsável pela interação do mouse do computador com o jogo, ele serve para poder seguir a direção do tiro e da movimentação do herói
- spawnInimigo
    - faz os inimigos aparecerem
- calcKill
    - calcula a quantidade de mortes
- calcDano
    - calcula a quantidade de dano recebido
- Main
    - Faz a impressão da janela
        - RenderWindow
    - heroiShape
        - Desenha o heroi
    - heroMousePose
        - Posiciona o heroi na posição do mouse
    - Loop do jogo
        - Faz o jogo funcionar enquanto a condição for satisfeita
        - Se a munição do heroi for menor que zero, o jogo encerra
        - faz o calculo da quantidade de frames
        - se o botão do mouse for pressionado, faz heroi se mover
        - atualiza a janela
        - desenha os itens da janela
    - draws
        - desenha o heroi na janela
        - enquanto a janela estiver impressa na tela, pega a quantidade de projéteis
        - desenha os inimigos na janela
        - desenha a base do herói
        - desenha a vida do personagem na janela
        - desenha a quantidade de munição do heroi na janela
    -  update
        -  atualiza as informações importantes do jogo
            -  movimentação do herói
            -  novos inimigos que estão aparecendo
            -  calculo de mortes
            -  calculo de mortes
    -  CalcDano
        -  Calcula o dano recebido
    -  CalcKill
        -  verifica se algum projpétil acertou algum inimigo
    -  CalcShoot
        -  Lógica do calculo dos tiros disparados
    -  MoveHero
        -  Logica de movimentação do herói
    -  SpawnInimigo
        -  Cuida da logica de aparecimento de novos inimigos na tela

### Utils
    1. drawUtils.cpp
    2. drawUtils.hpp
    3. vectorUtils.cpp
    4. vectorUtils.hpp

>1. drawUtils.cpp
>2. drawUtils.hpp

Faz a criação de textos utilizando o pacote de fontes inserido no diretório do jogo

>3. vectorUtils.cpp
>4. vectorUtils.hpp

Faz o calculo dos vetores que são úteis ao jogo, como o de direção e destino.

### Resources
    1. font
        1. arial.ttf
    2. somTiro.mp3

>1. font
    >    1. arial.ttf

1. arial.ttf
- fonte para os textos utilizados no jogo

    1. somTiro.mp3
- Música tema do jogo

### SRC
>1. trabalhoBaseDefense

-   >1. game

    -   >1. colisoes

        -   >1. colisoes.cpp
        -   >2. colisoes.h

Esses dois arquivos são responsáveis basicamente pela pelas colisões que ocorrem no jogo, como as colisões entre os inimigos e a bsae, inimigos com os tiros, herois com os tiros e assim vai.

-   1. game.cpp
-   2. game.h

Esses dois arquivos são os responsáveis por controlar as funções principais do jogo. Neles que a maioria das coisas são executadas e unidas. Digamos que são os arquivos "Mestres".

-   >4. gameEntities
    - >1. actions
    -   >1. shooting
        -   >1. enemyShooting.cpp
        -   >2. enemyShooting.h
        -   >3. heroShooting.cpp
        -   >4. heroShooting.h

>1. enemyShooting.cpp
>2. enemyShooting.h

Responsável pelos tiros dos inimigos.

>3. heroShooting.cpp
>4. heroShooting.h

Responsável pelos tiros do herói.

-   >2. spawning
    -   >1. dropavelSpawn.cpp
    -   >2. dropavelSpawn.h
    -   >3. enemySpawn.cpp
    -   >4. enemySpawn.hpp

>1. dropavelSpawn.cpp
>2. dropavelSpawn.h

Responsável pelo aparecimento dos itens que são dropados pelos inimigos que morreram.

>3. enemySpawn.cpp
>4. enemySpawn.hpp

Responsável pelo aparecimento dos inimigos no jogo.

>3. impl
- Dentro do arquivo existem muitas funções essênciais, dentre elas:
    - Função dos atributos da base e suas funcionalidades
    - Diretório dos itens dropáveis e os seus respectivos efeitos.
        - dentro de cada arquivo tel=remos listados os efeitos que cada item de cada arquivo faz.
    - atributos do heroi
    - atributos dos inimigos
        - esses atributos podem ir variando d eacordo com qual inimigo está aparecendo, já que há diversos inimigos que foram inseridos no jogo.
    - atributos dos projéteis

-   >5. gameUtils
    -   >1. gameEnemyUtils.cpp
    -   >1. gameEnemyUtils.h

Utilidades do jogo.

-   >6. telas
    - >1. telaGameOver.cpp
    - >2. telaGameOver.h
    - >3. telaMenu.cpp
    - >4. telaMenu.h

São basicamente as telas que são imprimidas no jogo, sendo, respectivamente: Tela para quando perder e a telça do menu

- >7. variables
      Aqui nós teremos basicamente as informações das variáveis dos inimigos, herói e tela.

- >8. logger
      São basicamente os erros que podem ocorrer durante a execussão do jogo.
