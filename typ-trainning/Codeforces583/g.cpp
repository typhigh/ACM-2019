    #include <bits/stdc++.h>
    using namespace std;
    const int MAXN = 2010;
    typedef bitset<MAXN> bs;
     
    bs one[MAXN], num[MAXN], wrong;
    int n, m, Next[MAXN], Prev[MAXN];
    set<pair<int, int>> s;
    void insert(int x) {
    	pair<int, int> pi = make_pair(num[x].count(), x);
    	s.insert(pi);
    	auto it = s.find(pi), it2 = it;
    	Prev[x] = Next[x] = 0;
    	wrong[x] = 0;
    	if (it != s.begin()) Prev[x] = (--it)->second;
    	if (++it2 != s.end()) Next[x] = (it2)->second;
    	if (Prev[x]) {
    		Next[Prev[x]] = x;
    		if ((num[Prev[x]] & num[x]) != num[Prev[x]]) wrong[x] = true;
    		else wrong[x] = false;
    	}
    	if (Next[x]) {
    		Prev[Next[x]] = x;
    		if ((num[Next[x]] & num[x]) != num[x]) wrong[Next[x]] = true;
    		else wrong[Next[x]] = false;
    	}
    }
    void erase(int x) {
    	pair<int, int> pii = make_pair(num[x].count(), x);
    	s.erase(pii);
    	wrong[x] = wrong[Next[x]] = false;
    	if (Prev[x]) Next[Prev[x]] = Next[x];
    	if (Next[x]) Prev[Next[x]] = Prev[x];
    	if (Prev[x] && Next[x]) 
    		wrong[Next[x]] = ((num[Prev[x]] & num[Next[x]]) != num[Prev[x]]);
    }
     
    void query() {
    	if (wrong.none()) {
    		puts("-1");
    		return;
    	}
    	int x = wrong._Find_first();
    	bs tmp = num[Prev[x]] ^ (num[x] & num[Prev[x]]);
    	int c1 = tmp._Find_first();
    	tmp = num[x] ^ (num[x] & num[Prev[x]]);
    	int c2 = tmp._Find_first();
    	if (c1 > c2) swap(c1, c2);
    	int r1 = x, r2 = Prev[x];
    	if (r1 > r2) swap(r1, r2);
    	printf("%d %d %d %d\n", r1, c1, r2, c2);
    }
     
    void init() {
    	for (int i = 1; i < MAXN; ++i) {
    		one[i] = one[i-1];
    		one[i].set(i);
    	}
    	for (int i = 1; i <= n; ++i) insert(i);
    }
    int main() {
    	int q;
    	scanf("%d %d %d", &n, &m, &q);
    	init();
    	while(q--) {
    		int a, l, r;
    		scanf("%d %d %d", &a, &l, &r);
    		erase(a);
    		num[a] ^= one[l-1]^one[r];
    		insert(a);
    		query();
    	}
    }
