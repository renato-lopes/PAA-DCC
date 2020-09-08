#include <stdlib.h>
#include <stdio.h>

int * insertsort(int *A, int N) {
    for (int j=1;j<N;j++) {
        int key = A[j];
        int i = j-1;
        while (i>=0 && A[i]>key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    return A;
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
    A = insertsort(A, N);
    for (int i=0; i<N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    free(A);
    return 0;
}
