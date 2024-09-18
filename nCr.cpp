#include <bits/stdc++.h>
using namespace std;

#define ll long long

/* ------------- nCr ---------------- */

const int N = 1e5;
const int M = 1e9+7;

vector<int> fac(N,1),inV(N,1);

ll mypower(ll b,ll p,ll M)
{
    b%=M;
    ll ans=1;
    while(p)
    {
        if(p&1) ans=ans*b%M;
        b=b*b%M;
        p>>=1;
    }
    
    return ans;
}

ll nCr(ll n,ll r)
{
    if(r < 0 || n < r) return 0;
    int ans = fac[n];
    ans = (ans %M * inV[r] %M ) %M;
    ans = (ans %M * inV[n-r] %M ) %M;
    return ans;
}



int main()
{
    fac[0] = 1;
    for(int i=1;i<N;i++) fac[i] = (fac[i-1] %M * 1LL * i %M ) %M;

    inV[N-1] = mypower(fac[N-1], M-2, M);
    for(int i=N-1;i>=1;i--) inV[i-1] = (inV[i] %M * 1LL * i %M ) %M;

}

