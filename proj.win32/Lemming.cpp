#include "Lemming.h"
#include "cocos2d.h"

USING_NS_CC;

Lemming::Lemming()
{
	m_positionX = 0;
	m_positionY = 0;

	m_sprite = Sprite::create("hu_tao.jpg");
	m_sprite->setScale(10.0);
}