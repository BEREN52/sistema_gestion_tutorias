# Sistema de Gestión de Tutorías Académicas

Este es un proyecto desarrollado en **C estándar** para la asignatura de Fundamentos de Programación en la **Escuela Politécnica Nacional (EPN)**. El sistema permite gestionar el agendamiento, control y seguimiento de tutorías académicas mediante una interfaz de consola interactiva.

## Características Principales

El sistema cuenta con persistencia de datos y un sistema de control de acceso dinámico dividido en 3 roles:

*   **Administrador:** Gestión total del sistema. Puede registrar usuarios, forzar la creación de ofertas de tutorías y acceder al módulo de reportes estadísticos. (Credenciales por defecto: `admin` / `111`).
*   **Docente:** Puede ofertar disponibilidad de materias filtradas, revisar el listado de alumnos inscritos en sus clases y cambiar el estado de la tutoría a "Dictada" (Inactiva).
*   **Estudiante:** Cuenta con un sistema de auto-registro en la pantalla de inicio. Puede consultar catálogos en tiempo real e inscribirse a tutorías activas con un solo código.

## Tecnologías Utilizadas

*   **Lenguaje:** C 
*   **Entorno de Desarrollo:** Zinjai / MinGW (GCC)
*   **Persistencia:** Archivos planos (`.txt`)
*   **Estructuras:** Arreglos de `structs`, validaciones estrictas de I/O y control de buffers.

## Estructura del Proyecto

El código fuente está modularizado para aplicar las mejores prácticas de ingeniería de software:
*   `main.c`: Menús principales, control de sesión y flujos de ejecución.
*   `estudiantes.c / .h`: Lógica y estructuras del módulo de estudiantes.
*   `docentes.c / .h`: Lógica y estructuras del módulo de profesores.
*   `tutorias.c / .h`: Motor principal de asignaciones, catálogos cruzados y reportes.

*(En el repositorio también se incluyen los **Manuales de Usuario y Técnico** en formato PDF detallando el funcionamiento interno y externo).*

## Cómo ejecutar el proyecto

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/tu-usuario/nombre-del-repo.git](https://github.com/tu-usuario/nombre-del-repo.git)
2. Abre la carpeta del proyecto en Zinjai o cualquier IDE compatible con C.
3. Asegúrate de que todos los archivos .c y .h estén en el mismo directorio.
4. Compila y ejecuta el archivo main.c.

## Autores

*   Carlos Caviedes.
*   Beren Quinga.
