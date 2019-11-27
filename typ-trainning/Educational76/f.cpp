#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int LIM = 15;
map<vector<int>, int> mp;

int n, a[MAXN];

void out(vector<int> a) {
    for (auto x: a) cout << x << " ";
    cout << endl;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    vector<int> vec;
    vec.resize(n);
    for (int x = 0; x < (1<<LIM); ++x) {
        for (int i = 0; i < n; ++i) 
            vec[i] = __builtin_popcount((a[i] >> LIM) ^ x);
        for (int i = n-1; i >= 0; --i)
            vec[i] -= vec[0];
        if (x == 0) {
//            out(vec);
        }
        mp[vec] = x;
    }

    for (int x = 0; x < (1<<LIM); ++x) {
        for (int i = 0; i < n; ++i) 
            vec[i] = __builtin_popcount((a[i] & ((1 << LIM)-1) ) ^ x);
        for (int i = n-1; i >= 0; --i)
            vec[i] = vec[0] - vec[i];
        if (x == 0) {
//            out(vec);
        }
        if (mp.count(vec)) {
            int y = (mp[vec] << LIM) | x;
            printf("%d\n", y);
            return 0;
        }
    }
    puts("-1");
    return 0;
}