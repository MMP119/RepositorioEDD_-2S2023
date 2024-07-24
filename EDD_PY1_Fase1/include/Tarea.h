#ifndef TAREA_H
#define TAREA_H


class Tarea
{
    public:
        std::string IDProyecto;
        std::string NombreTarea;
        Tarea(std::string codigoProyecto, std::string nombre);
        virtual ~Tarea();

    protected:

    private:
};

#endif // TAREA_H
