#include<iostream>
using namespace std;

typedef long long int64;

const int maxm = 10000000;
const int maxn = 50000;
const int con[3]={5,7,11};
bool a[maxm];
int p[maxn],seq[maxn];
int T,n,totalPrime;

void calculateFirst50000prime() {
    totalPrime=0;
    for (int i=2;i<maxm && totalPrime<maxn;i++) {
        if (!a[i]) p[totalPrime++]=i;
        for (int j=0;j<totalPrime && (int64)p[j]*i<maxm;j++) {
            a[p[j]*i]=true;
            if (i%p[j]==0) break;
        }
    }

    // printf("%d %d\n",totalPrime, p[totalPrime - 1]);
    // for (int i=0;i<totalPrime;i++) printf("%d ",p[i]);printf("\n");
}

void solve() {
    // 首先肯定一点，N大于等于3，肯定有解
    // 构造法，先构造从小到大排序的素数p1,p2,...,pn
    // 之后令p1*2*z,p2*2*3,p3*3*5,p4*5*7,p5*7*11,p6*11*5,p7*5*7,...,p(n-1)*x*y,p(n)*y*z，其中x,y,z为5,7,11的其中一种，且互不相同
    for (int i=0;i<maxn;i++) seq[i]=p[i];
    for (int i=3;i<maxn;i++) seq[i]*=con[i%3]*con[(i+1)%3];
    seq[1]*=2*3;seq[2]*=3*5;
    // for (int i=0;i<maxn;i++) printf("%d ",p[i]);printf("\n");
}

int main() {
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    calculateFirst50000prime();
    solve();
    scanf("%d",&T);
    for (;T;T--) {
        scanf("%d",&n);
        seq[0]*=2*con[n%3];
        for (int i=0;i<n-1;i++) printf("%d ",seq[i]);printf("%d\n",seq[n-1]);
        seq[0]/=2*con[n%3]; // rollback
    }
    return 0;
}