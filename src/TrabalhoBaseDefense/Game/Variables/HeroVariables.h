#ifndef SRC_TRABALHOBASEDEFENSEEXE_HEROVARIABLES_H
#define SRC_TRABALHOBASEDEFENSEEXE_HEROVARIABLES_H

class HeroVariables {
public:
    /**
     * Quantidade de heróis
     */
    int heroiAmount = 1;

    /**
     * Municao do herói
     */
    int heroiMunicao = 50;

    /**
     * Velocidade do herói
     */
    float heroiSpeed = 5.0f;

    /**
     * Vida do herói
     */
    int heroiVida = 100;

    /**
     * Textura 1 do herói
     */
    std::string heroiTexture1 = "resources/sprites/arqueiro_1.png";

};

#endif //SRC_TRABALHOBASEDEFENSEEXE_HEROVARIABLES_H
