#include <stdio.h>
#define file_lectores "lectores.dat"
#define stLector struct _lector
#define stLibroReseniado struct _libroReseniado

struct _libroReseniado{
    int ISNB;
    char nombre[30];
};

struct _lector {
	int ID;
	char nombre[40];
	int edad;
	char genero[10];
	char ciudad[30];
	int cantLibrosReseniados;
	stLibroReseniado librosReseniados[20];
	int borrado;
};

void menuGestorLectores();

void borrarLector(char nombre[]);

void reescribirLector(char nombre[]);
stLector reescribirLectorAux(stLector _lector);

void consultarLectores(char nombre[]);
void mostrarLectores();
void mostrarLectorAux(stLector lector);
void mostrarLectoresBorrados();

void cargarLectores();
void cargarLectoresAux(FILE *lectores);
