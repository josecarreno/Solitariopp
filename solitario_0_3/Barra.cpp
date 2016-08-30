#include "StdAfx.h"
#include "Barra.h"

CBarra::CBarra(float pX, float pY, float pAncho, float pLargo, float pCarga, float pVelocidad)
{
	x = pX;
	y = pY;
	ancho = pAncho;
	largo = pLargo;
	carga = pCarga;
	velocidad = pVelocidad;
}
CBarra::CBarra(void)
{
}

CBarra::~CBarra(void)
{
}
float CBarra::getX()
{
	return x;
}
float CBarra::getY()
{
	return y;
}
float CBarra::getAncho()
{
	return ancho;
}
float CBarra::getLargo()
{
	return largo;
}
float CBarra::getCarga()
{
	return carga;
}
float CBarra::getVelocidad()
{
	return velocidad;
}
void CBarra::setX(float pX)
{
	x = pX;
}
void CBarra::setY(float pY)
{
	y = pY;
}
void CBarra::setAncho(float pAncho)
{
	ancho = pAncho;
}
void CBarra::setLargo(float pLargo)
{
	largo = pLargo;
}
void CBarra::setCarga(float pCarga)
{
	carga = pCarga;
}
void CBarra::setVelocidad(float pVelocidad)
{
	velocidad = pVelocidad;
}
void CBarra::dibujar(Graphics ^g)
{
	g->DrawRectangle(Pens::White, x, y, largo, ancho);
	if (carga > 0.0)
	{
		float _largo = carga*(largo - 6.0)/100.0;
		float _ancho = ancho - 6.0;
		g->FillRectangle(Brushes::White, x + 3, y + 3, _largo, _ancho);
	}
}
void CBarra::disminuir()
{
	if (carga > 0.0)
		carga -= velocidad;
	if (carga < 0.0)
		carga = 0.0;
}
void CBarra::aumentar(float porcentaje)
{
	if (carga < 100.0)
		carga += porcentaje;
	if (carga > 100.0)
		carga = 100.0;
}
