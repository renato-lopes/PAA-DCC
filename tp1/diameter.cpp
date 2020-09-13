#include <iostream>
#include <limits>
#include <vector>
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

void readEdges(int **graph, int n, int m) {
    // Initialize graph with no edges
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j) {
                graph[i][j] = INF;
            }
        }
    }
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
    }
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

void getPath(int **P, int i, int j, vector <int>& path) {
    if (i == j) {
        path.push_back(i);
    } else if (P[i][j] == -1) {
        cout << "Error" << endl;
    } else {
        getPath(P, i, P[i][j], path);
        path.push_back(j);
    }
}

void calculateDiameter(int ***D, int ***P, int n) {
    // Run Floyd-Warshall to get all-pairs shortest distance
    floydWarshall(D, P, n);
    // Get diameter (max min distance)
    int diameter=-1, u, v;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (D[n][i][j] < INF && D[n][i][j] > diameter) {
                diameter = D[n][i][j];
                u = i;
                v = j;
            }
        }
    }
    // Get path between u and v
    vector <int> path;
    getPath(P[n], u, v, path);
    // Print output
    cout << diameter << endl;
    cout << u+1 << " " << v+1 << endl;
    cout << int(path.size()) << endl;
    for (int i = 0; i<path.size()-1; i++) {
        cout << path[i]+1 << " ";
    }
    cout << path[path.size()-1]+1 << endl;
}

int main(int argc, char const *argv[])
{
    // Read amount of vertices n and of edges m
    int n, m;
    cin >> n;
    cin >> m;
    // Allocate memory for matrices
    int ***D = create3dArray(n+1, n, n); // D matrices
    int ***P = create3dArray(n+1, n, n); // Pi matrices
    // Read graph edges
    readEdges(D[0], n, m);
    // Calculate diameter
    calculateDiameter(D, P, n);
    // Free memory
    deallocate3dArray(D, n+1, n, n);
    deallocate3dArray(P, n+1, n, n);
    return 0;
}

