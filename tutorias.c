#include <stdio.h>
#include <string.h>
#include <ctype.h>  
#include "tutorias.h"
#include "docentes.h"
#include "estudiantes.h"

#define MAX_TUTORIAS 100
Tutoria listaTutorias[MAX_TUTORIAS];
int totalTutorias = 0;


void asignarTutoria() {
	system("cls"); //Para que se limpie la consola
	
	// Deben existir docentes antes de agendar
	if (totalDocentes == 0) {
		printf("\n No hay docentes en el sistema. Registre un docente primero.\n");
		return;
	}
	
	// Deben existir estudiantes antes de agendar
	if (totalEstudiantes == 0) {
		printf("\n No hay estudiantes en el sistema. Registre un estudiante primero.\n");
		return;
	}
	
	if (totalTutorias >= MAX_TUTORIAS) {
		printf("\nEl sistema no puede agendar mas tutorias.\n");
		return;
	}
	
	printf("\n AGENDAR NUEVA TUTORIA \n");
	
	// VALIDACION DEL CODIGO DE LA TUTORIA
	int codigoValido = 0;
	do {
		printf("Ingrese un codigo unico para esta tutoria: ");
		scanf("%14s", listaTutorias[totalTutorias].codigoTutoria);
		while (getchar() != '\n');
		
		int codigoDuplicado = 0;
		for (int i = 0; i < totalTutorias; i++) {
			if (strcmp(listaTutorias[i].codigoTutoria, listaTutorias[totalTutorias].codigoTutoria) == 0) {
				codigoDuplicado = 1; // Por si encuentra un codigo ya existente
				break;
			}
		}
		
		if (codigoDuplicado == 1) {
			printf("El codigo '%s' ya esta en uso. Por favor ingrese uno diferente.\n\n", listaTutorias[totalTutorias].codigoTutoria);
		} else {
			codigoValido = 1;
		}
	} while (codigoValido == 0);
	
	strcpy(listaTutorias[totalTutorias].cedulaEstudiante, "SIN_ASIGNAR");
	
	// CREAR LA TUTORIA
	int opTema = 0;
	do {
		system("cls"); 
		printf("\n SELECCIONE LA MATERIA DE LA TUTORIA \n");
		printf("1. Programacion\n");
		printf("2. Calculo\n");
		printf("3. Algebra\n");
		printf("4. Mecanica\n");
		printf("Seleccione una opcion: ");
		
		if (scanf("%d", &opTema) != 1) {
			while (getchar() != '\n');
			opTema = 0;
		} else {
			while (getchar() != '\n');
		}
		
		switch(opTema) {
		case 1: strcpy(listaTutorias[totalTutorias].tema, "Programacion"); break;
		case 2: strcpy(listaTutorias[totalTutorias].tema, "Calculo"); break;
		case 3: strcpy(listaTutorias[totalTutorias].tema, "Algebra"); break;
		case 4: strcpy(listaTutorias[totalTutorias].tema, "Mecanica"); break;
		default: printf("Opcion invalida.\n"); opTema = 0;
		}
	} while (opTema == 0);
	
	// FILTRO DE LOS DOCENTES POR LA MATERIA ELEGIDA
	int opDocente = 0;
	do {
		system("cls"); 
		printf("\n DOCENTES DISPONIBLES PARA: %s \n", listaTutorias[totalTutorias].tema);
		
		int docentesFiltrados[50];
		int contFiltrados = 0;
		
		// Busca solo los que den esta materia
		for (int i = 0; i < totalDocentes; i++) {
			if (strcmp(listaDocentes[i].materiaEncargada, listaTutorias[totalTutorias].tema) == 0) {
				docentesFiltrados[contFiltrados] = i; // Guarda su posicion original
				contFiltrados++;
				printf("%d. %s\n", contFiltrados, listaDocentes[i].nombreCompleto);
			}
		}
		
		if (contFiltrados == 0) {
			printf("\n No hay docentes registrados que den esta materia.\n");
			system("pause");
			return; // Cancela la creacion
		}
		
		printf("\nSeleccione un docente de la lista: ");
		if (scanf("%d", &opDocente) != 1) {
			while (getchar() != '\n'); opDocente = 0;
		} else {
			while (getchar() != '\n');
		}
		
		if (opDocente >= 1 && opDocente <= contFiltrados) {
			int indiceReal = docentesFiltrados[opDocente - 1];
			strcpy(listaTutorias[totalTutorias].codigoDocente, listaDocentes[indiceReal].nombreCompleto);
		} else {
			printf("Opcion invalida.\n");
			opDocente = 0;
			system("pause");
		}
	} while (opDocente == 0);
	
	// CATALOGO: FECHA
	int opFecha = 0;
	do {
		system("cls"); 
		printf("\n SELECCIONE LA FECHA \n");
		printf("1. 24/07/2026\n2. 25/07/2026\n3. 26/07/2026\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opFecha); while (getchar() != '\n');
		
		switch(opFecha) {
		case 1: strcpy(listaTutorias[totalTutorias].fecha, "24/07/2026"); break;
		case 2: strcpy(listaTutorias[totalTutorias].fecha, "25/07/2026"); break;
		case 3: strcpy(listaTutorias[totalTutorias].fecha, "26/07/2026"); break;
		default: opFecha = 0;
		}
	} while (opFecha == 0);
	
	// CATALOGO: HORA
	int opHora = 0;
	do {
		system("cls"); 
		printf("\n SELECCIONE EL HORARIO \n");
		printf("1. 08:00 - 09:00\n2. 10:00 - 11:00\n3. 14:00 - 15:00\n4. 16:00 - 17:00\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opHora); while (getchar() != '\n');
		
		switch(opHora) {
		case 1: strcpy(listaTutorias[totalTutorias].hora, "08:00"); break;
		case 2: strcpy(listaTutorias[totalTutorias].hora, "10:00"); break;
		case 3: strcpy(listaTutorias[totalTutorias].hora, "14:00"); break;
		case 4: strcpy(listaTutorias[totalTutorias].hora, "16:00"); break;
		default: opHora = 0;
		}
	} while (opHora == 0);
	
	listaTutorias[totalTutorias].estado = ACTIVA;
	totalTutorias++;
	printf("\nTutoria creada exitosamente.\n");
}

// INSCRIPCION DEL ESTUDIANTE
void inscribirseEnTutoriaEstudiante(char* cedulaLogueada) {
	system("cls");
	printf("\n INSCRIPCION A TUTORIAS DISPONIBLES \n");
	
	if (totalEstudiantes == 0) {
		printf("\nDebe registrarse como estudiante primero.\n");
		return;
	}
	
	// El catalogo se muestra en columnas
	int disponibles = 0;
	printf("\n%-10s | %-28s | %-20s | %-12s | %-10s\n", "CODIGO", "MATERIA", "DOCENTE", "FECHA", "HORA");
	printf("____________________________________________________________________________________________\n");
	
	for (int i = 0; i < totalTutorias; i++) {
		if (listaTutorias[i].estado == ACTIVA && strcmp(listaTutorias[i].cedulaEstudiante, "SIN_ASIGNAR") == 0) {
			printf("%-10s | %-28.28s | %-20.20s | %-12s | %-10s\n",
				   listaTutorias[i].codigoTutoria, listaTutorias[i].tema,
				   listaTutorias[i].codigoDocente, listaTutorias[i].fecha, listaTutorias[i].hora);
			disponibles++;
		}
	}
	
	if (disponibles == 0) {
		printf("\nNo hay tutorias disponibles para inscripcion en este momento.\n");
		return;
	}
	
	char codigoIngresado[15];
	int tutoriaValida = 0;
	printf("\nIngrese el CODIGO de la tutoria a la que desea inscribirse: ");
	scanf("%14s", codigoIngresado);
	while (getchar() != '\n');
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].codigoTutoria, codigoIngresado) == 0 &&
			listaTutorias[i].estado == ACTIVA &&
			strcmp(listaTutorias[i].cedulaEstudiante, "SIN_ASIGNAR") == 0) {
			
			strcpy(listaTutorias[i].cedulaEstudiante, cedulaLogueada);
			tutoriaValida = 1;
			printf("\nInscripcion exitosa a la tutoria %s.\n", codigoIngresado);
			break;
		}
	}
	
	if (!tutoriaValida) {
		printf("Codigo invalido o la tutoria ya fue tomada.\n");
	}
}

// DICTAR TUTORIA PARA DOCENTE
void dictarTutoriaDocente() {
	system("cls");
	char codigoBusqueda[15];
	int encontrada = 0;
	
	printf("\n DICTAR TUTORIA \n");
	if (totalTutorias == 0) {
		printf("No hay tutorias registradas.\n");
		return;
	}
	
	printf("Ingrese el CODIGO de la tutoria que va a dictar: ");
	scanf("%14s", codigoBusqueda);
	while (getchar() != '\n');
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].codigoTutoria, codigoBusqueda) == 0) {
			encontrada = 1;
			if (listaTutorias[i].estado != ACTIVA) {
				printf("\nEsta tutoria ya se encuentra INACTIVA o FINALIZADA.\n");
			} else {
				listaTutorias[i].estado = INACTIVA; 
				printf("\nTutoria iniciada. Marcada automaticamente como INACTIVA para los estudiantes.\n");
			}
			break;
		}
	}
	
	if (encontrada == 0) {
		printf("\No se encontro ninguna tutoria con ese codigo.\n");
	}
}

void listarTutoriasActivas() {
	system("cls");
	printf("\n CATALOGO GENERAL DE TUTORIAS ACTIVAS \n\n");
	if (totalTutorias == 0) { printf("No hay tutorias.\n"); return; }
	
	int encontradas = 0;
	printf("%-8s | %-28s | %-20s | %-15s | %-10s | %-5s\n", "CODIGO", "MATERIA", "DOCENTE", "C. ESTUDIANTE", "FECHA", "HORA");
	printf("________________________________________________________________________________________________________\n");
	
	for (int i = 0; i < totalTutorias; i++) {
		if (listaTutorias[i].estado == ACTIVA) {
			printf("%-8s | %-28.28s | %-20.20s | %-15.15s | %-10s | %-5s\n",
				   listaTutorias[i].codigoTutoria, listaTutorias[i].tema, listaTutorias[i].codigoDocente,
				   listaTutorias[i].cedulaEstudiante, listaTutorias[i].fecha, listaTutorias[i].hora);
			encontradas++;
		}
	}
	if (encontradas == 0) printf("\nNo hay tutorias ACTIVAS.\n");
}

void consultarTutoriasPorEstudiante(char* cedulaLogueada) {
	system("cls");
	char cedulaBuscada[15];
	int encontradas = 0;
	printf("\n MIS TUTORIAS \n");
	if (totalTutorias == 0) { printf("No hay tutorias.\n"); return; }
	
	if (strlen(cedulaLogueada) == 0) {
		// Si viene un texto vacio "", significa que es el Admin y hay que preguntarle
		printf("Ingrese el numero de cedula a buscar: ");
		scanf("%14s", cedulaBuscada); 
		while (getchar() != '\n');
	} else {
		// Si tiene datos, es porque el estudiante ya inicio sesion. Se copia sola.
		strcpy(cedulaBuscada, cedulaLogueada);
	}
	
	printf("\n%-8s | %-28s | %-20s | %-10s | %-10s\n", "CODIGO", "MATERIA", "DOCENTE", "FECHA", "ESTADO");
	printf("______________________________________________________________________________________\n");
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].cedulaEstudiante, cedulaBuscada) == 0) { 
			printf("%-8s | %-28.28s | %-20.20s | %-10s | %-10s\n",
				   listaTutorias[i].codigoTutoria, listaTutorias[i].tema, listaTutorias[i].codigoDocente,
				   listaTutorias[i].fecha, (listaTutorias[i].estado == ACTIVA) ? "ACTIVA" : "INACTIVA");
			encontradas++;
		}
	}
	if (encontradas == 0) printf("\nNo se encontraron registros.\n");
}

void consultarTutoriasPorDocente() {
	system("cls");
	char nombreBuscado[60];
	int encontradas = 0;
	printf("\n MIS TUTORIAS (DOCENTE) \n");
	if (totalTutorias == 0) { printf("No hay tutorias.\n"); return; }
	
	printf("Ingrese su nombre exacto: ");
	scanf(" %[^\n]", nombreBuscado); while (getchar() != '\n');
	
	printf("\n%-8s | %-28s | %-15s | %-10s | %-10s\n", "CODIGO", "MATERIA", "C. ESTUDIANTE", "FECHA", "ESTADO");
	printf("_____________________________________________________________________________________________\n");
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].codigoDocente, nombreBuscado) == 0) { 
			printf("%-8s | %-28.28s | %-15.15s | %-10s | %-10s\n",
				   listaTutorias[i].codigoTutoria, listaTutorias[i].tema, listaTutorias[i].cedulaEstudiante,
				   listaTutorias[i].fecha, (listaTutorias[i].estado == ACTIVA) ? "ACTIVA" : "INACTIVA");
			encontradas++;
		}
	}
	if (encontradas == 0) printf("\nNo se encontraron registros.\n");
}


void cambiarEstadoTutoria() { 
	system("cls"); //Para que se limpie la consola
	char codigoBusqueda[15];
	int encontrada = 0;
	
	printf("\n CAMBIAR ESTADO DE TUTORIA \n");
	if (totalTutorias == 0) {
		printf("No hay tutorias registradas en el sistema.\n");
		return;
	}
	
	printf("Ingrese el codigo de la tutoria que desea modificar: ");
	scanf("%14s", codigoBusqueda);
	while (getchar() != '\n');
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].codigoTutoria, codigoBusqueda) == 0) {
			encontrada = 1;
			printf("\nTutoria Encontrada - Tema: %s\n", listaTutorias[i].tema);
			printf("Estado actual: %s\n", (listaTutorias[i].estado == ACTIVA) ? "ACTIVA" : "INACTIVA/CANCELADA");
			
			int nuevaOpcion = 0;
			printf("\n¿Que desea hacer?\n");
			printf("1. Marcar como INACTIVA / CANCELADA\n");
			printf("2. Mantener como ACTIVA\n");
			printf("Seleccione: ");
			scanf("%d", &nuevaOpcion);
			while (getchar() != '\n');
			
			if (nuevaOpcion == 1) {
				listaTutorias[i].estado = INACTIVA; 
				printf("\nEl estado de la tutoria ha sido actualizado.\n");
			} else {
				printf("\nNo se realizaron cambios.\n");
			}
			break;
		}
	}
	
	if (encontrada == 0) {
		printf("\nNo se encontro ninguna tutoria con ese codigo.\n");
	}
}

void cancelarTutoria() { 
	cambiarEstadoTutoria(); 
}

void reprogramarTutoria() { 
	system("cls");
	char codigoBusqueda[15];
	int encontrada = 0;
	
	printf("\n REPROGRAMAR TUTORIA \n");
	if (totalTutorias == 0) {
		printf("No hay tutorias registradas en el sistema.\n");
		return;
	}
	
	printf("Ingrese el codigo de la tutoria que desea reprogramar: ");
	scanf("%14s", codigoBusqueda);
	while (getchar() != '\n');
	
	for (int i = 0; i < totalTutorias; i++) {
		if (strcmp(listaTutorias[i].codigoTutoria, codigoBusqueda) == 0) {
			encontrada = 1;
			
			// Validacion para evitar reprogramar tutorias canceladas
			if (listaTutorias[i].estado != ACTIVA) {
				printf("\nEsta tutoria se encuentra INACTIVA/CANCELADA.\n");
				printf("No se puede reprogramar. Cambie su estado a ACTIVA primero.\n");
				break; 
			}
			
			printf("\nTutoria Encontrada - Tema: %s\n", listaTutorias[i].tema);
			printf("Fecha actual: %s | Hora actual: %s\n", listaTutorias[i].fecha, listaTutorias[i].hora);
			
			// Pedir nueva fecha
			int opFecha = 0;
			do {
				printf("\n SELECCIONE LA NUEVA FECHA \n");
				printf("1. 24/07/2026\n");
				printf("2. 25/07/2026\n");
				printf("3. 26/07/2026\n");
				printf("Seleccione una opcion: ");
				
				if (scanf("%d", &opFecha) != 1) {
					while (getchar() != '\n');
					opFecha = 0;
				} else {
					while (getchar() != '\n');
				}
				
				switch(opFecha) {
				case 1: strcpy(listaTutorias[i].fecha, "24/07/2026"); break;
				case 2: strcpy(listaTutorias[i].fecha, "25/07/2026"); break;
				case 3: strcpy(listaTutorias[i].fecha, "26/07/2026"); break;
				default: printf("Opcion invalida. Intente de nuevo.\n"); opFecha = 0;
				}
			} while (opFecha == 0);
			
			// Pedir nuevo horario
			int opHora = 0;
			do {
				printf("\n SELECCIONE EL NUEVO HORARIO \n");
				printf("1. 08:00 - 09:00\n");
				printf("2. 10:00 - 11:00\n");
				printf("3. 14:00 - 15:00\n");
				printf("4. 16:00 - 17:00\n");
				printf("Seleccione una opcion: ");
				
				if (scanf("%d", &opHora) != 1) {
					while (getchar() != '\n');
					opHora = 0;
				} else {
					while (getchar() != '\n');
				}
				
				switch(opHora) {
				case 1: strcpy(listaTutorias[i].hora, "08:00"); break;
				case 2: strcpy(listaTutorias[i].hora, "10:00"); break;
				case 3: strcpy(listaTutorias[i].hora, "14:00"); break;
				case 4: strcpy(listaTutorias[i].hora, "16:00"); break;
				default: printf("Opcion invalida. Intente de nuevo.\n"); opHora = 0;
				}
			} while (opHora == 0);
			
			printf("\nLa tutoria ha sido reprogramada exitosamente.\n");
			break;
		}
	}
	
	if (encontrada == 0) {
		printf("\nNo se encontro ninguna tutoria con el codigo '%s'.\n", codigoBusqueda);
	}
}


//Archivos para el .txt
void guardarTutorias() {
	FILE *archivo = fopen("tutorias.txt", "w"); //w para reescribir los archivos
	
	if (archivo == NULL) {
		printf("No se pudo crear el archivo de tutorias.\n");
		return;
	}
	
	fprintf(archivo, "%d\n", totalTutorias); //guardamos el total actual
	
	for (int i = 0; i < totalTutorias; i++) {
		fprintf(archivo, "%s\n", listaTutorias[i].codigoTutoria);
		fprintf(archivo, "%s\n", listaTutorias[i].cedulaEstudiante);
		fprintf(archivo, "%s\n", listaTutorias[i].codigoDocente);
		fprintf(archivo, "%s\n", listaTutorias[i].fecha);
		fprintf(archivo, "%s\n", listaTutorias[i].hora);
		fprintf(archivo, "%s\n", listaTutorias[i].tema);
		fprintf(archivo, "%d\n", listaTutorias[i].estado);
	}
	
	fclose(archivo);
}

void cargarTutorias() {
	FILE *archivo = fopen("tutorias.txt", "r"); //r para leer
	
	if (archivo == NULL) {
		return; 
	}
	
	fscanf(archivo, "%d\n", &totalTutorias); //leemos los registros guardados
	
	// Reconstruimos el arreglo línea por línea limpiando los "Enter" con strcspn
	for (int i = 0; i < totalTutorias; i++) {
		fgets(listaTutorias[i].codigoTutoria, 15, archivo);
		listaTutorias[i].codigoTutoria[strcspn(listaTutorias[i].codigoTutoria, "\n")] = 0;
		
		fgets(listaTutorias[i].cedulaEstudiante, 15, archivo);
		listaTutorias[i].cedulaEstudiante[strcspn(listaTutorias[i].cedulaEstudiante, "\n")] = 0;
		
		fgets(listaTutorias[i].codigoDocente, 60, archivo);
		listaTutorias[i].codigoDocente[strcspn(listaTutorias[i].codigoDocente, "\n")] = 0;
		
		fgets(listaTutorias[i].fecha, 15, archivo);
		listaTutorias[i].fecha[strcspn(listaTutorias[i].fecha, "\n")] = 0;
		
		fgets(listaTutorias[i].hora, 10, archivo);
		listaTutorias[i].hora[strcspn(listaTutorias[i].hora, "\n")] = 0;
		
		fgets(listaTutorias[i].tema, 100, archivo);
		listaTutorias[i].tema[strcspn(listaTutorias[i].tema, "\n")] = 0;
		
		int estadoTemp; // El estado lo leemos primero como entero y luego lo asignamos al enum
		fscanf(archivo, "%d\n", &estadoTemp);
		listaTutorias[i].estado = estadoTemp;
	}
	
	fclose(archivo);
}


// MODULO DE REPORTES Y ESTADISTICAS
void generarReporteTutoriasPorDocente() {
	system("cls");
	printf("\n REPORTE: TUTORIAS ASIGNADAS POR DOCENTE \n");
	if (totalDocentes == 0 || totalTutorias == 0) {
		printf("No hay datos suficientes en el sistema para este reporte.\n"); 
		return;
	}
	
	printf("\n%-25s | %-15s\n", "DOCENTE", "TOTAL TUTORIAS");
	printf("___________________________________________________\n");
	
	// Recorremos la lista de docentes y contamos cuantas tutorias tiene cada uno
	for (int i = 0; i < totalDocentes; i++) {
		int contador = 0;
		for (int j = 0; j < totalTutorias; j++) {
			if (strcmp(listaDocentes[i].nombreCompleto, listaTutorias[j].codigoDocente) == 0) {
				contador++;
			}
		}
		printf("%-25.25s | %d\n", listaDocentes[i].nombreCompleto, contador);
	}
}

void generarReporteEstudiantesMasTutorias() {
	system("cls");
	printf("\n REPORTE: TOP ESTUDIANTES CON MAS TUTORIAS \n");
	if (totalEstudiantes == 0 || totalTutorias == 0) {
		printf("No hay datos suficientes en el sistema para este reporte.\n"); 
		return;
	}
	
	int maxTutorias = 0;
	int conteoEstudiantes[100] = {0}; // Arreglo temporal para guardar conteos
	
	// Contamos cuantas tutorias tiene cada estudiante
	for (int i = 0; i < totalEstudiantes; i++) {
		for (int j = 0; j < totalTutorias; j++) {
			if (strcmp(listaEstudiantes[i].cedula, listaTutorias[j].cedulaEstudiante) == 0) {
				conteoEstudiantes[i]++;
			}
		}
		// Descubrimos cual es el numero maximo de tutorias actual
		if (conteoEstudiantes[i] > maxTutorias) {
			maxTutorias = conteoEstudiantes[i];
		}
	}
	
	if (maxTutorias == 0) {
		printf("\nNingun estudiante se ha inscrito a las tutorias ofertadas aun.\n");
		return;
	}
	
	printf("\nEstudiantes con el maximo de inscripciones: %d tutoria\n", maxTutorias);
	printf("___________________________________________________________\n");
	for (int i = 0; i < totalEstudiantes; i++) {
		if (conteoEstudiantes[i] == maxTutorias) {
			printf("-> %s (Cedula: %s)\n", listaEstudiantes[i].nombreCompleto, listaEstudiantes[i].cedula);
		}
	}
}

void generarReporteDocentesMasTutorias() {
	system("cls");
	printf("\n REPORTE: DOCENTES CON MAS TUTORIAS OFERTADAS \n");
	if (totalDocentes == 0 || totalTutorias == 0) {
		printf("No hay datos suficientes en el sistema para este reporte.\n"); 
		return;
	}
	
	int maxTutorias = 0;
	int conteoDocentes[50] = {0}; 
	
	for (int i = 0; i < totalDocentes; i++) {
		for (int j = 0; j < totalTutorias; j++) {
			if (strcmp(listaDocentes[i].nombreCompleto, listaTutorias[j].codigoDocente) == 0) {
				conteoDocentes[i]++;
			}
		}
		if (conteoDocentes[i] > maxTutorias) {
			maxTutorias = conteoDocentes[i];
		}
	}
	
	if (maxTutorias == 0) {
		printf("\nNingun docente ha ofertado tutorias aun.\n");
		return;
	}
	
	printf("\nDocentes con mayor carga de tutorias: %d tutorias ofertadas\n", maxTutorias);
	printf("_______________________________________________________________\n");
	for (int i = 0; i < totalDocentes; i++) {
		if (conteoDocentes[i] == maxTutorias) {
			printf(" %s, Materia: %s\n", listaDocentes[i].nombreCompleto, listaDocentes[i].materiaEncargada);
		}
	}
}

void generarReporteGeneralActivas() {
	system("cls");
	printf("\n ESTADISTICAS GENERALES DE TUTORIAS \n");
	if (totalTutorias == 0) {
		printf("No hay tutorias creadas en el sistema.\n"); 
		return;
	}
	
	int activas = 0, inactivas = 0, sinAsignar = 0;
	
	for (int i = 0; i < totalTutorias; i++) {
		if (listaTutorias[i].estado == ACTIVA) {
			activas++;
			// Revisamos si esta Activa pero esperando alumnos
			if (strcmp(listaTutorias[i].cedulaEstudiante, "SIN_ASIGNAR") == 0) {
				sinAsignar++;
			}
		} else {
			inactivas++;
		}
	}
	
	printf("\nTotal de Tutorias Registradas en el Archivo: %d\n", totalTutorias);
	printf("\n");
	printf("Tutorias ACTIVAS:                %d\n", activas);
	printf("   - Con estudiante inscrito:    %d\n", activas - sinAsignar);
	printf("   - Ofertas vacias esperando:   %d\n", sinAsignar);
	printf("\nTutorias INACTIVAS/DICTADAS:   %d\n", inactivas);
}

void generarReporteCanceladasReprogramadas() {
	system("cls");
	printf("\n REPORTE DE TUTORIAS INACTIVAS / DICTADAS \n");
	if (totalTutorias == 0) {
		printf("No hay tutorias registradas en el sistema.\n"); 
		return;
	}
	
	int encontradas = 0;
	printf("\n%-10s | %-25s | %-20s\n", "CODIGO", "DOCENTE", "MATERIA");
	printf("____________________________________________________________\n");
	
	for (int i = 0; i < totalTutorias; i++) {
		if (listaTutorias[i].estado != ACTIVA) {
			printf("%-10s | %-25.25s | %-20.20s\n", 
				   listaTutorias[i].codigoTutoria, 
				   listaTutorias[i].codigoDocente, 
				   listaTutorias[i].tema);
			encontradas++;
		}
	}
	
	if (encontradas == 0) {
		printf("\nNinguna tutoria ha sido dictada o cancelada aun.\n");
	} else {
		printf("\nTotal de tutorias en el historial inactivo: %d\n", encontradas);
	}
}
