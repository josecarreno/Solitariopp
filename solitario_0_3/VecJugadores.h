#pragma once
#include "Jugador.h"
#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;
using namespace System::Drawing;
class CVecJugadores
{
private:
	CJugador * * vec;
	int N;
	void guardaEnArchivo();
	void leeDeArchivo();
public:
	CVecJugadores(void);
	~CVecJugadores(void);
	int getN();
	CJugador * getJugEnPos(int pos);
	void agregarJugador(CJugador * nuevo);
	void eliminarUltimo();
	bool verificar_mejor_tiempo(int tiempo);
	void ordenar();
	void dibujar(Graphics ^g);
};
