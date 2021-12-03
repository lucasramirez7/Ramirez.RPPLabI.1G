#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Parser.h"
#include "post.h"
#include "controller.h"




int controller_loadFromText(LinkedList* pArrayListPost){

    int ok = 0;
    FILE* pFile;
    char path[25];

    if (pArrayListPost != NULL){

        system("cls");
        printf("-*-*-*-* Cargar los datos de los posteos  *-*-*-*-*\n");
        printf("Ingrese el nombre del archivo (posts.csv): ");
        scanf("%s", path);

        while(strcmp(path, "posts.csv") != 0){
            printf("**ERROR** Ingrese el nombre del archivo (posts.csv): ");
            scanf("%s", path);
        }

        pFile = fopen(path, "r");

        if (pFile == NULL)
        {
            puts("No se pudo abrir el archivo\n");
        }
        else{
            if(parser_PostFromText(pFile, pArrayListPost)){

                puts("Carga de archivo de texto exitosa\n");
                ok = 1;

            }
        }
    }

    fclose(pFile);

    return ok;
}

int controller_listPost(LinkedList* pArrayListPost){

	int ok = 0;

	sPost* auxPost;
	if (pArrayListPost != NULL)
	{

		puts("                                    *-*-* LISTA DE POSTEOS  *-*-*	        ");
		puts("----------------------------------------------------------------------------------------------");
		printf(" ID          USUARIO         ME GUSTAS    NO ME GUSTAS   FOLLOWERS\n");
		for (int i = 0; i < ll_len(pArrayListPost); i++)
		{
			auxPost = (sPost*) ll_get(pArrayListPost, i);
			showPost(auxPost);
		}
		ok = 1;
	}
	else
	{
		 puts("\nNO HAY NADA EN LA LISTA!!!!");
	}
	return ok;
}

int controller_asignarEstadisticas(LinkedList* pArrayListPost){

	int ok =0;

	pArrayListPost = ll_map(pArrayListPost, asignarLikes);
	pArrayListPost = ll_map(pArrayListPost, asignarDislikes);
	pArrayListPost = ll_map(pArrayListPost, asignarFollowers);

	if(pArrayListPost != NULL){
		controller_listPost(pArrayListPost);
		ok=1;
	}
	return ok;
}


int controller_sortFollowers(LinkedList* pArrayListPost){

	int ok = 0;

	if  (pArrayListPost != NULL){

	    ll_sort(pArrayListPost, compararFollowers,0);
	    controller_listPost(pArrayListPost);
	    ok=1;
	}


	return ok;

}
/*
int controller_filtrarMejoresPosteos(LinkedList* pArrayListPost){

    system("cls");
	int ok =0;


	pArrayListPost = ll_filter(pArrayListPost, filtrarPosteosLikes);

	if(pArrayListPost != NULL)
	{
		controller_listPost(pArrayListPost);
        ok = controller_saveAsText("posteos.csv",pArrayListPost);
        if( ok == 1)
        {
            puts("Archivo creado con exito!!\n");
        }

	}

	return ok;
}

*/
