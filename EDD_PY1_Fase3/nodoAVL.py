class Nodo_AVL():
    def __init__(self, id_proyecto, nombre_proyecto, prioridad):
        self.id = id_proyecto
        self.proyecto = nombre_proyecto
        self.prioridad = prioridad
        self.izquierdo = None
        self.derecho = None
        self.altura = 1
        self.factor_equilibrio = 0

        