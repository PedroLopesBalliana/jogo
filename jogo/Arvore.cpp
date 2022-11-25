#pragma once
#include "Arvore.h"

Arvore::Arvore() : Inimigo(), Bulbassauro(), Atirador()
{
	if (!texture.loadFromFile("assets/Inimigos/Arvoreee.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!envenenar.loadFromFile("assets/Inimigos/entespikes.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture, true);
	sprite.scale(sf::Vector2f(0.75, 0.75));
	sprite.setPosition(sf::Vector2f(300.f, 325.f));
	Personagem::facingLeft=false;
	Entidade::velocidadeV.y = 50.f;
	Entidade::velocidade = 300.f;
	Personagem::num_vidas = 5;
}
Arvore::~Arvore()
{

}
void Arvore::pular()
{
	Entidade::velocidadeV.y = -sqrtf(2.0f * 981.0f * 100.0f);
}
void Arvore::mover()
{
	if (sprite.getPosition().x < limEsq && !Personagem::facingLeft)
	{
		Personagem::facingLeft = true;
		sprite.move(sf::Vector2f(300.0f, 0.f));
		sprite.scale(-1, 1);
		//pular();
	}
	if (sprite.getPosition().x > limDir && Personagem::facingLeft)
	{
		Personagem::facingLeft = false;
		sprite.move(sf::Vector2f(-300.0f, 0.f));
		sprite.scale(-1, 1);
		//pular();
	}
	if (!Personagem::facingLeft)
		sprite.move(sf::Vector2f(-3.0f, 0.f));
	else
		sprite.move(sf::Vector2f(3.0f, 0.f));
	if (sprite.getPosition().y > 425.f)
	{
		pular();
	}

}
void Arvore::executar(float deltaTempo)
{
	if (Personagem::num_vidas > 0)
	{
		printf("sprite bounds %f \n %f \n", sprite.getGlobalBounds().height, sprite.getGlobalBounds().width);
		float aux;
		float centroX, centroY;
		sf::Vector2f posi;
		Entidade::gravidade(deltaTempo);
		bossImprimirSe();
		mover();
		sprite.move(Entidade::velocidadeV * 0.01f);
		aux = rand() % 500;
		if (rand() % 2)
		{
			aux = -aux;
		}
		tiro->setForca(aux);
		if (Personagem::facingLeft)
		{
			centroX = sprite.getPosition().x - (sprite.getGlobalBounds().width / 2);
			centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
		}
		else
		{
			centroX = sprite.getPosition().x + (sprite.getGlobalBounds().width / 2);
			centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
		}
		posi.x = centroX;
		posi.y = centroY;
		tiro->executar(deltaTempo, posi);
		charge++;
		if (charge == 500)
		{
			sprite.setTexture(envenenar);
			Pedra::setVeneno(true);
			charge = 0;
		}
		if (charge == 100)
		{
			sprite.setTexture(texture);
			Pedra::setVeneno(false);
		}
	}
	else
	{
		sprite.move(1000.f, 1000.f);
	}
}

void Arvore::operator--()
{
	if (quant > 1)
	{
		sprite.setTexture(envenenar);
		Pedra::setVeneno(true);
	}
	else
	{
		Personagem::num_vidas--;
		quant--;
	}
}
void Arvore::bossImprimirSe()
{
	geren_graf->desenharEntidades(sprite);
}
