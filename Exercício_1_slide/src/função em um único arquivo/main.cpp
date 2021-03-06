#include<stdio.h>
#include<stdlib.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree(){
	return NULL;
}

void insertTree(Tree **t, Record r)
{
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void showTreeInOrder(Tree *t)
{
  if(!(t == NULL)){
    showTreeInOrder(t->esq); 
    printf("%d ", t->reg.key);
    showTreeInOrder(t->dir); 
  }
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}

void pesquisa(Tree **t, Tree **aux, Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}
	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}

void preordem(Tree *t) {
	if(!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void meio(Tree *t) {
	if(!(t == NULL)) {
		meio(t->esq);
		printf("%d ", t->reg.key);
		meio(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%d ", t->reg.key);
	}
}


int main(){

	int reg[] = {12, 7, 13, 23, 11, 3, 4, 8, 10, 99, 1, 17, 9};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	for(int i=0; i< 13; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}

	printf("\n\nExerc??cio de ??rvore \nautor: Leonardo Campos\n\n");

	printf("??rvore inicial: \n");

	printf("{ ");
	showTreeInOrder(raiz);
	printf("}\n");

	//{23, 11, 12, 8}
	printf("Excluindo valores: {23, 11, 12, 8}\n");
	r.key = 23;
	removeTree(&raiz, r);
	r.key = 11;
	removeTree(&raiz, r);
	r.key = 12;
	removeTree(&raiz, r);
	r.key = 8;
	removeTree(&raiz, r);

	printf("??rvore ap??s exclus??o:\n");
	printf("{ ");
	showTreeInOrder(raiz);
	printf("}\n");

	printf("\n");

	printf("pre_ordem: { ");
	preordem(raiz);
	printf("}");
	
	printf("\nmeio: { ");
	meio(raiz);
	printf("}\n");
	
	printf("pos_ordem: { ");
	posordem(raiz);
	printf("}\n");

  return 0;
}
