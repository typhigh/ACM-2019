#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
vector<int> a[3];
int n, k[3];
int L[MAXN], R[MAXN];


int solve() {
    for (int i = 0; i <= n+1; ++i) {
        int it1 = lower_bound(a[0].begin(), a[0].end(), i) - a[0].begin();
        L[i] += a[0].size() - it1;
        int it2 = lower_bound(a[1].begin(), a[1].end(), i) - a[1].begin();
        L[i] += it2;
//        cout << L[i] << " ";
        if (i) L[i] = min(L[i], L[i-1]);
    }
//    cout << '\n';

    for (int i = n+1; i >= 0; --i) {
        int it1 = upper_bound(a[1].begin(), a[1].end(), i) - a[1].begin();
        R[i] += a[1].size() - it1;
        int it2 = upper_bound(a[2].begin(), a[2].end(), i) - a[2].begin();
        R[i] += it2;
//        cout << R[i] << " ";
        if (i <= n) R[i] = min(R[i], R[i+1]);
    }
//    cout << '\n';
    int ans = n + 1;
    for (int i = 0; i <= n+1; ++i) {
        ans = min(ans, L[i]+R[i ? i-1:i]);
    }
    return ans;
}

int main() {
    scanf("%d %d %d", k+0, k+1, k+2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < k[i]; ++j) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    n = k[0] + k[1] + k[2];
//    puts("!!");
    printf("%d\n", solve());
}