#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
vector<pair<int, int>> edges;

struct Graph {
    vector<int> G[MAXN];
    bool vis[MAXN];
    int n;

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            G[i].clear();
        }    
    }

    void add(int u, int e) {
        G[u].push_back(e);
    }

    vector<int> solve(int s, int flag) {
        vector<int> ret;
        queue<int> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int x= q.front();
            q.pop();
            for (int y: G[x]) {
                auto& e = edges[y];
                int v = flag == 0? e.first : e.second;
                if (vis[v]) continue;
                q.push(v);
                vis[v] = true;
                ret.push_back(y);
            }
        }
        return ret;
    }
}g1, g2;

int n, m, vis[MAXN];
int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        edges.clear();
        ++kase;
        scanf("%d %d", &n, &m);
        g1.init(n);
        g2.init(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            edges.emplace_back(u, v);
            g1.add(u, edges.size()-1);
            g2.add(v, edges.size()-1);
        }
//        cout << "!!" << endl;
        vector<int> a1 = g1.solve(1, 1), a2 = g2.solve(1, 0);
        for (int x: a2) a1.push_back(x);
        sort(a1.begin(), a1.end());
        a1.erase(unique(a1.begin(), a1.end()), a1.end());
        for (int x: a1) {
            vis[x] = kase;
//            cout << x << endl;
        }
        int cnt = 2 * n - a1.size();
        for (int u = 0; u < edges.size(); ++u) {
            if (vis[u] == kase) continue;
            if (cnt) {
                cnt--;
                vis[u] = kase;
                continue;
            }
            printf("%d %d\n", edges[u].first, edges[u].second);
        }
    }
}