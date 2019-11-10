#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, Next[MAXN], Prev[MAXN], a[MAXN], b[MAXN];

void del(int x) {
    if (Prev[x]) Next[Prev[x]] = Next[x];
    if (Next[x]) Prev[Next[x]] = Prev[x];
}

bool check(int x) {
    if (Prev[x]) return true;
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= n; ++i) scanf("%d", b+i);
    for (int i = 1; i <= n; ++i) {
        if (i < n) Next[a[i]] = a[i+1];
        if (i > 0) Prev[a[i]] = a[i-1];
    } 
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int now = b[i];
        if (check(now)) ++cnt;
        del(now);
    }    
    printf("%d\n", cnt);
}