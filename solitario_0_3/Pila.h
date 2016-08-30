#pragma once
#include <stack>
#include "Carta.h"
using namespace std;
using namespace System::Drawing;
class CPila
{
protected:
	stack<CCarta *> pila;
	int x;
	int y;
	int ancho;
	int alto;
	bool seleccionado;
	int tipo;
	int next;
	int pos;
public:
	CPila(Image ^imgBaraja, int pX, int pY);
	CPila(void);
	~CPila(void);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	int getTipo();
	bool getSeleccionado();
	int getNext();
	int getPos();
	
	void setX(int pX);
	void setY(int pY);
	void setAncho(int pAncho);
	void setAlto(int pAlto);
	void setTipo(int pTipo);
	void setSeleccionado(bool pSeleccionado);
	void setNext(int pNext);
	void setPos(int pPos);
	virtual void dibujar(Graphics ^g, Image ^imgBaraja);
	virtual int dame_elemento_pos(int pos);
	void push(CCarta * nueva);
	void pop();
	CCarta * top();
	bool empty();
	int size();
};
