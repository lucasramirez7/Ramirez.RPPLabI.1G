#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

typedef struct{
	int id;
	char user[128];
	int likes;
	int dislikes;
	int followers;
}sPost;

sPost* new_Post();
sPost* post_newParametros(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr);
void post_delete(sPost* pPost);
int post_setId(sPost* this,int id);
int post_getId(sPost* this,int* id);
int post_setUser(sPost* this,char* user);
int post_getUser(sPost* this,char* user);
int post_setLikes(sPost* this,int likes);
int post_getLikes(sPost* this,int* likes);
int post_setDislikes(sPost* this,int dislikes);
int post_getDislikes(sPost* this,int* dislikes);
int menu();
int post_setFollowers(sPost* this,int followers);
int post_getFollowers(sPost* this,int* followers);
int showPost(sPost* post);
void* asignarLikes(void* likes);
void* asignarDislikes(void* dislikes);
void* asignarFollowers(void* followers);
int compararFollowers(void* pFollowersA,void* pFollowersB);
int filtrarPosteosLikes(void* likes);





#endif // POST_H_INCLUDED
