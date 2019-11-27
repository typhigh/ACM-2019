#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 720;
vector<int> G[MAXN];
int n, m;
int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN], deg[MAXN];

LL calc(int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN]) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) 
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

LL solve() {
    calc(A, A, B);
    calc(A, B, C);
    LL ret = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) ret += C[i][j] * B[i][j];
    } 
//    cout << ret << endl;
    ret /= 10;
//    cout << ret << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (!A[i][j]) continue;
            for (int k = 1; k < j; ++k) {
                if (!A[i][k] || !A[k][j]) continue;
                ret -= deg[i] + deg[j] + deg[k] - 3; 
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        A[x][y] = A[y][x] = 1;
        ++deg[x], ++deg[y];
    }
    cout << solve() << endl;
}