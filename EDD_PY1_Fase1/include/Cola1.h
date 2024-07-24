#ifndef COLA1_H
#define COLA1_H

#include "NodoCola.h"
#include "Proyecto.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

class Cola1
{
    public:
        NodoCola *Primero;
        int Tamanio;
        void Encolar(std::string Nombre, std::string Tipo_de_Prioridad);
        void Descolar();
        bool VerProyectos();
        void Ordenar();
        void RetornarProyectoActual();
        void Graficar();
        std::string buscarPrioridadPorID(std::string codigoProyecto);
        Cola1();
        virtual ~Cola1();

    protected:

    private:
};

#endif // COLA1_H
