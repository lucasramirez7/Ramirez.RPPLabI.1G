#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "post.h"
#include "LinkedList.h"
#include "Controller.h"


sPost* new_Post(){

	sPost* newPost = (sPost*) malloc(sizeof(sPost));
	if(newPost != NULL)
	{
		newPost->id = 0;
		strcpy(newPost->user, "");
		newPost->likes = 0;
		newPost->dislikes = 0;
        newPost->followers = 0;
	}

	return newPost;
}

sPost* post_newParametros(char* idStr,char* userStr,char* likeStr, char* dislikeStr, char* followersStr){

	sPost* newPost = new_Post();

	if(newPost != NULL)
	{
		if(!(post_setId(newPost, atoi(idStr)) &&
			(post_setUser(newPost,userStr) &&
			(post_setLikes(newPost, atoi(likeStr)) &&
			(post_setDislikes(newPost,atoi(dislikeStr)) &&
            (post_setFollowers(newPost,atoi(followersStr))))))))
		{
			free(newPost);
			newPost = NULL;
		}
	}

	return newPost;
}



void post_delete(sPost* pPost){

	if(pPost != NULL)
	{
		free(pPost);
	}
}

int post_setId(sPost* this,int id){

	int ok =0;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		ok =1;
	}

	return ok;
}

int post_getId(sPost* this,int* id){
	int ok = 0;
	if(this != NULL && id != NULL )
	{
		*id = this->id;
		ok = 1;
	}

	return ok;
}

int post_setUser(sPost* this,char* user){

	int ok =0;
	char auxString[128];

	if(this != NULL && user != NULL && strlen(user) >= 3 && strlen(user) < 128)
	{
		strcpy(auxString, user);
		strlwr(auxString);
		auxString[0]= toupper(auxString[0]);
		strcpy(this->user,auxString);
		ok =1;
	}

	return ok;
}


int post_getUser(sPost* this,char* user){
	int ok = 0;
	if(this != NULL && user != NULL ){
		strcpy(user,this->user);
		ok = 1;
	}

	return ok;
}

int post_setLikes(sPost* this,int like){

	int ok =0;

	if(this != NULL && like  >= 0)
	{
		this->likes = like;
		ok =1;
	}

	return ok;
}

int post_getLikes(sPost* this,int* like ){
	int ok = 0;
	if(this  != NULL && like != NULL )
	{
		*like = this->likes;
		ok = 1;
	}

	return ok;
}
int post_setDislikes(sPost* this,int disLike){

	int ok =0;

	if(this != NULL && disLike >= 0)
	{
		this->dislikes = disLike;
		ok =1;
	}

	return ok;
}

int post_getDislikes(sPost* this,int* disLike){
	int ok = 0;
	if(this != NULL && disLike != NULL )
	{
		*disLike = this->dislikes;
		ok = 1;
	}

	return ok;
}
int post_setFollowers(sPost* this,int followers){

	int ok =0;

	if(this != NULL && followers >= 0)
	{
		this->followers = followers;
		ok =1;
	}

	return ok;
}

int post_getFollowers(sPost* this,int* followers){
	int ok = 0;
	if(this != NULL && followers != NULL )
	{
		*followers = this->followers;
		ok = 1;
	}

	return ok;
}

int menu()
{
    int option;

    puts("     *** ABM PELICULAS ***");
    puts("  1- Cargar Archivo");
    puts("  2- Imprimir lista");
    puts("  3- Asignar Estadisticas");
    puts("  4- filtrar por mejores posteos");
    puts("  5- filtrar por heaters:");
    puts("  6-  ordenar por nivel de cantidad de followers:");
    puts("  7- mostrar más popular:");
    puts("  10- SALIR");
    puts("Ingrese option: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int showPost(sPost* post){

    int ok = 0;
    int id;
    char users[60];
    int likes;
    int dislikes;
    int followers;

    if (post != NULL){
        if (post_getId(post,&id) &&
             post_getUser(post,users) &&
             post_getLikes(post,&likes) &&
             post_getDislikes(post, &dislikes) &&
             post_getFollowers(post,&followers)
           )
        {
            printf ("  %-3d     %-15s       %-5d       %d          %5d\n", id, users, likes, dislikes, followers);
            ok = 1;
        }
    }
    return ok;
}


void* asignarLikes(void* likes){

    int max = 500;
    int min= 3000;
    int like;

    sPost* auxLikes = NULL;


    if(likes != NULL)
    {
        auxLikes = (sPost*)likes;
        like = rand() % (max - min + 1) + min;
        post_setLikes(auxLikes,like);
    }

    return auxLikes;
}

void* asignarDislikes(void* dislikes){

    int max = 300;
    int min= 3500;
    int dislike;

    sPost* auxDislikes = NULL;


    if(dislikes != NULL)
    {
        auxDislikes = (sPost*)dislikes;
        dislike = rand() % (max - min + 1) + min;
        post_setDislikes(auxDislikes,dislike);
    }

    return auxDislikes;
}

void* asignarFollowers(void* followers){

    int max = 10000;
    int min= 20000;
    int follower;

    sPost* auxFollowers = NULL;


    if(followers != NULL)
    {
        auxFollowers = (sPost*)followers;
        follower = rand() % (max - min + 1) + min;
        post_setFollowers(auxFollowers,follower);
    }

    return auxFollowers;
}



int compararFollowers(void* pFollowersA,void* pFollowersB){
    int ok= 0;

    if(((sPost*)pFollowersA)-> followers > ((sPost*)pFollowersB)-> followers)
    {
        ok= 1;
    }
    if(((sPost*)pFollowersA)-> followers < ((sPost*)pFollowersB)-> followers)
    {
        ok = -1;
    }

    return ok;
}

int filtrarPosteosLikes(void* likes){

    int ok=0;

    sPost* auxPost = NULL;

    if(likes != NULL)
    {
        auxPost = (sPost*)likes;
        if( auxPost ->likes >= 5000){
            ok =1;
        }
    }
    return ok;
}


