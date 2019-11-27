#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, a[MAXN], id[MAXN];
int d[MAXN][20];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        id[a[i]] = i;
    }
    
}