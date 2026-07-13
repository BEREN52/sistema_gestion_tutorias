#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estudiantes.h"

#define MAX_ESTUDIANTES 100 // Una base de datos temporal
Estudiante listaEstudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;


void registrarEstudiante() {
	system("cls"); //Para que se limpie la consola
	if (totalEstudiantes >= MAX_ESTUDIANTES) {
		printf("\nEl sistema esta lleno. No se pueden registrar mas estudiantes.\n");
		return; 
	}
	
	printf("\n FORMULARIO DE REGISTRO \n");
	
	// 1. VALIDACION ESTRICTA DE CEDULA
	int cedulaValida = 0;
	do {
		printf("Ingrese el numero de cedula: ");
		scanf("%14s", listaEstudiantes[totalEstudiantes].cedula);
		while (getchar() != '\n');
		
		int esNumero = 1;
		for (int i = 0; listaEstudiantes[totalEstudiantes].cedula[i] != '\0'; i++) {
			if (!isdigit(listaEstudiantes[totalEstudiantes].cedula[i])) { //isdigit es para verificar que se ingresen digitos
				esNumero = 0; 
				break;
			}
		}
		
		if (esNumero == 1 && strlen(listaEstudiantes[totalEstudiantes].cedula) == 10) {
			cedulaValida = 1;
		} else {
			printf("La cedula debe tener 10 digitos.\n\n");
		}
	} while (cedulaValida == 0);
	
	
	// 2. NOMBRES Y APELLIDOS
	int nombreValido = 0;
	do {
		printf("Ingrese los nombres y apellidos: ");
		fgets(listaEstudiantes[totalEstudiantes].nombreCompleto, 60, stdin);
		listaEstudiantes[totalEstudiantes].nombreCompleto[strcspn(listaEstudiantes[totalEstudiantes].nombreCompleto, "\n")] = 0;
		
		int esLetra = 1;
		
		if (strlen(listaEstudiantes[totalEstudiantes].nombreCompleto) == 0) { //Evita que se presione "Enter" y quede vacio
			esLetra = 0;
		} else {
			for (int i = 0; listaEstudiantes[totalEstudiantes].nombreCompleto[i] != '\0'; i++) {
				if (!isalpha(listaEstudiantes[totalEstudiantes].nombreCompleto[i]) && !isspace(listaEstudiantes[totalEstudiantes].nombreCompleto[i])) { //isalpha revisa letras, isspace permite que el nombre tenga espacios intermedios
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
	
	// 3. CATALOGO: CARRERA
	int opCarrera = 0;
	do {
		system("cls"); //Para que se limpie la consola
		printf("\n SELECCIONE LA CARRERA \n");
		printf("1. Software\n");
		printf("2. Ciencias de la Computacion\n");
		printf("3. Sistemas de Informacion\n");
		printf("4. Ciencia de Datos e Inteligencia Artificial\n");
		printf("Seleccione una opcion: ");
		
		if (scanf("%d", &opCarrera) != 1) {
			while (getchar() != '\n');
			opCarrera = 0;
		} else {
			while (getchar() != '\n');
		}
		
		switch(opCarrera) {
		case 1: strcpy(listaEstudiantes[totalEstudiantes].carrera, "Ingenieria de Software"); break; //strcpy copia el contenido de una cadena en otra
		case 2: strcpy(listaEstudiantes[totalEstudiantes].carrera, "Ciencias de la Computacion"); break;
		case 3: strcpy(listaEstudiantes[totalEstudiantes].carrera, "Sistemas de Informacion"); break;
		case 4: strcpy(listaEstudiantes[totalEstudiantes].carrera, "Ciencia de Datos e Inteligencia Artificial"); break;
		default: printf("Opcion invalida. Intente de nuevo.\n"); opCarrera = 0;
		}
	} while (opCarrera == 0);
	
	
	// 4. CATALOGO: SEMESTRE
	int opSemestre = 0;
	do {
		system("cls"); //Para que se limpie la consola
		printf("\n SELECCIONE EL SEMESTRE \n");
		printf("1. Primer Semestre\n");
		printf("2. Segundo Semestre\n");
		printf("3. Tercer Semestre\n");
		printf("4. Cuarto Semestre\n");
		printf("5. Quinto Semestre\n");
		printf("6. Sexto Semestre\n");
		printf("7. Septimo Semestre\n");
		printf("8. Octavo Semestre\n");
		printf("Seleccione una opcion: ");
		
		if (scanf("%d", &opSemestre) != 1) {
			while (getchar() != '\n');
			opSemestre = 0;
		} else {
			while (getchar() != '\n');
		}
		
		switch(opSemestre) {
		case 1: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Primer Semestre"); break;
		case 2: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Segundo Semestre"); break;
		case 3: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Tercer Semestre"); break;
		case 4: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Cuarto Semestre"); break;
		case 5: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Quinto Semestre"); break;
		case 6: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Sexto Semestre"); break;
		case 7: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Septimo Semestre"); break;
		case 8: strcpy(listaEstudiantes[totalEstudiantes].nivelSemestre, "Octavo Semestre"); break;
		default: printf("Opcion invalida. Intente de nuevo.\n"); opSemestre = 0;
		}
	} while (opSemestre == 0);
	
	// 5. CORREO
	system("cls"); //Para que se limpie la consola
	printf("\nIngrese el correo electronico: ");
	scanf("%49s", listaEstudiantes[totalEstudiantes].correoElectronico);
	while (getchar() != '\n');
	
	printf("Cree una contrasena para su cuenta: ");
	scanf("%29s", listaEstudiantes[totalEstudiantes].contrasena);
	while (getchar() != '\n');
	
	totalEstudiantes++;
	printf("\nEstudiante registrado exitosamente.\n");
}

void listarEstudiantes() { 
	system("cls"); //Para que se limpie la consola
	printf("\n LISTA DE ESTUDIANTES MATRICULADOS \n");
	if(totalEstudiantes == 0) {
		printf("Aun no hay estudiantes registrados en el sistema.\n");
		return;
	}
	
	for(int i = 0; i < totalEstudiantes; i++) {
		printf("\nEstudiante #%d\n", i + 1);
		printf("Cedula:   %s\n", listaEstudiantes[i].cedula);
		printf("Nombre:   %s\n", listaEstudiantes[i].nombreCompleto);
		printf("Carrera:  %s\n", listaEstudiantes[i].carrera);
		printf("Semestre: %s\n", listaEstudiantes[i].nivelSemestre);
		printf("Correo:   %s\n", listaEstudiantes[i].correoElectronico);
		printf("\n");
	}
}

void guardarEstudiantes() {
	FILE *archivo = fopen("estudiantes.txt", "w");
	
	if (archivo == NULL) {
		printf("No se pudo crear el archivo de estudiantes.\n");
		return;
	}
	
	fprintf(archivo, "%d\n", totalEstudiantes);
	
	for (int i = 0; i < totalEstudiantes; i++) {
		fprintf(archivo, "%s\n", listaEstudiantes[i].cedula);
		fprintf(archivo, "%s\n", listaEstudiantes[i].contrasena);
		fprintf(archivo, "%s\n", listaEstudiantes[i].nombreCompleto);
		fprintf(archivo, "%s\n", listaEstudiantes[i].carrera);
		fprintf(archivo, "%s\n", listaEstudiantes[i].nivelSemestre);
		fprintf(archivo, "%s\n", listaEstudiantes[i].correoElectronico);
	}
	
	fclose(archivo);
}

void cargarEstudiantes() {
	FILE *archivo = fopen("estudiantes.txt", "r");
	
	if (archivo == NULL) {
		return; 
	}
	
	fscanf(archivo, "%d\n", &totalEstudiantes);
	
	for (int i = 0; i < totalEstudiantes; i++) {
		fgets(listaEstudiantes[i].cedula, 15, archivo);
		listaEstudiantes[i].cedula[strcspn(listaEstudiantes[i].cedula, "\n")] = 0;
		
		fgets(listaEstudiantes[i].contrasena, 30, archivo);
		listaEstudiantes[i].contrasena[strcspn(listaEstudiantes[i].contrasena, "\n")] = 0;
		
		fgets(listaEstudiantes[i].nombreCompleto, 60, archivo);
		listaEstudiantes[i].nombreCompleto[strcspn(listaEstudiantes[i].nombreCompleto, "\n")] = 0;
		
		fgets(listaEstudiantes[i].carrera, 50, archivo);
		listaEstudiantes[i].carrera[strcspn(listaEstudiantes[i].carrera, "\n")] = 0;
		
		fgets(listaEstudiantes[i].nivelSemestre, 20, archivo);
		listaEstudiantes[i].nivelSemestre[strcspn(listaEstudiantes[i].nivelSemestre, "\n")] = 0;
		
		fgets(listaEstudiantes[i].correoElectronico, 50, archivo);
		listaEstudiantes[i].correoElectronico[strcspn(listaEstudiantes[i].correoElectronico, "\n")] = 0;
	}
	
	fclose(archivo);
}

int buscarEstudiantePorCedula(const char* cedulaIngresada, Estudiante* estudianteEncontrado) { return 0; }
int validarCedulaUnica(const char* cedulaIngresada) { return 1; }
int validarCorreo(const char* correoIngresado) { return 1; }
