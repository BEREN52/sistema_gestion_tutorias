#include <stdio.h>
#include <string.h>
#include "estudiantes.h"

#define MAX_ESTUDIANTES 100 //Una base de datos temporal
Estudiante listaEstudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

void registrarEstudiante(){
	if (totalEstudiantes >= MAX_ESTUDIANTES){
		printf("\nEl sistema está lleno, no se pueden registrar mas estudaintes\n");
			return;
	}
	 
	printf("\n FORMULARIO DE REGISTRO \n");
	
	printf("Ingrese el numero de cedula: \n");
	scanf("%14s", listaEstudiantes[totalEstudiantes].cedula);
	
	while (getchar() != '\n');
	
	//Nombres Completos
	printf("Ingrese los nombres y apellidos: \n");
	fgets(listaEstudiantes[totalEstudiantes].nombreCompleto, 60, stdin); //Usamos fgets para poder escribir textos con espacios
	listaEstudiantes[totalEstudiantes].nombreCompleto[strcspn(listaEstudiantes[totalEstudiantes].nombreCompleto, "\n")] = 0; //Usamos strcspn para que no se guarde el Enter
	
	//Carrera
	printf("Ingrese la carrera: \n");
	fgets(listaEstudiantes[totalEstudiantes].carrera, 50, stdin);
	listaEstudiantes[totalEstudiantes].carrera[strcspn(listaEstudiantes[totalEstudiantes].carrera, "\n")] = 0;
	
	//Semestre
	printf("Ingrese el semestre al que pertenece: \n");
	fgets(listaEstudiantes[totalEstudiantes].nivelSemestre, 20, stdin); 
	listaEstudiantes[totalEstudiantes].nivelSemestre[strcspn(listaEstudiantes[totalEstudiantes].nivelSemestre, "\n")] = 0;
	
	//Correo
	printf("Ingrese el correo electronico: \n");
	scanf("%49s", listaEstudiantes[totalEstudiantes].correoElectronico);
	while (getchar() != '\n');
	
	totalEstudiantes++;
	printf("Estudiante registrado en el sistema");
}
	
void listarEstudiantes(){ 
	printf("\n LISTA DE ESTUDIANTES MATRICULADOS \n");
	if(totalEstudiantes == 0){
		printf("Aun no hay estudiantes registrados en el sistema \n");
		return;
	}
	
	for(int i = 0; i < totalEstudiantes; i++){
		printf("\nEstudiante #%d\n", i + 1);
		printf("Cedula: %s\n", listaEstudiantes[i].cedula);
		printf("Nombre: %s\n", listaEstudiantes[i].nombreCompleto);
		printf("Carrera: %s\n", listaEstudiantes[i].carrera);
		printf("Semestre: %s\n", listaEstudiantes[i].nivelSemestre);
		printf("Correo: %s\n", listaEstudiantes[i].correoElectronico);
		printf("\n");
	}
}

int buscarEstudiantePorCedula(const char* cedulaIngresada, Estudiante* estudianteEncontrado) { return 0; }
int validarCedulaUnica(const char* cedulaIngresada) { return 1; }
int validarCorreo(const char* correoIngresado) { return 1; }
