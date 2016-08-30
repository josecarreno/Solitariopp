#include "StdAfx.h"
#include "Jugador.h"
CJugador::CJugador(int pMovimientos, int pTiempo, int pCartasIniciales)
{
	movimientos = pMovimientos;
	tiempo = pTiempo;
	cartasIniciales = pCartasIniciales;
}
CJugador::CJugador(void)
{
}

CJugador::~CJugador(void)
{
}
int CJugador::getMovimientos()
{
	return movimientos;
}
int CJugador::getTiempo()
{
	return tiempo;
}
int CJugador::getSeg()
{
	return tiempo / 10 % 60;
}
int CJugador::getMin()
{
	return tiempo / 10 / 60;
}
int CJugador::getCartasIniciales()
{
	return cartasIniciales;
}
void CJugador::setMovimientos(int pMovimientos)
{
	movimientos = pMovimientos;
}
void CJugador::setTiempo(int pTiempo)
{
	tiempo = pTiempo;
}
void CJugador::setCartasIniciales(int pCartasIniciales)
{
	cartasIniciales = pCartasIniciales;
}
void CJugador::leeDeArchivo(FILE * archivo)
{
	fread(&movimientos, sizeof(movimientos), 1, archivo);
	fread(&tiempo, sizeof(tiempo), 1, archivo);
	fread(&cartasIniciales, sizeof(cartasIniciales), 1, archivo);
}
void CJugador::guardaEnArchivo(FILE * archivo)
{
	fwrite(&movimientos, sizeof(movimientos), 1, archivo);
	fwrite(&tiempo, sizeof(tiempo), 1, archivo);
	fwrite(&cartasIniciales, sizeof(cartasIniciales), 1, archivo);
	
}
