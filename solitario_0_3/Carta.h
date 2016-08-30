#pragma once
using namespace System::Drawing;
class CCarta
{
private:
	int numero;
	int palo;
	bool caraArriba;
	int x;
	int y;
	int ancho;
	int alto;
public:
	CCarta(int pNumero, int pPalo, int pX, int pY, int pAncho, int pAlto, bool pCaraArriba);
	CCarta(void);
	~CCarta(void);
	int getNumero();
	int getPalo();
	bool getCaraArriba();
	int getX();
	int getY();
	void setNumero(int pNumero);
	void setPalo(int pPalo);
	void setCaraArriba(bool pCaraArriba);
	void setX(int pX);
	void setY(int pY);
	void voltear();
	void dibujar(Graphics ^g, Image ^imgBaraja);
};
