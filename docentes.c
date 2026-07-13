#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "docentes.h"
 
#define MAX_DOCENTES 50 //Una base de datos temporal
Docente listaDocentes[MAX_DOCENTES];
int totalDocentes = 0;

void registrarDocente(){
	system("cls"); //Para que se limpie la consola
	if (totalDocentes >= MAX_DOCENTES){
		printf("\nEl sistema está lleno, no se pueden registrar mas docentes\n");
		return;
	}
	
	printf("\n FORMULARIO DE REGISTRO \n");
	
	printf("Ingrese el codigo del docente: \n");
	scanf("%14s", listaDocentes[totalDocentes].codigoDocente);
	while (getchar() != '\n');
	
	//Nombres Completos
	int nombreValido = 0;
	do {
		printf("Ingrese los nombres y apellidos: ");
		fgets(listaDocentes[totalDocentes].nombreCompleto, 60, stdin);
		listaDocentes[totalDocentes].nombreCompleto[strcspn(listaDocentes[totalDocentes].nombreCompleto, "\n")] = 0;
		
		int esLetra = 1;
		
		if (strlen(listaDocentes[totalDocentes].nombreCompleto) == 0) { //Evita que se presione "Enter" y quede vacio
			esLetra = 0;
		} else {
			for (int i = 0; listaDocentes[totalDocentes].nombreCompleto[i] != '\0'; i++) {
				if (!isalpha(listaDocentes[totalDocentes].nombreCompleto[i]) && !isspace(listaDocentes[totalDocentes].nombreCompleto[i])) { 
					esLetra = 0; 
					break;
				}
			}
		}
		
		if (esLetra == 1) {
			nombreValido = 1; 
		} else {
			printf("El nombre solo debe contener letras y espacios.\n\n");
		}
	} while (nombreValido == 0);
	
	//Materia encargada
	int opMateria = 0;
	do {
		system("cls"); //Para que se limpie la consola
		printf("\n SELECCIONE LA MATERIA ENCARGADA \n");
		printf("1. Programacion\n");
		printf("2. Calculo\n");
		printf("3. Algebra\n");
		printf("4. Mecanica\n");
		printf("Seleccione una opcion: ");
		
		if (scanf("%d", &opMateria) != 1) {
			while (getchar() != '\n');
			opMateria = 0;
		} else {
			while (getchar() != '\n');
		}
		
		switch(opMateria) {
		case 1: strcpy(listaDocentes[totalDocentes].materiaEncargada, "Programacion"); break;
		case 2: strcpy(listaDocentes[totalDocentes].materiaEncargada, "Calculo"); break;
		case 3: strcpy(listaDocentes[totalDocentes].materiaEncargada, "Algebra"); break;
		case 4: strcpy(listaDocentes[totalDocentes].materiaEncargada, "Mecanica"); break;
		default: printf("Opcion invalida. Intente de nuevo.\n"); opMateria = 0;
		}
	} while (opMateria == 0);
	
	totalDocentes++;
	printf("\nDocente registrado exitosamente.\n");
}
	
	void listarDocentes(){ 
		printf("\n LISTA DE DOCENTES REGISTRADOS \n");
		if(totalDocentes == 0){
			printf("Aun no hay docentes registrados en el sistema \n");
			return;
		}
		
		for(int i = 0; i < totalDocentes; i++){
			printf("\nDocente #%d\n", i + 1);
			printf("Codigo unico: %s\n", listaDocentes[i].codigoDocente);
			printf("Nombre: %s\n", listaDocentes[i].nombreCompleto);
			printf("Materia encargada: %s\n", listaDocentes[i].materiaEncargada);
			printf("\n");
		}
	}
	
void guardarDocentes() {
	FILE *archivo = fopen("docentes.txt", "w");
			
	if (archivo == NULL) {
		printf("No se pudo crear el archivo de docentes.\n");
		return;
	}
			
	fprintf(archivo, "%d\n", totalDocentes);
			
	for (int i = 0; i < totalDocentes; i++) {
		fprintf(archivo, "%s\n", listaDocentes[i].codigoDocente);
		fprintf(archivo, "%s\n", listaDocentes[i].nombreCompleto);
		fprintf(archivo, "%s\n", listaDocentes[i].materiaEncargada);
	}
			
	fclose(archivo);
}
		
void cargarDocentes() {
	FILE *archivo = fopen("docentes.txt", "r");
		
	if (archivo == NULL) {
		return; 
	}
			
	fscanf(archivo, "%d\n", &totalDocentes);
			
	for (int i = 0; i < totalDocentes; i++) {
		fgets(listaDocentes[i].codigoDocente, 15, archivo);
		listaDocentes[i].codigoDocente[strcspn(listaDocentes[i].codigoDocente, "\n")] = 0;
				
		fgets(listaDocentes[i].nombreCompleto, 60, archivo);
		listaDocentes[i].nombreCompleto[strcspn(listaDocentes[i].nombreCompleto, "\n")] = 0;
				
		fgets(listaDocentes[i].materiaEncargada, 50, archivo);
		listaDocentes[i].materiaEncargada[strcspn(listaDocentes[i].materiaEncargada, "\n")] = 0;
				
	}
			
	fclose(archivo);
}

int buscarDocentePorCodigo(const char* codigoIngresado, Docente* docenteEncontrado) { return 0; }
int validarCodigoDocenteUnico(const char* codigoIngresado) { return 1; }
