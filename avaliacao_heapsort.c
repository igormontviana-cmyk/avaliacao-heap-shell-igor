#include <stdio.h>

// Funcao auxiliar para imprimir o vetor
void imprimirVetor(int arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Funcao para manter a propriedade do Max-Heap (Rebaixamento)
void maxHeapify(int arr[], int n, int i) {
    int maior = i;          // Inicializa o maior como a raiz
    int esq = 2 * i + 1;    // Filho da esquerda
    int dir = 2 * i + 2;    // Filho da direita

    // Se o filho da esquerda e maior que a raiz
    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    // Se o filho da direita e maior que o maior atual
    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    // Se o maior nao e a raiz, troca e chama recursivamente
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        maxHeapify(arr, n, maior);
    }
}

// Funcao para construir o Max-Heap inicial
void construirMaxHeap(int arr[], int n) {
    int i;
    // Comeca do ultimo no que nao e folha e vai subindo
    for (i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Funcao que faz a extracao da raiz (primeiro passo do HeapSort)
void extrairRaiz(int arr[], int n) {
    // Troca a raiz (maior elemento) com o ultimo elemento do heap
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;

    // Chama o Heapify na nova raiz, reduzindo o tamanho visivel do heap (n-1)
    // para nao mexer no elemento que ja esta ordenado no final
    maxHeapify(arr, n - 1, 0);
}

int main() {
    int vetor[] = {30, 12, 45, 6, 18, 3};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("=== DEMONSTRACAO DA QUESTAO 2 EM C ===\n\n");
    
    printf("Vetor original:\n");
    imprimirVetor(vetor, n);

    // Passo A: Construir Max-Heap
    construirMaxHeap(vetor, n);
    printf("\na) Max-Heap construido:\n");
    imprimirVetor(vetor, n);

    // Passo B: Primeira Extracao
    extrairRaiz(vetor, n);
    printf("\nb) Vetor apos a primeira extracao da raiz (45):\n");
    imprimirVetor(vetor, n);
    
    printf("\n(Obs: O 45 foi para o final e o resto do vetor manteve a estrutura de Max-Heap)\n");

    return 0;
}
