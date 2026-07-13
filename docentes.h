#ifndef DOCENTES_H
#define DOCENTES_H

typedef struct {
	char codigoDocente[15];
	char nombreCompleto[60];
	char materiaEncargada[50];
	char horarioDisponible[100];
} Docente;

extern Docente listaDocentes[]; //para compartir las variables o funciones
extern int totalDocentes;
void cargarDocentes();
void guardarDocentes();
void registrarDocente();
void listarDocentes();
int buscarDocentePorCodigo(const char* codigoIngresado, Docente* docenteEncontrado);
int validarCodigoDocenteUnico(const char* codigoIngresado);

#endif
