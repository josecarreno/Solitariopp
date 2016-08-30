#include "StdAfx.h"
#include "Pila.h"

CPila::CPila(Image ^imgBaraja, int pX, int pY)
{
	ancho = imgBaraja->Width / 13;
	alto = imgBaraja->Height / 5;
	x = pX;
	y = pY;
	seleccionado = false;
	next = 0;
}
CPila::CPila(void)
{
}

CPila::~CPila(void)
{
	while (!pila.empty())
		pila.pop();
}
int CPila::getX()
{
	return x;
}
int CPila::getY()
{
	return y;
}
int CPila::getAncho()
{
	return ancho;
}
int CPila::getAlto()
{
	return alto;
}
int CPila::getTipo()
{
	return tipo;
}
bool CPila::getSeleccionado()
{
	return seleccionado;
}
int CPila::getNext()
{
	return next;
}
int CPila::getPos()
{
	return pos;
}

void CPila::setX(int pX)
{
	x = pX;
}
void CPila::setY(int pY)
{
	y = pY;
}
void CPila::setAncho(int pAncho)
{
	ancho = pAncho;
}
void CPila::setAlto(int pAlto)
{
	alto = pAlto;
}
void CPila::setTipo(int pTipo)
{
	tipo = pTipo;
}
void CPila::setSeleccionado(bool pSeleccionado)
{
	seleccionado = pSeleccionado;
}
void CPila::setNext(int pNext)
{
	next = pNext;
}
void CPila::setPos(int pPos)
{
	pos = pPos;
}

void CPila::dibujar(Graphics ^g, Image ^imgBaraja)
{
	if (pila.empty())
	{
		Rectangle recDestino = Rectangle(x, y, ancho, alto);
		Rectangle recOrigen = Rectangle(1 * ancho, 4 * alto, ancho, alto);
		g->DrawImage(imgBaraja, recDestino, recOrigen, GraphicsUnit::Pixel);
	}
	else
	{
		pila.top()->dibujar(g, imgBaraja);
	}
	if (seleccionado)
	{
		Rectangle rec = Rectangle(x, y, ancho, alto);
		g->DrawRectangle(Pens::Yellow, rec);
	}
}
void CPila::push(CCarta * nueva)
{
	pila.push(nueva);
}
void CPila::pop()
{
	pila.pop();
}
CCarta * CPila::top()
{
	return pila.top();
}
bool CPila::empty()
{
	return pila.empty();
}
int CPila::size()
{
	return pila.size();
}
int CPila::dame_elemento_pos(int pos)
{
	return -1;
}