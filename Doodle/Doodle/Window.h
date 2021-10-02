#include <SFML/Graphics.hpp>
#include <iostream>
#include "C_Doodle.h"

class Window : public sf::RenderWindow {
	sf::Texture texture;
	sf::Color _bgColor;
	sf::Sprite sprite;
	sf::IntRect IntRect;
	Doodle *doodle;
public:
	Window(int width, int heigth) : sf::RenderWindow(sf::VideoMode(width, heigth), "Hello, doodle!") {
		_bgColor = sf::Color::White;
		texture.loadFromFile("background.png");
		// texture.loadFromFile("background.png");
		this->doodle = new Doodle(0, 0);
		
	}

	void show() {

		while (this->isOpen())
		{
			sf::Event event;
			while (this->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->close();
				}
				this->clear(sf::Color::White);
				sf::Sprite sprite(texture);
				//sf::Sprite sprite1(texture1);
				sprite.move(0, 0);
				this->draw(sprite);
				this->draw(doodle->getSprite());
				
				//this->draw(sprite1);
				this->display();
			}
		}
	}

	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}
	~Window() {}
};