#include "../Headers/libro.h"

void menuGestorLibros(){

    int seleccion_libros;
    int seguir = 0;
    int exit;
    char idLibro_Modificar[50];
    char idLibro_Borrar[50];
    char idLibro_Consulta[50];


    do{

        do{
            printf("GESTOR DE LIBROS 1.0\n");
            printf("1-Agregar nuevo libro\n2-Borrar Libro\n3-Modificar Libro\n4-Consultar Libros\n5-Listar Libros\n6-Listar Libros Borrados\n7-Listar Libros por Calificacion\n");
            scanf("%d", &seleccion_libros);
            if(seleccion_libros >= 1 && seleccion_libros < 8){
                seguir = 1;
            } else {
                system("cls");
                printf("Opcion invalida\n");
            }

        }while(seguir != 1);
        system("cls");
        seguir = 0;

        switch(seleccion_libros){
        case 1:
            system("cls");
            cargarLibros();
        break;
        case 2:
            printf("Ingrese el nombre del libro que desea borrar: ");
            fflush(stdin);
            fgets(idLibro_Borrar, 50, stdin);
            idLibro_Borrar[strlen (idLibro_Borrar) - 1] = '\0';
            borrarLibro(idLibro_Borrar);
        break;
        case 3:
            printf("Ingrese el nombre del libro que desea modificar: ");
            fflush(stdin);
            fgets(idLibro_Modificar, 50, stdin);
            idLibro_Modificar[strlen (idLibro_Modificar) - 1] = '\0';
            reescribirLibro(idLibro_Modificar);
        break;
        case 4:
            printf("Ingrese el nombre del libro que desea consultar: ");
            fflush(stdin);
            fgets(idLibro_Consulta, 50, stdin);
            idLibro_Consulta[strlen (idLibro_Consulta) - 1] = '\0';
            consultarLibros(idLibro_Consulta);
        break;
        case 5:
           mostrarLibros();
        break;
        case 6:
            mostrarLibrosBorrados();
        break;
        case 7:
            mostrarLibrosPorCalificacion();
        break;
        default:
            printf("Opcion invalida");
        break;
        }

        do{
            system("cls");
            printf("Desea salir al inicio? 1-si 2-no:");
            scanf("%d", &exit);
            if(exit == 1 || exit == 2){
                seguir = 1;
            } else {
                printf("Opcion invalida\n");
            }
        } while(seguir != 1);

    }while(exit != 1);

}
void consultarLibros(char nombre[]){
FILE * libros = fopen(file_libros, "rb+");
    stLibro libroTemp;
    int existe = 0;

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(strcmp(libroTemp.nombre, nombre) == 0){
               existe = 1;
            }
        }

        if(existe == 0){
            printf("El libro '%s' no existe\n", nombre);
        } else {
            if(libroTemp.borrado == 1){
                printf("El libro '%s' existe\n", nombre);
            } else {
                printf("El libro '%s' existe pero esta deshabilitado\n", nombre);
            }
        }

    }
    system("pause");
    fclose(libros);
}
void mostrarLibrosBorrados(){
    stLibro libroTemp;
    FILE * libros = fopen(file_libros, "rb");

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(libroTemp.borrado == 1){
                mostrarLibroAux(libroTemp);
            }
        }
    } else {
        printf("Archivo no encontrado");
    }
    system("pause");
    fclose(libros);
}
void borrarLibro(char nombre[]){

    FILE * libros = fopen(file_libros, "rb+");
    stLibro libroTemp;
    int ubicacion = 0;

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(strcmp(libroTemp.nombre, nombre) != 0){
                ubicacion++;
            } else {
                break;
            }
        }

        libroTemp.borrado = 1;

        fseek(libros, sizeof(stLibro)*(ubicacion), SEEK_SET);
        fwrite(&libroTemp, sizeof(stLibro), 1, libros);

    }
    system("pause");
    fclose(libros);

}
void reescribirLibro(char nombre[]){

    FILE * libros = fopen(file_libros, "rb+");
    stLibro libroTemp;
    int ubicacion = 0;

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(strcmp(libroTemp.nombre, nombre) != 0){
                ubicacion++;
            } else {
                break;
            }
        }
        printf("Ubicacion: %d\n", ubicacion);
        libroTemp = reescribirLibroAux(libroTemp);

        fseek(libros, sizeof(stLibro)*(ubicacion), SEEK_SET);
        fwrite(&libroTemp, sizeof(stLibro), 1, libros);

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
void mostrarLibrosPorCalificacion() {

    int orden,dim;

    stLibro libroTemp;

    stLibro LibrosReseniados[99];
    int i = 0;

    FILE * libros = fopen(file_libros, "rb");

    if(libros != NULL){

        while (fread(&libroTemp,sizeof(stLibro),1,libros) > 0)
        {
            if(libroTemp.borrado!=1){
                LibrosReseniados[i] = libroTemp;
                i++;
            }
        }
    } else {
        printf("Archivo no encontrado");
    }
    fclose(libros);

    printf("Como desea ordenarlos?:1-Menor a Mayor,2-Mayor a Menor\n");
    scanf("%d",&orden);
    BubbleSort(LibrosReseniados,i,orden);

    printf("Hay %d libros\n",i);

    printf("Cuantos desea ver en el ordenamiento?:0-Todos\n");
    scanf("%d",&dim);
    if(dim>i){
        printf("La cantidad ingresada es superior, se mostraran todos");
        mostrarArrayLibros(LibrosReseniados,i);
        system("pause");
    }else{
        if(dim==0){
           mostrarArrayLibros(LibrosReseniados,i);
           system("pause");
        }else{
            mostrarArrayLibros(LibrosReseniados,dim);
            system("pause");
        }
    }

}
void BubbleSort(stLibro LibrosReseniados[],int i,int orden){


stLibro aux;

    for(int j=0; j < i-1; j++){//Repito el proceso hasta que no haga falta
        for(int h=0; h < i-j-1; h++){//Se repite por el tamaño del array-1

            if(orden!=2){//Ordena de menor a mayor
                if(LibrosReseniados[h].calificacion>LibrosReseniados[h+1].calificacion){//Compara sus valores
                    aux=LibrosReseniados[h];//Guardo los datos en una variable auxiliar
                    LibrosReseniados[h]=LibrosReseniados[h+1];//Reemplazo su valor por el otro
                    LibrosReseniados[h+1]=aux;//Reemplazo el valor por la auxiliar
                }
            }else{//Ordena de mayor a menor
                if(LibrosReseniados[h].calificacion<LibrosReseniados[h+1].calificacion){//Compara sus valores
                    aux=LibrosReseniados[h];//Guardo los datos en una variable auxiliar
                    LibrosReseniados[h]=LibrosReseniados[h+1];//Reemplazo su valor por el otro
                    LibrosReseniados[h+1]=aux;//Reemplazo el valor por la auxiliar
                }
            }
        }
    }
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
    system("pause");
    fclose(libros);
}
void mostrarLibroAux(stLibro libro){
    printf("ISNB: %d\n", libro.ISNB);
    printf("Nombre: %s\n", libro.nombre);
    printf("Genero: %s\n", libro.genero);
    printf("Autor: %s\n", libro.autor);
    printf("Cantidad de paginas: %d\n", libro.cantidadDePaginas);
    printf("Precio: %d\n", libro.precio);
    printf("Calificacion: %f\n", libro.calificacion);
    printf("-------------\n");
}
void mostrarArrayLibros(stLibro LibrosReseniados[],int dim){
    for(int i=0; i<dim; i++){
        mostrarLibroAux(LibrosReseniados[i]);
    }
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
    int salir = 1;
    while(salir == 1){
        stLibro libro;

        libro.borrado = 0;

        printf("Ingrese ISNB del libro: ");
        scanf("%d",&libro.ISNB);
        printf("Ingrese nombre del libro: ");
        fflush(stdin);
        fgets(libro.nombre, 30, stdin);
        printf("Ingrese genero del libro: ");
        fgets(libro.genero, 30, stdin);
        printf("Ingrese autor del libro: ");
        fgets(libro.autor, 30, stdin);
        printf("Ingrese la cantidad de paginas: ");
        scanf("%d",&libro.cantidadDePaginas);
        printf("Ingrese su precio: ");
        scanf("%d",&libro.precio);
        printf("Ingrese su calificacion: ");
        scanf("%f",&libro.calificacion);

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
