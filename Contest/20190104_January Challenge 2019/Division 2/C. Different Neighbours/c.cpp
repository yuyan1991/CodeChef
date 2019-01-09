// 构造法
#include<iostream>
using namespace std;

const int maxn = 55;
const int maxm = 4;
int a[maxn][maxn];
int seq[2][maxm];
int T,n,m,maxColor;

int getMaxColor() {
    // 根据四色原理，最多4种颜色
    if (n==1 && m<=2 || n<=2 && m==1) return 1;
    if (n==1 || m==1 || n==2 && m==2) return 2;
    if (n>=3 && m==2 || n==2 && m>=3) return 3;
    return 4;
}

void fill() {
    maxColor = getMaxColor();
    //当maxColor<4时，直接填充
    if (maxColor<4) {
        for (int j=0;j<m;j++) a[0][j]=j/2%maxColor+1;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++) {
                // 四色原理：方案数肯定不超过4
                for (int mark=1;mark<=maxColor;mark++) {
                    if (i-2>=0 && a[i-2][j]==mark) continue;
                    if (i-1>=0 && j-1>=0 && a[i-1][j-1]==mark) continue;
                    if (i-1>=0 && j+1<m && a[i-1][j+1]==mark) continue;
                    if (j-2>=0 && a[i][j-2]==mark) continue;
                    a[i][j]=mark;
                    break;
                }
            }
        return;
    }

    // 下面是对maxColor为4的情况的填充方法
    // 对棋盘进行黑白染色，假设(0,0)是黑色，先给黑色格子上色
    for (int i=0;i<maxColor;i++) seq[0][i]=i+1; // 1,2,...,#maxColor
    seq[1][0]=maxColor;for (int i=1;i<maxColor;i++) seq[1][i]=i; // #maxColor,1,2,...,#maxColor-1
    for (int i=0;i<n;i++) {
        for (int j=0+(i&1),c=0;j<m;j+=2,c++) {
            a[i][j]=seq[i&1][(c+i/2)%maxColor];
        }
    }

    // 再给白色格子上色
    seq[0][0]=maxColor;for (int i=1;i<maxColor;i++) seq[0][i]=i; // #maxColor,1,2,...,#maxColor-1
    for (int i=0;i<maxColor-1;i++) seq[1][i]=i+2;seq[1][maxColor-1]=1; // 2,...,#maxColor,1
    
    for (int i=0;i<n;i++) {
        for (int j=0+((i+1)&1),c=0;j<m;j+=2,c++) {
            a[i][j]=seq[i&1][(c+i/2)%maxColor];
        }
    }
}

void print() {
    printf("%d\n",maxColor);
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
        fill();
        print();
    }
    return 0;
}