#include "GameScene.h"
#include "Ship.h"
#include"MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <memory>



GameScene::GameScene() {
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

}
int GameScene::getScore() {
	return score_;

}

void GameScene::increaseScore() {
	++score_;
	
	
}
int GameScene::getLives() {


	return lives_;
}
int GameScene::increaseLives() {
	if (score_ % 10 == 0 && score_ >> 1) {
		++lives_;
	}
	return lives_;
}
void GameScene::AC(){
	AM.setBuffer(GAME.getSoundBuffer("Resources/AC.wav"));
	AM.play();
}
void GameScene::BC() {
	BM.setBuffer(GAME.getSoundBuffer("Resources/BC.wav"));
	BM.play();
}
void GameScene::CC() {
	CM.setBuffer(GAME.getSoundBuffer("Resources/CC.wav"));
	CM.play();
}
void GameScene::DC() {
	DM.setBuffer(GAME.getSoundBuffer("Resources/DC.wav"));
	DM.play();
}
void GameScene::EC() {
	EM.setBuffer(GAME.getSoundBuffer("Resources/EC.wav"));
	EM.play();
}
void GameScene::decreaseLives() 
{ 
	--lives_; 
	if (lives_ == 0) { 
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_); 
		GAME.setScene(gameOverScene); 
	} 
	
}


