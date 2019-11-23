#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
	it = conjunto.begin();
}

ListaObstaculos::~ListaObstaculos()
{
	excluirSet();
}

void ListaObstaculos::incluirObstaculo(Obstaculo* o)
{
	if (o != NULL)
		conjunto.insert(o);
}

void ListaObstaculos::excluirSet()
{
	conjunto.clear();
}

Obstaculo* ListaObstaculos::pegarObstaculo(int i)
{
	int j = 0;
	for (it = conjunto.begin(); it != conjunto.end(); it++)
	{
		if (j == i)
			return *it;
		j++;
	}
	return nullptr;
}

