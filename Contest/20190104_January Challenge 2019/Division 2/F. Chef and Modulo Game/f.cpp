#include<iostream>
using namespace std;

#define int64 long long

int T,n,p;
int64 ans;

void form() {
    for (int n=1;n<=100;n++) {
        for (int p=n;p<=100;p++) {
            printf("(%d,%d): ",n,p);
            int m = 0, cnt = 0;
            for (int i=1;i<=p;i++)
                for (int j=1;j<=p;j++)
                    for (int k=1;k<=p;k++)
                        if (n%i%j%k%n > m) {
                            m = n%i%j%k%n;
                            cnt = 1;
                        } else if (n%i%j%k%n == m) {
                            cnt++;
                        }
            printf("M=%d,C=%d\n",m,cnt);
        }
    }
}

void solve() {
    // 当1<=n<=2，容易验证不管怎么做都好，M只能为0，所以答案就是p*p*p
    if (n<3) 
        ans = (int64)p * p * p;
    else {
        ans = 0;
        // 当n>3时，M=(n-1)/2，因为我们要让M达到最大，只需要用到下面三种方法即可
        // 1. 令i=n/2+1，那么n%i的值就是(n-1)/2，之后的j和k只需要取(n-1)/2+1...p即可保持M=(n-1)/2，方案总数为c1=(p-(n-1)/2)^2
        ans += (int64)(p-(n-1)/2) * (p-(n-1)/2);
        // 2. 令j=n/2+1，i取n+1...p, k取(n-1)/2+1...p, 那么M的值就是(n-1)/2，方案总数为c2=(p-(n-1)/2)*(p-n)
        ans += (int64)(p-(n-1)/2) * (p-n);
        // 3. 令k=(n/2)+1, i取n+1...p, k取n+1...p, 那么M的值就是(n-1)/2，方案总数为c3=(p-n)*(p-n)
        ans += (int64)(p-n) * (p-n);
    }
}

int main() {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    // form();
    scanf("%d", &T);
    for (;T;T--) {
        scanf("%d%d",&n,&p);
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}