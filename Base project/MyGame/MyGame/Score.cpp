#include "Score.h"
#include "GameScene.h"
#include <sstream>

Score::Score(sf::Vector2f pos) {

	text_.setFont(GAME.getFont("Resources/Cournef-Regular,ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setColor(sf::Color::White);
	assignTag("score");



}
void Score::draw() {
	GAME.getRenderWindow().draw(text_);



}
void Score::update(sf::Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	std::stringstream stream;
	stream << "SCORE: " << scene.getScore();
	text_.setString(stream.str());
}



