#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
char s[MAXN];
int n;

int main() {
    int T;
    scanf("%d", &T);
    vector<int> odd, even;
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        odd.clear();
        even.clear();
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            if (x & 1) odd.push_back(x);
            else even.push_back(x);
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (c1 < odd.size() && (c2 >= even.size() || odd[c1] < even[c2])) s[i] = odd[c1++] + '0';
            else s[i] = even[c2++] + '0';  
        }
        printf("%s\n", s);
    }

}