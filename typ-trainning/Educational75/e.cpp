#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int n;
vector<int> M[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) M[i].clear();
        for (int i = 0; i < n; ++i) {
            int m, p;
            scanf("%d %d", &m, &p);
            M[m].push_back(p);
        }    
        int pref = n, cnt = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int m = n-1; m >= 0; --m) {
            pref -= M[m].size();
            for (int p: M[m]) q.push(p);
            while (pref + cnt < m) {
                ++cnt;
                ans += q.top();
                q.pop();
            }
        }
        cout << ans << endl;
    }
}