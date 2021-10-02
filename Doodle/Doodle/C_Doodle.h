#pragma once;
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <time.h> 

class Doodle {
	sf::Texture texture1;
	sf::Sprite sprite;
	sf::IntRect IntRect;
	int x = 0;
	int y = 0;
	bool gameIsOver = false;
public:
	Doodle(int x, int y) {
		this->x = x;
		this->y = y;
		texture1.loadFromFile("doodle.png");
		this->sprite.setTexture(this->texture1);
		this->sprite.setPosition(450, 775);
		
	}
	sf::Sprite getSprite() {
		return this->sprite;
	}
	void movement(char move) {
		switch (move) {
		case 'w':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case 's':
			y--;
			break;
		default:
			gameIsOver == true;
		}
	}
};