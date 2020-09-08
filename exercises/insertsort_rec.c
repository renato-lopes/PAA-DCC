#include <stdlib.h>
#include <stdio.h>

void insertsort_rec(int *A, int p, int q) {
    if (q-p+1 > 1) {
        int element = A[q];
        insertsort_rec(A, p, q-1);
        int i = q-1;
        while (i >= 0 && A[i] > element) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = element;
    }
}

int main(int argc, char const *argv[]) {
    int N = 10;
    int *A = (int *) malloc(N*sizeof(int));
    A[0] = 10;
    A[1] = 9;
    A[2] = 6;
    A[3] = 1;
    A[4] = 2;
    A[5] = 5;
    A[6] = 3;
    A[7] = 7;
    A[8] = 8;
    A[9] = 4;
    for (int i=0; i<N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    insertsort_rec(A, 0, 9);
    for (int i=0; i<N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    free(A);
    return 0;
}
