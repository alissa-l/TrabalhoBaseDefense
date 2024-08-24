#include <random>
#include "GameEnemyUtils.h"
#include "../../Logger/Logger.hpp"
#include "../GameEntities/impl/Dropavel.h"
#include "../GameEntities/Actions/Spawning/DropavelSpawn.h"
#include "../../Util/VectorUtils.hpp"
#include "../GameEntities/Actions/Shooting/EnemyShooting.h"

void GameEnemyUtils::limparInimigos(std::vector<Inimigo> &inimigos, std::vector<Dropavel> &dropaveis,
                                    int &totalInimigosMortos, int &totalInimigosMortosCalculo) {
    Logger logger = Logger("log.txt", LogLevel::DEBUG);
    // Loop
    for (int i = 0; i < inimigos.size(); ++i) {
        // Se a vida do inimigo for menor ou igual a 0
        if (inimigos[i].getVida() <= 0) {
            // Dropa um item aleatório se o inimigo morrer
            droparItem(inimigos[i], dropaveis);

            // Remove o inimigo do vetor
            inimigos.erase(inimigos.begin() + i);

            // Loga a morte do inimigo
            std::string si = "Inimigo morto " + inimigos[i].getNome();
            logger.log(LogLevel::DEBUG, si);

            // Incrementa o total de inimigos mortos
            totalInimigosMortos++;
            totalInimigosMortosCalculo++;

            // Loga o total de inimigos mortos
            logger.log(LogLevel::DEBUG, "Total de inimigos mortos: " + std::to_string(totalInimigosMortos));
        }
    }
}


void GameEnemyUtils::droparItem(const Inimigo& inimigo, std::vector<Dropavel> &dropaveis) {
    Logger logger = Logger("log.txt", LogLevel::DEBUG);
    logger.log(LogLevel::DEBUG, "Dropando item");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    int random = dis(gen);

    if (random == 0) {
        Dropavel dropavel = DropavelSpawn::spawnRandomDropavel();
        dropavel.setPosicao(inimigo.getPosicao());
        dropaveis.push_back(dropavel);
    }
}

void GameEnemyUtils::tiroInimigos(std::vector<Inimigo> &inimigos, std::vector<Projetil> &projeteis, sf::Clock &clock,
                                  double shootingFrequency, Base &base) {
    for(auto &i : inimigos) {
        float elapsedTime = clock.getElapsedTime().asSeconds() - i.getLastShot();
        bool canShoot = elapsedTime >= shootingFrequency;
        if (canShoot) {
            i.setLastShot(clock.getElapsedTime().asSeconds());
            sf::Vector2f basePos = base.getBase().getPosition();
            sf::Vector2f baseSize = base.getBase().getSize();
            sf::Vector2f centroBase = sf::Vector2f(basePos.x + baseSize.x / 2, basePos.y + baseSize.y / 2);
            sf::Vector2f direcao = VectorUtils::calcularDirecao(i.getPosicao(), centroBase);
            EnemyShooting::shoot(i, projeteis, direcao);
        }
    }
}

void GameEnemyUtils::updateDirecaoInimigos(std::vector<Inimigo> &inimigos, std::vector<Heroi> &herois) {
    for (auto &i : inimigos) {
        try {
            Inimigo inimigo = i;
            inimigo.update();
            inimigo.updateDirecao(herois);
            i = inimigo;
        } catch (std::exception &e) {
            std::string es = e.what();
            throw std::runtime_error("Erro ao atualizar o inimigo: " + es);
        }
    }
}

