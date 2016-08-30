#include "StdAfx.h"
#include "VecJugadores.h"

CVecJugadores::CVecJugadores(void)
{
	N = 0;
	leeDeArchivo();
	if ( N == 0 )
		vec = NULL;
}

CVecJugadores::~CVecJugadores(void)
{
	if (N>0)
	{
		guardaEnArchivo();
		for(int i=0; i<N; i++)
		{
			delete vec[i];
		}
		delete [] vec;
	}
}
void CVecJugadores::leeDeArchivo()
{
	FILE * archivo = fopen("jugadores.dat", "rb");
	if ( archivo != NULL )
	{
		fread(&N, sizeof(N), 1, archivo);
		vec = new CJugador *[N];
		for(int i=0; i<N; i++)
		{
			CJugador * aux = new CJugador();
			aux->leeDeArchivo(archivo);
			vec[i] = aux;
		}
		fclose(archivo);
	}
}
void CVecJugadores::guardaEnArchivo()
{
	FILE * archivo = fopen("jugadores.dat", "wb");
	if (archivo != NULL)
	{
		fwrite(&N, sizeof(N), 1 ,archivo);
		for(int i=0; i<N; i++)
			vec[i]->guardaEnArchivo(archivo);
		fclose(archivo);
	}
}
int CVecJugadores::getN()
{
	return N;
}
CJugador * CVecJugadores::getJugEnPos(int pos)
{
	return vec[pos];
}
void CVecJugadores::agregarJugador(CJugador *nuevo)
{
	CJugador* *temp = new CJugador *[N+1];
	for(int i=0; i<N; i++)
		temp[i] = vec[i];
	delete [] vec;
	vec = temp;
	vec[N] = new CJugador(nuevo->getMovimientos(), 
		                  nuevo->getTiempo(), 
						  nuevo->getCartasIniciales());
	N++;
}
void CVecJugadores::eliminarUltimo()
{
	if (N <= 0)
		return;
	CJugador* *temp = new CJugador *[N-1];
	for(int i=0; i<N-1; i++)
		temp[i] = vec[i];
	delete vec[N-1];
	delete [] vec;
	vec = temp;
	N--;
}
bool CVecJugadores::verificar_mejor_tiempo(int tiempo)
{ 
	if (N < 5)
		return true;
	if (tiempo < vec[N-1]->getTiempo())
		return true;
	return false;
}
void CVecJugadores::ordenar()
{
	int k;
	CJugador * aux;
	for (int i=1; i<N; i++)
	{
		aux = vec[i];
		k = i-1;
		while (k >= 0 && aux->getTiempo() < vec[k]->getTiempo())
		{
			vec[k+1] = vec[k];
			k--;
		}
		vec[k+1] = aux;
	}

}
void CVecJugadores::dibujar(Graphics ^g)
{
	g->DrawString("Tiempo", gcnew Font("Calibri", 14),Brushes::White, 45, 15);
	g->DrawString("Movimientos", gcnew Font("Calibri", 14),Brushes::White, 125, 15);
	for(int i=0; i<N ;i++)
	{
		g->DrawString(i+1 + ". ", gcnew Font("Calibri", 14),Brushes::White, 15, 45 + i *15);
		g->DrawString(vec[i]->getMin().ToString() + " : " + vec[i]->getSeg().ToString(), 
					  gcnew Font("Calibri", 14),Brushes::White, 55, 45 + i *15);
		g->DrawString(vec[i]->getMovimientos().ToString(), 
					  gcnew Font("Calibri", 14),Brushes::White, 175, 45 + i *15);
	}
}