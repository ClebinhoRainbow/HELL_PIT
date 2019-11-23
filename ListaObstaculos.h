#pragma once

#include "Obstaculo.h"
#include <set>
using namespace std;

class ListaObstaculos	
{
private:
	std::set<Obstaculo*> conjunto;
	std::set<Obstaculo*>::iterator it;
	
public:
	ListaObstaculos();	
	~ListaObstaculos();

	void incluirObstaculo(Obstaculo* o);
	void excluirSet();

	const int pegarTamanho() const { return conjunto.size(); }

	Obstaculo* pegarObstaculo(int i);
};