#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

typedef struct {
	char cedula[15];
	char nombreCompleto[60];
	char contrasena[30];
	char carrera[50];
	char nivelSemestre[20];
	char correoElectronico[50];
} Estudiante;

extern Estudiante listaEstudiantes[]; //para compartir las variables o funciones
extern int totalEstudiantes;
void cargarEstudiantes();
void guardarEstudiantes();
void registrarEstudiante();
void listarEstudiantes();
int buscarEstudiantePorCedula(const char* cedulaIngresada, Estudiante* estudianteEncontrado);
int validarCedulaUnica(const char* cedulaIngresada);
int validarCorreo(const char* correoIngresado);

#endif
