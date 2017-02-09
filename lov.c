//https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/innocent-swaps-and-his-emotions-1/

#include <stdio.h>
#define N 1000006
typedef long long ll;
const int M = 1e9 + 7;
ll F[N],Fi[N],p2[N];
long long modulo(long long a,long long b,long long c){
long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
while(b > 0){
if(b%2 == 1){
x=(x*y)%c;
}
y = (y*y)%c; // squaring the base
b /= 2;
}
return x%c;
}
void pre()
{   
    int i;
    F[0] = p2[0] = 1; 
    for(i=1;i<N;i++){
        F[i] = F[i - 1] * i % M;
        p2[i] = p2[i - 1] * 2 % M;
    }
    i=1000000;
    Fi[i] = modulo(F[i],M-2,M);
    for(i--;i>=0;i--){
        Fi[i] = Fi[i + 1] * (i + 1) % M;
    }
    
}
ll C(ll n,ll k){
    ll res;
    res = F[n] * Fi[k] % M;
    res = res * Fi[n - k] % M;
    return res;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    pre();
    while(T--)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        printf("%lld\n",C(n,k) * p2[k] % M);
    }
    return 0;
}
