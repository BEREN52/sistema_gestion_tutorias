#ifndef TUTORIAS_H
#define TUTORIAS_H

#include "estudiantes.h"
#include "docentes.h"

typedef enum {
	ACTIVA,
		CANCELADA,
		REPROGRAMADA
} EstadoTutoria;

typedef struct {
	char codigoTutoria[15];
	char cedulaEstudiante[15];
	char codigoDocente[15];
	char fecha[12];
	char hora[6];
	char tema[100];
	EstadoTutoria estado;
} Tutoria;

void asignarTutoria();
void cancelarTutoria();
void reprogramarTutoria();
void listarTutoriasActivas();
void consultarTutoriasPorEstudiante();
void consultarTutoriasPorDocente();
void generarReporteTutoriasPorDocente();
void generarReporteEstudiantesMasTutorias();
void generarReporteDocentesMasTutorias();
void generarReporteGeneralActivas();
void generarReporteCanceladasReprogramadas();

#endif
