#include "Jogo.h"

Jogo::Jogo() :
	janela(sf::VideoMode(960, 540), "Hell Pit", sf::Style::Close),
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(960.0f, 540.0f))
{
	fase1 = nullptr;
	fase2 = nullptr;
	gerenciadorgrafico.setMenuBackgroundTexture(menuIniciar.getCorpo());
}


Jogo::~Jogo()
{

}

void Jogo::executar()
{
	while (janela.isOpen())
	{
		view.setCenter(menuIniciar.getCorpo().getPosition().x + 480.0f,
			menuIniciar.getCorpo().getPosition().y + 270.0f);
		janela.setView(view);
		switch (menuIniciar.executar(janela))
		{
		default:
			break;
		case 1:
			fase1 = new Entrada_Inferno(gerenciadorgrafico, 0);
			fase1->executar(janela, view);
			delete(fase1);
			break;
		case 2:
			fase2 = new Profundezas_do_Inferno(gerenciadorgrafico, 0);
			fase2->executar(janela, view);
			delete(fase2);
			break;
		case 3:
			janela.close();
			break;
		case 4:
			janela.close();
			break;
		}
	}
}
