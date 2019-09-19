#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
const double eps = 1e-6;
int n, m;

struct Line {
	double x, y1, y2;
	int flag;
	Line () {}
	Line (double x, double y1, double y2, int flag):x(x), y1(y1), y2(y2), flag(flag) {}
	bool operator < (const Line& rhs) const {
		return x < rhs.x;
	}
};

struct node {
	double len[3];
	int flag;
	void init() {
		len[0] = len[1] = len[2] = flag = 0;
	}
}t[MAXN<<2];

vector<double> y;

void build(int id, int l, int r) {
//	memset(t[id], 0, sizeof(t[id]));
	t[id].init();
	t[id].len[0] = y[r] - y[l];
	if (l + 1 ==  r) return ;
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid, r);
}

void Calc(int id, int l, int r) {
	if (t[id].flag >= 2) {
		t[id].len[2] = t[id].len[0];
		t[id].len[1] = 0;
	} else if (t[id].flag == 1) {
		if (l + 1 == r) t[id].len[2] = 0;
		else t[id].len[2] = t[id<<1].len[1]+ t[id<<1].len[2] + t[id<<1|1].len[1] + t[id<<1|1].len[2];
		t[id].len[1] = t[id].len[0];
		t[id].len[1] -= t[id].len[2];
	} else {
		assert(t[id].flag == 0);
		if (l + 1 == r) t[id].len[1] = t[id].len[2] = 0;
		else {
			t[id].len[2] = t[id<<1].len[2] + t[id<<1|1].len[2];
			t[id].len[1] = t[id<<1].len[1] + t[id<<1|1].len[1];
		}
	}
}

void update(int id, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		t[id].flag += d;
	} else {
		int mid = (l+r) >> 1;
		if (L < mid) update(id<<1, l, mid, L, R, d);
		if (R > mid) update(id<<1|1, mid, r, L, R, d);
	}
	Calc(id, l, r);
}

map<double, int> idy;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &m);
		vector<Line> lines;
		y.clear();
		idy.clear();
		y.push_back(-1);
		for (int i = 0; i < m; ++i) {
			double x1, y1, x2, y2;
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			lines.emplace_back(x1, y1, y2, 1);
			lines.emplace_back(x2, y1, y2, -1);
			y.push_back(y1);
			y.push_back(y2);
		}
		sort(lines.begin(), lines.end());
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
//		for (int i = 0; i < x.size(); ++i) idx[x[i]] = i;
		for (int i = 0; i < y.size(); ++i) idy[y[i]] = i;
		n = y.size() - 1;
		build(1, 1, n);
		double ans = 0;
		for (int i = 0; i < lines.size(); ++i) {
			if (i) ans += (lines[i].x - lines[i-1].x) * t[1].len[2];
			update(1, 1, n, idy[lines[i].y1], idy[lines[i].y2], lines[i].flag);
		}
//		cout << ans << endl;
		printf("%.2f\n", ans + eps);
	}
}
