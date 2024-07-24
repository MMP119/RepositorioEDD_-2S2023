class dataTareas:
    def __init__(self, idTarea, nombreTarea, codigoEncargado, codigoProyecto, idProyecto):
        self.idTarea = idTarea
        self.nombreTarea = nombreTarea
        self.codigoEncargado = codigoEncargado
        self.codigoProyecto = codigoProyecto
        self.idProyecto = idProyecto

    def getIDTarea(self):
        return self.idTarea
    
    def getNombreTarea(self):
        return self.nombreTarea
    
    def getCodigoEncargado(self):
        return self.codigoEncargado
    
    def getCodigoProyecto(self):
        return self.codigoProyecto
    
    def getIDProyecto(self):
        return self.idProyecto
    
    