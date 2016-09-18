/**
Universidade Federal Rural de Pernambuco
Discente: Ewerton Queiroz
Disciplina: Algoritmos e Estruturas de Dados
Data: 17/09/2016
Atividade: EP1
*/

#include <stdio.h>
#include <stdlib.h>

int aux[50];

typedef struct {
    int x;
    int y;
} Tponto;

int z = 0; // A variavel global z controla o tamanho do vetor.

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
        z++;
        fscanf (arquivo, "%d", &aux[z]);
    }

    fclose (arquivo);
}

void separar_vetores (int v[], Tponto pontos[]) {
    int i, j;

    j = 1;
    for (i = 0; i < v[0]; i++) {
        pontos[i].x = v[j++];
    }

    for (i = 0; i < v[0]; i++) {
        pontos[i].y = v[j++];
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
void imprimir_vetor (int v[], int inicio, int tamanho) {
    int a;

    printf ("%d ", inicio);

    for (a = inicio; a <= tamanho; a++) {
        printf ("%d ", v[a]);
    }

    printf ("\n\n");
}

int main()
{
    // Mudar o nome do arquivo
    char url[] = "trembala.dat";
    ler_arquivo (url);

    Tponto ponto[z];

    separar_vetores(aux, ponto);

    imprimir_vetor(ponto, 0, z);
}
