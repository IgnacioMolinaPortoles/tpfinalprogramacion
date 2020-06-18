#include "libro.h"

void reescribirLibro(char[] nombre){

    FILE * libros = fopen(file_libros, "rb+");
    stLibro libro;
    long size = 0;

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(libroTemp.nombre == "nombreLibro"){
                libro = reescribirLibroAux(libro);
                size=ftell(libros);

                fseek(libros, size, SEEK_SET);
                fwrite(&libro, sizeof(stLibro), 1, libros);
            }
        }

        
    }

    fclose(libros);

}
stLibro reescribirLibroAux(stLibro _libro){

    stLibro libroAux;

    printf("Nuevo ISNB (0 para omitir): ");
    scanf("%d", &libroAux.ISNB);

    if (libroAux.ISNB != 0)
        _libro.ISNB = libroAux.ISNB;

    printf("Nuevo nombre (presione enter para omitir): ");
    fflush(stdin);
    int result = scanf("%99[^\n]%*c", libroAux.nombre);

    if (result == 1)
        strcpy(_libro.nombre,libroAux.nombre);

    printf("Nuevo genero (presione enter para omitir): ");
    fflush(stdin);
    int result = scanf("%99[^\n]%*c", libroAux.genero);

    if (result == 1)
        strcpy(_libro.genero,libroAux.genero);

    printf("Nuevo autor (presione enter para omitir): ");
    fflush(stdin);
    int result = scanf("%99[^\n]%*c", libroAux.autor);

    if (result == 1)
        strcpy(_libro.autor,libroAux.autor);
    
    printf("Nueva Cantidad de paginas (0 para omitir): ");
    scanf("%d", &libroAux.cantidadDePaginas);

    if (libroAux.cantidadDePaginas != 0)
        _libro.cantidadDePaginas = libroAux.cantidadDePaginas;
    
    printf("Nueva precio (0 para omitir): ");
    scanf("%d", &libroAux.precio);

    if (libroAux.precio != 0)
        _libro.precio = libroAux.precio;

    printf("Nueva calificacion (0 para omitir): ");
    scanf("%d", &libroAux.calificacion);

    if (libroAux.calificacion != 0)
        _libro.calificacion = libroAux.calificacion;

    return _libro;
}
void mostrarLibros() {

    stLibro libroTemp;
    FILE * libros = fopen(file_libros, "rb");

    if(libros != NULL){
        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(libroTemp.borrado == 0){
                mostrarLibroAux(libroTemp);
            }
        }
    }

    fclose(libros);
}
void mostrarLibroAux(stLibro libro){
    printf("ISNB: %s\n", libro.nombreYapellido);
    printf("Nombre: %s\n", libro.nombre);
    printf("Genero: %c\n", libro.genero);
    printf("Autor: %s\n", libro.autor);
    printf("Cantidad de paginas: %d\n", libro.cantidadDePaginas);
    printf("Precio: %d\n", libro.precio);
    printf("Calificacion: %d\n", libro.calificacion);
    printf("-------------\n");
}
void cargarLibro(){
    
    FILE * libros = fopen(file_libros, "rb");

    if(libros == NULL){
        FILE * _libros = fopen(file_libros, "wb");
        cargarlibrosAux(libros);
        fclose(_libros);
    } else {
        FILE * _libros = fopen(file_libros, "ab");
        cargarlibrosAux(libros);
        fclose(_libros);
    }

    fclose(libros);

}
void cargarLibrosAux(FILE *libros){
    int salir = 0;
    while(salir != 5){
        stLibro libro;

        char nombre[2];

        sprintf(nombre,"%d",i+1);

        strcat(libro.nombre, "nachoLibro ");
        strcat(libro.nombre, nombre);
        
        strcat(libro.genero, "nachoGenero ");
        strcat(libro.genero, nombre);

        strcat(libro.autor, "nachoAutor");
        strcat(libro.autor, nombre);

        libro.ISNB = i+1;
        libro.cantidadDePaginas = 10+i+1;
        libro.precio = 100+i+1;
        libro.calificacion = 0.0;
        libro.borrado = 0;
        printf("libro %s guardado\n", libro.nombre);
        
        /*
        printf("Ingrese ISNB del libro: ");
        scanf("%s", alumno.ISNB);*/

        fwrite(&libro, sizeof(stLibro), 1, libros);

        strcpy(libro.genero, "");
        strcpy(libro.nombre,"");
        salir++;
        /*printf("Desea ingresar otro libro (1-Si 2-No)?");
        scanf("%d", &salir);*/
    }
}

