#pragma once
using namespace System::Drawing;
class CBarra
{
private:
	float x;
	float y;
	float ancho;
	float largo;
	float carga;
	float velocidad;
public:
	CBarra(float pX, float pY, float pAncho, float pLargo, float pCarga, float pVelocidad);
	CBarra(void);
	~CBarra(void);
	float getX();
	float getY();
	float getAncho();
	float getLargo();
	float getCarga();
	float getVelocidad();
	void setX(float pX);
	void setY(float pY);
	void setAncho(float pAncho);
	void setLargo(float pLargo);
	void setCarga(float pCarga);
	void setVelocidad(float pVelocidad);
	void dibujar(Graphics ^g);
	void disminuir();
	void aumentar(float porcentaje);
};
