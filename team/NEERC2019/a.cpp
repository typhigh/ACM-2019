#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210;
struct Ans {
	bool yes;
	int one, two;
	vector<pair<int, int>> a;
};

Ans ans[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool vis1[MAXN][MAXN][4][4];
Ans dp[MAXN][MAXN][4][4];

void out(Ans &a) {
	if (!a.yes) {
		puts("Impossible");
		return;
	}
	printf("%d:%d\n", a.one, a.two);
	for (auto p: a.a) printf("%d:%d ", p.first, p.second);
	puts("");
}

Ans Swap(Ans a) {
	for (auto& p: a.a) swap(p.first, p.second);
	return a;
}

Ans DL(Ans a) {
//	out(a);
	return a;
}

Ans check(int a, int b, int one, int two) {
	if (a < 0 || b  < 0) {
		Ans ret;
		ret.a.clear();
		ret.yes = 0;
		return ret;		
	}		
	Ans& ret = dp[a][b][one][two];
	if (one < two) {
		ret = Swap(check(b, a, two, one));
		return DL(ret);
	}

//	cout << a << " " << b << " " << one << " " << two << endl;
	if (vis1[a][b][one][two]) {
		return dp[a][b][one][two]; 
	}

	vis1[a][b][one][two] = true;
	if (a < (one-1) * 25 + 15 || b < two * 25) {
		ret.yes = false;
		return DL(ret);
	}

	if (one == 3 && two == 2) {
		for (int y = 0; y <= 13; ++y) {
			ret = check(a-15,b-y, one-1, two);
			if (ret.yes) {
				ret.a.emplace_back(15,y);
				return DL(ret);
			}
		}
		ret.yes = false;
		return DL(ret);
	}

	if (a < one * 25 || b < two * 25) {
		ret.yes = false;
		return DL(ret);
	}

	if (two) {
		for (int x = 0; x <= 23; ++x) {
			ret = check(a-x, b-25, one, two-1);
			if (ret.yes) {
				ret.a.insert(ret.a.begin(), make_pair(x, 25));
				return DL(ret);
			} 
		}
		int f = (a - one * 25);
		int g = max(f + 2, 25);
		ret = check(a-f, b-g, one, two-1);
		ret.a.insert(ret.a.begin(), make_pair(f, g));
		return DL(ret);
	}
	
	// one:0 a:b
	if (a > one * 25) {
		int x = a - one * 25;
		ret = check(a - (x + 25), b - (x + 23), one-1, two);
		ret.a.emplace_back(25+x, 23+x);
		return DL(ret);
	}
		
	int now = b;
	for (int i = 0; i < one; ++i) {
		int val = min(23, now);
		now -= val;
		ret.a.emplace_back(25, val);
	}
	if (now) ret.yes = false;
	else ret.yes = true;
	return DL(ret);

}

Ans calc(int a, int b) {
	Ans ret;
	for (int two = 0; two <= 2; ++two) {
		ret = check(a, b, 3, two);
		if (ret.yes) {
			ret.one = 3;
			ret.two = two;
			return ret;
		}
	}
	
	for (int one = 2; one >= 0; --one) {
		ret = check(a, b, one, 3);
		if (ret.yes) {
			ret.one = one;
			ret.two = 3;
			return ret;
		}
	}
	ret.yes = false;
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!vis[a][b]) {
			vis[a][b] = 1;
			ans[a][b] = calc(a, b);
		}
		out(ans[a][b]);
	}
}
