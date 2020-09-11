#include <iostream>
#include <limits>
#include <string>
using namespace std;

#define MAX_V 300
#define INF 99999999

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

void deallocate3dArray(int ***A, int d, int n, int m) {
    for (int i=0; i<d; i++) {
        for (int j=0; j<n; j++) {
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
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

void floydWarshall(int ***D, int ***P, int n) {
    // Initialize P(0)
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j && D[0][i][j] < INF) {
                P[0][i][j] = i;
            } else {
                P[0][i][j] = -1;
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

int getPath(int **P, int i, int j, string& output) {
    if (i == j) {
        output.append(to_string(i+1));
        output.append(" ");
        return 1;
    } else if (P[i][j] == -1) {
        cout << "Error" << endl;
        return 0;
    } else {
        int res = getPath(P, i, P[i][j], output);
        output.append(to_string(j+1));
        output.append(" ");
        return res + 1;
    }
}

void calculateDiameter(int ***D, int ***P, int n) {
    floydWarshall(D, P, n);
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
    string path("");
    int numv = getPath(P[n-1], u, v, path);
    cout << diameter << endl;
    cout << u+1 << " " << v+1 << endl;
    cout << numv << endl;
    cout << path << endl;
}

int main(int argc, char const *argv[])
{
    int ***D = create3dArray(MAX_V+1, MAX_V+1, MAX_V+1); // D matrices
    int ***P = create3dArray(MAX_V+1, MAX_V+1, MAX_V+1); // Pi matrices
    int n = readGraph(D[0]);
    calculateDiameter(D, P, n);

    deallocate3dArray(D, MAX_V+1, MAX_V+1, MAX_V+1);
    deallocate3dArray(P, MAX_V+1, MAX_V+1, MAX_V+1);
    return 0;
}

