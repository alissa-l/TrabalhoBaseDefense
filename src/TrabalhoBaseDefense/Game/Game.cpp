#include <iostream>
#include "Game.h"
#include "Variables/Variables.h"
#include "GameEntities/GameEntity.h"
#include "GameEntities/impl/Heroi.hpp"
#include "GameEntities/impl/Inimigo.hpp"
#include "GameEntities/impl/Projetil.hpp"
#include "SFML/Window/Event.hpp"
#include "GameEntities/Actions/Shooting/HeroShooting.h"
#include "../Util/VectorUtils.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "GameEntities/impl/Base.hpp"
#include "Telas/TextoJogo.h"

// SFML

//Variaveis do jogo
/**
 * Herói
 */
std::vector<Heroi> herois;

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
 * Setup do jogo
 */
void Game::setup() {

    for(size_t i = 0; i < Variables().heroiAmount; i++) {
        Heroi heroi;
        heroi.load();
        herois.push_back(heroi);
    }

    for(auto heroi : herois) {
        heroi.load();
    }

    base.load();


}

/**
 * Metódo inicial da classe
 */
void Game::run() {

    Logger logger = Logger(Variables().logFile, Variables().logLevel);
    logger.log(LogLevel::INFO, "Iniciando o jogo");

    sf::RenderWindow window(sf::VideoMode(Variables().tamX, Variables().tamY), "Base Defense");
    window.setFramerateLimit(Variables().frameRate);

    // Setup
    try {
        setup();
    } catch (std::exception &e) {
        std::string se = e.what();
        logger.log(LogLevel::ERROR, "Erro ao iniciar o jogo: " + se);
    }

    // Se a janela não foi criada, encerra o jogo
    if (!window.isOpen()) {
        logger.log(LogLevel::ERROR, "Janela não foi criada");
        throw std::runtime_error("Janela não foi criada");
    }

    // Loop principal
    while (window.isOpen()) {
        frame_count++;

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

        if(base.getVida() <= 0) {
            window.close();
        }

        if(herois[0].getVida() <= 0) {
            window.close();
        }

        window.clear(sf::Color::White);

        // Atualizar estados
        try {
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
    for(auto &heroi : herois) {
        try {
            heroi.update(window);

            if(shoot) {
                HeroShooting::shoot(shoot, heroi, projeteis, projMousePos);
            }

        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o herói: " + es);
        }

    }

    // Update dos projeteis
    for(int i = 0; i < projeteis.size(); i++) {

        try {
            Projetil projetil = projeteis[i];

            projetil.update();

            if(projetil.getProjetil().getPosition().x < 0 ||
               projetil.getProjetil().getPosition().x > Variables().tamX ||
               projetil.getProjetil().getPosition().y < 0 ||
               projetil.getProjetil().getPosition().y > Variables().tamY) {

                projeteis.erase(projeteis.begin() + i);
            } else {
                projeteis[i] = projetil;
            }


        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o projetil: " + es);
        }

    }

    // Aumentar round_c
    round_c = frame_count / 600;
    spawnInimigo();
    calculateColisions();
}

void Game::draw(sf::RenderWindow &window) {

    for (auto heroi : herois) {
        heroi.draw(window);
    }

    for (auto inimigo : inimigos) {
        inimigo.draw(window);
    }

    for (auto projetil : projeteis) {
        projetil.draw(window);
    }

    base.draw(window);

    window.draw(textoJogo.texto);
}

void Game::drawText(sf::RenderWindow &window) {
    sf::Font font;
    if(!font.loadFromFile("resources/font/arial.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }
    sf::Text texto;

    std::string text = "Vida: " + std::to_string(herois[0].getVida()) + "\nMunicao: " + std::to_string(herois[0].getMunicao()) +
                       "\nRound: " + std::to_string(round_c) + "\nVida da Base: " + std::to_string(base.getVida());

    texto.setString(text);
    texto.setCharacterSize(24);

    texto.setStyle(sf::Text::Bold);

    texto.setFillColor(sf::Color::Black);
    texto.setPosition(Variables().tamX - 240,  20);

    texto.setFont(font);
    window.draw(texto);

}

// Cuida da lógica de spawn e movimento dos inimigos
void Game::spawnInimigo() {
    if(frame_count % Variables().inimigoFrequency == 0) {

        int x;
        int y;

        // Selecao aleatoria do lado de spawn
        if (rand() % 2 == 0) {
            x = 0;
            y = rand() % (Variables().tamY - 1) + 1;
        } else {
            y = 0;
            x = rand() % (Variables().tamX - 1) + 1;
        }

        sf::RectangleShape inimigoShape = sf::RectangleShape(sf::Vector2f(50, 50));

        inimigoShape.setPosition(x, y);
        inimigoShape.setFillColor(sf::Color::Red);
        Inimigo inimigo = Inimigo(inimigoShape, 100, 10.0f, 10);
        inimigo.setInimigoShape(inimigoShape);
        inimigos.push_back(inimigo);
    }

    for(int i = 0; i < inimigos.size(); i++) {
        sf::RectangleShape inimigoShape = inimigos[i].getInimigoShape();

        Heroi heroiProximo = herois[0];

        sf::Vector2f direcao = VectorUtils::calcularDirecao(inimigoShape.getPosition(), heroiProximo.sprite.getPosition());
        inimigoShape.setPosition(inimigoShape.getPosition() + direcao * Variables().inimigoSpeed);
        inimigos[i].setInimigoShape(inimigoShape);
    }
}

void Game::calculateColisions() {

    for(int i = 0; i < projeteis.size(); i++) {
        for(int j = 0; j < inimigos.size(); j++) {
            if(projeteis[i].getProjetil().getGlobalBounds().intersects(inimigos[j].getInimigoShape().getGlobalBounds())) {
                projeteis.erase(projeteis.begin() + i);
                inimigos.erase(inimigos.begin() + j);
            }
        }
    }

    for (int i = 0; i < inimigos.size(); ++i) {
        Heroi heroi = herois[0];
        if(inimigos[i].getInimigoShape().getGlobalBounds().intersects(heroi.sprite.getGlobalBounds())) {
            herois[0].setVida(herois[0].getVida() - 10);
            inimigos.erase(inimigos.begin() + i);
        }

        if(inimigos[i].getInimigoShape().getGlobalBounds().intersects(base.getBase().getGlobalBounds())) {
            base.setVida(base.getVida() - 10);
            inimigos.erase(inimigos.begin() + i);
        }
    }

}

