#include "../Headers/lector.h"

void menuGestorLectores(){

    int seleccion_lectores;
    int seguir = 0;
    int exit;
    char idLector_Modificar[50];
    char idLector_Borrar[50];
    char idLector_Consulta[50];


        do{

        do{
            printf("GESTOR DE LECTORES 1.0\n");
            printf("1-Agregar nuevo Lector\n2-Borrar Lector\n3-Modificar Lector\n4-Consultar Lectores\n5-Listar Lectores\n6-Listar Lectores Borrados\n");
            scanf("%d", &seleccion_lectores);
            if(seleccion_lectores >= 1 && seleccion_lectores < 7){
                seguir = 1;
            } else {
                system("cls");
                printf("Opcion invalida\n");
            }

        }while(seguir != 1);

        seguir = 0;

        switch(seleccion_lectores){
        case 1:
            system("cls");
            cargarLectores();
        break;
        case 2:
            printf("Ingrese el nombre del lector que desea borrar: ");
            fflush(stdin);
            fgets(idLector_Borrar, 50, stdin);
            idLector_Borrar[strlen (idLector_Borrar) - 1] = '\0';
            borrarLector(idLector_Borrar);

        break;
        case 3:
            printf("Ingrese el nombre del lector que desea modificar: ");
            fflush(stdin);
            fgets(idLector_Modificar, 50, stdin);
            idLector_Modificar[strlen (idLector_Modificar) - 1] = '\0';
            reescribirLector(idLector_Modificar);

        break;
        case 4:
            printf("Ingrese el nombre del lector que desea consultar: ");
            fflush(stdin);
            fgets(idLector_Consulta, 50, stdin);
            idLector_Consulta[strlen (idLector_Consulta) - 1] = '\0';
            consultarLectores(idLector_Consulta);

        break;
        case 5:
            mostrarLectores();
        break;
        case 6:
            mostrarLectoresBorrados();
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
void consultarLectores(char nombre[]){
FILE * lectores = fopen(file_lectores, "rb+");
    stLector lectorTemp;
    int existe = 0;

    if(lectores != NULL){

        while (fread(&lectorTemp,sizeof(stLector),1,lectores) > 0)
        {
            if(strcmp(lectorTemp.nombre, nombre) == 0){
               existe = 1;
            }
        }

        if(existe == 0){
            printf("El lector '%s' no existe\n", nombre);
        } else {
            if(lectorTemp.borrado == 1){
                printf("El lector '%s' existe\n", nombre);
            } else {
                printf("El lector '%s' existe pero esta deshabilitado\n", nombre);
            }
        }

    }
    system("pause");
    fclose(lectores);
}
void mostrarLectoresBorrados(){
    stLector lectorTemp;
    FILE * lectores = fopen(file_lectores, "rb");

    if(lectores != NULL){

        while (fread(&lectorTemp,sizeof(stLector),1,lectores) > 0)
        {
            if(lectorTemp.borrado == 1){
                mostrarLectorAux(lectorTemp);
            }
        }
    } else {
        printf("Archivo no encontrado");
    }
    system("pause");
    fclose(lectores);
}
void borrarLector(char nombre[]){

    FILE * lectores = fopen(file_lectores, "rb+");
    stLector lectorTemp;
    int ubicacion = 0;

    if(lectores != NULL){

        while (fread(&lectorTemp,sizeof(stLector),1,lectores) > 0)
        {
            if(strcmp(lectorTemp.nombre, nombre) != 0){
                ubicacion++;
            } else {
                break;
            }
        }

        lectorTemp.borrado = 1;

        fseek(lectores, sizeof(stLector)*(ubicacion), SEEK_SET);
        fwrite(&lectorTemp, sizeof(stLector), 1, lectores);

    }
    system("pause");
    fclose(lectores);

}
void reescribirLector(char nombre[]){

    FILE * lectores = fopen(file_lectores, "rb+");
    stLector lectorTemp;
    int ubicacion = 0;

    if(lectores != NULL){

        while (fread(&lectorTemp,sizeof(stLector),1,lectores) > 0)
        {
            if(strcmp(lectorTemp.nombre, nombre) != 0){
                ubicacion++;
            } else {
                break;
            }
        }
        printf("Ubicacion: %d\n", ubicacion);
        lectorTemp = reescribirLectorAux(lectorTemp);

        fseek(lectores, sizeof(stLector)*(ubicacion), SEEK_SET);
        fwrite(&lectorTemp, sizeof(stLector), 1, lectores);

    }
    system("pause");
    fclose(lectores);

}
stLector reescribirLectorAux(stLector _lector){

    stLector lectorAux;

    printf("Nuevo ID (0 para omitir): ");
    scanf("%d", &lectorAux.ID);

    if (lectorAux.ID != 0)
        _lector.ID = lectorAux.ID;

    printf("Nuevo nombre (presione enter para omitir): ");
    fflush(stdin);
    int result_nombre = scanf("%99[^\n]%*c", lectorAux.nombre);

    if (result_nombre == 1)
        strcpy(_lector.nombre,lectorAux.nombre);

    printf("Nueva edad (0 para omitir): ");
    scanf("%d", &lectorAux.edad);

    if (lectorAux.edad != 0)
        _lector.edad = lectorAux.edad;

    printf("Nuevo genero (presione enter para omitir): ");
    fflush(stdin);
    int result_genero = scanf("%99[^\n]%*c", lectorAux.genero);

    if (result_genero == 1)
        strcpy(_lector.genero,lectorAux.genero);

    printf("Nueva ciudad (presione enter para omitir): ");
    fflush(stdin);
    int result_ciudad = scanf("%99[^\n]%*c", lectorAux.ciudad);

    if (result_ciudad == 1)
        strcpy(_lector.ciudad,lectorAux.ciudad);

    printf("Nueva cantidad de librosReseniados (0 para omitir): ");
    scanf("%d", &lectorAux.librosReseniados);

    if (lectorAux.librosReseniados != 0)
        _lector.librosReseniados = lectorAux.librosReseniados;

    return _lector;
}
void mostrarLectores(){

    stLector lectorTemp;
    FILE * lectores = fopen(file_lectores, "rb");

    if(lectores != NULL){

        while (fread(&lectorTemp,sizeof(stLector),1,lectores) > 0)
        {
            if(lectorTemp.borrado != 1){
                mostrarLectorAux(lectorTemp);
            }
        }
    } else {
        printf("Archivo no encontrado");
    }
    system("pause");
    fclose(lectores);
}
void mostrarLectorAux(stLector lector){
    printf("ID: %d\n", lector.ID);
    printf("Nombre y Apellido: %s\n", lector.nombre);
    printf("Edad: %d\n", lector.edad);
    printf("Genero: %s\n", lector.genero);
    printf("Ciudad: %s\n", lector.ciudad);
    printf("Libros Reseniados: %d\n", lector.librosReseniados);
    printf("-------------\n");
}
void cargarLectores(){

    FILE * lectores = fopen(file_lectores, "rb");

    if(lectores == NULL){
        FILE * _lectores = fopen(file_lectores, "wb");
        cargarLectoresAux(_lectores);
        fclose(_lectores);
    } else {
        FILE * _lectores = fopen(file_lectores, "ab");
        cargarLectoresAux(_lectores);
        fclose(_lectores);
    }

    fclose(lectores);

}
void cargarLectoresAux(FILE *lectores){
    int salir = 1;
    while(salir == 1){
        stLector lector;

        lector.borrado = 0;

        printf("Ingrese ID del lector: ");
        scanf("%d",&lector.ID);
        printf("Ingrese nombre y apellido del lector: ");
        fflush(stdin);
        fgets(lector.nombre, 40, stdin);
        printf("Ingrese edad del lector: ");
        scanf("%d",&lector.edad);
        printf("Ingrese genero del lector: ");
        fgets(lector.genero, 10, stdin);
        printf("Ingrese ciudad del lector: ");
        fgets(lector.ciudad, 30, stdin);
        printf("Ingrese cantidad de libros reseniados por el lector: ");
        scanf("%d",&lector.librosReseniados);

        lector.nombre[strlen (lector.nombre) - 1] = '\0';
        lector.genero[strlen (lector.genero) - 1] = '\0';
        lector.ciudad[strlen (lector.ciudad) - 1] = '\0';

        fwrite(&lector, sizeof(stLector), 1, lectores);
        system("cls");
        printf("lector %s guardado\n", lector.nombre);

        salir++;
        printf("Desea ingresar otro lector (1-Si 2-No)?");
        scanf("%d", &salir);
    }
}
