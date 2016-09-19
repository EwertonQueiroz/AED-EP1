/**
Universidade Federal Rural de Pernambuco
Discente: Ewerton Queiroz
Disciplina: Algoritmos e Estruturas de Dados
Data: 17/09/2016
Atividade: EP1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int compara (x, y) void *x, *y; {
    if ( *(int*)x > *(int*)y )
       return 1;
    else if ( *(int*)x == *(int*)y )
            return 0;
    else if ( *(int*)x < *(int*)y )
            return -1;
}

int aux[100];
int V, T, W, B; // Utilizei as variav�is V, T, W e T para retornar os pontos que correspondem aos pontos x e y
                // da menor dist�ncia encontrada entre os dois pontos calculados.

typedef struct {
    int x;
    int y;
} Tponto;

int z = 0; // A variavel global z controla o tamanho do vetor.
int tamanho;

void ler_arquivo (char url[]);
void separar_vetores (int v[], Tponto pontos[]);
float calcular_distancia (Tponto p1, Tponto p2);
float forca_bruta (Tponto ponto[], int n);
float distancia (Tponto ponto[], int n);

void imprimir_pontos (Tponto pontos[]);

int main () {
    // Mudar o nome do arquivo
    char url[] = "trembala.dat";
    ler_arquivo (url);

    Tponto ponto[tamanho];

    separar_vetores (aux, ponto);

    printf ("(%d, %d) (%d, %d) = %.2f", V, T, W, B, forca_bruta(ponto, tamanho));

//    imprimir_pontos (ponto);
}

/**
Esta fun��o realiza a leitura do arquivo que cont�m as altitudes da pista.
Atentar para o fato de que n�o h� verifica��o de validade do arquivo, ou seja,
se o arquivo n�o for localizado o programa funcionar� de maneira inesperada.
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

/**
Esta fun��o separa os elementos correspondentes a x e a y do vetor aux para o vetor do tipo Tponto
com as coordenadas correspondentes a x e a y.
*/
void separar_vetores (int v[], Tponto pontos[]) {
    int i, j;

    j = 1;
    for (i = 0; i < tamanho; i++) {
        pontos[i].x = v[j++];
    }

    for (i = 0; i < tamanho; i++) {
        pontos[i].y = v[j++];
    }
}

// Essa fun��o calcula a dist�ncia euclidiana dos pontos recebidos atrav�s dos par�metros.
float calcular_distancia (Tponto p1, Tponto p2) {
    return sqrt (pow (p1.x - p2.x, 2) + pow (p1.y - p2.y, 2));
}

// Essa fun��o calcula a dist�ncia dos pontos por for�a bruta.
float forca_bruta (Tponto ponto[], int n) {
    float menor_distancia = FLT_MAX;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (calcular_distancia (ponto[i], ponto[j]) < menor_distancia) {
                menor_distancia = calcular_distancia (ponto[i], ponto[j]);
                V = ponto[i].x;
                T = ponto[i].y;
                W = ponto[j].x;
                B = ponto[j].y;
            }
        }
    }

    return menor_distancia;
}

// Esta fun��o realiza a impress�o dos pontos lidos do arquivo.
void imprimir_pontos (Tponto pontos[]) {
    int a;
    for (a = 0; a < tamanho; a++) {
        printf ("%d ", pontos[a].x);
    }
    printf("\n");
    for (a = 0; a < tamanho; a++) {
        printf ("%d ", pontos[a].y);
    }

    printf ("\n\n");
}

/**
A partir daqui eu tentei implementar a solu��o do problema com complexidade O(n log n),
mas n�o consegui, entretando, seguem a implementa��es incompletas.

float distancia (Tponto ponto[], int n) {
    qsort(ponto, n, sizeof(Tponto), compara);

    int i;
    for (i = 1; i < n; i++) {
        a[i] = i; // Slide 43
    }
    return distancia_rec (ponto, a, 1, n);
}


float distancia_rec (Tponto ponto[], int p, int r) {
    if (r <= p + 2) {
        return forca_bruta(ponto, r);
    }

    else {
        int q = (p + r) / 2;
        float de = distancia_rec (ponto, p, q);
        float dd = distancia_rec (ponto, q + 1, r);

        return combine (ponto, p, r, de, dd);
    }
}
*/
