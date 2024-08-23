#ifndef SRC_TRABALHOBASEDEFENSEEXE_FILEUTILS_H
#define SRC_TRABALHOBASEDEFENSEEXE_FILEUTILS_H


#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"

class FileUtils {
public:
    /**
     * Carrega a fonte do jogo
     * @return
     */
    static sf::Font getFont();

    /**
     * Carrega um sprite do jogo
     */
     static sf::Sprite getSprite(const std::string& path);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_FILEUTILS_H
