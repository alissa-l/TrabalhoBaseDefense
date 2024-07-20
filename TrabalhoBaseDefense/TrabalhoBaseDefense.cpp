#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"
#include "math.h"
#include "../Utils/VectorUtils.hpp"
#include "../Utils/DrawUtils.hpp"

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
std::vector<sf::RectangleShape> projeteis;
std::vector<sf::Vector2f> direcoes;
float projectileSpeed = 10.0f;

// Relógio
sf::Clock m_clock;

// Mouse
sf::Vector2f mousePos;
sf::Vector2f lastMousePos;

int main()
{
    // Janela
    sf::RenderWindow window(sf::VideoMode(tamX, tamY), "Base Defense");
    window.setFramerateLimit(frameRate);

    //Variáveis
    heroiShape = DrawUtils::desenharHeroi(heroi);

    mousePos = heroiShape.getPosition();

    // Game loop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear(sf::Color::White);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

            lastMousePos = mousePos;
            mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        }

        sf::Vector2f destino = sf::Vector2f(mousePos);
        sf::Vector2f direcao = VectorUtils::calcularDirecao(heroiShape.getPosition(), destino);

        float distance = sqrt(pow(destino.x - heroiShape.getPosition().x, 2) + pow(destino.y - heroiShape.getPosition().y, 2));


        if (distance > 3.0f) {
            heroiShape.setPosition(heroiShape.getPosition() + direcao * 5.0f);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for(int i = 0; i<1; i++) {
                projeteis.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
                projeteis.back().setFillColor(sf::Color::Blue);
                projeteis.back().setPosition(heroiShape.getPosition());
                direcoes.push_back(VectorUtils::calcularDirecao(heroiShape.getPosition(), mousePos));
            }
        }

        if (!projeteis.empty() && !direcoes.empty()) {
            for (int i = 0; i < projeteis.size(); i++) {
                projeteis[i].setPosition(projeteis[i].getPosition() + direcoes[i] * projectileSpeed);
            }

        }

        window.draw(heroiShape);

        for(auto &proj : projeteis) {
            window.draw(proj);
        }

        std::string vida = "Vida: " + std::to_string(heroi.getVida());
        DrawUtils::createText(vida, 1100, 20, window);

        std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
        DrawUtils::createText(municao, 1100, 50, window);

        window.display();

    }

    return 0;
}

void update(sf::RenderWindow &window) {


}