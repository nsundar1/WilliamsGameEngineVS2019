#include "Meteor.h"
#include <memory>
#include "Explosion.h"
#include"GameScene.h"
#include "Score.h"
#include <sstream>


float xSPEED = 0.30f;

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
		sprite_.setPosition(sf::Vector2f(pos.x - xSPEED * msElapsed, pos.y));

	}
}
sf::FloatRect Meteor::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("laser")) {
		sf::Vector2f location = sprite_.getPosition();
		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(location));
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		if (location.y <= 120) {
			scene.AC();
		}
		if (location.y <= 240 && location.y >= 121) {
			scene.BC();
		}
		if (location.y <= 360 && location.y >= 241) {
			scene.CC();
		}
		if (location.y <= 480 && location.y >= 361) {
			scene.DC();
		}
		if (location.y <= 600 && location.y >= 481) {
			scene.EC();
		}
		otherGameObject.makeDead();
			
		//LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY)); //creates laser
		//GAME.getCurrentScene().addGameObject(laser); //adds laser
		
		
		GAME.getCurrentScene().addGameObject(explosion);


		if (scene.Speed() == true) {
			xSPEED = .5f;
		}
		scene.increaseScore();
		scene.increaseLives();
	//	GameScene& scene = (GameScene&)GAME.getCurrentScene();
		//std::stringstream stream;
	//	stream << "Score: " << scene.increaseScore();

	}
	
	makeDead();
}