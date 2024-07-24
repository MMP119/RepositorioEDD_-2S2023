#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cerrno>      // Para errno
#include <cstring>     // Para strerror
#include <limits>
#include <Lista.h>
#include <ColaPrioridad.h>
#include <Matriz.h>
#include <ListaDoble.h>
#include <Cola1.h>
using namespace std;

void menu(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void ingreso(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void cargarEmpleados(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void crearProyecto(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void crearTareas(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void asignarTareas(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void graficar(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);
void asignarProyecto(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia);

void ingreso(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    string usuario;
    string contrasena;

    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"Usuario:";
    cin>>usuario;
    cout<<"Password:";
    cin>>contrasena;

    if(usuario=="PM-202110509" && contrasena=="pmPassword123"){
        menu(lista, cola, matrizN,listaDoble,colaCopia);
    }else{
        cout<<"Usuario o contrasena incorrecta"<<endl;
        ingreso(lista, cola, matrizN, listaDoble,colaCopia);
    }
}

void menu(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    int opcion;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"1. Cargar empleados"<<endl;
    cout<<"2. Crear proyecto"<<endl;
    cout<<"3. Asignar proyecto"<<endl;
    cout<<"4. Crear tareas"<<endl;
    cout<<"5. Asignar tareas"<<endl;
    cout<<"6. Generar Reportes" <<endl;
    cout<<"Elija una opcion:";
    cin >> opcion;

    while (opcion<1 || opcion>10)
    {
        cout<<"Opcion no valida"<<endl;
        menu(lista, cola, matrizN, listaDoble,colaCopia);
    }
    switch (opcion)
    {
    case 1:
        cargarEmpleados(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    case 2:
        crearProyecto(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    case 3:
        asignarProyecto(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    case 4:
        crearTareas(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    case 5:
        asignarTareas(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    case 6:
        graficar(lista, cola, matrizN, listaDoble,colaCopia);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}

void cargarEmpleados(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    int opcion;
    string nombre;
    string contra;
    string ruta;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"************* MENU CARGA EMPLEADOS *************"<<endl;
    cout<<"1. Cargar Manual"<<endl;
    cout<<"2. Cargar Masiva"<<endl;
    cout<<"Elija una opcion:";
    cin >> opcion;
    switch (opcion)
    {
        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Nombre:";
            getline(cin, nombre);
            cout<<"Contraseña:";
            getline(cin, contra);
            lista->Insertar(nombre,contra);
            cout <<"Empleado cargado con exito..." <<endl;
            //lista->VerLista();
            break;
        case 2:
            cout<<"Ingrese el nombre del archivo:";
            cin >> ruta;
            lista->LeerArchivo(ruta);
            //lista->VerLista();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
    }
    menu(lista, cola, matrizN,listaDoble,colaCopia);
}

void crearProyecto(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    string nombreProyecto;
    string prioridad;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"************* MENU DE PROYECTO *************"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Nombre del proyecto:";
    getline(cin, nombreProyecto);
    cout<<"Tipo de Prioridad:";
    cin >> prioridad;
    cout<< "Proyecto creado correctamente,";
    cola->Encolar(nombreProyecto,prioridad);
    colaCopia->Encolar(nombreProyecto,prioridad);
    //cola->VerProyectos();
    //cout<<" "<<endl;
    cola->Ordenar();
    colaCopia->Ordenar();
    //cola->VerProyectos();
    menu(lista, cola, matrizN,listaDoble,colaCopia);
}


void asignarProyecto(Lista *lista,ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    string IDempleado;
    string IDproyecto;
    string puesto;
    static int fro = 1;
    static int bac = 1;
    static int qa = 1;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"************* MENU DE ASIGNAR PROYECTO *************"<<endl;
    cout<<"EMPLEADOS DISPONIBLES"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //imprimir empleados con sus ID generados, pedir que empleado se le asigna proyecto
    lista->VerLista();
    cout<<"Ingrese el ID del empleado:";
    getline(cin,IDempleado);
    std::string nombre = lista->BuscarPorCodigo(IDempleado);

    if (nombre == "Lista vacía") {
        std::cout << "La lista está vacía." << std::endl;
    } else if (nombre == "Empleado no encontrado") {
        std::cout << "Empleado con el código:" << IDempleado << " no encontrado." << std::endl;
    }

    // imprimir el listado de los puestos que hay y pedir cual elegir
    cout<<"PUESTOS DISPONIBLES:"<<endl;
    cout<<"1. Developer Frontend"<<endl;
    cout<<"2. Developer Backend"<<endl;
    cout<<"3. Quality Assurance"<<endl;
    cout<<"Seleccione un puesto:";
    getline(cin, puesto);
    if (puesto == "1") {
            puesto = "FDEV-" + std::to_string(fro);
            fro++;
        } else if (puesto == "2") {
            puesto = "BDEV-" + std::to_string(bac);
            bac++;
        } else if (puesto == "3") {
            puesto = "QA-" + std::to_string(qa);
            qa++;
        } else {
            cout << "Opcion no valida" << endl;
        }
    //imprimir todos los proyectos con su ID, pedir que ingrese ID
    cout<<"PROYECTOS DISPONIBLES"<<endl;
    colaCopia->VerProyectos();

    cout<<"Ingrese ID del proyecto:";
    getline(cin, IDproyecto);

    // luego se ingresa a la matriz dispersab
        while(cola->Primero)
    {
        matrizN->insertar_proyecto(cola);
        cola->Descolar();
    }

    matrizN->insertar_empleado(lista);
    matrizN->asignarProyecto(nombre,IDproyecto, puesto);

    cout<<"Proyecto:"<<IDempleado<<", "<<nombre<<", "<<puesto<<", "<<IDproyecto<<endl;
    cout<<"Proyecto asignado correctamente..."<<endl;

    menu(lista, cola, matrizN,listaDoble,colaCopia);
}

void crearTareas(Lista *lista, ColaPrioridad *cola, Matriz *matrizN, ListaDoble *listaDoble,Cola1 *colaCopia){
    string IDproyecto;
    string nombreTarea;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"************* MENU DE TAREAS *************"<<endl;
    cout<<"PROYECTOS DISPONIBLES:"<<endl;
    colaCopia->VerProyectos();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Elije un proyecto:";
    getline(cin, IDproyecto);
    cout<<"Nombre de la Tarea:";
    getline(cin, nombreTarea);

    listaDoble->Insertar(IDproyecto, nombreTarea, "");
    cout<<"TAREA CREADA CON EXITO"<<endl;

    menu(lista, cola, matrizN,listaDoble,colaCopia);
}


void asignarTareas(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){
    string id_proyecto;
    string id_empleado;
    string tarea;
    cout<<"*************    EDD ProjectUp   *************"<<endl;
    cout<<"*************  Bienvenido PM-202110509  *************"<<endl;
    cout<<"************* MENU ASIGNAR TAREAS *************"<<endl;
    // que proyecto va a elegir, imprimir proyectos
    cout<<"PROYECTOS DISPONIBLES:"<<endl;
    colaCopia->VerProyectos();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Elige un proyecto (ingresa ID):";
    getline(cin, id_proyecto);
    // mostrar tareas de ese proyecto, generar funcion que retorne las tareas por codigo de proyecto
    cout<<"TAREAS DEL PROYECTO:"<<endl;
    listaDoble->MostrarTareasPorProyecto(id_proyecto);
    cout<<"Elige una tarea:";
    getline(cin,tarea);

    // mostrar empleados, imprimir códigos de los empleados
    //elegir empleado
    cout<<"lISTA DE EMPLEADOS:"<<endl;
    lista->VerLista();
    cout<<"Ingrese el ID del empleado:";
    getline(cin, id_empleado);

    //Agregamos
    listaDoble->Asignar(id_proyecto,tarea,id_empleado);
    cout<<"TAREA ASIGNADA CON EXITO"<<endl;

    menu(lista, cola, matrizN,listaDoble,colaCopia);
}

void graficar(Lista *lista, ColaPrioridad *cola, Matriz *matrizN,ListaDoble *listaDoble,Cola1 *colaCopia){

    matrizN->Graficar();
    colaCopia->Graficar();
    lista->Graficar();
    listaDoble->Graficar();
    matrizN->generarJSON(colaCopia, listaDoble);
    menu(lista, cola, matrizN,listaDoble,colaCopia);
}



int main(){
    Lista *lista = new Lista();
    ColaPrioridad *cola = new ColaPrioridad();
    Matriz *matrizN = new Matriz();
    ListaDoble *listaDoble = new ListaDoble();
    Cola1 *colaCopia = new Cola1();

    ingreso(lista, cola, matrizN,listaDoble,colaCopia);
    return 0;
}
