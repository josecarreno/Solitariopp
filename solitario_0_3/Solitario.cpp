#include "StdAfx.h"
#include "Solitario.h"

CSolitario::CSolitario(void)
{
}

CSolitario::~CSolitario(void)
{ 
	for (int i=0; i<vec.size(); i++)
		delete vec[i];
	delete barra;
}
int CSolitario::getSemilla()
{
	return semilla;
}
int CSolitario::getSeg()
{
	return tiempo / 10 % 60;
}
int CSolitario::getMin()
{
	return tiempo / 10 / 60;
}
int CSolitario::getMovimientos()
{
	return movimientos;
}
int CSolitario::getTiempo()
{
	return tiempo;
}
int CSolitario::getCartasIniciales()
{
	return cartasIniciales;
}
bool CSolitario::getBarraActivada()
{
	return barraActivada;
}
void CSolitario::inicializar(Image ^imgBaraja, int pSemilla, int pCartasIniciales, bool conBarra)
{
	srand(pSemilla);
	semilla = pSemilla;
	cartasIniciales = pCartasIniciales;
	movimientos = 0;
	tiempo = 0;
	CPilaMazo * mazo = new CPilaMazo(imgBaraja, 25, 375);
	mazo->setPos(vec.size());
	vec.push_back(mazo);
	CPila * desecho = new CPila(imgBaraja, 25, 225);
	desecho->setPos(vec.size());
	desecho->setTipo(1);
	vec.push_back(desecho);
	for(int i=0; i<5; i++)
	{
		CPilaEscalera * escalera = new CPilaEscalera(imgBaraja, 125 + i * 100, 40);
		escalera->setPos(vec.size());
		vec.push_back(escalera);
	}
	for(int i=0; i<4; i++)
	{
		CPilaDestino * destino = new CPilaDestino(imgBaraja, 650, 150 + i*120, i+1);
		destino->setPos(vec.size());
		vec.push_back(destino);
	}
	llenar_pilas_destino(0, 7, 10);
	barraActivada = conBarra;
	barra =  new CBarra(160, 540, 30, 400, 100.0, 0.3);
}
void CSolitario::llenar_pilas_destino(int pos_PilaMazo, int posI_PilaDestino,
									  int posF_PilaDestino)
{
	for(int i=posI_PilaDestino; i<=posF_PilaDestino; i++)
	{
		for(int j=0; j<cartasIniciales; j++)
		{
			bool encontrado = false;
			CPila * aux = new CPila();
			while(!vec[pos_PilaMazo]->empty() && !encontrado)
			{
				if(vec[pos_PilaMazo]->top()->getNumero() == vec[i]->dame_elemento_pos(vec[i]->getNext()))
				{
					mover_carta(vec[pos_PilaMazo], vec[i]);
					encontrado = true;
				}
				else
				{
					aux->push(vec[pos_PilaMazo]->top());
					vec[pos_PilaMazo]->pop();
				}
			}
			while(!aux->empty())
			{
				vec[pos_PilaMazo]->push(aux->top());
				aux->pop();
			}
		}
	}
}
void CSolitario::dibujar_todos(Graphics ^g, Image ^imgBaraja)
{
	for(int i=0; i<vec.size(); i++)
		vec[i]->dibujar(g, imgBaraja);
	g->DrawString("Movimientos: " + movimientos.ToString(), gcnew Font("Calibri", 18),Brushes::White, 280, 500);
	System::String ^strmin = getMin().ToString();
	System::String ^strseg = getSeg().ToString();
	if ( getMin() < 10 )
		strmin = "0" + strmin;
	if ( getSeg() < 10 )
		strseg = "0" + strseg;
	g->DrawString(strmin + " : " + strseg, gcnew Font("Calibri", 18),Brushes::White, 325, 575);
	if (barraActivada)
		barra->dibujar(g);
}
void CSolitario::aumentarTiempo()
{
	if (tiempo < 2147483647)
		tiempo++;
}
CPila * CSolitario::get_pila_seleccionada()
{
	for(int i=0; i<vec.size(); i++)
		if( vec[i]->getSeleccionado() )
			return vec[i];
	return NULL;
}
CPila * CSolitario::get_pila_en_click(int posX , int posY)
{
	for(int i=0; i<vec.size(); i++)
		if ( posX >= vec[i]->getX() && 
			 posX <= vec[i]->getX() + vec[i]->getAncho() &&
			 posY >= vec[i]->getY() &&
			 posY <= vec[i]->getY() + vec[i]->getAlto())
			 return vec[i];
	return NULL;
}
void CSolitario::interactuar_con_click(int posX, int posY)
{
	CPila * pila_sel = get_pila_seleccionada();
	CPila * pila_click = get_pila_en_click(posX, posY);
	if (pila_click == NULL)
	{
		if (pila_sel != NULL)
			pila_sel->setSeleccionado(false);
		return;
	}
	if (pila_sel == NULL)
	{
		if (!pila_click->empty())
			pila_click->setSeleccionado(true);
		return;
	}
	if (pila_sel == pila_click)
	{
		for(int i=0; i<vec.size(); i++)
			vec[i]->setSeleccionado(false);
		return;
	}
	if (verificar_movimiento(pila_sel, pila_click))
	{
		mover_carta(pila_sel, pila_click);
		guardar_movimiento(pila_sel, pila_click);
		movimientos++;
		for(int i=0; i<vec.size(); i++)
			vec[i]->setSeleccionado(false);
		if( barraActivada && pila_click->getTipo() != 3)
			barra->aumentar(20);
		else if ( barraActivada && pila_click->getTipo() == 3)
			barra->aumentar(100);
	}
	else
	{
		if (!pila_click->empty())
		{
			for(int i=0; i<vec.size(); i++)
				vec[i]->setSeleccionado(false);
			pila_click->setSeleccionado(true);
		}
	}
}
void CSolitario::interactuar_con_click_der(int posX, int posY)
{
	CPila * pila_origen = get_pila_en_click(posX, posY);
	if (pila_origen == NULL)
		return;
	int tipoOrigen = pila_origen->getTipo();
	if (tipoOrigen != 3)
	{
		for(int i = 7; i<vec.size(); i++)
			if(verificar_movimiento(pila_origen, vec[i]))
			{
				mover_carta(pila_origen, vec[i]);
				guardar_movimiento(pila_origen, vec[i]);
				movimientos++;
				for(int i=0; i<vec.size(); i++)
					vec[i]->setSeleccionado(false);
				if( barraActivada)
					barra->aumentar(100);
				return;
			}
	}
}
bool CSolitario::verificar_movimiento(CPila *pila_origen, CPila *pila_destino)
{
	if (pila_origen->empty() || pila_origen == pila_destino || pila_origen == NULL || pila_destino == NULL)
		return false;
	int tipo_origen = pila_origen->getTipo();
	int tipo_destino = pila_destino->getTipo();
	if (tipo_destino == 3 && (pila_destino->dame_elemento_pos(pila_destino->getNext()) != pila_origen->top()->getNumero()|| 
		pila_destino->getNext() >= 12))
		return false;
	if ( tipo_origen == 0 ||
		 tipo_origen == 1 && ( tipo_destino == 2 || tipo_destino == 3) ||
		 tipo_origen == 2 && tipo_destino == 3)
		return true;
	return false;
}
void CSolitario::mover_carta(CPila *pila_origen, CPila *pila_destino)
{
	if (pila_origen->empty() || pila_origen == pila_destino || pila_origen == NULL || pila_destino == NULL)
		return;
	int x_origen = pila_origen->getX();
	int y_origen = pila_origen->getY();
	int x_dest = pila_destino->getX();
	int y_dest = pila_destino->getY();
	if (pila_origen->getTipo() == 2 && pila_origen->size() > 1)
	{
		pila_origen->top()->setY(y_dest);
		pila_origen->setY(y_origen - ESP_V);
	}
	else if (pila_destino->getTipo() == 2 && !pila_destino->empty())
	{
		pila_origen->top()->setY(y_dest + ESP_V);
		pila_destino->setY(y_dest + ESP_V);
	}
	else
		pila_origen->top()->setY(y_dest);
	pila_origen->top()->setX(x_dest);
	pila_destino->push(pila_origen->top());
	pila_origen->pop();
	if (pila_destino->getTipo() == 3)
	{
		pila_destino->setNext(pila_destino->getNext() + 1);
	}
}
void CSolitario::guardar_movimiento(CPila *pila_origen,CPila *pila_destino)
{
	if ( pila_deshacer.size() >= MAX_UNDO_REDO )
	{
		stack<int> aux;
		while(!pila_deshacer.empty())
		{
			aux.push(pila_deshacer.top());
			pila_deshacer.pop();
		}
		aux.pop();
		while(!aux.empty())
		{
			pila_deshacer.push(aux.top());
			aux.pop();
		}
	}
	pila_deshacer.push(pila_origen->getPos() * 10 + pila_destino->getPos());
}
void CSolitario::deshacer()
{
	if( pila_deshacer.empty())
		return;
	int origen = pila_deshacer.top() / 10;
	int destino = pila_deshacer.top() % 10;
	mover_carta(vec[destino], vec[origen]);
	pila_deshacer.pop();
	if (vec[destino]->getTipo() == 3)
		vec[destino]->setNext(vec[destino]->getNext() - 1);
	movimientos--;
}
bool CSolitario::verificar_victoria()
{
	int cont = 0;
	for(int i=7; i<=10; i++)
	{
		if (vec[i]->size() >= 12)
			cont++;
	}
	if (cont >= 4)
		return true;
	return false;
}
int CSolitario::verificar_derrota()
{
	if (barra->getCarga() <= 0.0)
		return 1;
	return 0;
}
CBarra * CSolitario::getBarra()
{
	return barra;
}