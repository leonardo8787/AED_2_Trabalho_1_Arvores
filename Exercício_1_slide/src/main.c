#include "arvore.h"

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

	printf("\n\nExercício de árvore \nautor: Leonardo Campos\n\n");

	printf("Árvore inicial: \n");

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

	printf("Árvore após exclusão:\n");
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
