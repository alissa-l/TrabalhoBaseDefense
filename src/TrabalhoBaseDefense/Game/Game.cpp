#include <iostream>
#include <random>
#include "Game.h"
#include "Variables/Variables.h"
#include "GameEntities/GameEntity.h"
#include "GameEntities/impl/Heroi.hpp"
#include "GameEntities/impl/Inimigo.h"
#include "GameEntities/impl/Projetil.hpp"
#include "SFML/Window/Event.hpp"
#include "GameEntities/Actions/Shooting/HeroShooting.h"
#include "../Util/VectorUtils.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "GameEntities/impl/Base.hpp"
#include "GameEntities/Actions/Spawning/EnemySpawn.hpp"
#include "Colisoes/Colisoes.h"
#include "Variables/HeroVariables.h"
#include "GameEntities/impl/Inimigos/InimigoComum.h"
#include "GameEntities/impl/Inimigos/InimigoRapido.h"
#include "GameEntities/impl/Inimigos/InimigoFortificado.h"
#include "Variables/WindowConstants.h"
#include "GameEntities/impl/Inimigos/InimigoBoss.h"
#include "Telas/TelaMenu.h"
#include "GameEntities/Actions/Shooting/EnemyShooting.h"
#include "GameEntities/impl/Dropavel.h"
#include "GameEntities/Actions/Spawning/DropavelSpawn.h"
#include "GameUtils/GameEnemyUtils.h"
#include "GameEntities/impl/Dropaveis/DropavelContext.hpp"

//Variaveis do jogo
/**
 * Herói
 */
std::vector<Heroi> herois;

/**
 * Spawn de inimigos
 */
std::vector<Inimigo> inimigosSpawn;

/**
 * Inimigos
 */
std::vector<Inimigo> inimigos;

/**
 * Base
 */
Base base;

/**
 * Projeteis
 */
std::vector<Projetil> projeteis;

/**
 * Relógio
 */
sf::Clock m_clock;

/**
 * Contador de frames
 */
int frame_count = 0;

/**
 * Ultimo spawn de inimigo
 */
int lastSpawn = 0;

/**
 * Mouse - Controla a ultima posição do mouse
 */
sf::Vector2f projMousePos;

/**
 * Atirar bool - Controla se o herói está atirando - Atirar só uma vez
 */
bool shoot = false;

/**
 * Número round_c
 */
int round_c = 0;

/**
 * Damage reset - Heroi
 */
int heroDamageReset = 0;

/**
 * Damage reset - Base
 */
int baseDamageReset = 0;

/**
 * Total de inimigos mortos
 */
int totalInimigosMortos = 0;
int totalInimigosMortosCalculo = 0;

/**
 * Mapa com as variáveis dos inimigos
 */
std::map<std::string, double> enemyVars;

/**
 * Logger
 */
Logger logger = Logger(Variables().logFile, Variables().logLevel);

std::vector<Dropavel> dropaveis;

/**
 * Setup do jogo
 */
void Game::setup() {

    for (size_t i = 0; i < HeroVariables().heroiAmount; i++) {
        Heroi heroi;
        heroi.load();
        herois.push_back(heroi);
    }

    for (auto heroi: herois) {
        heroi.load();
    }

    try {
        loadEnemies();
    } catch (std::exception &e) {
        std::string s = e.what();
        throw std::runtime_error("Erro ao carregar os inimigos: " + s);
    }

    base.load();
}

/**
 * Metódo inicial da classe
 */
void Game::run() {

    // Logger
    logger.log(LogLevel::INFO, "Iniciando o jogo");

    // Setup
    try {
        setup();
    } catch (std::exception &e) {
        std::string se = e.what();
        logger.log(LogLevel::ERROR, "Erro ao iniciar o jogo: " + se);
    }


    // Janela
    sf::RenderWindow window(sf::VideoMode(WindowConstants().tamX, WindowConstants().tamY), "Base Defense");
    window.setFramerateLimit(WindowConstants().frameRate);

    // Se a janela não foi criada, encerra o jogo
    if (!window.isOpen()) {
        logger.log(LogLevel::ERROR, "Janela não foi criada");
        throw std::runtime_error("Janela não foi criada");
    }

    // Tela de menu
    int dificuldade = 0;
    try {
        TelaMenu::menuScreen(window, logger, dificuldade);
    } catch (std::exception &e) {
        std::string se = e.what();
        logger.log(LogLevel::ERROR, "Erro abrindo tela de menu " + se);
    }

    for (int i = 0; i < dificuldade * 2; ++i) {
        increaseDifficulty();
    }
    
    //
    // Loop principal
    //
    while (window.isOpen()) {

        frame_count++;
        heroDamageReset--;
        baseDamageReset--;

        // Eventos
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    shoot = true;
                    projMousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                }
            }
        }

//        if (baseShape.getVida() <= 0) {
//            window.close();
//            // TODO: Implementar tela de game over
//        }
//
//        if (herois[0].getVida() <= 0) {
//            window.close();
//            // TODO: Implementar tela de game over
//        }

        window.clear(sf::Color::White);

        // Atualizar estados
        try {
            calculateColisions();
            update(window);
        } catch (std::exception &e) {
            std::string s = e.what();
            logger.log(LogLevel::ERROR, "Erro ao atualizar o jogo: " + s);
        }

        // Desenhar tudo na tela
        try {
            draw(window);
            drawText(window);
        } catch (std::exception &e) {
            std::string s = e.what();
            logger.log(LogLevel::ERROR, "Erro ao desenhar o jogo: " + s);
        }

        window.display();


    }

}

void Game::update(sf::RenderWindow &window) {

    // Update dos heróis
    updateHeroi(window);

    // Update dos projeteis
    updateProjetil();

    // Update dos inimigos
    updateInimigos();

    // Update do round
    updateRounds();

    // Update dos drops
    for (auto &dropavel: dropaveis) {
        dropavel.update();
    }

    calculateColisions();
}

void Game::draw(sf::RenderWindow &window) {

    for (auto heroi: herois) {
        heroi.draw(window);
    }

    for (auto inimigo: inimigos) {
        inimigo.draw(window);
    }

    for (auto projetil: projeteis) {
        projetil.draw(window);
    }

    for (auto dropavel: dropaveis) {
        dropavel.draw(window);
    }

    base.draw(window);

}

void Game::drawText(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("resources/font/arial.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }
    sf::Text texto;

    std::string text =
            "Vida: " + std::to_string(herois[0].getVida()) + "\nMunicao: " + std::to_string(herois[0].getMunicao()) +
            "\nRound: " + std::to_string(round_c) + "\nVida da Base: " + std::to_string(base.getVida());

    texto.setString(text);
    texto.setCharacterSize(24);

    texto.setStyle(sf::Text::Bold);

    texto.setFillColor(sf::Color::Black);
    texto.setPosition(WindowConstants().tamX - 240, 20);

    texto.setFont(font);
    window.draw(texto);

}

/**
 * Calcula as colisões e os efeitos
 */
void Game::calculateColisions() {

    // Calcula as colisoes relacionadas aos inimigos
    for (auto &inimigo : inimigos) {
        // Heroi x Inimigo
        for (auto &heroi : herois) {

            if (Colisoes::colide(heroi, inimigo)) {
                if(heroDamageReset > 0) continue;
                heroi.setVida(heroi.getVida() - inimigo.getDano());
                heroDamageReset = 30;

                std::string si = "Heroi atingido - Vida: " + std::to_string(heroi.getVida());
                logger.log(LogLevel::DEBUG, si);
            }
        }

        // Inimigo x Projeteis
        if (Colisoes::colide(inimigo, projeteis)) {
            inimigo.setVida(inimigo.getVida() - 100);
            std::string si = "Inimigo atingido " + inimigo.getNome() + " - Vida: " + std::to_string(inimigo.getVida());
            logger.log(LogLevel::DEBUG, si);
        }


    }

    // Colisao projetil inimigo x baseShape
    for(auto &proj : projeteis) {
        if (proj.getFriendly()) continue;
        if (Colisoes::colide(proj, base)) {
            proj.setJaColidiu(true);
            std::string si = "Projetil atingiu a baseShape";
            logger.log(LogLevel::DEBUG, si);

            if (baseDamageReset > 0) continue;
            base.setVida(base.getVida() - 5);
            baseDamageReset = 60;
        }
    }

    // Colisao projetil x projetil
    for(auto &proj : projeteis) {
        for(auto &proj2 : projeteis) {
            if(&proj == &proj2) continue;
            if (Colisoes::colide(proj, proj2)) {
                proj.setJaColidiu(true);
                proj2.setJaColidiu(true);
                std::string si = "SORTE - Projetil atingiu outro projetil";
                logger.log(LogLevel::DEBUG, si);
            }
        }
    }

    // Colisao inimigo x baseShape
    for(auto &inimigo : inimigos) {
        if (Colisoes::colide(inimigo, base)) {

            // Posicoes e tamanhos das entidades pros calculos
            sf::Vector2f basePos = base.getBase().getPosition();
            sf::Vector2f baseSize = base.getBase().getSize();
            sf::Vector2f inimigoPos = inimigo.getPosicao();

            // Verifica qual borda o inimigo está tocando
            bool isTouchingLeftEdge = (inimigoPos.x < basePos.x && inimigoPos.y >= basePos.y && inimigoPos.y <= basePos.y + baseSize.y);
            bool isTouchingRightEdge = (inimigoPos.x > basePos.x + baseSize.x && inimigoPos.y >= basePos.y && inimigoPos.y <= basePos.y + baseSize.y);
            bool isTouchingTopEdge = (inimigoPos.y < basePos.y && inimigoPos.x >= basePos.x && inimigoPos.x <= basePos.x + baseSize.x);
            bool isTouchingBottomEdge = (inimigoPos.y > basePos.y + baseSize.y && inimigoPos.x >= basePos.x && inimigoPos.x <= basePos.x + baseSize.x);

            // Faz o inimigo parar de se mover na direção da borda que ele está tocando
            inimigo.setStopMovingX(isTouchingLeftEdge || isTouchingRightEdge);
            inimigo.setStopMovingY(isTouchingTopEdge || isTouchingBottomEdge);

            if(baseDamageReset > 0) continue;
            base.setVida(base.getVida() - inimigo.getDano());
            baseDamageReset = 60;

            std::string si = "Base atingida " + inimigo.getNome() + " - Vida: " + std::to_string(base.getVida());
            logger.log(LogLevel::DEBUG, si);
        } else {
            inimigo.setStopMovingX(false);
            inimigo.setStopMovingY(false);
        }
    }

    // Dropaveis x heroi
    for (int i = 0; i < dropaveis.size(); ++i) {
        for (auto &heroi : herois) {
            if (Colisoes::colide(heroi, dropaveis[i])) {
                DropavelContext::applyEffect(heroi, base, dropaveis[i]);
                dropaveis.erase(dropaveis.begin() + i);
                --i;
                break;
            }
        }
    }


    // Remove projeteis que colidiram
    for (int i = 0; i < projeteis.size(); ++i) {
        if (projeteis[i].getJaColidiu()) {
            projeteis.erase(projeteis.begin() + i);
            std::string si = "Projetil removido";
            logger.log(LogLevel::DEBUG, si);
        }
    }

}

void Game::loadVars() {
    enemyVars["inimigoFrequency"] = EnemyVariables().inimigoFrequency;
    enemyVars["inimigoSpeedBase"] = EnemyVariables().inimigoSpeedBase;
    enemyVars["inimigoBaseDamage"] = EnemyVariables().inimigoBaseDamage;
    enemyVars["inimigoBaseLife"] = EnemyVariables().inimigoBaseLife;
    enemyVars["baseSpawnRate"] = EnemyVariables().baseSpawnRate;
    enemyVars["shootingFrequency"] = EnemyVariables().shootingFrequency;
}

void Game::increaseDifficulty() {
    loadVars();

    if (enemyVars["inimigoFrequency"] == 60) {
        enemyVars["inimigoFrequency"] = 60;
    } else {
        enemyVars["inimigoFrequency"] = enemyVars["inimigoFrequency"] - 20;
    }

    enemyVars["inimigoSpeedBase"] = enemyVars["inimigoSpeedBase"] + 0.1;
    enemyVars["inimigoBaseDamage"] = enemyVars["inimigoBaseDamage"] + 2;
    enemyVars["inimigoBaseLife"] = enemyVars["inimigoBaseLife"] + 10;
    enemyVars["baseSpawnRate"] = enemyVars["baseSpawnRate"] + 0.1;

    logger.log(LogLevel::DEBUG, "Dificuldade aumentada");
    for (auto m : enemyVars) {
        logger.log(LogLevel::DEBUG, m.first + ": " + std::to_string(m.second));
    }
}

/**
 * Carrega todos os tipos de inimigos
 */
void Game::loadEnemies() {
    loadVars();

    Inimigo inimigoComum = InimigoComum::get(enemyVars);
    inimigosSpawn.push_back(inimigoComum);

    Inimigo inimigoRapido = InimigoRapido::get(enemyVars);
    inimigosSpawn.push_back(inimigoRapido);

    Inimigo inimigoFortificado = InimigoFortificado::get(enemyVars);
    inimigosSpawn.push_back(inimigoFortificado);

    Inimigo inimigoBoss = InimigoBoss::get(enemyVars);
    inimigosSpawn.push_back(inimigoBoss);
}

/**
 * Update dos herois <br>
 * Calcula a posição do herói e controle dos tiros
 * @param window
 */
void Game::updateHeroi(sf::RenderWindow &window) {
    for (auto &heroi: herois) {
        try {
            heroi.update(window);

            if (shoot) {
                HeroShooting::shoot(shoot, heroi, projeteis, projMousePos);
            }

        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o herói: " + es);
        }

    }
}

/**
 * Update dos inimigos <br>
 * Atualiza a posição e direção dos inimigos e verifica se estão mortos
 */
void Game::updateInimigos() {

    /**
     * Atualiza a direção dos inimigos e chama inimigo.update()
     */
    GameEnemyUtils::updateDirecaoInimigos(inimigos, herois);

    /**
     * Limpa os inimigos mortos <br>
     * Dropa um item aleatório se o inimigo morrer
     */
    GameEnemyUtils::limparInimigos(inimigos, dropaveis, totalInimigosMortos, totalInimigosMortosCalculo);

    /**
     * Spawna projeteis dos inimigos <br>
     * Atira em direção a baseShape
     */
    double shootingFrequency = enemyVars["shootingFrequency"];
    GameEnemyUtils::tiroInimigos(inimigos, projeteis, m_clock, shootingFrequency, base);

    /**
     * Spawna inimigos <br>
     */
    EnemySpawn::spawnEnemy(inimigos, inimigosSpawn, lastSpawn, frame_count, herois, enemyVars);
}

/**
 * Update dos projeteis <br>
 * Move os projeteis e verifica se ja sairam da tela
 */
void Game::updateProjetil() {
    for (int i = 0; i < projeteis.size(); i++) {

        try {
            Projetil projetil = projeteis[i];

            projetil.update();

            if (projetil.getProjetil().getPosition().x < 0 ||
                projetil.getProjetil().getPosition().x > WindowConstants().tamX ||
                projetil.getProjetil().getPosition().y < 0 ||
                projetil.getProjetil().getPosition().y > WindowConstants().tamY) {

                projeteis.erase(projeteis.begin() + i);
            } else {
                projeteis[i] = projetil;
            }


        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o projetil: " + es);
        }

    }
}

/**
 * Faz update dos rounds <br>
 * Aumenta a dificuldade a cada round
 */
void Game::updateRounds() {
    if(totalInimigosMortos > 1 && totalInimigosMortosCalculo % 10 == 0) {
        round_c = round_c + 1;
        totalInimigosMortosCalculo++;
        if(round_c < 20) {
            increaseDifficulty();
            loadEnemies();
        }
    }
}
