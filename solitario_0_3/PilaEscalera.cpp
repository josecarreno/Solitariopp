#include "StdAfx.h"
#include "PilaEscalera.h"

CPilaEscalera::CPilaEscalera(Image ^imgBaraja, int pX, int pY) : CPila(imgBaraja, pX, pY)
{
	tipo = 2;
	next = 0;

}
CPilaEscalera::CPilaEscalera(void)
{
}

CPilaEscalera::~CPilaEscalera(void)
{
}

void CPilaEscalera::dibujar(Graphics ^g, Image ^imgBaraja)
{
	if (pila.empty())
	{
		Rectangle recDestino = Rectangle(x, y, ancho, alto);
		Rectangle recOrigen = Rectangle(1 * ancho, 4 * alto, ancho, alto);
		g->DrawImage(imgBaraja, recDestino, recOrigen, GraphicsUnit::Pixel);
	}
	else
	{
		stack<CCarta*> aux;
		while(!pila.empty())
		{
			aux.push(pila.top());
			pila.pop();
		}
		while(!aux.empty())
		{
			aux.top()->dibujar(g, imgBaraja);
			pila.push(aux.top());
			aux.pop();
		}
	}
	if (seleccionado)
	{
		Rectangle rec = Rectangle(x, y, ancho, alto);
		g->DrawRectangle(Pens::Yellow, rec);
	}
	//CPila::dibujar(g, imgBaraja);
}
int CPilaEscalera::dame_elemento_pos(int pos)
{
	return -1;
}