#pragma once

#include "Engine/GameEngine.h"

class Explosion : public AnimatedSprite {
public:
	Explosion(sf::Vector2f pos);
	void update(sf::Time& elapsed);
	void AC();
private:
	void SetUpExplosionAnimation();
	sf::Sound boom_;
	sf::Sound AM;
	sf::Sound BM;
	sf::Sound CM;
	sf::Sound DM;
	sf::Sound EM;


};

typedef std::shared_ptr<Explosion> ExplosionPtr;



