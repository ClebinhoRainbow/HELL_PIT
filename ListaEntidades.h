#pragma once

#include "Entidade.h"
#include "Lista.h"

class ListaEntidades
{
private:
	Lista<Entidade> lEntidades;

public:
	ListaEntidades();
	~ListaEntidades();

	void incluirEntidade(Entidade* pe);
	void limparLista();
	void percorrerLista(sf::RenderWindow& janela);
};

