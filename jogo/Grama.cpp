#include "Grama.h"

Grama::Grama(): aderencia(0)
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Grama3.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(0.125f, 0.125f);
	sprite.setPosition(sf::Vector2f(300.f, 100.f));

}
Grama::~Grama()
{
}
void Grama::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	if (deltaTempo == 1.0f)
	{
		aderencia++;
	}
}
int Grama::getTipo()
{
	return aderencia;
}
