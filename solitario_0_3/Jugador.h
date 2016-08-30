#pragma once
#include <string.h>
#include <stdio.h>
class CJugador
{
private:
	int movimientos;
	int tiempo;
	int cartasIniciales;
public:
	CJugador(int pMovimientos, int pTiempo, int pCartasIniciales);
	CJugador(void);
	~CJugador(void);
	int getMovimientos();
	int getTiempo();
	int getCartasIniciales();
	int getSeg();
	int getMin();
	void setMovimientos(int pMovimientos);
	void setTiempo(int pTiempo);
	void setCartasIniciales(int pCartasIniciales);
	void leeDeArchivo(FILE * archivo);
	void guardaEnArchivo(FILE * archivo);
};
