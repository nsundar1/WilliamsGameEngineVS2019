#include "Ship.h"
#include <memory>
#include"Laser.h"
#include "Score.h"
#include "GameScene.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

float SPEED = 0.5f;
const int FIRE_DELAY = 200;




// Omit Code

void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	sprite_.setPosition(sf::Vector2f(x, y));
	if (fireTimer_ > 0) {
		fireTimer_ -= msElapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0) {
		fireTimer_ = FIRE_DELAY;
		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width; //where to put laser
		float laserY = y + (bounds.height / 2.0f);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY)); //creates laser
		GAME.getCurrentScene().addGameObject(laser); //adds laser



	}
	//Speed Buttons
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))	SPEED += 0.01f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))	SPEED -= 0.01f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	SPEED = 0.5f;
	//Regular Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	x += SPEED * msElapsed;
	//Special Movement
	srand(time(NULL));
	int Rand1 = rand() % 40;
	int Rand2 = rand() % 30;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))    x = Rand1 * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))    y = Rand2 * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) x -= SPEED * msElapsed * 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) x += SPEED * msElapsed * 5;
	sprite_.setPosition(sf::Vector2f(x, y));
	
}

Ship::Ship() {
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));

}

void Ship::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

