#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"
#include "math.h"
#include "../Utils/VectorUtils.hpp"
#include "../Utils/DrawUtils.hpp"
#include "../Classes/Projetil.hpp"
#include "../Classes/Inimigo.hpp"

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

// Inimigos
std::vector<Inimigo> inimigos;
float inimigoSpeed = 2.0f;
int inimigo_freq = 360;

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

void spawnInimigo();

void calcKill();

void calcDano();

void draws(sf::RenderWindow &window);

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
        window.clear(sf::Color::White);


        frame_count++;


        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

            move = true;
            heroMousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        }

        // UPDATE
        update(window);

        // DRAW
        draws(window);

        window.display();

    }

    return 0;
}

void draws(sf::RenderWindow &window) {
    window.draw(heroiShape);

    for (int(i) = 0; i < projeteis.size(); i++) {
        window.draw(projeteis[i].getProjetil());
    }

    for(int i = 0; i < inimigos.size(); i++) {
        window.draw(inimigos[i].getInimigoShape());
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
}

void update(sf::RenderWindow &window) {

    moveHero(window);
    calcShoot(window);
    spawnInimigo();
    calcKill();
    calcDano();

}

void calcDano() {
    for(int i = 0; i < inimigos.size(); i++) {
        if(inimigos[i].getInimigoShape().getGlobalBounds().intersects(heroiShape.getGlobalBounds())) {
            heroi.setVida(heroi.getVida() - 10);
        }
    }

}

// Vê se algum projétil acertou um inimigo
void calcKill() {

    for(int i = 0; i < projeteis.size(); i++) {
        for(int j = 0; j < inimigos.size(); j++) {
//            if(projeteis[i].getProjetil().getGlobalBounds().intersects(inimigos[j].getInimigoShape().getGlobalBounds())) {
//                projeteis.erase(projeteis.begin() + i);
//                inimigos[j].setVida(inimigos[j].getVida() - 100);
//                if(inimigos[j].getVida() <= 0) {
//                    inimigos.erase(inimigos.begin() + j);
//                    heroi.setMunicao(heroi.getMunicao() + 2);
//                }
//            }
        }
    }

}

// Lógica de cálculo de tiro
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
            projeteis.erase(projeteis.begin() + i);
        }
    }
}

// Lógica de movimentação do herói
void moveHero(sf::RenderWindow &window) {
    sf::Vector2f destino = sf::Vector2f(heroMousePos);
    sf::Vector2f direcao = VectorUtils::calcularDirecao(heroiShape.getPosition(), destino);

    // Calcula a distância entre o herói e o destino - Sem isso ele fica bugado
    float distance = sqrt(
            pow(destino.x - heroiShape.getPosition().x, 2) + pow(destino.y - heroiShape.getPosition().y, 2));

    if (distance < 3.0f) {
        move = false;
    }

    if (move) {
        heroiShape.setPosition(heroiShape.getPosition() + direcao * 5.0f);
    }
}

// Cuida da lógica de spawn e movimento dos inimigos
void spawnInimigo() {
    if(frame_count % inimigo_freq == 0) {
        if(frame_count > 60) {
            inimigo_freq -= 10;
        }
        sf::RectangleShape inimigoShape = sf::RectangleShape(sf::Vector2f(50, 50));

        int x;
        int y;

        // Selecao aleatoria do lado de spawn
        if (rand() % 2 == 0) {
            x = 0;
            y = rand() % (tamY - 1) + 1;
        } else {
            y = 0;
            x = rand() % (tamX - 1) + 1;
        }

        inimigoShape.setPosition(x, y);
        inimigoShape.setFillColor(sf::Color::Red);
        Inimigo inimigo = Inimigo(inimigoShape, 100);
        inimigos.push_back(inimigo);
    }

    for(int i = 0; i < inimigos.size(); i++) {
        sf::RectangleShape inimigoShape = inimigos[i].getInimigoShape();
        sf::Vector2f direcao = VectorUtils::calcularDirecao(inimigoShape.getPosition(), heroiShape.getPosition());
        inimigoShape.setPosition(inimigoShape.getPosition() + direcao * inimigoSpeed);
        inimigos[i].setInimigoShape(inimigoShape);
    }

    for(int i = 0; i < inimigos.size(); i++) {
        sf::RectangleShape projShape = sf::RectangleShape(sf::Vector2f(10, 10));
        projShape.setFillColor(sf::Color::Black);
        projShape.setPosition(inimigos[i].getInimigoShape().getPosition());
        Projetil proj = Projetil(VectorUtils::calcularDirecao(inimigos[i].getInimigoShape().getPosition(), heroiShape.getPosition()), projShape);
        projeteis.push_back(proj);
    }
}