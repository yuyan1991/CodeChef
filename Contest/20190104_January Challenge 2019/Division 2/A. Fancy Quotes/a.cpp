#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn = 111;
char c[maxn];

void init() {
	fgets(c, sizeof(c), stdin);
}

bool solve() {
	string cur = "";
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		if (c[i] == ' ') {
			cur = "";
		} else {
			cur += c[i];
			if (cur == "not" && (i == len - 1 || c[i + 1] == ' ' || c[i+1] == '\n'))
				return true;
		}
	}
	return false;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w",stdout);

	int T;
	scanf("%d\n", &T);
	for (;T;T--) {
		init();
		bool bigger = solve();
		if (bigger)
			printf("Real Fancy\n");
		else
			printf("regularly fancy\n");
	}

	return 0;
}
