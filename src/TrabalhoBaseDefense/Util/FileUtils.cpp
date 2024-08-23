#include "FileUtils.h"

sf::Font FileUtils::getFont() {
    sf::Font font;
    font.loadFromFile("resources/font/arial.ttf");
    return font;
}

sf::Sprite FileUtils::getSprite(const std::string &path) {
    sf::Texture texture;
    texture.loadFromFile(path);
    return sf::Sprite(texture);
}
