#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <time.h>  
#include <string>
#include <ctime>
class Window : public sf::RenderWindow {
	sf::Texture texture;
	sf::Color _bgColor;
	sf::Sprite sprite;
	sf::IntRect IntRect;
public:
	Window(int width, int heigth) : sf::RenderWindow(sf::VideoMode(width, heigth), "Hello, doodle!") {
		_bgColor = sf::Color::White;
		texture.loadFromFile("background.png");
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
					// texture.setRepeated(true);
					// texture.loadFromFile("background.png", sf::IntRect(100,100,100,100));
					sprite.move(30, 0);
					this->draw(sprite);
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

int main()
{
	Window* window = new Window(600, 600);
	window->show();
	delete window;
	return 0;
}