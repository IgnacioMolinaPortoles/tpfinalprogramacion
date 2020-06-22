#include <stdio.h>
#define file_lectores "lectores.dat"
#define stLector struct _lector

struct _lector {
	int ID;
	char nombre[40];
	int edad;
	char genero[10];
	char ciudad[30];
	int librosReseniados;
	int borrado;
};

void menuGestorLectores();

void cargarLectores();
void cargarLectoresAux(FILE *lectores);
