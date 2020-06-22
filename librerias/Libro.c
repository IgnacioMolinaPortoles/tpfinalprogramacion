#include "../Headers/libro.h"

void menuGestorLibros(){

    int seleccion_libros;
    int seguir = 0;
    int exit;
    char idLibro_Modificar[50];


        do{

        do{
            printf("GESTOR DE LIBROS 1.0\n");
            printf("1-Agregar nuevo libro\n2-Borrar Libro\n3-Modificar Libro\n4-Consultar Libros\n5-Listar Libros\n");
            scanf("%d", &seleccion_libros);
            if(seleccion_libros >= 1 && seleccion_libros < 6){
                seguir = 1;
            } else {
                system("cls");
                printf("Opcion invalida\n");
            }

        }while(seguir != 1);

        seguir = 0;

        switch(seleccion_libros){
        case 1:
            system("cls");
            cargarLibros();
        break;
        case 2:

        break;
        case 3:
            printf("Ingrese el nombre o ISBN del libro que desea modificar: ");
            fflush(stdin);
            fgets(idLibro_Modificar, 50, stdin);
            reescribirLibro(idLibro_Modificar);
        break;
        case 4:

        break;
        case 5:
           mostrarLibros();
        break;
        default:
            printf("Opcion invalida");
        break;
        }

        do{
            system("cls");
            printf("Desea volver al menu principal? 1-si 2-no:");
            scanf("%d", &exit);
            if(exit == 1 || exit == 2){
                seguir = 1;
            } else {
                printf("Opcion invalida\n");
            }
        } while(seguir != 1);

    }while(exit != 1);

}

void reescribirLibro(char nombre[]){

    FILE * libros = fopen(file_libros, "rb+");
    stLibro libro, libroTemp;
    long size = 0;

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            printf("%s y %s", libroTemp, nombre);
            if(strcmp(libroTemp.nombre, nombre) == 0){mostrarLibroAux(libroTemp);
                /*libro = reescribirLibroAux(libro);
                size=ftell(libros);

                fseek(libros, size, SEEK_SET);
                fwrite(&libro, sizeof(stLibro), 1, libros);*/
            }
        }


    }
    system("pause");
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
    int result_nombre = scanf("%99[^\n]%*c", libroAux.nombre);

    if (result_nombre == 1)
        strcpy(_libro.nombre,libroAux.nombre);

    printf("Nuevo genero (presione enter para omitir): ");
    fflush(stdin);
    int result_genero = scanf("%99[^\n]%*c", libroAux.genero);

    if (result_genero == 1)
        strcpy(_libro.genero,libroAux.genero);

    printf("Nuevo autor (presione enter para omitir): ");
    fflush(stdin);
    int result_autor = scanf("%99[^\n]%*c", libroAux.autor);

    if (result_autor == 1)
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
    } else {
        printf("Archivo no encontrado");
    }

    fclose(libros);
}
void mostrarLibroAux(stLibro libro){
    printf("ISNB: %s\n", libro.nombre);
    printf("Nombre: %s\n", libro.nombre);
    printf("Genero: %s\n", libro.genero);
    printf("Autor: %s\n", libro.autor);
    printf("Cantidad de paginas: %d\n", libro.cantidadDePaginas);
    printf("Precio: %d\n", libro.precio);
    printf("Calificacion: %d\n", libro.calificacion);
    printf("-------------\n");
}
void cargarLibros(){

    FILE * libros = fopen(file_libros, "rb");

    if(libros == NULL){
        FILE * _libros = fopen(file_libros, "wb");
        cargarLibrosAux(_libros);
        fclose(_libros);
    } else {
        FILE * _libros = fopen(file_libros, "ab");
        cargarLibrosAux(_libros);
        fclose(_libros);
    }

    fclose(libros);

}
void cargarLibrosAux(FILE *libros){
    int salir = 0;
    while(salir != 1){
        stLibro libro;

        libro.ISNB = salir+1;
        libro.cantidadDePaginas = 10+salir+1;
        libro.precio = 100+salir+1;
        libro.calificacion = 0.0;
        libro.borrado = 0;

        printf("Ingrese nombre del libro: ");
        fflush(stdin);
        fgets(libro.nombre, 30, stdin);
        printf("Ingrese genero del libro: ");
        fgets(libro.genero, 30, stdin);
        printf("Ingrese autor del libro: ");
        fgets(libro.autor, 30, stdin);

        libro.nombre[strlen (libro.nombre) - 1] = '\0';
        libro.genero[strlen (libro.genero) - 1] = '\0';
        libro.autor[strlen (libro.autor) - 1] = '\0';

        fwrite(&libro, sizeof(stLibro), 1, libros);
        system("cls");
        printf("libro %s guardado\n", libro.nombre);

        salir++;
        printf("Desea ingresar otro libro (1-Si 2-No)?");
        scanf("%d", &salir);
    }
}

