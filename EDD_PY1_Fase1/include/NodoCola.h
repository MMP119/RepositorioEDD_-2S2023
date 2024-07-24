#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Proyecto.h"

class NodoCola
{
    public:
        NodoCola *Siguiente;
        Proyecto *Proyecto_C;
        std::string Prioridad;
        NodoCola(Proyecto *nuevoProyecto, std::string prioridad);
        virtual ~NodoCola();

    protected:

    private:
};

#endif // NODOCOLA_H
