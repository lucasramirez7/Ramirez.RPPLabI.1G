#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Parser.h"
#include "post.h"

int parser_PostFromText(FILE* pFile , LinkedList* pArrayListPost){

	int ok = 0;
	int cant;
	char id[60];
	char users[60];
	char likes[60];
	char dislikes[60];
	char followers[60];
	sPost* auxPost;

	if (pFile != NULL && pArrayListPost != NULL  )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, users, likes, dislikes,followers);
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  id, users, likes, dislikes,followers);
			if (cant < 4){
				break;
			}

			auxPost = post_newParametros(id,users,likes,dislikes,followers);

			if (auxPost != NULL){
				ll_add (pArrayListPost, auxPost);
				ok = 1;
				auxPost = NULL;
			}
		}
		while (!feof(pFile));
	}
	return ok;
}
