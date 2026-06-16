#ifndef DOCENTES_H
#define DOCENTES_H

typedef struct {
	char codigoDocente[15];
	char nombreCompleto[60];
	char areaConocimiento[50];
	char horarioDisponible[100];
} Docente;

void registrarDocente();
void listarDocentes();
int buscarDocentePorCodigo(const char* codigoIngresado, Docente* docenteEncontrado);
int validarCodigoDocenteUnico(const char* codigoIngresado);

#endif
