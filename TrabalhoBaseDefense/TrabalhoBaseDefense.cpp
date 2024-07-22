#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"
#include "math.h"
#include "../Utils/VectorUtils.hpp"
#include "../Utils/DrawUtils.hpp"
#include "../Classes/Projetil.hpp"

// Metódo de atualização
void update(sf::RenderWindow &window);

// Configurações da janela
int tamX = 1280;
int tamY = 720;
int frameRate = 60;

// Instância do herói
Heroi heroi;

// Shape do herói
sf::RectangleShape heroiShape;

// Projeteis
std::vector<Projetil> projeteis;
float projectileSpeed = 10.0f;

// Relógio
sf::Clock m_clock;
int frame_count = 0;

// Mouse
sf::Vector2f heroMousePos;
sf::Vector2f projMousePos;

bool move = false;
bool shoot = false;


void moveHero(sf::RenderWindow &window);
void calcShoot(sf::RenderWindow &window);

int main() {
    // Janela
    sf::RenderWindow window(sf::VideoMode(tamX, tamY), "Base Defense");
    window.setFramerateLimit(frameRate);

    //Variáveis
    heroiShape = DrawUtils::desenharHeroi(heroi);

    heroMousePos = heroiShape.getPosition();

    // Game loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(heroi.getMunicao() > 0) {
                        heroi.setMunicao(heroi.getMunicao() - 1);
                        shoot = true;
                    }
                }
            }

        }
        frame_count++;

        if(frame_count % 60 == 0) {
            // LOGICA DE INIMIGO
        }

        window.clear(sf::Color::White);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

            move = true;
            heroMousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        }

        // UPDATE
        update(window);

        // DRAW
        window.draw(heroiShape);

        for (int(i) = 0; i < projeteis.size(); i++) {
            window.draw(projeteis[i].getProjetil());
        }

        sf::RectangleShape base = sf::RectangleShape(sf::Vector2f(400, 300));
        base.setOutlineThickness(5);
        base.setFillColor(sf::Color::Transparent);
        base.setOutlineColor(sf::Color::Black);
        base.setPosition(440, 210);

        window.draw(base);

        std::string vida = "Vida: " + std::to_string(heroi.getVida());
        DrawUtils::createText(vida, 1100, 20, window);

        std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
        DrawUtils::createText(municao, 1100, 50, window);

        window.display();

    }

    return 0;
}

void update(sf::RenderWindow &window) {

    moveHero(window);
    calcShoot(window);

}

void calcShoot(sf::RenderWindow &window) {
    if (shoot) {
        projMousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        sf::Vector2f direcao = VectorUtils::calcularDirecao(heroiShape.getPosition(), projMousePos);

        sf::RectangleShape proj = sf::RectangleShape(sf::Vector2f(10, 10));
        proj.setFillColor(sf::Color::Blue);
        proj.setPosition(sf::Vector2f(heroiShape.getPosition().x + 20, heroiShape.getPosition().y + 20));

        projeteis.emplace_back(direcao, proj);

        shoot = false;
    }

    for (int(i) = 0; i < projeteis.size(); i++) {
        sf::RectangleShape newProj = projeteis[i].getProjetil();
        newProj.setPosition(newProj.getPosition() + (projeteis[i].getDirecao() * projectileSpeed));
        projeteis[i].setProjetil(newProj);

        if (newProj.getPosition().x < 0 || newProj.getPosition().x > tamX || newProj.getPosition().y < 0 ||
            newProj.getPosition().y > tamY) {
            std::cout << "Removendo projétil" << std::endl;
            projeteis.erase(projeteis.begin() + i);
        }
    }
}

void moveHero(sf::RenderWindow &window) {
    sf::Vector2f destino = sf::Vector2f(heroMousePos);
    sf::Vector2f direcao = VectorUtils::calcularDirecao(heroiShape.getPosition(), destino);

    float distance = sqrt(
            pow(destino.x - heroiShape.getPosition().x, 2) + pow(destino.y - heroiShape.getPosition().y, 2));

    if (distance < 3.0f) {
        move = false;
    }

    if (move) {
        heroiShape.setPosition(heroiShape.getPosition() + direcao * 5.0f);
    }
}