#pragma once
#include "Pila.h"
#include "PilaMazo.h"
#include "PilaEscalera.h"
#include "PilaDestino.h"
#include "VecJugadores.h"
#include "Barra.h"
#include <time.h>
#include <vector>
#include <stack>
#define ESP_V 17
#define MAX_UNDO_REDO 10
using namespace System::Drawing;
class CSolitario
{
private:
	vector<CPila *> vec;
	stack<int> pila_deshacer;
	CBarra * barra;
	int semilla;
	int cartasIniciales;
	int movimientos;
	int tiempo;
	bool barraActivada;
	CPila * get_pila_seleccionada();
	CPila * get_pila_en_click(int posX , int posY);
	void llenar_pilas_destino(int pos_PilaMazo, int posI_PilaDestino, int posF_PilaDestino);
	bool verificar_movimiento(CPila *pila_origen, CPila *pila_destino);
	void mover_carta(CPila *pila_origen,CPila *pila_destino);
	void guardar_movimiento(CPila *pila_origen,CPila *pila_destino);
	int getSeg();
	int getMin();
public:
	CSolitario(void);
	~CSolitario(void);
	int getSemilla();
	int getCartasIniciales();
	int getMovimientos();
	int getTiempo();
	bool getBarraActivada();
	void inicializar(Image ^imgBaraja, int pSemilla, int pCartasIniciales, bool conBarra);
	void dibujar_todos(Graphics ^g, Image ^imgBaraja);
	void aumentarTiempo();
	void interactuar_con_click(int posX, int posY);
	void interactuar_con_click_der(int posX, int posY);
	void deshacer();
	bool verificar_victoria();
	int verificar_derrota();
	CBarra * getBarra();
};
