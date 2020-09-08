#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef INF
#define INF 9999999
#endif

void merge(int *A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *) malloc((n1)*sizeof(int));
    int *R = (int *) malloc((n2)*sizeof(int));
    int i, j;
    for (i=0;i<n1;i++) {
        L[i] = A[p + i];
    }
    for (j=0;j<n2;j++) {
        R[j] = A[q + 1 + j];
    }
    i = 0;
    j = 0;
    for (int k=p;k<=r;k++) {
        if (i >= n1) {
            A[k] = R[j];
            j++;
        } else if (j >= n2) {
            A[k] = L[i];
            i++;
        } else {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
        }
    }
    free(L);
    free(R);
}

void mergesort(int *A, int p, int r) {
    if (p < r) {
        int q = (int) floor((r+p)/2);
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char const *argv[])
{
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
    mergesort(A, 0, 9);
    for (int i=0; i<N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    free(A);
    return 0;
}