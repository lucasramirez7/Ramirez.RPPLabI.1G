#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#define EMPTY 0


int main()
{
    srand(time(NULL));
    char follow = EMPTY;
    int flag = EMPTY;
	LinkedList* postList = ll_newLinkedList();


	if (postList == NULL){
		puts("No se pudo crear el linkedList");
		exit(1);
	}

	do
	{
		switch (menu()){
		case 1:
			 if(!controller_loadFromText(postList)){

                puts("ERROR al cargar archivo texto");
			 }
			break;

        case 2:
            if(!controller_listPost(postList)){

                puts("ERROR al listar");
			 }
            break;

		case 3:
              if(!controller_asignarEstadisticas(postList)){

                puts("ERROR al listar");
			 }
        break;

        case 6:
            if(!controller_sortFollowers(postList)){
                 puts("ERROR");
            }

        break;

		case 10:
		    system("cls");
			puts("GRACIAS POR USAR EL PROGRAMA\n");
			follow = 1;
			break;

		default:
			printf("Opcion invalida!!\n");
		}
		system("pause");
		system("cls");

	}while(follow == EMPTY);

	free(postList);

    return 0;
}
