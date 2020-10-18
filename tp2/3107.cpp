#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 99999999

int stones[1000002];
int distances_c[1000002];
int distances_l[1000002];

int find_first_stone_reach(int i, int j, int stone, int range) {
    if (j-i == 0) {
        return i;
    }
    int m = floor((float)(j-i)/(float) 2);
    if (stones[stone] - stones[m+i] > range) {
        return find_first_stone_reach(m+i+1, j, stone, range);
    } else {
        if (stones[stone] - stones[i+m-1] > range) {
            return m+i;
        } else {
            return find_first_stone_reach(i, m+i, stone, range);
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N;
    cin >> M;

    stones[0] = 1;

    for (int i = 1; i<=N; i++) {
        int s;
        cin >> s;
        stones[i] = s;
    }
    stones[N+1] = M;

    int X, Y;
    cin >> X;
    cin >> Y;

    distances_c[0] = 0;
    distances_l[0] = 0;

    for (int i = 1; i<=N; i++) {
        if (stones[i] - stones[i-1] > Y) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i<(N+2); i++) {
        distances_c[i] = INF;
        distances_l[i] = INF;
    }

    
    for (int i = 1; i<(N+2); i++) {
        int min_c = INF;
        int min_l = INF;
        int lX;
        lX  = find_first_stone_reach(0, i, i, X);
        for (int j = lX; j<i; j++) {
            if (stones[i] - stones[j] <= X) {
                min_c = min(min_c, distances_c[j]);
                min_c = min(min_c, distances_l[j]);
            }
            if (min_c < INF) {
                break;
            }
        }
        int lY;
        lY = find_first_stone_reach(0, i, i, Y);
        for (int j = lY; j<i; j++) {
            if (stones[i] - stones[j] <= Y) {
                min_l = min(min_l, distances_c[j]);
            }
            if (min_l < INF) {
                
                break;
            }
        }
        if (min_c >= INF && min_l >= INF) {
            break;
        }
        distances_c[i] = min(distances_c[i], min_c + 1);
        distances_l[i] = min(distances_l[i], min_l + 1);
    }


    int min_dist = min(distances_c[N+1], distances_l[N+1]);

    if (min_dist < INF) {
        cout << min_dist << endl;
    } else {
        cout << -1 << endl;
    }

}


