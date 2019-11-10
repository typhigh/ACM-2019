#include <bits/stdc++.h>
using namespace std;

struct Node {
	char ch;
	int pos;
};

struct Op {
	int pos;
	bool del;
	char ch;
};

char s[10];

void read(vector<Op>& a) {
	while (scanf("%s", s) && s[0] != 'E') {
		if (s[0] == 'D') {
			int pos;
			scanf("%d %s", &pos, s);
			a.push_back(Op {pos, true, s[0]});  
		} else if (s[0] == 'I') {
			int pos;
			scanf("%d", &pos);
			a.push_back(Op {pos, false, 0});
		}
	}
}

int main() {
	vector<Op> a, b;
	read(a);
	read(b);
	if (a.size() == b.size()) {
		puts("1");
		return 0;
	}

	
}
