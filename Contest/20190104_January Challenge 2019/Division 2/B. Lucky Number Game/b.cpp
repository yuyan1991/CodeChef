#include<iostream>
using namespace std;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T,n,a,b,m, bobOwn, aliceOwn, commonOwn;

	scanf("%d", &T);
	for (;T;T--) {
		scanf("%d%d%d", &n, &a, &b);
		bobOwn = aliceOwn = commonOwn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			if (m % a == 0 && m % b == 0)
				commonOwn++;
			else if (m % a == 0)
					bobOwn++;
			else if (m % b == 0)
					aliceOwn++;
		}
		if ((commonOwn>0?1:0) + bobOwn > aliceOwn)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}

	return 0;
}
