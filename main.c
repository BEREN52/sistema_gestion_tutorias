#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tutorias.h"

int main() {
	Estudiante ePrueba;
	Docente dPrueba;
	Tutoria tPrueba;
	tPrueba.estado = ACTIVA;
	
	int opcionPrincipal = 0;
	

	do {
		system("cls");
		printf("\n  SISTEMA DE GESTION DE TUTORIAS  \n");
		printf("1. Gestionar Estudiantes\n");
		printf("2. Gestionar Docentes\n");
		printf("3. Gestionar Tutorias\n");
		printf("4. Modulo de Reportes y Analitica\n");
		printf("5. Salir del Sistema\n");
		printf("\nSeleccione una opcion: ");
		
		if (scanf("%d", &opcionPrincipal) != 1) {
			printf("Por favor, ingrese un numero valido.\n");
			while (getchar() != '\n'); 
			system ("pause");
			continue;
		}
		
		switch(opcionPrincipal) {
			
		case 1: {
			int opEstudiantes = 0;
			do { 
				system("cls");
				printf("\n GESTION DE ESTUDIANTES \n");
				printf("1. Registrar un nuevo estudiante\n");
				printf("2. Listar todos los estudiantes\n");
				printf("3. Volver al Menu Principal\n");
				printf("\nSeleccione una opcion: ");
				
				if (scanf("%d", &opEstudiantes) != 1) {
					while (getchar() != '\n');
					continue;
				}
				
				switch(opEstudiantes) {
				case 1: registrarEstudiante(); break;
				case 2: listarEstudiantes(); break;
				case 3: printf("\nRegresando\n"); break;
				default: printf("\nOpcion invalida.\n");
				}
				
				if(opEstudiantes != 3){
					printf("\n");
					system("pause");
				}
			} while(opEstudiantes != 3);
			break;
		}
		
		case 2: {
			int opDocentes = 0;
			do {
				system ("cls");
				printf("\n GESTION DE DOCENTES \n");
				printf("1. Registrar un nuevo docente\n");
				printf("2. Listar todos los docentes\n");
				printf("3. Volver al Menu Principal\n");
				printf("\nSeleccione una opcion: ");
				
				if (scanf("%d", &opDocentes) != 1) {
					while (getchar() != '\n');
					continue;
				}
				
				switch(opDocentes) {
				case 1: registrarDocente(); break;
				case 2: listarDocentes(); break;
				case 3: printf("\nRegresando\n"); break;
				default: printf("\nOpcion invalida.\n");
				}
				
				if(opDocentes != 3){
				printf("\n");
				system ("pause");
				}

			} while(opDocentes != 3);
			break;
		}
		
		case 3: {
			int opTutorias = 0;
			do {
				system ("cls");
				printf("\n GESTION DE TUTORIAS \n");
				printf("1. Asignar (Agendar) Tutoria\n");
				printf("2. Cancelar Tutoria\n");
				printf("3. Reprogramar Tutoria\n");
				printf("4. Listar Tutorias Activas\n");
				printf("5. Consultar Tutorias por Estudiante\n");
				printf("6. Consultar Tutorias por Docente\n");
				printf("7. Volver al Menu Principal\n");
				printf("\nSeleccione una opcion: ");
				
				if (scanf("%d", &opTutorias) != 1) {
					while (getchar() != '\n');
					continue;
				}
				
				switch(opTutorias) {
				case 1: asignarTutoria(); break;
				case 2: cancelarTutoria(); break;
				case 3: reprogramarTutoria(); break;
				case 4: listarTutoriasActivas(); break;
				case 5: consultarTutoriasPorEstudiante(); break;
				case 6: consultarTutoriasPorDocente(); break;
				case 7: printf("\nRegresando\n"); break;
				default: printf("\nOpcion invalida.\n");
				}
				
				if(opTutorias != 7){
					printf("\n");
					system ("pause");
				}
			} while(opTutorias != 7);
			break;
		}
		
		case 4: {
			int opReportes = 0;
			do {
				system ("cls");
				printf("\n REPORTES Y ESTADISTICAS \n");
				printf("1. Reporte de Tutorias por Docente\n");
				printf("2. Reporte: Estudiantes con mas tutorias\n");
				printf("3. Reporte: Docentes con mas tutorias\n");
				printf("4. Reporte General de Tutorias Activas\n");
				printf("5. Reporte de Canceladas y Reprogramadas\n");
				printf("6. Volver al Menu Principal\n");
				printf("\nSeleccione una opcion: ");
				
				if (scanf("%d", &opReportes) != 1) {
					while (getchar() != '\n');
					continue;
				}
				
				switch(opReportes) {
				case 1: generarReporteTutoriasPorDocente(); break;
				case 2: generarReporteEstudiantesMasTutorias(); break;
				case 3: generarReporteDocentesMasTutorias(); break;
				case 4: generarReporteGeneralActivas(); break;
				case 5: generarReporteCanceladasReprogramadas(); break;
				case 6: printf("\nRegresando\n"); break;
				default: printf("\nOpcion invalida.\n");
				}
				
				if(opReportes != 6){
					printf("\n");
					system ("pause");
					
				}
			} while(opReportes != 6);
			break;
		}
		
		case 5:
			printf("\nSaliendo del sistema de tutorias.\n");
			break;
			
		default:
			printf("\nOpcion no valida en el Menu Principal. Intente de nuevo.\n");
		}
		
	} while(opcionPrincipal != 5);
	
	return 0;
}
