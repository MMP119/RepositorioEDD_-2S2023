import os
from nodoAVL import Nodo_AVL

class Arbol_AVL():
    def __init__(self):
        self.raiz = None
    
    def Insertar(self, id, proyecto, prioridad):
        self.raiz = self.InsertarNodoAVL(id, proyecto, prioridad, self.raiz)
    
    def AlturaAVL(self, raiz):
        condicion = raiz == None
        return 0 if condicion else raiz.altura
    
    def Equilibrio(self, raiz):
        condicion = raiz == None 
        return 0 if condicion else (self.AlturaAVL(raiz.derecho) - self.AlturaAVL(raiz.izquierdo))
    
    def rotacionI(self, raiz):
        raiz_derecho = raiz.derecho
        hijo_izquiedo = raiz_derecho.izquierdo
        raiz_derecho.izquierdo = raiz
        raiz.derecho = hijo_izquiedo
        raiz.altura = 1 + max(self.AlturaAVL(raiz.izquierdo), self.AlturaAVL(raiz.derecho))
        raiz.factor_equilibrio = self.Equilibrio(raiz)
        raiz_derecho.altura = 1 + max(self.AlturaAVL(raiz_derecho.izquierdo), self.AlturaAVL(raiz_derecho.derecho))
        raiz_derecho.factor_equilibrio = self.Equilibrio(raiz_derecho)
        return raiz_derecho
    
    def rotacionD(self, raiz):
        raiz_izquierdo = raiz.izquierdo
        hijo_derecho = raiz_izquierdo.derecho 
        raiz_izquierdo.derecho = raiz
        raiz.izquierdo = hijo_derecho
        raiz.altura = 1 + max(self.AlturaAVL(raiz.izquierdo), self.AlturaAVL(raiz.derecho))
        raiz.factor_equilibrio = self.Equilibrio(raiz)
        raiz.izquierdo.altura = 1 + max(self.AlturaAVL(raiz_izquierdo.izquierdo), self.AlturaAVL(raiz_izquierdo.derecho))
        raiz_izquierdo.factor_equilibrio = self.Equilibrio(raiz_izquierdo)
        return raiz_izquierdo
    

    def InsertarNodoAVL(self,  id, proyecto, prioridad, raiz):
        if raiz is None:
            return Nodo_AVL(id, proyecto, prioridad)
        else:
            if raiz.id == id:
                raiz.id = id
            elif raiz.id > id:
                raiz.izquierdo = self.InsertarNodoAVL(id, proyecto, prioridad, raiz.izquierdo)
            elif  raiz.id < id:
                raiz.derecho = self.InsertarNodoAVL(id, proyecto, prioridad, raiz.derecho)

            raiz.altura = 1 + max(self.AlturaAVL(raiz.izquierdo), self.AlturaAVL(raiz.derecho))
            balanceo = self.Equilibrio(raiz)
            raiz.factor_equilibrio = balanceo
        
        if balanceo > 1 and id > raiz.derecho.id:
            return self.rotacionI(raiz)
        if balanceo < -1 and id < raiz.izquierdo.id:
            return self.rotacionD(raiz)
        if balanceo > 1 and id < raiz.derecho.id:
            raiz.derecho = self.rotacionD(raiz.derecho)
            return self.rotacionI(raiz)
        if balanceo < -1 and id > raiz.izquierdo.id:
            raiz.izquierdo = self.rotacionI(raiz.izquierdo)
            return self.rotacionD(raiz)
        return raiz
    
    def RecorridoInorden(self):
        self.Inorden(self.raiz)

    def Inorden(self, raiz):
        if raiz is not None:
            self.Inorden(raiz.izquierdo)
            print(raiz.id, end='')
            self.Inorden(raiz.derecho)
    
    def RecorridoPreOrden(self, raiz):
        self.PreOrden(self.raiz)

    def PreOrden(self, raiz):
        if raiz is not None:
            print(raiz.id, end='')
            self.PreOrden(raiz.izquierdo)
            self.PreOrden(raiz.derecho)

    def RecorridoPostOrden(self):
        self.PostOrden(self.raiz)
    
    def PostOrden(self, raiz):
        self.PostOrden(raiz.izquierdo)
        self.PostOrden(raiz.derecho)
        print(raiz.id, end='')

    def graficar(self):
        cadena = ''
        archivo = "arbolAVL.png"
        a = open("arbolAVL.dot", "w")
        if self.raiz is not None:
            cadena += "digraph arbol {"
            cadena += "node [shape = record, style=filled, fillcolor=seashell2];"	
            cadena += self.RetornarValoresArbol(self.raiz, 0, 0)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tpng arbolAVL.dot -o " + archivo)
    
    def RetornarValoresArbol(self, raiz, id, nivel):
        cadena = ''
        numero = id + 1
        if raiz is not None:
            # Crear un texto que incluya ID, Nombre, Prioridad y Nivel
            info_nodo = f"ID: {raiz.id}\nNombre: {raiz.proyecto}\nPrioridad: {raiz.prioridad}\nNivel: {nivel}"
            
            cadena += "\""
            cadena += f"{info_nodo}"
            cadena += "\" ;\n"
            if(raiz.izquierdo is not None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> {}".format(info_nodo, self.RetornarValoresArbol(raiz.izquierdo, numero, nivel + 1), info_nodo, self.RetornarValoresArbol(raiz.derecho, numero, nivel + 1))
                cadena += "{" + "rank=same" + "\"{}\" -> \"{}\" [style=invis]; ".format(info_nodo,  info_nodo) + "} \n"
            elif(raiz.izquierdo is not None and raiz.derecho is None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> x{}[style=invis];\n".format(info_nodo, self.RetornarValoresArbol(raiz.izquierdo, numero, nivel + 1), info_nodo, numero)
                cadena += "{" + "rank=same " + "\"{}\" -> x{} [style=invis]; ".format(info_nodo, numero) + "} \n"
            elif(raiz.izquierdo is None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> x{}[style=invis]; \n \"{}\" -> {}".format(info_nodo, numero, info_nodo, self.RetornarValoresArbol(raiz.derecho, numero, nivel + 1))
                cadena += "{" + "rank=same " + "x{} -> \"{}\" [style=invis]; ".format(numero, info_nodo) + "} \n"
        return cadena