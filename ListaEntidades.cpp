#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::incluirEntidade(Entidade* pe)
{
	lEntidades.incluirInfo(pe);
}

void ListaEntidades::removerEntidade(int id, int i)
{
	lEntidades.setNovo();

	while (lEntidades.getNovo())
	{
		if ((lEntidades.getNovo()->getInfo()->retornarId()) == id)
		lEntidades.setProxNovo();
	}
}

void ListaEntidades::limparLista()
{
	lEntidades.limpar();
}

void ListaEntidades::percorrerLista(sf::RenderWindow& janela)
{
	lEntidades.setNovo();

	while (lEntidades.getNovo()) // percorre a lista
	{
		lEntidades.getNovo()->getInfo()->imprimir_se(janela);
		lEntidades.setProxNovo();
	}
}
