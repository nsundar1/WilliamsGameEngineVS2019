#include "Meteor.h"
#include <memory>
#include "Explosion.h"
#include"GameScene.h"
#include "Score.h"
#include <sstream>


const float SPEED = 0.20f;

Meteor::Meteor(sf::Vector2f pos) { //constructor
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);




}
void Meteor::draw() {
	GAME.getRenderWindow().draw(sprite_);

}

void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1) { // redo page 29
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		makeDead();

	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		sprite_.setPosition(sf::Vector2f(pos.y - SPEED * msElapsed, pos.x));
	}
}
sf::FloatRect Meteor::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("laser")) {
		sf::Vector2f location = sprite_.getPosition();
		otherGameObject.makeDead();
		
		//LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY)); //creates laser
		//GAME.getCurrentScene().addGameObject(laser); //adds laser
		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f (location));
		
		GAME.getCurrentScene().addGameObject(explosion);

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
	//	GameScene& scene = (GameScene&)GAME.getCurrentScene();
		//std::stringstream stream;
	//	stream << "Score: " << scene.increaseScore();

	}
	makeDead();
}