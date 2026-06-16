#include <stdio.h>
#include <string.h>
#include "docentes.h"
 
#define MAX_DOCENTES 50 //Una base de datos temporal
Docente listaDocentes[MAX_DOCENTES];
int totalDocentes = 0;

void registrarDocente(){
	if (totalDocentes >= MAX_DOCENTES){
		printf("\nEl sistema está lleno, no se pueden registrar mas docentes\n");
		return;
	}
	
	printf("\n FORMULARIO DE REGISTRO \n");
	
	printf("Ingrese el codigo del docente: \n");
	scanf("%14s", listaDocentes[totalDocentes].codigoDocente);
	while (getchar() != '\n');
	
	//Nombres Completos
	printf("Ingrese los nombres y apellidos: \n");
	fgets(listaDocentes[totalDocentes].nombreCompleto, 60, stdin); //Usamos fgets para poder escribir textos con espacios
	listaDocentes[totalDocentes].nombreCompleto[strcspn(listaDocentes[totalDocentes].nombreCompleto, "\n")] = 0; //Usamos strcspn para que no se guarde el Enter
	
	//Materia encargada
	printf("Ingrese la materia encargada: \n");
	fgets(listaDocentes[totalDocentes].materiaEncargada, 50, stdin);
	listaDocentes[totalDocentes].materiaEncargada[strcspn(listaDocentes[totalDocentes].materiaEncargada, "\n")] = 0;
	
	//Horario disponible
	printf("Ingrese el horario disponible: \n");
	fgets(listaDocentes[totalDocentes].horarioDisponible, 20, stdin); 
	listaDocentes[totalDocentes].horarioDisponible[strcspn(listaDocentes[totalDocentes].horarioDisponible, "\n")] = 0;
	
	
	totalDocentes++;
	printf("Docente registrado en el sistema");
}
	
	void listarDocentes(){ 
		printf("\n LISTA DE DOCENTES REGISTRADOS \n");
		if(totalDocentes == 0){
			printf("Aun no hay docentes registrados en el sistema \n");
			return;
		}
		
		for(int i = 0; i < totalDocentes; i++){
			printf("\Docente #%d\n", i + 1);
			printf("Codigo unico: %s\n", listaDocentes[i].codigoDocente);
			printf("Nombre: %s\n", listaDocentes[i].nombreCompleto);
			printf("Materia encargada: %s\n", listaDocentes[i].materiaEncargada);
			printf("Horario disponible: %s\n", listaDocentes[i].horarioDisponible);
			printf("\n");
		}
	}

int buscarDocentePorCodigo(const char* codigoIngresado, Docente* docenteEncontrado) { return 0; }
int validarCodigoDocenteUnico(const char* codigoIngresado) { return 1; }
