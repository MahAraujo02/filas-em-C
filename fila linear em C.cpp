#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int primeiro = 0;
int ultimo = -1;
int fila[TAM];

void enqueue(int x){
	if (ultimo < TAM -1 ){
		
		ultimo ++;
		fila[ultimo] = x;
		printf("\nvalor inserido com sucesso\n");	
	}
	else{
		printf("\n valor nao inserido\n");
	}

}

int dequeue(){
	
	int aux;
	
	if(primeiro <= ultimo){
		aux = fila[primeiro];
		fila[primeiro] = -1;
		primeiro++;
		return aux;
	}
	else{
		printf("\nnao existe valor a se removido\n");
	}

}

void list (){
	int i;
	printf("\nValor dentro da lista:\n\n");
	for(i = primeiro; i < ultimo+1 ; i++){
		printf("Valor na posiçao %d - %d\n",i, fila[i]);
	}
	printf("\nCursor do primeiro : %d\n", primeiro);
	printf("Cursor do ultimo: %d\n", ultimo);
}

void clear(){
	int i;
	primeiro = 0;
	ultimo = -1;
	for (i = 0; i < TAM; i++){
		fila[i] = -1;
	}
}

int size(){
	return (ultimo - primeiro + 1);
}

int main(){
	
	int x;
	char op;
	
	while(op != 's'){
	printf("\ni - inserir\n");
	printf("r - remover\n");
	printf("l - listar\n");
	printf("s - sair\n");
	printf("c - limpar\n");
	printf("t - tamanho da fila\n");
	scanf("%c",&op);
	
	switch (op){
		
		case 'i':
		printf("digite o valor a ser inserido: \n");
		scanf("%d",&x);
		enqueue(x);
		break;
		
		case 'r':
		printf("Valor removido - %d\n", dequeue());
		break;
		
		case 'l':
		list();
		break;
		
		case 'c':
			clear();
			printf("\nLimpeza exevcutada\n");
			break;
		case 't':
			printf("o tamanho da fila eh: %d\n",size());
		case 's':
			printf("tchau\n");		
	}
		
  }

}
