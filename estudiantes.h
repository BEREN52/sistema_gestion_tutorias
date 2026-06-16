#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

typedef struct {
	char cedula[15];
	char nombreCompleto[60];
	char carrera[50];
	char nivelSemestre[20];
	char correoElectronico[50];
} Estudiante;

void registrarEstudiante();
void listarEstudiantes();
int buscarEstudiantePorCedula(const char* cedulaIngresada, Estudiante* estudianteEncontrado);
int validarCedulaUnica(const char* cedulaIngresada);
int validarCorreo(const char* correoIngresado);

#endif
