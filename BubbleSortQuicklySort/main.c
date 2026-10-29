
#include <stdio.h>

#define TAM 10

// Bubble Sort: compara elementos vizinhos e troca
// suas posicoes para ordenar em ordem decrescente.
void bubbleSort(float notas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (notas[j] < notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

// Particiona o vetor utilizando o ultimo elemento
// como pivo, colocando notas maiores a esquerda.
int particionar(float notas[], int inicio, int fim) {
    float pivo = notas[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (notas[j] > pivo) {
            i++;

            float temp = notas[i];
            notas[i] = notas[j];
            notas[j] = temp;
        }
    }

    // Coloca o pivo em sua posicao correta.
    float temp = notas[i + 1];
    notas[i + 1] = notas[fim];
    notas[fim] = temp;

    return i + 1;
}

// Quick Sort: divide o vetor em partes menores
// e ordena cada parte utilizando recursividade.
void quickSort(float notas[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(notas, inicio, fim);

        quickSort(notas, inicio, pivo - 1);
        quickSort(notas, pivo + 1, fim);
    }
}

void exibirNotas(float notas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }
    printf("\n");
}

int main() {
    float notas[TAM] = {
        7.5, 9.0, 6.2, 8.7, 5.5,
        10.0, 7.0, 4.8, 8.0, 6.5
    };

    float bubble[TAM], quick[TAM];

    // Copia os dados originais para que os dois
    // algoritmos trabalhem com as mesmas notas.
    for (int i = 0; i < TAM; i++) {
        bubble[i] = notas[i];
        quick[i] = notas[i];
    }

    printf("Notas originais:\n");
    exibirNotas(notas, TAM);

    bubbleSort(bubble, TAM);
    printf("\nNotas ordenadas com Bubble Sort:\n");
    exibirNotas(bubble, TAM);

    quickSort(quick, 0, TAM - 1);
    printf("\nNotas ordenadas com Quick Sort:\n");
    exibirNotas(quick, TAM);

    return 0;
}
