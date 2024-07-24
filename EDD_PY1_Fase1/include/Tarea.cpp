#include "Tarea.h"

Tarea::Tarea(std::string IDproyecto, std::string nombreTarea)
{
    //ctor
    this->IDProyecto = IDproyecto;
    this ->NombreTarea = nombreTarea;
}

Tarea::~Tarea()
{
    //dtor
}
