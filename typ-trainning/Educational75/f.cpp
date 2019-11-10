//高精度乘法
#include <bits/stdc++.h>
#define N 410000
using namespace std;
typedef long long ll;
namespace NTT
{
	const ll p = 998244353, g = 3;
  	ll a[10 * N], b[10 * N];
  	int len, l, r[10 * N];

  	ll quick(ll a, ll b) {
    	ll ret = 1;
    	while(b) 
    	{
      		if (b & 1) ret = ret * a % p;
      		a = a * a % p;
      		b >>= 1;
    	}
    	return ret;
  	}

  	void seta(int x, int k)
  	{
  		a[x] = k;
  	}

  	void setb(int x, int k)
  	{
  		b[x] = k;
  	}

  	void ntt(ll *a, int n, int f)
  	{
	  	//cout << n << endl;
	  	for(int i = 0; i < n; i ++) if (i < r[i]) swap(a[i], a[r[i]]);
	  	for(int i = 1; i < n; i <<= 1) {
      		ll wn = quick(g, (p - 1) / (i << 1)), x, y;
      		if (f < 0) wn = quick(wn, p - 2);
		  		//complex wn(cos(PI / i), sin(f * PI / i)), x, y;
		  	for(int j = 0; j < n; j += (i << 1))
		  	{
		    	ll w = 1;
		    	for(int k = 0; k < i; k ++, w = w * wn % p)
		   		{
		      		x = a[j + k]; y = w * a[j + i + k] % p;
		      		a[j + k] = (x + y) % p;
		      		a[j + i + k] = (x - y) % p;
		    	}
		  	}
    	}
  	}
 
  	void init(int w) {
		len = 1, l = 0;
		while (len < w) {
			++l;
			len *= 2;
		}
		for (int i = 0; i < len; ++i) a[i] = b[i] = 0;
  	}
  	
	void work(int w) {
    	len = 1, l = 0;
    	while(len < w)
    	{
  	  		l ++;
  	  		len *= 2;
    	}
    	for(int i = 0; i < len; i ++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    	ntt(a, len, 1);  ntt(b, len, 1);
    	for(int i = 0; i < len; i ++) a[i] = a[i] * b[i] % p;
    	ntt(a, len, - 1);
    	ll inv = quick(len, p - 2);
    	for(int i = 0; i < len; i ++) a[i] = a[i] * inv % p;
  	}
}

vector<int> ret;
vector<int> mul(const vector<int>& a, const vector<int>& b) {
	ret.resize(a.size() + b.size()-1);
	int w = a.size() + b.size() + 2;
	NTT::init(w);
	for (int i = 0; i < a.size(); ++i) NTT::seta(i, a[i]);
	for (int i = 0; i < b.size(); ++i) NTT::setb(i, b[i]);
	NTT::work(w);
	for (int i = 0; i < a.size() + b.size() - 1; ++i) ret[i] = (NTT::a[i]); 
	return ret;
}

vector<int> quick_pow(vector<int> a, ll b) {
	vector<int> ret = {1};
	while (b) {
		if (b & 1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ret;
} 

const int MAXN = 600010;
const ll MOD = 998244353;
int n, k, b[10];
ll ans[MAXN], fac[MAXN], inv[MAXN], twoP[MAXN];

void OUT(vector<int> a) {
	for (auto x: a) cout << x << " ";
	cout << "\n";
}

void init() {
	fac[0] = inv[0] = twoP[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = fac[i-1] * i % MOD;
	for (int i = 1; i < MAXN; ++i) twoP[i] = twoP[i-1] * 2 % MOD;
	inv[MAXN-1] = NTT::quick(fac[MAXN-1], MOD-2);
	for (int i = MAXN-2; i >= 0; --i) inv[i] = inv[i+1] * (i+1) % MOD;
}

ll C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

vector<int> quick_pow(int kase, int n) {
	if (kase == 1) {
		ret.resize(n+1);
		for (int i = 0; i <= n; ++i) ret[i] = twoP[i] * C(n, i) % MOD;
		return ret; 
	} else {
		ret.resize(2*n+1);
		for (int i = 0; i <= 2*n; ++i) ret[i] = C(2*n, i) % MOD;
		return ret;
	}
}
int main() {
	init();
	scanf("%d %d", &n, &k);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++mp[x];
	}
	for (int i = 0; i < k; ++i) {
		int x, one = 0, two = 0;
		scanf("%d", &x);
		for (auto p : mp) {
			if (p.first >= x) break;
			if (p.second >= 2) {
				++two;
			} else {
				++one;
			}
		}
		vector<int> ones = quick_pow(1, one);
		vector<int> twos = quick_pow(2, two);
		vector<int> add = mul(ones, twos);
//		OUT(ones);

//		OUT(add);
		for (int i = 0; i < add.size(); ++i) ans[i+1+x] = (ans[i+1+x] + add[i]) % MOD;

	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int m;
		scanf("%d", &m);
		m /= 2;
		cout << (ans[m] % MOD + MOD) % MOD << '\n';
	}
}