#ifndef TRABALHOBASEDEFENSE_VARIABLES_HPP
#define TRABALHOBASEDEFENSE_VARIABLES_HPP

class Variables {
public:
    /**
     * Tamanho X da janela
     */
    const int tamX = 1280;

    /**
     * Tamanho Y da janela
     */
    const int tamY = 720;

    /**
     * Framerate
     */
    const int frameRate = 60;

    /**
     * Velocidade do projétil
     */
    const float projectileSpeed = 10.0f;

    /**
     * Quantidade de heróis
     */
    int heroiAmount = 1;

    /**
     * Municao do herói
     */
    int heroiMunicao = 20;

    /**
     * Velocidade do herói
     */
    float heroiSpeed = 5.0f;

    /**
     * Frequência de inimigos
     */
    const int inimigoFrequency = 60;

    /**
     * Velocidade do inimigo
     */
     const float inimigoSpeed = 2.0f;

    /**
     * Log level
     */
    int logLevel = 5;

    std::string logFile = "log.txt";

    /**
     * Base vida
     */
    int baseLife = 100;

    /**
     * Tamnho da base
     */
    int baseTamX = 400;
    int baseTamY = 300;

    /**
     * Posição da base
     */
    int basePosX = 440;
    int basePosY = 210;
};

#endif //TRABALHOBASEDEFENSE_VARIABLES_HPP
