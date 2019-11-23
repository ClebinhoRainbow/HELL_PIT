#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{
	backgroundTexture.loadFromFile("Fase1.png");
	background2Texture.loadFromFile("Fase2.png");
	backgroundMenuTexture.loadFromFile("Menu.png");
	playerTexture.loadFromFile("Jogador1.png");
	player2Texture.loadFromFile("Jogador2.png");
	caoTexture.loadFromFile("Cao.png");
	bestaTexture.loadFromFile("Besta.png");
	floorTexture.loadFromFile("Chao1.png");
	floor2Texture.loadFromFile("Chao2.png");
	bolaDeFogoTexture.loadFromFile("Bola_de_Fogo.png");
	machadoTexture.loadFromFile("Machado.png");
	demonioTexture.loadFromFile("Demonio.png");
	pesadeloTexture.loadFromFile("Pesadelo.png");
	espinhosTexture.loadFromFile("Espinhos.png");
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}
