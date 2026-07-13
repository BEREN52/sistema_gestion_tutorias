#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tutorias.h"
#include "docentes.h"

typedef enum { NINGUNO, ESTUDIANTE, DOCENTE, ADMINISTRADOR } Rol;

int main() {
	Estudiante ePrueba;
	Docente dPrueba;
	Tutoria tPrueba;
	tPrueba.estado = ACTIVA;
	
	// Carga los archivos antes de iniciar
	cargarEstudiantes(); 
	cargarDocentes();  
	cargarTutorias();   
	
	// Variables de control de flujo y login
	int opcionPrincipal = 0;
	char usuarioInput[30];
	char claveInput[30];
	int loginExitoso = 0;
	Rol rolActual = NINGUNO;
	
	do {
		system("cls");
		printf("    SISTEMA DE TUTORIAS - BIENVENIDO\n");
		printf("\n");
		printf("1. Iniciar Sesion\n");
		printf("2. Registrarse\n");
		printf("3. Salir del Programa\n");
		printf("\nSeleccione una opcion: ");
		
		int opInicio = 0;
		if (scanf("%d", &opInicio) != 1) {
			while(getchar() != '\n');
			continue;
		}
		
		if (opInicio == 3) {
			// Si el usuario decide salir desde el inicio, guardamos y cerramos
			guardarEstudiantes();
			guardarDocentes();   
			guardarTutorias(); 
			return 0; 
		}
		
		if (opInicio == 2) {
			// Llama a la funcion de registro
			registrarEstudiante();
			// Guardamos inmediatamente para que el .txt se actualice
			guardarEstudiantes();
			printf("\nCuenta creada exitosamente.\n");
			system("pause");
			continue; // Vuelve a mostrar el menu para que inicie sesion
		}
		
		if (opInicio == 1) {
			system("cls");
			printf("\n INICIO DE SESION \n");
			printf("Usuario: ");
			scanf("%29s", usuarioInput);
			printf("Contrasena: ");
			scanf("%29s", claveInput);
			while (getchar() != '\n');
			
			// Verificacion Admin
			if (strcmp(usuarioInput, "admin") == 0 && strcmp(claveInput, "111") == 0) {
				loginExitoso = 1;
				rolActual = ADMINISTRADOR;
				printf("\nAutenticacion Exitosa. Bienvenido, Administrador.\n");
				system("pause");
			} 
			// Verificacion Docente
			else if (strcmp(usuarioInput, "docente") == 0 && strcmp(claveInput, "222") == 0) {
				loginExitoso = 1;
				rolActual = DOCENTE;
				printf("\nAutenticacion Exitosa. Bienvenido al Portal del Docente.\n");
				system("pause");
			} 
			// Verificacion Estudiante DINAMICA
			else {
				int estudianteEncontrado = 0;
				// Escaneamos la base de datos de estudiantes
				for (int i = 0; i < totalEstudiantes; i++) {
					// Comparamos el usuario con la CEDULA y la clave con la CONTRASEÑA
					if (strcmp(listaEstudiantes[i].cedula, usuarioInput) == 0 && 
						strcmp(listaEstudiantes[i].contrasena, claveInput) == 0) {
						
						loginExitoso = 1;
						rolActual = ESTUDIANTE;
						estudianteEncontrado = 1;
						printf("\n Autenticacion Exitosa. Bienvenido, %s.\n", listaEstudiantes[i].nombreCompleto);
						system("pause");
						break;					}
				}
				
				if (estudianteEncontrado == 0) {
					printf("\nUsuario o contraseña incorrectos. Intente de nuevo.\n");
					system("pause");
				}
			}
		}
	} while (loginExitoso == 0);
	
	
	//MENUS SEGUN EL ROL
	
	//ADMINISTRADOR
	if (rolActual == ADMINISTRADOR) {
		int opcionPrincipal = 0;
		do {
			system("cls");
			printf("\n  MENU DE ADMINISTRADOR \n");
			printf("1. Gestionar Estudiantes\n");
			printf("2. Gestionar Docentes\n");
			printf("3. Gestionar Tutorias\n");
			printf("4. Modulo de Reportes y Analitica\n");
			printf("5. Salir del Sistema\n");
			printf("\nSeleccione una opcion: ");
			
			if (scanf("%d", &opcionPrincipal) != 1) {
				printf("Ingrese un numero valido.\n");
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
					printf("1. Asignar Tutoria\n");
					printf("2. Cambiar Estado de Tutoria\n");
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
					case 5: consultarTutoriasPorEstudiante(""); break;
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
				printf("\nCerrando el Sistema de Gestion de Tutorias.\n");
				break;
				
			default:
				printf("\nOpcion no valida en el Menu Principal. Intente de nuevo.\n");
				system("pause");
			}
			
		} while(opcionPrincipal != 5);
		
		//ESTUDIANTE
	} else if (rolActual == ESTUDIANTE) {
		int opcionEstudiante = 0;
		do {
			system("cls");
			printf("\n  MENU DE ESTUDIANTE \n");
			printf("1. Inscribirse en una tutoria\n");
			printf("2. Ver mis tutorias registradas\n");
			printf("3. Salir del Sistema\n");
			printf("\nSeleccione una opcion: ");
			
			if (scanf("%d", &opcionEstudiante) != 1) {
				printf("Ingrese un numero valido.\n");
				while (getchar() != '\n'); 
				system ("pause");
				continue;
			}
			
			switch(opcionEstudiante) {
			case 1: inscribirseEnTutoriaEstudiante(usuarioInput); break;
			case 2: consultarTutoriasPorEstudiante(usuarioInput); break;
			case 3: printf("\nCerrando sesion de Estudante\n"); break;
			default: printf("\nOpcion invalida.\n");
			}
			
			if(opcionEstudiante != 4){
				printf("\n");
				system("pause");
			}
		} while(opcionEstudiante != 3);
	}
	
	//DOCENTE
 else if (rolActual == DOCENTE) {
	int opcionDocente = 0;
	do {
		system("cls");
		printf("\n  PORTAL DEL DOCENTE  \n");
		printf("1. Registrar mi perfil de docente\n");
		printf("2. Ver mis tutorias asignadas\n");
		printf("3. Dictar una tutoria\n");
		printf("4. Salir del Sistema\n");
		printf("\nSeleccione una opcion: ");
		
		if (scanf("%d", &opcionDocente) != 1) {
			while (getchar() != '\n'); 
			continue;
		}
		
		switch(opcionDocente) {
		case 1: registrarDocente(); break;
		case 2: consultarTutoriasPorDocente(); break;
		case 3: dictarTutoriaDocente(); break;
		case 4: printf("\nCerrando sesion del Portal del Docente\n"); break;
		default: printf("\nOpcion invalida.\n");
		}
		
		if(opcionDocente != 4){
			printf("\n");
			system("pause");
		}
	} while(opcionDocente != 4);
}
 
	// Guarda los archivos antes de salir
	guardarDocentes();
	guardarEstudiantes();
	guardarTutorias();
	
return 0;
}
