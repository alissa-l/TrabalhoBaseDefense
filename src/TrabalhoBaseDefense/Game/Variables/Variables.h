#ifndef TRABALHOBASEDEFENSE_VARIABLES_HPP
#define TRABALHOBASEDEFENSE_VARIABLES_HPP

/**
 * Classe que guarda as algumas variáveis globais do jogo
 */
class Variables {
public:

    /**
     * Velocidade do projétil
     */
    const float projectileSpeed = 10.0f;

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
