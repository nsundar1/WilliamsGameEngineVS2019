#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();
 
  
  int getScore();
 void increaseScore();

 int increaseLives();
 int getLives();
 void decreaseLives();
 void AC();
 void BC();
 void CC();
 void DC();
 void EC();
private:
	int score_ = 0;
	int lives_ = 3;
	sf::Sound AM;
	sf::Sound BM;
	sf::Sound CM;
	sf::Sound DM;
	sf::Sound EM;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
