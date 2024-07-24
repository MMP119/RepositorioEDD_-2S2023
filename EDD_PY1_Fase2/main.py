from tablaHash import TablaHash
from pathlib import Path
from tkinter import Tk, Canvas, Entry, Text, Button, PhotoImage, messagebox
from tkinter import Tk, ttk,Canvas, Entry, Text, Button, PhotoImage, filedialog, messagebox
import json
import csv
import tkinter as tk
from dataTareas import dataTareas
from listaSimple import ListaSimple
from arbolAVL import Arbol_AVL
from arbolB import ArbolB


arbolAVL = Arbol_AVL()
tablaH = TablaHash()
arbolB = ArbolB()
listaSimple = ListaSimple()

#---------------SING IN--------------------------------------------------
class ProjectUpApp:

    def __init__(self, root):
        self.root = root
        self.root.geometry("720x480")
        self.root.configure(bg="#FFFFFF")
        self.root.title("ProjectUp")
        self.initialize_ui()
       

    def initialize_ui(self):
        self.canvas = Canvas(
            self.root,
            bg="#FFFFFF",
            height=480,
            width=720,
            bd=0,
            highlightthickness=0,
            relief="ridge"
        )
        self.canvas.place(x=0, y=0)
        self.load_assets()
        self.create_widgets()

    def load_assets(self):
        self.image_image_1 = PhotoImage(file=self.relative_to_assets("image_1.png"))
        self.image_image_2 = PhotoImage(file=self.relative_to_assets("image_2.png"))
        self.entry_image_1 = PhotoImage(file=self.relative_to_assets("entry_1.png"))
        self.entry_image_2 = PhotoImage(file=self.relative_to_assets("entry_2.png"))
        self.button_image_1 = PhotoImage(file=self.relative_to_assets("button_1.png"))
        self.image_image_3 = PhotoImage(file=self.relative_to_assets("image_3.png"))

    def create_widgets(self):
        self.canvas.create_image(360.0, 240.0, image=self.image_image_1)
        self.canvas.create_image(360.0, 244.0, image=self.image_image_2)
        self.canvas.create_text(
            271.0,
            285.0,
            anchor="nw",
            text="Password:",
            fill="#000000",
            font=("Inter Bold", 24 * -1)
        )
        self.canvas.create_text(
            261.0,
            206.0,
            anchor="nw",
            text="User Name:",
            fill="#000000",
            font=("Inter Bold", 24 * -1)
        )
        self.button_1 = Button(
            image=self.button_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.obtener(),
            relief="flat"
        )
        self.button_1.place(x=266.0, y=371.0, width=189.0, height=50.0)
        self.canvas.create_image(353.5, 250.0, image=self.entry_image_1)
        self.entry_1 = Entry(
            bd=0,
            bg="#D7D7D7",
            fg="#000716",
            highlightthickness=0
        )
        self.entry_1.place(x=205.0, y=234.0, width=297.0, height=30.0)
        self.canvas.create_image(353.5, 327.0, image=self.entry_image_2)
        self.entry_2 = Entry(
            bd=0,
            bg="#D7D7D7",
            fg="#000716",
            highlightthickness=0,
            show="*"
        )
        self.entry_2.place(x=205.0, y=311.0, width=297.0, height=30.0)
        self.canvas.create_image(360.0, 125.0, image=self.image_image_3)

    @staticmethod
    def relative_to_assets(path: str) -> Path:
        OUTPUT_PATH = Path(__file__).parent
        ASSETS_PATH = OUTPUT_PATH / Path("./assets/frame0")
        return ASSETS_PATH / Path(path)


    def obtener(self):
        usuario = self.entry_1.get()
        password = self.entry_2.get()
        if usuario == "PM-202110509" and password == "PM-202110509":
            print("Bienvenido")
            self.root.destroy()
            projec = Tk()
            app = ProjectManagerApp(projec, tablaH,usuario)
            app.nombreProject()
            projec.resizable(False, False)
            projec.mainloop()

        elif tablaH.buscar(usuario, password) and tablaH.buscarProjectManager(usuario, password) == False:
            print('empleado')
            self.root.destroy()
            emp = Tk()
            appEmp = Empleado(emp, usuario)
            appEmp.nombreProject()
            emp.resizable(False, False)
            emp.mainloop()
        
        elif tablaH.buscarProjectManager(usuario, password) and tablaH.buscar(usuario, password):
            print("Bienvenido")
            self.root.destroy()
            projec = Tk()
            app = ProjectManagerApp(projec, tablaH,usuario)
            app.nombreProject()
            projec.resizable(False, False)
            projec.mainloop()
            
        else:
            messagebox.showinfo(message="Usuario o contraseña incorrecta")


#---------------------ADMINISTRADOR------------------------------------------------

cadena = ""
class ProjectManagerApp:
    def __init__(self, root, tablaH, usuario):
        self.root = root
        self.root.geometry("720x360")
        self.root.configure(bg="#FFFFFF")
        self.root.title("Project Manager")
        self.initialize_ui()
        self.tablaH = tablaH
        self.usuario = usuario
        self.cadena = ""


    def initialize_ui(self):
        self.canvas = Canvas(
            self.root,
            bg="#FFFFFF",
            height=360,
            width=720,
            bd=0,
            highlightthickness=0,
            relief="ridge"
        )
        self.canvas.place(x=0, y=0)
        self.load_assets()
        self.create_widgets()

    def load_assets(self):
        self.image_image_1 = PhotoImage(file=self.relative_to_assets("image_1.png"))
        self.image_image_2 = PhotoImage(file=self.relative_to_assets("image_2.png"))
        self.entry_image_1 = PhotoImage(file=self.relative_to_assets("entry_1.png"))
        self.image_image_3 = PhotoImage(file=self.relative_to_assets("image_3.png"))
        self.button_image_1 = PhotoImage(file=self.relative_to_assets("button_1.png"))
        self.button_image_2 = PhotoImage(file=self.relative_to_assets("button_2.png"))
        self.button_image_3 = PhotoImage(file=self.relative_to_assets("button_3.png"))
        self.button_image_4 = PhotoImage(file =self.relative_to_assets("button_4.png"))
        self.button_image_5 = PhotoImage(file =self.relative_to_assets("button_5.png"))

    def create_widgets(self):
        self.canvas.create_image(360.0, 180.0, image=self.image_image_1)
        self.canvas.create_image(652.0, 50.0, image=self.image_image_2)
        self.canvas.create_image(500.5, 50.0, image=self.entry_image_1)
        self.entry_1 = Text(
            bd=0,
            bg="#FFFFFF",
            fg="#000716",
            highlightthickness=0,
        )
        self.entry_1.place(x=423.0, y=35.0, width=155.0, height=28.0)
        self.canvas.create_image(360.0, 240.0, image=self.image_image_3)
        self.button_1 = Button(
            image=self.button_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.abrirArchivoCSV(),
            relief="flat"
        )
        self.button_1.place(x=81.0, y=208.0, width=232.0, height=43.0)
        self.canvas.create_text(
            55.0,
            167.0,
            anchor="nw",
            text="Elija una opcion:",
            fill="#000000",
            font=("Inter", 20 * -1)
        )
        self.button_2 = Button(
            image=self.button_image_2,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.regresar(),
            relief="flat"
        )
        self.button_2.place(x=34.0, y=32.0, width=79.0, height=36.0)
        self.button_3 = Button(
            image=self.button_image_3,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.abrirArchivoJSON(),
            relief="flat"
        )
        self.button_3.place(x=385.0, y=210.0, width=232.0, height=43.0)

        self.button_4 = Button(
            image=self.button_image_4,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.abrir_ventana_principal(),
            relief="flat"
        )
        self.button_4.place(x=81.0, y=269.0, width=232.0, height=43.0)

        self.button_5 = Button(
            image=self.button_image_5,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.abrir_proyectos(),
            relief="flat"
        )
        self.button_5.place(x=385.0, y=269.0, width=232.0, height=43.0)


    @staticmethod
    def relative_to_assets(path: str) -> Path:
        OUTPUT_PATH = Path(__file__).parent
        ASSETS_PATH = OUTPUT_PATH / Path("./assetsM/frame0")
        return ASSETS_PATH / Path(path)


    def nombreProject(self):
        self.entry_1.configure(state='normal')  # Habilitar el widget para edición
        self.entry_1.delete("1.0", 'end')  # Eliminar cualquier texto existente
        self.entry_1.insert("end", self.usuario)  # Insertar el nuevo texto
        self.entry_1.tag_add("center", "1.0", "end")  # Añadir un tag "center" al texto
        self.entry_1.tag_configure("center", justify='center')  # Configurar el tag para centrar el texto
        self.entry_1.configure(state='disabled')  # Deshabilitar el widget

        
    def regresar(self):
        self.root.destroy()
        inicio = Tk()
        app = ProjectUpApp(inicio)
        inicio.resizable(False, False)
        inicio.mainloop()


    def abrirArchivoJSON(self):
        try:
            cadena = ""
            abrirArch = filedialog.askopenfile(title = 'Abrir Archivo', filetypes = [('All Files', '*.*'),('JSON Files', '*.json')])
            with open(abrirArch.name,'r') as file:
                data = json.load(file)
                contador = 0
                    
            def imprimir_proyecto(proyecto, nivel):
                global cadena
                cadena += '|---' * nivel + proyecto['id'] + '-' + proyecto['nombre'] + '-' + proyecto['prioridad'] + '\n'
                if 'tareas' in proyecto and len(proyecto['tareas']) > 0:
                    for tarea in proyecto['tareas']:
                        cadena += '\t|---' * (nivel + 1) + tarea['nombre'] + '-' + tarea['empleado'] + '\n'
                if 'proyectos' in proyecto and len(proyecto['proyectos']) > 0:
                    for subproyecto in proyecto['proyectos']:
                        imprimir_proyecto(subproyecto, nivel + 1)
            
            for proyecto in data['Proyectos']:
                imprimir_proyecto(proyecto, 0)
            
            #print(cadena)
            self.cadena = cadena
            
            for i in range(len(data['Proyectos'])):
                arbolAVL.Insertar(data['Proyectos'][i]['id'],data['Proyectos'][i]['nombre'],data['Proyectos'][i]['prioridad'])

            for i in range(len(data['Proyectos'])):
                idProyecto = data['Proyectos'][i]['id']
                nombreProyecto = data['Proyectos'][i]['nombre']

                if len(data['Proyectos'][i]['tareas']) > 0:

                    for j in range(len(data['Proyectos'][i]['tareas'])):
                        contador += 1 
                        tarea = data['Proyectos'][i]['tareas'][j]['nombre']
                        empleadoTarea = (data["Proyectos"][i]["tareas"][j]["empleado"])
                        idTarea = f"T{contador}-{idProyecto}"

                        arbolB.insertar(dataTareas(idTarea,tarea, empleadoTarea, idProyecto, nombreProyecto))
                    contador = 0
           
            messagebox.showinfo(message="Archivo Cargado Correctamente")
        except:
            messagebox.showinfo(message="Ocurrio un error al abrir el archivo")
    
    def abrirArchivoCSV(self):
        try:
            abrirArch = filedialog.askopenfile(title = 'Abrir Archivo', filetypes = [('All Files', '*.*'),('CSV Files', '*.csv')])
            csv_file = open(abrirArch.name, 'r')
            reader = csv.reader(csv_file, delimiter=',')
            next(reader, None)
            for row in reader:
                id,nombre,password,puesto = row
                self.tablaH.Insertar(id,nombre,password,puesto)
                
            messagebox.showinfo(message="Archivo Cargado Correctamente")
        except:
            messagebox.showinfo(message="Ocurrio un error al abrir el archivo")
    
    #---------VENTANA PROYECTOS, TAREAS------------------
    def abrir_proyectos(self):
        self.root.destroy()
        proyecto = Tk()
        app = ProyectoTareas(proyecto, self.usuario, cadena)
        app.nombreProject()
        proyecto.resizable(False, False)
        proyecto.mainloop()

    #---------VENTANA TABLA HASH------------------
    def abrir_ventana_principal(self):
        ventana_principal = tk.Tk()
        ventana_principal.title("Tabla Hash")
        ventana_principal.geometry("620x320")

        tabla = ttk.Treeview(ventana_principal, columns=("Columna1", "Columna2", "Columna3", "Columna4"))
        tabla.heading("#0", text="Indice")
        tabla.heading("#1", text="Codigo Empleado")
        tabla.heading("#2", text="Nombre")
        tabla.heading("#3", text="Puesto")
        tabla.column("#0",width=70)

        def AgregarTabla():
            tabla.delete(*tabla.get_children())
            for clave, valor in self.tablaH.tabla.items():
                print(f"Clave: {clave}, Valor: {valor.codigo}")
                tabla.insert("", "end", text=clave,values=(valor.codigo, valor.nombre, valor.puesto))

        AgregarTabla()
        tabla.pack(pady=20)
        
        def cerrar_sesion():
            ventana_principal.destroy()

        boton_cerrar_sesion = tk.Button(ventana_principal, text="Regresar", command=cerrar_sesion)
        boton_cerrar_sesion.pack(pady=12)

#-------------------------ADMINISTRADOR 2 (PROYECTOS, TAREAS)----------------------------------
class ProyectoTareas:
    def __init__(self, root, usuario, cadena):
        self.root = root
        self.root.geometry("720x480")
        self.root.configure(bg="#FFFFFF")
        self.usuario = usuario
        self.cadena = cadena

        self.canvas = Canvas(
            self.root,
            bg="#FFFFFF",
            height=480,
            width=720,
            bd=0,
            highlightthickness=0,
            relief="ridge"
        )
        self.canvas.place(x=0, y=0)

        self.assets()
        self.widgets()

    def assets(self):
        self.image_image_1 = PhotoImage(file=self.relative_to_assets("image_1.png"))
        self.image_image_2 = PhotoImage(file=self.relative_to_assets("image_2.png"))
        self.entry_image_1 = PhotoImage(file=self.relative_to_assets("entry_1.png"))
        self.entry_image_2 = PhotoImage(file=self.relative_to_assets("entry_2.png"))
        self.button_image_1 = PhotoImage(file=self.relative_to_assets("button_1.png"))
        self.button_image_2 = PhotoImage(file=self.relative_to_assets("button_2.png"))
        self.button_image_3 = PhotoImage(file=self.relative_to_assets("button_3.png"))

    def widgets(self):
        self.canvas.create_image(360.0, 240.0, image=self.image_image_1)
        self.canvas.create_image(652.0, 50.0, image=self.image_image_2)

        self.canvas.create_image(500.5, 50.0, image=self.entry_image_1)
        self.entry_1 = Text(
            bd=0,
            bg="#FFFFFF",
            fg="#000716",
            highlightthickness=0
        )
        self.entry_1.place(x=423.0, y=35.0, width=155.0, height=28.0)

        self.canvas.create_image(358.5, 311.0, image=self.entry_image_2)
        self.entry_2 = Text(
            bd=0,
            bg="#FFFFFF",
            fg="#000716",
            highlightthickness=0
        )
        self.entry_2.place(x=50.0, y=167.0, width=617.0, height=286.0)
        self.entry_2.configure(state='normal')  # Habilitar el widget para edición
        self.entry_2.delete("1.0", 'end')  # Eliminar cualquier texto existente
        self.entry_2.insert("end", self.cadena)  # Insertar el nuevo texto
        self.entry_2.tag_add("center", "1.0", "end")  # Añadir un tag "center" al texto
        self.entry_2.tag_configure("center", justify='left')  # Configurar el tag para centrar el texto
        self.entry_2.configure(state='disabled') 

        self.button_1 = Button(
            image=self.button_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.graficarAVL(),
            relief="flat"
        )
        self.button_1.place(x=358.0, y=126.0, width=163.0, height=32.0)

        self.canvas.create_text(
            34.0,
            129.0,
            anchor="nw",
            text="Reportes y Tareas",
            fill="#000000",
            font=("Inter", 20 * -1)
        )

        self.button_2 = Button(
            image=self.button_image_2,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.regresa(),
            relief="flat"
        )
        self.button_2.place(x=34.0, y=32.0, width=93.0, height=33.0)

        self.button_3 = Button(
            image=self.button_image_3,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.graficarB(),
            relief="flat"
        )
        self.button_3.place(x=544.0, y=126.0, width=139.0, height=32.0)

        self.root.resizable(False, False)

    def relative_to_assets(self, path: str):
        OUTPUT_PATH = Path(__file__).parent
        ASSETS_PATH = OUTPUT_PATH / Path("./assetsProyectoTareas/frame0")
        return ASSETS_PATH / Path(path)
    
    def regresa(self):
        self.root.destroy()
        manager = Tk()
        app = ProjectManagerApp(manager, tablaH, self.usuario)
        app.nombreProject()
        manager.resizable(False, False)
        manager.mainloop()

    def nombreProject(self):
        self.entry_1.configure(state='normal')  # Habilitar el widget para edición
        self.entry_1.delete("1.0", 'end')  # Eliminar cualquier texto existente
        self.entry_1.insert("end", self.usuario)  # Insertar el nuevo texto
        self.entry_1.tag_add("center", "1.0", "end")  # Añadir un tag "center" al texto
        self.entry_1.tag_configure("center", justify='center')  # Configurar el tag para centrar el texto
        self.entry_1.configure(state='disabled')  # Deshabilitar el widget

    def graficarAVL(self):
        arbolAVL.graficar()
        messagebox.showinfo(message="Reporte Generado Correctamente")

    def graficarB(self):
        arbolB.graficar()
        messagebox.showinfo(message="Reporte Generado Correctamente")
#-------------------------EMPLEADO----------------------------------
codigoProyecto = []
class Empleado:
    def __init__(self, root, usuario):
        self.root = root
        self.usuario = usuario
        self.root.geometry("720x480")
        self.root.configure(bg="#FFFFFF")
        self.initialize_ui()
        #self.agregarTabla()
       
    def initialize_ui(self):
        self.canvas = Canvas(
            self.root,
            bg="#FFFFFF",
            height=480,
            width=720,
            bd=0,
            highlightthickness=0,
            relief="ridge"
        )
        self.canvas.place(x=0, y=0)
        self.load_assets()
        self.create_widgets()
        
    def load_assets(self):
        self.image_image_1 = PhotoImage(file=self.relative_to_assets("image_1.png"))
        self.image_image_2 = PhotoImage(file=self.relative_to_assets("image_2.png"))
        self.image_image_3 = PhotoImage(file=self.relative_to_assets("image_3.png"))
        self.button_image_1 = PhotoImage(file=self.relative_to_assets("button_1.png"))

    def create_widgets(self):
        self.image_1 = self.canvas.create_image(360.0, 240.0, image=self.image_image_1)
        self.image_2 = self.canvas.create_image(652.0, 50.0, image=self.image_image_2)

        self.entry_image_1 = PhotoImage(file=self.relative_to_assets("entry_1.png"))
        self.entry_bg_1 = self.canvas.create_image(500.5, 50.0, image=self.entry_image_1)
        self.entry_1 = Text(bd=0, bg="#FFFFFF", fg="#000716", highlightthickness=0)
        self.entry_1.place(x=423.0, y=35.0, width=155.0, height=28.0)

        self.canvas.create_image(358.0, 292.0, image=self.image_image_3)
        self.canvas.create_text(34.0, 104.0, anchor="nw", text="Tareas", fill="#000000", font=("Inter", 20 * -1))

        self.button_1 = Button(
            image=self.button_image_1,
            borderwidth=0,
            highlightthickness=0,
            command=lambda: self.regresar(),
            relief="flat"
        )
        self.button_1.place(x=34.0, y=32.0, width=70.0, height=33.0)

        self.tabla = ttk.Treeview(self.root, columns=("Columna1", "Columna2", "Columna3"))
        self.tabla.heading("#0", text="Codigo Tarea")
        self.tabla.heading("#1", text="Nombre de Proyecto")
        self.tabla.heading("#2", text="Nombre de Tarea")
        self.tabla.column("#0",width=150)
        self.tabla.column("#1",width=150)
        self.tabla.column("#2",width=280)
        self.tabla.place(x=50.0, y=200.0, width=580.0, height=250.0)

        elementosArbolB = arbolB.recorrer()
        for elemento in elementosArbolB:
            listaSimple.agregar(elemento)
        
        auxiliar = listaSimple.primero

        while auxiliar != None:
            if auxiliar.dato.getCodigoEncargado() == self.usuario:
                if auxiliar.dato.getCodigoProyecto() not in codigoProyecto:
                    codigoProyecto.append(auxiliar.dato.getCodigoProyecto())                
            auxiliar = auxiliar.siguiente

        self.combo = ttk.Combobox(self.root, 
            state="readonly",
            values=["Sin Filtrar"]+codigoProyecto)
        self.combo.bind("<<ComboboxSelected>>", self.agregarTabla)

        self.combo.place(x=50.0, y=150.0, width=100.0, height=33.0)
        self.combo.set("Sin Filtrar")    
        aux1 = listaSimple.primero
        while aux1 != None:
            if aux1.dato.getCodigoEncargado() == self.usuario:
                self.tabla.insert("", "end", text=aux1.dato.getIDTarea(), values=(aux1.dato.getIDProyecto(), aux1.dato.getNombreTarea()))
            aux1 = aux1.siguiente   

        codigoProyecto.clear()
        arbolB.borrarArreglo()

    def agregarTabla(self, event=None):
        self.tabla.delete(*self.tabla.get_children())

    # Obtener la opción seleccionada del ComboBox
        opcionSeleccionada = self.combo.get()
        print(opcionSeleccionada)

        if opcionSeleccionada == "Sin Filtrar":
            aux = listaSimple.primero
            while aux != None:
                if aux.dato.getCodigoEncargado() == self.usuario:
                    self.tabla.insert("", "end", text=aux.dato.getIDTarea(), values=(aux.dato.getIDProyecto(), aux.dato.getNombreTarea()))
                aux = aux.siguiente
        else:
            # Filtra y muestra solo las tareas relacionadas con el proyecto seleccionado
            aux = listaSimple.primero
            while aux != None:
                if aux.dato.getCodigoEncargado() == self.usuario and aux.dato.getCodigoProyecto() == opcionSeleccionada:
                    self.tabla.insert("", "end", text=aux.dato.getIDTarea(), values=(aux.dato.getIDProyecto(), aux.dato.getNombreTarea()))
                aux = aux.siguiente

    @staticmethod
    def relative_to_assets(path: str) -> Path:
        OUTPUT_PATH = Path(__file__).parent
        ASSETS_PATH = OUTPUT_PATH / Path("./assetsEmpleado/frame0")
        return ASSETS_PATH / Path(path)

    def regresar(self):
        listaSimple.limpiar()
        #print(listaSimple)
        self.root.destroy()
        inicio = Tk()
        app = ProjectUpApp(inicio)
        inicio.resizable(False, False)
        inicio.mainloop()

    def nombreProject(self):
        self.entry_1.configure(state='normal')  # Habilitar el widget para edición
        self.entry_1.delete("1.0", 'end')  # Eliminar cualquier texto existente
        self.entry_1.insert("end", self.usuario)  # Insertar el nuevo texto
        self.entry_1.tag_add("center", "1.0", "end")  # Añadir un tag "center" al texto
        self.entry_1.tag_configure("center", justify='center')  # Configurar el tag para centrar el texto
        self.entry_1.configure(state='disabled')  # Deshabilitar el widget


#---------------------------------------------------------------------------------
if __name__ == "__main__":
    root = Tk()
    app = ProjectUpApp(root)
    root.resizable(False, False)
    root.mainloop()