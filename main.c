/**
Universidade Federal Rural de Pernambuco
Discente: Ewerton Queiroz
Disciplina: Algoritmos e Estruturas de Dados
Data: 17/09/2016
Atividade: EP1
*/

#include <stdio.h>
#include <stdlib.h>

int aux[100];

typedef struct {
    int x[40];
    int y[40];
} Tponto;

int z = 0; // A variavel global z controla o tamanho do vetor.
int tamanho;

/**
Esta função realiza a leitura do arquivo que contém as altitudes da pista.
Atentar para o fato de que não há verificação de validade do arquivo, ou seja,
se o arquivo não for localizado o programa funcionará de maneira inesperada.
*/
void ler_arquivo (char url[]) {
    FILE *arquivo;

    arquivo = fopen (url, "r");

    fscanf (arquivo, "%d", &aux[z]);

    while (aux[z] != 0) {
        fscanf (arquivo, "%d", &aux[++z]);
    }

    fclose (arquivo);

    tamanho = aux[0];
}

void separar_vetores (int v[], Tponto *pontos) {
    int i, j;

    j = 1;
    for (i = 0; i < tamanho; i++) {
        pontos -> x[i] = v[j++];
    }

    for (i = 0; i < tamanho; i++) {
        pontos -> y[i] = v[j++];
    }
}

// Esta função percorre o vetor da esquerda para a direita e o ordena de maneira crescente.
void ordenar_selecao (int v[], int inicio, int tamanho) {
    int i, j, x, menor;

    for (i = inicio; i < tamanho - 1; ++i) {
        menor = i;

        for (j = i + 1; j < tamanho; ++j) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        x = v[i];
        v[i] = v[menor];
        v[menor] = x;
    }
}

// Esta função realiza a impressão dos pontos.
void imprimir_vetor (Tponto pontos) {
    int a;
    for (a = 0; a < tamanho; a++) {
        printf ("%d ", pontos.x[a]);
    }
    printf("\n");
    for (a = 0; a < tamanho; a++) {
        printf ("%d ", pontos.y[a]);
    }

    printf ("\n\n");
}

int main () {
    Tponto ponto;

    // Mudar o nome do arquivo
    char url[] = "trembala.dat";
    ler_arquivo (url);

    separar_vetores (aux, &ponto);

//    ordenar_selecao(ponto.x, 0, tamanho);

    imprimir_vetor (ponto);
}
