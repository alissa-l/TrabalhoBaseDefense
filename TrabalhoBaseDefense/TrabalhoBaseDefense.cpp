#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"
#include <cmath>
#include "../Utils/VectorUtils.hpp"
#include "../Utils/DrawUtils.hpp"
#include "../Classes/Projetil.hpp"
#include "../Classes/Inimigo.hpp"
#include "../Classes/Variables.hpp"
#include "../Classes/GameEntity.hpp"

std::vector<GameEntity> gameEntities;

// Metódo de atualização
void update(sf::RenderWindow &t_window);

// Instância do herói
Heroi heroi;

// Inimigos
std::vector<Inimigo> inimigos;
float inimigoSpeed = 2.0f;
int inimigo_freq = 360;

// Projeteis
std::vector<Projetil> projeteis;
float projectileSpeed = Variables().projectileSpeed;

// Relógio
sf::Clock m_clock;
int frame_count = 0;

// Mouse
sf::Vector2f projMousePos;

bool shoot = false;

void calcShoot(sf::RenderWindow &t_window);

void spawnInimigo();

void calcKill();

void calcDano();

void draws(sf::RenderWindow &t_window);
sf::RenderWindow window;


int main() {
    // Janela
    window.create(sf::VideoMode(Variables().tamX, Variables().tamY), "Base Defense");

    window.setFramerateLimit(60);
    heroi.load();
    window.setKeyRepeatEnabled(false);

    std::vector<std::vector<float>> times(5);
    // Game loop
    while (window.isOpen()) {
        frame_count++;

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);



        // UPDATE
        update(window);

        // DRAW
        draws(window);

        window.display();



    }

    for (const auto& x : times) {
        float avg = 0;
        for(auto i : x) {
            avg+=i;
        }
        std::cout << avg / x.size() << "\n";
    }

    return 0;
}

void draws(sf::RenderWindow &t_window) {
    heroi.draw(t_window);

    for (auto & projetil : projeteis) {
        projetil.draw(t_window);
    }

    for(const auto & inimigo : inimigos) {
        t_window.draw(inimigo.getInimigoShape());
    }


    sf::RectangleShape base = sf::RectangleShape(sf::Vector2f(400, 300));
    base.setOutlineThickness(5);
    base.setFillColor(sf::Color::Transparent);
    base.setOutlineColor(sf::Color::Black);
    base.setPosition(440, 210);

    t_window.draw(base);

//    std::string vida = "Vida: " + std::to_string(heroi.getVida());
//    DrawUtils::createText(vida, 1100, 20, t_window);
//
//    std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
//    DrawUtils::createText(municao, 1100, 50, t_window);

}

/**
 * Atualiza o jogo
 * Chama as funcoes de atualizacao do heroi, projeteis, inimigos e colisoes
 * @param t_window
 */
void update(sf::RenderWindow &t_window) {

    heroi.update(t_window);
    calcShoot(t_window);
    spawnInimigo();
    calcKill();
    calcDano();

}

void calcDano() {
    for(int i = 0; i < inimigos.size(); i++) {
        if(inimigos[i].getInimigoShape().getGlobalBounds().intersects(heroi.sprite.getGlobalBounds())) {
            heroi.setVida(heroi.getVida() - 10);
        }
    }

}

// Vê se algum projétil acertou um inimigo
void calcKill() {

    for(int i = 0; i < projeteis.size(); i++) {
        for(int j = 0; j < inimigos.size(); j++) {

            if(projeteis[i].getProjetil().getGlobalBounds().intersects(inimigos[j].getInimigoShape().getGlobalBounds())) {
                projeteis.erase(projeteis.begin() + i);
                inimigos[j].setVida(inimigos[j].getVida() - 100);
                if(inimigos[j].getVida() <= 0) {
                    inimigos.erase(inimigos.begin() + j);
                }
            }
        }
    }

}

// Lógica de cálculo de tiro
void calcShoot(sf::RenderWindow &t_window) {
    if (shoot) {
        projMousePos = sf::Vector2f(sf::Mouse::getPosition(t_window));

        sf::Vector2f direcao = VectorUtils::calcularDirecao(heroi.sprite.getPosition(), projMousePos);

        sf::RectangleShape proj = sf::RectangleShape(sf::Vector2f(10, 10));
        proj.setFillColor(sf::Color::Blue);
        proj.setPosition(sf::Vector2f(heroi.sprite.getPosition().x + 20, heroi.sprite.getPosition().y + 20));

        projeteis.emplace_back(direcao, proj);

        shoot = false;
    }

    for (int(i) = 0; i < projeteis.size(); i++) {
        sf::RectangleShape newProj = projeteis[i].getProjetil();
        newProj.setPosition(newProj.getPosition() + (projeteis[i].getDirecao() * projectileSpeed));
        projeteis[i].setProjetil(newProj);

        if (newProj.getPosition().x < 0 || newProj.getPosition().x > Variables().tamX || newProj.getPosition().y < 0 ||
            newProj.getPosition().y > Variables().tamY) {
            projeteis.erase(projeteis.begin() + i);
        }
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
            y = rand() % (Variables().tamY - 1) + 1;
        } else {
            y = 0;
            x = rand() % (Variables().tamX - 1) + 1;
        }

        inimigoShape.setPosition(x, y);
        inimigoShape.setFillColor(sf::Color::Red);
        Inimigo inimigo = Inimigo(inimigoShape, 100, 10.0f, 10);
        inimigos.push_back(inimigo);
    }

    for(int i = 0; i < inimigos.size(); i++) {
        sf::RectangleShape inimigoShape = inimigos[i].getInimigoShape();
        sf::Vector2f direcao = VectorUtils::calcularDirecao(inimigoShape.getPosition(), heroi.sprite.getPosition());
        inimigoShape.setPosition(inimigoShape.getPosition() + direcao * inimigoSpeed);
        inimigos[i].setInimigoShape(inimigoShape);
    }
}