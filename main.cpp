#include <SFML/Graphics.hpp>
#include "iostream"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Base Defense");


    sf::CircleShape shape(100.f);

    int x = 100;
    int y = 100;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        sf::Sprite image;
        image.setPosition(sf::Vector2f(x,y));
        image.scale(sf::Vector2f(1,1.5));

        window.clear();
        window.draw(shape);
        window.draw(image);
        window.display();

    }

    return 0;
}
