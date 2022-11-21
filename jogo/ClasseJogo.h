#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Floresta.h"
#include "GerenciadorGrafico.h"
#include "Menu.h"

class ClasseJogo
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	Jogador *jogador1;
	Jogador* jogador2;
	Floresta* fase1;
	Menu* menu;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();
	void fase1Prin();
};

