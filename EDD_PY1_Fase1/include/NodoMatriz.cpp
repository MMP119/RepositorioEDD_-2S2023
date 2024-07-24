#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(Proyecto *proyecto, Empleado *encargado, int posx, int posy)
{
    //ctor
    this->Abajo = 0;
    this->Anterior = 0;
    this->Arriba = 0;
    this->Siguiente = 0;
    this->PosY = posy;
    this->PosX = posx;
    this->Encargado_c = encargado;
    this->Proyecto_c = proyecto;
    this->Tareas = new ListaDoble();
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}
