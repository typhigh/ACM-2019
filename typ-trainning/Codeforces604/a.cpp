#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
char s[MAXN];

bool solve() {
    int n = strlen(s+1);
    s[0] = s[n+1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != '?') {
            if (s[i] == s[i-1] || s[i] == s[i+1]) return false;
            continue;
        } 
        s[i] = 'a';
        if (s[i] == s[i-1] || s[i] == s[i+1]) ++s[i];
        if (s[i] == s[i-1] || s[i] == s[i+1]) ++s[i];
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s+1);
        if (solve()) printf("%s\n", s+1);
        else puts("-1");
    }
}