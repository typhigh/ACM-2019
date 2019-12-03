        /**************************************************************
            Problem: 4477
            User: typhigh
            Language: C++
            Result: Wrong_Answer
        ****************************************************************/
        
        #include <bits/stdc++.h>
        using namespace std;
        const int MAXN = 100010;
        int root[MAXN], ch[MAXN*15][26], val[MAXN*15], tot;
        
        void Copy(int dst, int src) {
            memcpy(ch[dst], ch[src], sizeof(ch[dst]));
        //    val[dst] = val[src];
        }
        
        void insert(char* s, int old, int now) {
        //    cout << s << " " << now << endl;
            int len = strlen(s);
            for (int i = 0; i < len; ++i) {
                Copy(now, old);
                int c = s[i] - 'a';
                int node = ++tot;
                ch[now][c] = node;
                old = ch[old][c];
                now = node;
                val[now] = val[old];
                ++val[now];
            }
        }
        
        int queryCnt(char *s, int now) {
        //    cout << s << " " << now << endl;
            int len = strlen(s);
            for (int i = 0; i < len; ++i) {
                int c = s[i] - 'a';
                if (ch[now][c] == 0) return 0;
                now = ch[now][c];
            }
            return val[now];
        }
        
        int dep[MAXN], ST[2*MAXN][20], ss, fa[MAXN], vis[MAXN];
        int Log2[2*MAXN];
        
        int n;
        char s[MAXN][20];
        vector<int> G[MAXN];
        vector<pair<int, int> > edges;
        void addEdge(int u, int v, int id) {
            edges.push_back(make_pair(v, id));
            edges.push_back(make_pair(u, id));
            int m = edges.size();
            G[u].push_back(m-2);
            G[v].push_back(m-1);
        }
        
        void DFS(int u) {
            vis[u] = ++ss;
            ST[ss][0] = u;
            for (int i = 0; i < G[u].size(); ++i) {
                pair<int, int>& e = edges[G[u][i]];
                int v = e.first;
                int eid = e.second;
                if (v == fa[u]) continue;
                dep[v] = dep[u]+1;
                root[v] = ++tot;
                insert(s[eid], root[u], root[v]);
                fa[v] = u;
                DFS(v);
                ST[++ss][0] = u;
            }
        }
        
        int Min(int x, int y) {
            return dep[x] < dep[y] ? x : y;
        }
        
        void buildST() {
            Log2[1] = 0;
            for (int i = 2; i <= ss; ++i) Log2[i] = Log2[i>>1] + 1;
            for (int j = 1; j <= Log2[ss]; ++j) {
                for (int i = 1; i + (1<<j)-1 <= ss; ++i) {
                    ST[i][j] = Min(ST[i][j-1], ST[i+(1<<j-1)][j-1]);
                }
            }
        }
        
        int queryST(int u, int v) {
            int l = vis[u], r = vis[v];
            if (l > r) swap(l, r);
            int k = Log2[r-l+1];
            return Min(ST[l][k], ST[r-(1<<k)+1][k]);
        }
        
        int query(int u, int v, char* s) {
            int lca = queryST(u, v);
        //    cout << lca << endl;
        //    cout << queryCnt(s, root[u]) << " " << queryCnt(s, root[v]) << " " << queryCnt(s, root[lca]) << endl;
            return queryCnt(s, root[u]) + queryCnt(s, root[v]) - 2 * queryCnt(s, root[lca]);
        }
        
        char tmp[15];
        int main() {
            scanf("%d", &n);
            for (int i = 0; i < n-1; ++i) {
                int u, v;
                scanf("%d %d %s", &u, &v, s[i]);
                addEdge(u, v, i);
            }
            root[1] = ++tot;
            fa[1] = 0;
            DFS(1);
            buildST();
            int q;
            scanf("%d", &q);
            while (q--) {
                int u, v;
                scanf("%d %d %s", &u, &v, tmp);
                printf("%d\n", query(u, v, tmp));
            }
        }
        
        /*
        7
        1 2 abc
        1 3 ab
        2 4 c
        2 5 ad
        3 6 abe
        3 7 zbf
        5
        1 2 abc
        2 4 c
        1 5 a
        1 5 ad
        6 7 zb
        */