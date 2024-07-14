#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(
        sf::VideoMode(800, 600), 
        "Time Estimation"
    );
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    // sf::CircleShape shape(100.0);
    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setFillColor(sf::Color::Cyan);
    rect.setPosition(sf::Vector2f(50, 50));
    // shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            rect.setPosition(rect.getPosition() + sf::Vector2f(0, -10));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rect.setPosition(rect.getPosition() + sf::Vector2f(0, 10));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            rect.setPosition(rect.getPosition() + sf::Vector2f(-10, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            rect.setPosition(rect.getPosition() + sf::Vector2f(10, 0));
        }
        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}