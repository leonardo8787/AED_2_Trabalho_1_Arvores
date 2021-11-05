
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	char *key;
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
    printf("%s ", t->reg.key);
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
	//(*cont)++;
	if(strcmp((*t)->reg.key , r.key)<0){ pesquisa(&(*t)->esq, aux, r); return;}
	if(strcmp((*t)->reg.key , r.key)>0){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}

void preordem(Tree *t) {
	if(!(t == NULL)) {
		printf("%s ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void meio(Tree *t) {
	if(!(t == NULL)) {
		meio(t->esq);
		printf("%s ", t->reg.key);
		meio(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%s ", t->reg.key);
	}
}


int main(){

	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int *cont=0;
	int tamBusca=10, quantVetor, tamPalavra=30, quantArvore=0;
	int controle;

	char *palavra[] = {"ab","bc","c","d","e","f","g","h","i","j","k","l","m","n","o","p","k","r","s","t","u","v","w","x","y","z","a1","b1","c1","d1","e1","f1"};
	char *busca[] = {"ab","k","l","a","b","d","r","q","m","e"};

	tamPalavra = sizeof(palavra)/sizeof(palavra[0]);
	tamBusca = sizeof(busca)/sizeof(busca[0]);

	system("clear || cls");

	printf("\nElementos da árvore binária: ");
	printf("\n{");
	for(int i=0; i<30; i++){
		quantArvore++;
		r.key = palavra[i];
		r.value = 1;
		printf("%s ", r.key);
		insertTree(&raiz, r);
	}
	printf("}\n");


	printf("\nBusca binária com palavras\n");
	printf("autor: Leonardo de Oliveira Campos\n\n\n");

	printf("Pré-ordem");
	printf("\n{");
	preordem(raiz);
	printf("}");

	printf("\nMeio");
	printf("\n{");
	meio(raiz);
	printf("}\n");

	printf("Pós-ordem");
	printf("\n{");
	posordem(raiz);
	printf("}\n");

	printf("\nPalavras");
	printf("{");
	for(int i=0; i<30; i++){
		printf(" %s ",palavra[i]);
	}
	printf("}\n");
	
	printf("\nPesquisa palavra: ");
	printf("\n{");
	for(int i=0; i<tamBusca; i++) {
		printf("%s ", busca[i]);
	}
	printf("}\n\n");




	for(int i=0; i < tamBusca; i++) {
		r.key = busca[i];
		pesquisa(&raiz, &aux, r);
		//printf("teste: %s", busca[i]);
	}

	for(int i=0; i < tamBusca; i++) {
		printf("teste");
		for(int j=0; j < tamPalavra; j++) {
			printf("teste");
			quantVetor++;
			controle = strcmp(busca[i], palavra[j]);
			if(controle == 0) {
				controle = 1;
				break;
			}
		}
	}






	printf("\n\n");
	printf("acessos na arvore: %d\n", quantArvore);
	printf("acessos medio na arvore: %d\n", (quantArvore / tamBusca));
	printf("acessos no vetor: %d\n", quantVetor);
	printf("acessos medio no vetor: %d\n", (quantVetor / tamBusca));
	printf("\n\n");

  return 0;
}
