#include "StdAfx.h"
#include "PilaMazo.h"

CPilaMazo::CPilaMazo(Image ^imgBaraja, int pX, int pY) : CPila(imgBaraja, pX, pY)
{
	tipo = 0;
	llenar();
	desordenar();
}
CPilaMazo::CPilaMazo(void)
{
}

CPilaMazo::~CPilaMazo(void)
{
}
void CPilaMazo::llenar()
{
	for(int j=3; j>=0; j--)
		for(int i=13; i >= 1; i--)
		{
			if ( j != 0 || i > 4 )
			{
				CCarta * nueva = new CCarta(i, j, x, y, ancho, alto, true);
				pila.push(nueva);
			}
		}
}
void CPilaMazo::desordenar()
{
	for(int i=0; i<pila.size(); i++)
	{
		int nAleat = rand() % (pila.size());
		intercambiar_pos(i,nAleat);
	}
}
void CPilaMazo::intercambiar_pos(int p1, int p2)
{
	if (p2 == p1)
		return;
	if (p2 < p1)
	{
		int a = p2;
		p2 = p1;
		p1 = a;
	}
	stack<CCarta *> aux;
	CCarta * carta1;
	CCarta * carta2;
	for(int i=0; i<=p2; i++)
	{
		if ( i == p1)
			carta1 = pila.top();
		else if ( i == p2)
			carta2 = pila.top();
		else
			aux.push(pila.top());
		pila.pop();
	}
	pila.push(carta1);
	for(int i=p2-1; i>=0; i--)
	{
		if ( i == p1)
			pila.push(carta2);
		else 
		{
			pila.push(aux.top());
			aux.pop();
		}
	}
}
void CPilaMazo::dibujar(Graphics ^g, Image ^imgBaraja)
{
	for(int i = pila.size() / 10; i>0; i--)
	{
		Rectangle recDestino = Rectangle(x, y - 6*i, ancho, alto);
		Rectangle recOrigen = Rectangle(0, 4 * alto, ancho, alto);
		g->DrawImage(imgBaraja, recDestino, recOrigen, GraphicsUnit::Pixel);
	}
	CPila::dibujar(g, imgBaraja);
}
int CPilaMazo::dame_elemento_pos(int pos)
{
	return -1;
}