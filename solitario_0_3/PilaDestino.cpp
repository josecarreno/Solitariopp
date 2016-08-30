#include "StdAfx.h"
#include "PilaDestino.h"

CPilaDestino::CPilaDestino(Image ^imgBaraja, int pX, int pY, int inicio) : CPila(imgBaraja, pX, pY)
{
	tipo = 3;
	cartaAsociada = new CCarta(inicio, 0, pX + imgBaraja->Width/13 + 20, pY, imgBaraja->Width/13, imgBaraja->Height/5, true);
	vecAsociado.push_back(inicio * 2);
	for (int i=1; i<13; i++)
	{
		int num = vecAsociado[i-1] + inicio;
		if(num > 13)
			num = num - 13;
		vecAsociado.push_back(num);
	}

}
CPilaDestino::CPilaDestino(void)
{
}

CPilaDestino::~CPilaDestino(void)
{
}
void CPilaDestino::dibujar(Graphics ^g, Image ^imgBaraja)
{
	CPila::dibujar(g, imgBaraja);
	cartaAsociada->dibujar(g, imgBaraja);
	if ( next <12 )
		g->DrawString("Next " + vecAsociado[next].ToString(), gcnew Font("Calibri", 18),Brushes::White, x, y - 25);
	else
	{
		Rectangle recDestino = Rectangle(x, y, ancho, alto);
		Rectangle recOrigen = Rectangle(2 * ancho, 4 * alto, ancho, alto);
		g->DrawImage(imgBaraja, recDestino, recOrigen, GraphicsUnit::Pixel);
	}
	
}
int CPilaDestino::dame_elemento_pos(int pos)
{
	return vecAsociado[pos];
}
