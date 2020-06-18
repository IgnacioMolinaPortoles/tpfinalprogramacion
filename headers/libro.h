#include <stdio.h>
#define file_libros "libros.dat"
#define stLibro struct _libro

struct _libro {
    int ISNB;
    char nombre[30];
    char genero;
    char autor[30];
    int cantidadDePaginas;
    int precio;
    float calificacion;
    int borrado;
};

void reescribirLibro(char[] nombre);
stLibro reescribirLibroAux(stLibro _libro);
void mostrarLibros();
void mostrarLibroAux(stLibro libro);
void cargarLibros();
void cargarLibrosAux(FILE *libros);
