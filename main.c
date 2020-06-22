#include <stdio.h>
#include <stdlib.h>
#include "./Headers/libro.h"
#include <string.h>
#include "./Headers/lector.h"

int main()
{
    char usuario[50];
    int seleccion, exit;
    int seguir = 0;

    printf("--------- Bienvenido ----------\nIngrese su usuario: ");
    scanf("%s", &usuario);
    system("cls");

    do{
        printf("%s, desea ingresar al gestor de 1-Libros o 2-Lectores?:");
        do{
            scanf("%d", &seleccion);
            if(seleccion == 1 || seleccion == 2){
                seguir = 1;
            } else {
                printf("Opcion invalida\n");
                printf("Desea ingresar al gestor de 1-Libros o 2-Lectores?:");
            }
        }while(seguir != 1);

        seguir = 0;

        switch(seleccion){
        case 1:
            system("cls");
            menuGestorLibros();
        break;
        case 2:
<<<<<<< HEAD

=======
            system("cls");
            menuGestorLectores();
>>>>>>> joaquin
        break;
        default:
            printf("Opcion invalida");
        break;
        }

        do{
            printf("Desea cerrar el programa? 1-si 2-no:");
            scanf("%d", &exit);
            if(exit == 1 || exit == 2){
                seguir = 1;
                printf("Cerrando...");
            } else {
                printf("Opcion invalida\n");
            }
        } while(seguir != 1);

    }while(exit != 1);



    return 0;
}
