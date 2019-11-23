#pragma once

#include "Inimigo.h"
#include <list>
using namespace std;

class ListaInimigos
{
private:
	list<Inimigo*> lInimigos;
	list<Inimigo*>::iterator it;

public:
	ListaInimigos();
	~ListaInimigos();

	void incluirInimigo(Inimigo* e);
	void removerInimigo(int i);
	void excluirLista();

	const int pegarTamanho() const { return lInimigos.size(); }

	Inimigo* pegarInimigo(int it);
};
