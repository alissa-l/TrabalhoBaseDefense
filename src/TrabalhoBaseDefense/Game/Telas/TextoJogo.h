#ifndef SRC_TRABALHOBASEDEFENSE_TEXTOJOGO_H
#define SRC_TRABALHOBASEDEFENSE_TEXTOJOGO_H


#include "SFML/Graphics/Text.hpp"
#include "../GameEntities/impl/Heroi.hpp"
#include "../GameEntities/impl/Base.hpp"

class TextoJogo {
public:
    sf::Text texto;
    TextoJogo();

    void update(Heroi &heroi, int round, const Base& base);
};


#endif //SRC_TRABALHOBASEDEFENSE_TEXTOJOGO_H
