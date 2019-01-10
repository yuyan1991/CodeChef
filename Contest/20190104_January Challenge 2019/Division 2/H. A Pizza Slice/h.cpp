// 这题考的是数学归纳法还有初中高中的平面几何知识，把图画出来，把题目说的四个类型的角都整理一下通项公式，就可以得出答案了
#include<iostream>
using namespace std;

int T,n,t,x,y,z,m,p,q;

int solve() {
    int res=2*n+1;
    m=x;
    switch (t) {
        case 1:
            if (y==x+1 && z==x) res=m;
            if (y==x+1 && z==y+1) res=2*n-m-1;
            if (y==x-1 && x==z) res=m;
            if (y==x-1 && z==y-1) res=2*n-m+3;
            break;
        case 2:
            if (y==x+1 && z==y+1) res=2*n-2*m-1;
            if (y==x-1 && z==y-1) res=2*n-2*m+3;
            break;
        case 3:
            if (y==x+1 && z==y+1) res=2*n-m+1;
            if (y==x+1 && z==x) res=m;
            if (y==x-1 && x==z) res=m;
            if (y==x-1 && z==y-1) res=2*n-m+1;
            break;
        case 4:
            if (y==x+1 && z==y+1) res=2*n-2*m-1;
            if (y==x-1 && z==y-1) res=2*n-2*m+3;
            break;
    }
    return res;
}

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    scanf("%d",&T);
    for (;T;T--) {
        scanf("%d%d%d%d%d",&n,&t,&x,&y,&z);
        p = solve();
        q = 2*n+1; 
        printf("%d %d\n", p/gcd(p,q), q/gcd(p,q));
    }
    return 0;
}