#include<iostream>
using namespace std;

const int maxn = 1000 + 1;
int v[maxn][maxn];
bool exist[maxn][maxn];
int n,m,r,c,start,step;
int x[maxn*maxn],y[maxn*maxn];
int len;

void init() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<2*m;i++) {
        scanf("%d%d",&r,&c);
        exist[r][c]=true;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&v[i][j]);
}

void addCell(int r, int c) {
    x[len]=r;
    y[len]=c;
    len++;
}

void print() {
    printf("%d",len);
    for (int i=0;i<len;i++) printf(" %d %d",x[i],y[i]);
    printf("\n");
}

void solve() {
    //构造法，用之字形的路径划分n*n的矩阵，这样，每个指定的格子都可以排到一个顺序，把有序的格子依次序一一配对，就可以构造到一个解了，不过这个解很粗糙，得出的值不会很忧
    bool trigger = false;
    for (int i=1;i<=n;i++) {
        if (i & 1) {
            start = 1;
            step = 1;
        } else {
            start = n;
            step = -1;
        }
        for (int j=start;1<=j && j<=n;j+=step) {
            if (exist[i][j]) {
                trigger=!trigger;
                if (!trigger) {
                    addCell(i,j);
                    print();
                    len=0;
                }
            }
            if (trigger) addCell(i,j);
        }
    }
}

int main() {
    freopen("g.in", "r", stdin);
    freopen("g.out","w",stdout);
    init();
    solve();
    return 0;
}
