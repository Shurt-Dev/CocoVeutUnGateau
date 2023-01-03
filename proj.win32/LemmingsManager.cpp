#include "LemmingsManager.h"

LemmingsManager::~LemmingsManager()
{

}

void LemmingsManager::SpawnLemming()
{
	Lemming* item = new Lemming;
    std::vector<Lemming>::iterator it = this->village.end();
    this->village.insert(it, item);
};

void LemmingsManager::UpdateLemming(float dt)
{
    for (int i = 0; i < sizeof(village) / sizeof(int); i++)
    {
        // move the sprite
        this->village[i].m_sprite->setPosition(this->village[i].m_sprite->getPosition() + velocity * dt);

        // check if the sprite has collided with the edge of the screen
        auto size = cocos2d::Director::getInstance()->getWinSize();
        if (this->village[i].m_sprite->getPosition().x > size.width || this->village[i].m_sprite->getPosition().x < 0) {
            velocity.x = -velocity.x;
        }
        if (this->village[i].m_sprite->getPosition().y > size.height || this->village[i].m_sprite->getPosition().y < 0) {
            velocity.y = -velocity.y;
        }
    }
}
;