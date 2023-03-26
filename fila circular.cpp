#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//fila circular

int primeiro = 0;
int ultimo = -1;
int flag= 0;
int fila[TAM];

void enqueue(int x){
	
	if (ultimo < TAM -1){
		if (flag == 0)
	{
		ultimo ++;
		fila[ultimo] = x;
		printf("\nvalor inserido com sucesso\n");	
	}
		else if(flag == 1 && ultimo < primeiro -1){
		ultimo ++;
		fila[ultimo] = x;
		printf("\nvalor inserido com sucesso\n");
	}
	   else
	   	printf("\nO valor nao foi inserido\n");
	   
	}
	else{
		
		if(primeiro != 0){
			ultimo = 0;
			flag =1;
			fila[ultimo] = x;
			printf("\nvalor inserido com sucesso\n");	
		}
		else
			printf("\nO valor nao foi inserido\n");
		
	}
}

int dequeue(){
	
	int aux;
	if(primeiro < TAM)
	{
		if(flag == 0 && primeiro <= ultimo)
		{
			aux = fila[primeiro];
			fila[primeiro] = -1;
			primeiro++;
			return aux;
		}
		else if(flag == 1 && primeiro != ultimo)
		{
			aux = fila[primeiro];
			fila[primeiro] = -1;
			primeiro++;
			return aux;
		}
	}
	else 
	{
		if(ultimo != 0)
		{
			primeiro = 0;
			flag = 0;
			aux = fila[primeiro];
		    fila[primeiro] = -1;
		    return aux;
		}	
		else
		printf("\nNao existe valor a se removido\n");
	}

}

void list (){
	int i;
	printf("\n----------------LISTA---------------\n\n");
	for(i = 0; i < TAM ; i++){
		printf("\tValor na posiçao %d - %d\n",i, fila[i]);
	}
	printf("\n------------------------------------\n\n");
	
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
	int op;
	
	do{
	printf("\n1 - inserir\n");
	printf("2 - remover\n");
	printf("3 - listar\n");
	printf("4 - sair\n");
	printf("5 - limpar\n");
	printf("6 - tamanho da fila\n");
	
	printf("escolha a opçao desejada\n");
	scanf("%d",&op);
	
	switch (op){
		
		case 1:
		printf("digite o valor a ser inserido: \n");
		scanf("%d",&x);
		enqueue(x);
		break;
		
		case 2:
			printf("Valor removido - %d\n", dequeue());
			break;
		case 3:
			list();
			break;
		case 4:
			clear();
			printf("\nLimpeza exevcutada\n");
			break;
		case 5:
			printf("o tamanho da fila eh: %d\n",size());
			break;
		case 6:
			printf("tchau\n");
			break;	
		default:
		printf("\nopçao invalida\n");	
	}
	
}while(op != 6);
  
  return 0;

}
