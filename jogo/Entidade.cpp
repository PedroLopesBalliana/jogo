#pragma once
#include "Entidade.h"
 // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidade::Entidade():Ente()
{
}
Entidade::~Entidade()
{

}
sf::Vector2f Entidade::getFronteiras()
{
	return sprite.getPosition();
}
sf::Sprite Entidade::getSprite()
{
	return sprite;
}