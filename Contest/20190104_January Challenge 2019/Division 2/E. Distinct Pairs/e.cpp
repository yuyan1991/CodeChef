#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200000 + 10;
struct node {
    int num, position;
} a[maxn], b[maxn];
int T,n,m;

void init() {
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i].num);
        a[i].position = i;
    }
    for (int i=0;i<m;i++) {
        scanf("%d", &b[i].num);
        b[i].position = i;
    }
}

bool cmp(node &x, node &y) {
    return x.num < y.num;
}

void solve() {
    sort(a, a+n, cmp);
    sort(b, b+m, cmp);
}

void print() {
    // for (int i=0;i<n;i++) printf("(%d,%d) ", a[i].num, a[i].position);printf("\n");
    // for (int i=0;i<m;i++) printf("(%d,%d) ", b[i].num, b[i].position);printf("\n");
    for (int i=0;i<m;i++) printf("%d %d\n", a[0].position, b[i].position);
    for (int i=1;i<n;i++) printf("%d %d\n", a[i].position, b[m-1].position);
}

int main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);

    init();
    solve();
    print();

    return 0;
}