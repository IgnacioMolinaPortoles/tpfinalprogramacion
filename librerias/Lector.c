#include "../Headers/lector.h"

void menuGestorLectores(){

    int seleccion_lectores;
    int seguir = 0;
    int exit;


        do{

        do{
            printf("GESTOR DE lectores 1.0\n");
            printf("1-Agregar nuevo Lector\n2-Borrar Lector\n3-Modificar Lector\n4-Consultar Lectores\n5-Listar Lectores\n");
            scanf("%d", &seleccion_lectores);
            if(seleccion_lectores >= 1 && seleccion_lectores < 6){
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

        break;
        case 3:

        break;
        case 4:

        break;
        case 5:

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

        lector.ID = salir+1;
        lector.edad = 10+salir+1;
        lector.librosReseniados = 3+salir+1;
        lector.borrado = 0;

        printf("Ingrese nombre y apellido del lector: ");
        fflush(stdin);
        fgets(lector.nombre, 40, stdin);
        printf("Ingrese genero del lector: ");
        fgets(lector.genero, 10, stdin);
        printf("Ingrese ciudad del lector: ");
        fgets(lector.ciudad, 30, stdin);

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
