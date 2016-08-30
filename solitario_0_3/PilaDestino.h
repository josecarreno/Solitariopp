#pragma once
#include "pila.h"
#include <vector>
using namespace std;
using namespace System::Drawing;
class CPilaDestino : public CPila
{
private:
	vector<int> vecAsociado;
	CCarta * cartaAsociada;
public:
	CPilaDestino(Image ^imgBaraja, int pX, int pY, int inicio);
	CPilaDestino(void);
	~CPilaDestino(void);
	void dibujar(Graphics ^g, Image ^img);
	int dame_elemento_pos(int pos);
};
