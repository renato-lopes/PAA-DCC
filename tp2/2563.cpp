#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D[100];
int P[100];
int M[101][10001];

int dp(int i, int j) {
    if (i == 0 || j <= 0) {
        return 0;
    }
    if (M[i][j] != -1) {
        return M[i][j];
    }
    if (P[i-1] > j) {
        M[i][j] = dp(i-1, j);
        return M[i][j];
    }
    M[i][j] = max(dp(i-1, j), dp(i-1, j-P[i-1])+D[i-1]);
    return M[i][j];
}

int main(int argc, char const *argv[])
{
    int N;
    int K;
    while (cin >> N) {
        cin >> K;

        for (int i = 0; i<N; i++) {
            cin >> D[i];
        }

        for (int i = 0; i<N; i++) {
            cin >> P[i];
        }

        for (int i = 0; i<=N; i++) {
            for (int j = 0; j<=K; j++) {
                M[i][j] = -1;
            }
        }

        cout << dp(N, K) << endl;
    }
}


