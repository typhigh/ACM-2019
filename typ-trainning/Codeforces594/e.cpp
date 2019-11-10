#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
LL p, ans[MAXN];
int n, t[MAXN];

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cand;
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> qs;
    set<int> s;
    s.insert(n+1);
    for (int i = 1; i <= n; ++i) {
        cand.push(make_pair(t[i], i));
    }
    int cnt = n;
    LL cur = 0;
    while (cnt) {
        if (!q.empty()) {
            int now = q.front();
            q.pop();
            cur += p;
            ans[now] = cur;
            --cnt;
            while (!cand.empty() && cand.top().first < cur) {
                auto node = cand.top();
                cand.pop();
                if (node.second < *s.begin()) {
                    q.push(node.second);
                    s.insert(node.second);
                } else {
                    qs.push(node.second);
                }
            }
            s.erase(now);
            continue;
        }
        if (qs.empty() && q.empty()) cur = max(cur, (LL)cand.top().first);
        while (!cand.empty() && cand.top().first <= cur) {
            auto t = cand.top();
            cand.pop();
            qs.push(t.second);
        }
        int t = *s.begin();
        if (!qs.empty() && qs.top() <= t) {
            q.push(qs.top());
            s.insert(qs.top());
            qs.pop();
        }
    }
}

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) scanf("%d", t+i);
    solve();
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i==n];
}