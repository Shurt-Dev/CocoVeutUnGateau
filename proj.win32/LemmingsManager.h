#pragma once
#include "cocos2d.h"
#include "Lemming.h"

#define VILLAGE_SIZE 20

class LemmingsManager
{
	std::vector<Lemming> village(1);
	//Lemming village[VILLAGE_SIZE];
	cocos2d::Vec2 velocity = cocos2d::Vec2(100, 0);

public:
	~LemmingsManager();
	void SpawnLemming();
	void UpdateLemming(float dt);
};