#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cur = 0;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x % 2) {
            if (cur) printf("%d\n", (x+1)/2);
            else printf("%d\n", (x-1)/2);
            cur ^= 1;
        } else {
            printf("%d\n", x/2);
        }
    }    
}