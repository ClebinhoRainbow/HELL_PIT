#pragma once

#include "Plataforma.h"
#include <vector>
using namespace std;

class ListaPlataformas
{
private:
	vector<Plataforma*> lPlataformas;

public:
	ListaPlataformas();
	~ListaPlataformas();
	
	void incluirPlataforma(Plataforma* pltfrm);
	void excluirVector();

	const int pegarTamanho() const { return lPlataformas.size(); }

	Plataforma* pegarPlataforma(int i);
};

