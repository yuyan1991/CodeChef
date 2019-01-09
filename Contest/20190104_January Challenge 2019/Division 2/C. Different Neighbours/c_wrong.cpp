// 错误的想法，在n=3，m=5的时候出现反例
#include<iostream>
using namespace std;

const int maxn = 55;
int a[maxn][maxn];
int T,n,m,ans;

void solve() {
    ans=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            // 四色原理：方案数肯定不超过4
            for (int mark=1;mark<=4;mark++) {
                if (i-2>=0 && a[i-2][j]==mark) continue;
                if (i-1>=0 && j-1>=0 && a[i-1][j-1]==mark) continue;
                if (i-1>=0 && j+1<m && a[i-1][j+1]==mark) continue;
                if (j-2>=0 && a[i][j-2]==mark) continue;
                a[i][j]=mark;
                ans=max(ans,mark);
                break;
            }
        }
}

void print() {
    printf("%d\n",ans);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m-1;j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][m-1]);
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d",&T);
    for (;T;T--) {
        scanf("%d%d",&n,&m);
        solve();
        print();
    }
    return 0;
}