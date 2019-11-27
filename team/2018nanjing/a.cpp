#include <bits/stdc++.h>
using namespace std;

int n, k;

bool solve() {
    if (k == 1 || n == 0) return n & 1;
    return true;
}
int main() {
    scanf("%d %d", &n, &k);
    if (solve()) puts("Adrien");
    else puts("Austin");
}