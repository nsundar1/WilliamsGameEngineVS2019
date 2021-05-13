#include "Debris.h"
const float SPEED = 0.5f;
Debris::Debris(sf::Vector2f pos) {
	sprite_.setTexture(GAME.getTexture("Resources/debris.png"));
	sprite_.setPosition(pos);
	sprite_.setPosition(pos); assignTag("debris");
}
void Debris::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void Debris::update(sf::Time& elapsed) { 
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1) { 
		makeDead(); 
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	} 
}