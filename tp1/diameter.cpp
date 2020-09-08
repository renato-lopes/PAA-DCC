#include <iostream>
#include <limits>
#include <string>
using namespace std;

#define MAX_V 300
#define INF 99999999

int **create2dArray(int n, int m) {
    int **A = new int*[n];
    for (int i=0; i<n; i++) {
        A[i] = new int[m];
        for (int j=0; j<m; j++) {
            A[i][j] = 0;
        }
    }
    return A;
}

int ***create3dArray(int d, int n, int m) {
    int ***A = new int**[d];
    for (int i=0; i<d; i++) {
        A[i] = new int*[n];
        for (int j=0; j<n; j++) {
            A[i][j] = new int[m];
            for (int k=0; k<m; k++) {
                A[i][j][k] = 0;
            }
        }
    }
    return A;
}

void deallocate2dArray(int **A, int n, int m) {
    for (int i=0; i<n; i++) {
        delete[] A[i];
    }
    delete[] A;
}

void deallocate3dArray(int ***A, int d, int n, int m) {
    for (int i=0; i<d; i++) {
        for (int j=0; j<n; j++) {
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
}

void printGraph(int **graph, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int readGraph(int **graph) {
    // Initialize graph with no edges
    for (int i=0; i<MAX_V; i++) {
        for (int j=0; j<MAX_V; j++) {
            if (i != j) {
                graph[i][j] = INF;
            }
        }
    }
    int n, m;
    cin >> n;
    cin >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
    }
    return n;
}

void floydWarshall(int **graph, int ***D, int ***P, int n) {
    // Initialize D(0) and P[0]
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            D[0][i][j] = graph[i][j];
            if (i != j && D[0][i][j] < INF) {
                P[0][i][j] = i;
            }
        }
    }
    // Execute Floyd-Warshall algorithm
    for (int k=1; k<=n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (D[k-1][i][j] <= (D[k-1][i][k-1] + D[k-1][k-1][j])) {
                    D[k][i][j] = D[k-1][i][j];
                    P[k][i][j] = P[k-1][i][j];
                } else {
                    D[k][i][j] = D[k-1][i][k-1] + D[k-1][k-1][j];
                    P[k][i][j] = P[k-1][k-1][j];
                }
            }
        }
    }
}

void calculateDiameter(int **graph, int ***D, int ***P, int n) {
    floydWarshall(graph, D, P, n);
    // Get diameter
    int diameter=0, u, v;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (D[n][i][j] < INF && D[n][i][j] > diameter) {
                diameter = D[n-1][i][j];
                u = i;
                v = j;
            }
        }
    }
    cout << "diameter " << diameter << endl;
    cout << u+1 << " " << v+1 << endl;
    // TODO: Print path
}

int main(int argc, char const *argv[])
{
    int **graph = create2dArray(MAX_V, MAX_V); // Graph weights matrix
    int ***D = create3dArray(MAX_V+1, MAX_V+1, MAX_V+1); // D matrices
    int ***P = create3dArray(MAX_V+1, MAX_V+1, MAX_V+1); // Pi matrices
    int n = readGraph(graph);
    calculateDiameter(graph, D, P, n);

    deallocate2dArray(graph, MAX_V, MAX_V);
    deallocate3dArray(D, MAX_V+1, MAX_V+1, MAX_V+1);
    deallocate3dArray(P, MAX_V+1, MAX_V+1, MAX_V+1);
    return 0;
}

