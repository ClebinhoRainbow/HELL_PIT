#pragma once

#include <iostream>

template<class TIPO>
class Lista
{
private:
	template<class TIPOEL> class Elemento;

	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pUltimo;
	Elemento<TIPO>* pAtual;
	Elemento<TIPO>* c;

	template<class TIPOEL>
	class Elemento
	{
	private:
		TIPOEL* pInfo;
		Elemento<TIPOEL>* pProximo;
		Elemento<TIPOEL>* pAnterior;

	public:
		Elemento()
		{
			pProximo = NULL;
			pAnterior = NULL;
			pInfo = NULL;
		}

		~Elemento()
		{
			//fazer a desalocação
		}

		void setProximo(Elemento<TIPOEL>* pp)
		{
			pProximo = pp;
		}

		Elemento<TIPOEL>* getProximo()
		{
			return pProximo;
		}

		void setAnterior(Elemento<TIPOEL>* pa)
		{
			pAnterior = pa;
		}

		Elemento<TIPOEL>* getAnterior()
		{
			return pAnterior;
		}

		void setInfo(TIPOEL* pi)
		{
			pInfo = pi;
		}

		TIPOEL* getInfo()
		{
			return pInfo;
		}
	};

public:
	Lista()
	{
		Inicializar();
	}

	~Lista()
	{
		//fazer codigo de desalocar
	}

	void Inicializar()
	{
		pPrimeiro = NULL;
		pUltimo = NULL;
		pAtual = pPrimeiro;
	}

	void incluirInfo(TIPO* pInfo)
	{
		if (NULL != pInfo)
		{
			Elemento<TIPO>* pElemento = NULL;
			pElemento = new Elemento<TIPO>();
			pElemento->setInfo(pInfo);
			incluirElemento(pElemento);
		}
	}

	bool incluirElemento(Elemento<TIPO>* pElemento)
	{
		if (pElemento != NULL)
		{
			if (pPrimeiro == NULL)
			{
				pPrimeiro = pElemento;
				pUltimo = pPrimeiro;
			}
			else
			{
				pElemento->setAnterior(pAtual);
				pElemento->setProximo(NULL);
				pUltimo->setProximo(pElemento);
				pUltimo = pUltimo->getProximo();
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	void limpar()
	{
		Elemento<TIPO>* paux1;
		Elemento<TIPO>* paux2;

		paux1 = pPrimeiro;
		paux2 = paux1;

		while (paux1 != NULL)
		{
			paux2 = paux1->getProximo();
			delete(paux1);
			paux1 = paux2;
		}

		pPrimeiro = NULL;
		pUltimo = NULL;
		pAtual = NULL;
	}

	TIPO* getInfo()
	{
		return pAtual->getInfo();
	}

	Elemento<TIPO>* getPrimeiro()
	{
		return pPrimeiro;
	}

	Elemento<TIPO>* getNovo()
	{
		return c;
	}

	void setNovo()
	{
		c = pPrimeiro;
	}

	void setProxNovo()
	{
		c = c->getProximo();
	}
};