#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
int n, k, a[MAXN];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0;  i < n; ++i) scanf("%d", a+i);
    DP(0);
}