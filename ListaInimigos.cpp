#include "ListaInimigos.h"

ListaInimigos::ListaInimigos()
{
}

ListaInimigos::~ListaInimigos()
{
	excluirLista();
}

Inimigo* ListaInimigos::pegarInimigo(int i)
{
	int j = 0;
	for (it = lInimigos.begin(); it != lInimigos.end(); it++)
	{
		if (j == i)
			return *it;
		j++;
	}
}
void ListaInimigos::excluirLista()
{
	lInimigos.clear();
}

void  ListaInimigos::incluirInimigo(Inimigo* e)
{

  		if (e)
        {
            lInimigos.push_back(e);
        }
        else
        {
            cout << "ponteiro nulo!!" << endl;
        }
}

void  ListaInimigos::removerInimigo(int i)
{
	int j = 0;
	for (it = lInimigos.begin(); it != lInimigos.end(); it++)
	{
		if (i == j)
		{
			(*it)->getCorpo().setPosition(sf::Vector2f(10000.0f, 600.0f));
			it = lInimigos.erase(it);
		}
		j++;
	}
}
