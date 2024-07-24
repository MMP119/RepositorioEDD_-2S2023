#ifndef PROYECTO_H
#define PROYECTO_H
#include <string>

using namespace std;

class Proyecto
{
    public:
        std::string Nombre;
        std::string Codigo;
        Proyecto(std::string codigo, std::string nombre);
        virtual ~Proyecto();

    protected:

    private:
};

#endif // PROYECTO_H

