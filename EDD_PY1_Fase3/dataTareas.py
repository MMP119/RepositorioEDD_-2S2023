class dataTareas:
    def __init__(self, idTarea, nombreTarea, codigoEncargado, codigoProyecto, idProyecto, estado):
        self.idTarea = idTarea
        self.nombreTarea = nombreTarea
        self.codigoEncargado = codigoEncargado
        self.codigoProyecto = codigoProyecto
        self.idProyecto = idProyecto
        self.estado = estado

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

    def getEstado(self):
        return self.estado
    
    def setEstado(self, estado):
        self.estado = estado
    