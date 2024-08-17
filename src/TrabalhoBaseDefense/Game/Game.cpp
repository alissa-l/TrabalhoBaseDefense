#include <iostream>
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
#include "Telas/TextoJogo.h"
#include "GameEntities/Actions/Spawning/EnemySpawn.hpp"
#include "Colisoes/Colisoes.h"
#include "Variables/HeroVariables.h"
#include "GameEntities/impl/Inimigos/InimigoComum.h"
#include "GameEntities/impl/Inimigos/InimigoRapido.h"
#include "GameEntities/impl/Inimigos/InimigoFortificado.h"
#include "Variables/WindowConstants.h"

// SFML

//Variaveis do jogo
/**
 * Herói
 */
std::vector<Heroi> herois;

/**
 * Spawn de inimigos
 */
std::map<double, Inimigo> inimigosSpawn;

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
 * Texto do jogo
 */
TextoJogo textoJogo;

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
 * Logger
 */
Logger logger = Logger(Variables().logFile, Variables().logLevel);

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
        inimigosSpawn.insert(std::pair<double, Inimigo>(InimigoComum().chanceSpawn, InimigoComum().get()));
        inimigosSpawn.insert(std::pair<double, Inimigo>(InimigoRapido().chanceSpawn, InimigoRapido().get()));
        inimigosSpawn.insert(std::pair<double, Inimigo>(InimigoFortificado().chanceSpawn, InimigoFortificado().get()));
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
    try {
        menuScreen(window);
    } catch (std::exception &e) {
        std::string se = e.what();
        logger.log(LogLevel::ERROR, "Erro abrindo tela de menu " + se);
    }

    // Loop principal
    while (window.isOpen()) {

        frame_count++;
        heroDamageReset--;
        baseDamageReset--;
        EnemyVariables::setInimigoFrequency(EnemyVariables::inimigoFrequency - round_c * 30);

        // Eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    shoot = true;
                    projMousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                }
            }
        }

//        if (base.getVida() <= 0) {
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

    // Update dos projeteis
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

    // Update dos inimigos
    for (int i = 0; i < inimigos.size(); i++) {
        try {
            Inimigo inimigo = inimigos[i];
            inimigo.update();
            inimigo.updateDirecao(herois);
            inimigos[i] = inimigo;
        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o inimigo: " + es);
        }
    }

    // Spawna um inimigo se entrar na condição
    EnemySpawn::spawnEnemy(inimigos, inimigosSpawn, lastSpawn, frame_count, herois);

    // Aumentar round_c
    round_c = frame_count / (30 * 60);
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

    base.draw(window);

    window.draw(textoJogo.texto);
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

        // Inimigo x Base
        if (Colisoes::colide(inimigo, base)) {
            if(baseDamageReset > 0) continue;
            base.setVida(base.getVida() - inimigo.getDano());
            baseDamageReset = 30;
            inimigo.setDirecao(sf::Vector2f(0, 0));

            std::string si = "Base atingida " + inimigo.getNome() + " - Vida: " + std::to_string(base.getVida());
            logger.log(LogLevel::DEBUG, si);
        }
    }

    // Remove inimigos mortos
    for (int i = 0; i < inimigos.size(); ++i) {
        if (inimigos[i].getVida() <= 0) {
            inimigos.erase(inimigos.begin() + i);
            std::string si = "Inimigo morto " + inimigos[i].getNome();
            logger.log(LogLevel::DEBUG, si);
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

/**
 * Tela de menu
 * @param window
 */
void Game::menuScreen(sf::RenderWindow &window) {
    while (true) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                logger.log(LogLevel::INFO, "Jogo encerrado - menu");
            }

            if (event.type == sf::Event::KeyPressed) {
                logger.log(LogLevel::INFO, "Jogo iniciado - menu");
                return;
            }

        }
        window.clear(sf::Color::White);


        sf::Font font;
        if (!font.loadFromFile("resources/font/arial.ttf")) {
            throw std::runtime_error("Erro ao carregar fonte");
        }

        //
        // Textos do menu
        //
        std::vector<sf::Text> textos(2);

        // Titulo
        textos[0].setString("Base Defense");
        textos[0].setCharacterSize(30);

        // Instruções
        textos[1].setString("Pressione qualquer tecla para iniciar o jogo");
        textos[1].setCharacterSize(20);

        // Para cada texto, setar as propriedades
        for (auto &texto : textos) {
            texto.setFillColor(sf::Color::Black);
            texto.setStyle(sf::Text::Bold);
            texto.setFont(font);

            // Centrailizar textto
            sf::FloatRect textRect = texto.getLocalBounds();
            texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            texto.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
        }

        // Ajustar a posição do titulo por um offset de Y
        textos[1].move(0, 50);

        // Desenhar os textos
        for (auto texto : textos) {
            window.draw(texto);
        }

        // Display
        window.display();
    }
}