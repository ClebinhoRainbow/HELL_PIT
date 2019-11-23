#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{
}

ListaPlataformas::~ListaPlataformas()
{
}

void ListaPlataformas::incluirPlataforma(Plataforma* pltfrm)
{
	lPlataformas.push_back(pltfrm);
}

void ListaPlataformas::excluirVector()
{
	lPlataformas.clear();
}

Plataforma* ListaPlataformas::pegarPlataforma(int i)
{
	return lPlataformas[i];
}
