#pragma once
#include "pila.h"

class CPilaMazo : public CPila
{

public:
	CPilaMazo(Image ^imgBaraja, int pX, int pY);
	CPilaMazo(void);
	~CPilaMazo(void);
	void llenar();
	void desordenar();
	void intercambiar_pos(int p1, int p2);
	void dibujar(Graphics ^g, Image ^imgBaraja);
	int dame_elemento_pos(int pos);
};
