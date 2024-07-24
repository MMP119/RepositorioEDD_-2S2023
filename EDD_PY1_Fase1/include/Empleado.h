#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
using namespace std;

class Empleado
{
    public:
        std::string Nombre;
        std::string Password;
        std::string Codigo;
        std::string Puesto;
        Empleado(std::string nombre, std::string password);
        virtual ~Empleado();

    protected:

    private:
};

#endif // EMPLEADO_H

