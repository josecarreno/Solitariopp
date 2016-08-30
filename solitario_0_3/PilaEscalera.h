#pragma once
#include "Pila.h"
class CPilaEscalera : public CPila
{
private:
	int next;
public:
	CPilaEscalera(Image ^imgBaraja, int pX, int pY);
	CPilaEscalera(void);
	~CPilaEscalera(void);
	void dibujar(Graphics ^g, Image ^imgBaraja);
	int dame_elemento_pos(int pos);
};
