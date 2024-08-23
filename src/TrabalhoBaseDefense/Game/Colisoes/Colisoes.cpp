#include "Colisoes.h"

bool Colisoes::colide(Heroi &heroi, Inimigo &inimigo) {
    return heroi.getColisionBox().getGlobalBounds().intersects(inimigo.getColisionBox().getGlobalBounds());
}

bool Colisoes::colide(Inimigo &inimigo, std::vector<Projetil> &projeteis) {
    for (auto &proj : projeteis) {
        if(!proj.getFriendly()) continue;
            if (inimigo.getColisionBox().getGlobalBounds().intersects(proj.getProjetil().getGlobalBounds())) {
                proj.setJaColidiu(true);
            return true;
        }
    }
    return false;
}

bool Colisoes::colide(Heroi &heroi, std::vector<Projetil> &projeteis) {
    for (auto &proj : projeteis) {
        if(proj.getFriendly()) continue;
        if (heroi.getColisionBox().getGlobalBounds().intersects(proj.getProjetil().getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

bool Colisoes::colide(Inimigo &inimigo, Base &base) {
    sf::FloatRect inimigoBounds = inimigo.getColisionBox().getGlobalBounds();
    sf::FloatRect baseBounds = base.getBase().getGlobalBounds();

    if (inimigoBounds.intersects(baseBounds)) {
        return true;
    }

    return false;
}

bool Colisoes::colide(Projetil &projetil, Base &base) {
    sf::FloatRect projetilBounds = projetil.getProjetil().getGlobalBounds();
    sf::FloatRect baseBounds = base.getBase().getGlobalBounds();

    if (projetilBounds.intersects(baseBounds)) {
        return true;
    }

    return false;
}

bool Colisoes::colide(Projetil &projetil, Projetil &projetil2) {
    sf::FloatRect projetilBounds = projetil.getProjetil().getGlobalBounds();
    sf::FloatRect projetil2Bounds = projetil2.getProjetil().getGlobalBounds();

    if (projetilBounds.intersects(projetil2Bounds)) {
        return true;
    }

    return false;
}
