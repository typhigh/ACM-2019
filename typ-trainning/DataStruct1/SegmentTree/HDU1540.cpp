#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;

int n, m;
char s[10];

struct node {
	int cl;
	int cr;
	bool connect;
} t[MAXN<<2];

struct Answer {
	bool lcon;
	bool rcon;
	int val;
};
void pushUp(int id) {
	t[id].cl = t[id].cr = t[id].connect = 0;
	if (t[id<<1].cl) {
		t[id].cl = t[id<<1].cl;
		if (t[id<<1].connect) t[id].cl += t[id<<1|1].cl;
	}
	if (t[id<<1|1].cr) {
		t[id].cr = t[id<<1|1].cr;
		if (t[id<<1|1].connect) t[id].cr += t[id<<1].cr;
	}
	t[id].connect = t[id<<1].connect && t[id<<1|1].connect;
}

void build(int id, int l, int r) {
	if (l == r) {
		t[id].cl = t[id].cr = 1;
		t[id].connect = true;
		return ;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	pushUp(id);
}

void update(int id, int l, int r, int x, int d) {
	if (l == r) {
		t[id].cl = t[id].cr = t[id].connect = d;
		return;
	}
	int mid = (l+r) >> 1;
	if (x <= mid) update(id<<1, l, mid, x, d);
	else if (x > mid) update(id<<1|1, mid+1, r, x, d);
	pushUp(id);
}

void del(int x) {
	update(1, 1, n, x, 0);
}

void restore(int x) {
	update(1, 1, n, x, 1);
}

Answer merge(Answer ans, node& other, bool left) {
	if (left) {
		// rcon may change but lcon not
		if (ans.rcon) {
			ans.val += other.cl;
			if (!other.connect) ans.rcon = false;
		}
	} else {
		if (ans.lcon) {
			ans.val += other.cr;
			if (!other.connect) ans.lcon = false;
		}
	}
	return ans;
}

Answer query(int id, int l, int r, int x) {
	if (l == r) {
		int flag = t[id].connect;
		return Answer {flag, flag, flag};
	}
	int mid = (l+r) / 2;
	Answer ans;
	node other;
	bool left = false;
	if (x <= mid) left = true;
	if (left) {
		ans = query(id<<1, l, mid, x);
		other = t[id<<1|1];
	} else {
		ans = query(id<<1|1, mid+1, r, x);
		other = t[id<<1];
	}
	ans = merge(ans, other, left);
//	printf("[%d, %d] %d %d %d\n", l, r, ans.lcon, ans.rcon, ans.val);
	return ans;
}


int query(int x) {
	return query(1, 1, n, x).val;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		build(1, 1, n);
		stack<int> last;
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			int x;
			if (s[0] == 'D') {
				scanf("%d", &x);
				del(x);
				last.push(x);
			} else if (s[0] == 'R') {
				if (last.empty()) continue;
				int x = last.top();
				last.pop();
				restore(x);
			} else if (s[0] == 'Q') {
				scanf("%d", &x);
				printf("%d\n", query(x));
			}
		}
	}
}
