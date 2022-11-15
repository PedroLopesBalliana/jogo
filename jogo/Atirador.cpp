#pragma once
#include "Atirador.h"

Atirador::Atirador(): Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1));
	sprite.setPosition(sf::Vector2f(200.f, 150.f));
}
Atirador::~Atirador()
{

}
void Atirador::executar(float deltaTempo)
{
	if (num_vidas > 0)
	{
		gravidade(deltaTempo);
		imprimirSe();
		mover();
		if (tipo == 1)
		{
			tiro->executar(deltaTempo, sprite.getPosition(), 0.f);
		}
		else if(tipo == 2)
		{
			tiro->executar(deltaTempo, sprite.getPosition(), 250.f);
		}
		else if (tipo == 3)
		{
			tiro->executar(deltaTempo, sprite.getPosition(), -250.f);
		}
	}
	else
	{
		sprite.move(sf::Vector2f(1000, 1000));
		tiro->executar(deltaTempo, sprite.getPosition(), -250.f);
	}
}
void Atirador::mover()
{
	if (tipo == 1)
	{
		if (sprite.getPosition().x < 100 && !facingLeft)
		{
			facingLeft = true;
			sprite.scale(-1, 1);
		}
		if (sprite.getPosition().x > 900 && facingLeft)
		{
			facingLeft = false;
			sprite.scale(-1, 1);
		}
		if (sprite.getPosition().y > 200 && !goingUp)
		{
			goingUp = true;
		}
		if (sprite.getPosition().y < 100 && goingUp)
		{
			goingUp = false;
		}
		if (!facingLeft)
			sprite.move(sf::Vector2f(-3.f, 0.f));
		else
			sprite.move(sf::Vector2f(3.f, 0.f));
		if (!goingUp)
			sprite.move(sf::Vector2f(0.f, 1.5f));
		else
			sprite.move(sf::Vector2f(0.f, -1.5f));
	}
	else if (tipo == 2 || tipo == 3)
	{
		if (sprite.getPosition().y > 600 && !goingUp)
		{
			goingUp = true;
		}
		if (sprite.getPosition().y < 100 && goingUp)
		{
			goingUp = false;
		}
		if (!goingUp)
			sprite.move(sf::Vector2f(0.f, 1.5f));
		else
			sprite.move(sf::Vector2f(0.f, -1.5f));
	}
}
void Atirador::setProjetil(Projetil* pr)
{
	tiro = pr;
}
