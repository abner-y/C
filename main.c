#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Fila {
	int *queue;
	int front, rear, count;
};

void criarFila(struct Fila *f) {
	f->queue = (int *)malloc(MAX * sizeof(int));
	f->front = 0;
	f->rear = -1;
	f->count = 0;
}

void inserir(struct Fila *f, int v) {
	if (f->rear == MAX - 1)
		f->rear = -1;

	f->rear++;
	f->queue[f->rear] = v;
	f->count++;
}

int remover(struct Fila *f) {
	int temp = f->queue[f->front++];

	if (f->front == MAX) {
		f->front = 0;
	}

	f->count--;
	return temp;
}

int filaVazia(struct Fila *f) {
	return (f->count == 0);
}

int filaCheia(struct Fila *f) {
	return (f->count == MAX);
}

void displayFila(struct Fila *f) {
	int cont, i;

	for (cont = 0, i = f->front; cont < f->count; cont++) {
		printf("| %d |\t", f->queue[i++]);

		if (i == MAX) {
			i = 0;
		}
	}
	printf("\n\n");
}

int main() {
	int sw, n, k = 0, valor = 0, i, posicao;

	struct Fila josephusFila;

	criarFila(&josephusFila);

	if (filaCheia(&josephusFila)) {
		printf("\nA fila está cheia!\n\n");

	} else {
		printf("Digite a quantidade de pessoas: ");
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			inserir(&josephusFila, i + 1);
		}
	}

	while (k <= 0) {
		printf("\nValor válido de pulo:");
		scanf("%d", &k);
	}
	posicao = k - 1;

	while (1) {
		printf("\n1 - Inserir elementos\n2 - Extrair elementos\n3 - Imprimir "
			   "Elementos Fila\n0 - Sair\n\nEscolha: ");
		scanf("%d", &sw);

		switch (sw) {
		case 0:
			exit(0);
		case 1:
			if (filaCheia(&josephusFila)) {
				printf("\nA fila está cheia!\n\n");

			} else {
				printf("Digite o valor que deseja adicionar: ");
				scanf("%d", &valor);
				inserir(&josephusFila, valor);
			}

			break;

		case 2:
			if (filaVazia(&josephusFila)) {
				printf("\nA fila está vazia!\n\n");
			} else {
				for (i = 0; i <= posicao; i++) {
					valor = remover(&josephusFila);
					if (i != posicao) {
						inserir(&josephusFila, valor);
					}
				}
			}

			break;
		case 3:
			if (filaVazia(&josephusFila)) {
				printf("\nFila vazia!!!\n\n");

			} else {
				displayFila(&josephusFila);
			}
			break;

		default:
			printf("\nEscolha Invalida\n\n");
		}
	}
}
