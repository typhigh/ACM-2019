#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 500100;
int minv[MAXN<<2], maxv[MAXN<<2], f[MAXN<<2];

void build(int id, int l, int r) {
    if (l == r) {
        minv[id] = maxv[id] = f[id] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    minv[id] = maxv[id] = f[id] = 0;
}

void pushDown(int id) {
    if (f[id]) {
        minv[id<<1] += f[id];
        minv[id<<1|1] += f[id];
        maxv[id<<1] += f[id];
        maxv[id<<1|1] += f[id];
        f[id<<1] += f[id];
        f[id<<1|1] += f[id];
        f[id] = 0;
    }
}

void pushUp(int id) {
    minv[id] = min(minv[id<<1], minv[id<<1|1]);
    maxv[id] = max(maxv[id<<1], maxv[id<<1|1]);
}

int queryMin(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return minv[id];
    }
    pushDown(id);
    int mid = (l+r) >> 1;
    int ans = INF;
    if (mid >= L) ans = min(ans, queryMin(id<<1, l, mid, L, R));
    if (mid+1 <= R) ans = min(ans, queryMin(id<<1|1, mid+1, r, L, R));
    pushUp(id);
    return ans;
}


int queryMax(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return maxv[id];
    }
    pushDown(id);
    int mid = (l+r) >> 1;
    int ans = -INF;
    if (mid >= L) ans = max(ans, queryMax(id<<1, l, mid, L, R));
    if (mid+1 <= R) ans = max(ans, queryMax(id<<1|1, mid+1, r, L, R));
    pushUp(id);
    return ans;
}

void update(int id, int l, int r, int L, int R, int d) {
//    cout << id << " " << l << " " << r << " " << d << '\n';
    if (L <= l && r <= R) {
        minv[id] += d;
        maxv[id] += d;
        f[id] += d;
        return;
    }
    pushDown(id);
    int mid = (l+r) >> 1;
    if (mid >= L) update(id<<1, l, mid, L, R, d);
    if (mid+1 <= R) update(id<<1|1, mid+1, r, L, R, d);
    pushUp(id);
}

int n;
char s[1000100], now[1001000];
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int nn = n/2 + 10;
    build(1, 1, n/2+10);
    int cur = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
//        cout << now << endl;
//        cout << s[i] << " " << cur << endl;
        if (s[i] == 'L') cur = max(0, cur-1);
        else if (s[i] == 'R') ++cur;
        else {
            if (now[cur] != s[i]) {
                if (now[cur] == '(') {
                    update(1, 1, nn, cur+1, nn, -1);                
                } else if (now[cur] == ')') {
                    update(1, 1, nn, cur+1, nn, 1);
                }

                if (s[i] == '(') {
                    update(1, 1, nn, cur+1, nn, 1);
                } else if (s[i] == ')') {
                    update(1, 1, nn, cur+1, nn, -1);
                }

                now[cur] = s[i]; 
                int q1 = queryMin(1, 1, nn, 1, nn);
                int q2 = queryMin(1, 1, nn, nn, nn);
//                cout << q1 << " " << q2 << endl;
                bool yes = q1 == 0 && q2 == 0;
                if (!yes) {
                    last = -1;
                } else {
                    last = queryMax(1, 1, nn, 1, nn);
                }
            }
        } 
        printf("%d ", last);
    } 
    puts("");
}