#include "StdAfx.h"
#include "Carta.h"
CCarta::CCarta(int pNumero, int pPalo, int pX, int pY, int pAncho, int pAlto, bool pCaraArriba)
{
	numero = pNumero;
	palo = pPalo;
	x = pX;
	y = pY;
	ancho = pAncho;
	alto = pAlto;
	caraArriba = pCaraArriba;
}
CCarta::CCarta(void)
{
}

CCarta::~CCarta(void)
{
}
int CCarta::getNumero()
{
	return numero;
}
int CCarta::getPalo()
{
	return palo;
}
bool CCarta::getCaraArriba()
{
	return caraArriba;
}
int CCarta::getX()
{
	return x;
}
int CCarta::getY()
{
	return y;
}
void CCarta::setNumero(int pNumero)
{
	numero = pNumero;
}
void CCarta::setPalo(int pPalo)
{
	palo = pPalo;
}
void CCarta::setCaraArriba(bool pCaraArriba)
{
	caraArriba = pCaraArriba;
}
void CCarta::setX(int pX)
{
	x = pX;
}
void CCarta::setY(int pY)
{
	y = pY;
}
void CCarta::voltear()
{
	caraArriba = !caraArriba;
}
void CCarta::dibujar(Graphics ^g, Image ^imgBaraja)
{
	int iH, iV;
	if ( caraArriba )
	{
		iV = palo;
		iH = numero - 1;
	}
	else 
	{
		iH = 0;
		iV = 4;
	}
	Rectangle recDestino = Rectangle(x, y, ancho, alto);
	Rectangle recOrigen = Rectangle(iH * ancho, iV * alto, ancho, alto);
	g->DrawImage(imgBaraja, recDestino, recOrigen, GraphicsUnit::Pixel);
}
