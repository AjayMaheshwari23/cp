#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 1e5 + 5;
int par[N];
int siz[N];
int property[N];
// vector<vector<int>> vec(N);
vector<int> score(N,0);

void make(int v)
{
    par[v]=v;
    siz[v]=1;
    property[v] = v;             // ?
    // vec[v].push_back(v);
}

int getpar(int v)
{
    if(v==par[v]) return v;
    return par[v] = getpar(par[v]) ;
}

void addbtoa(int a,int b)
{
    a = getpar(a) ;
    b = getpar(b) ;
    if(a!=b)
    {
        if(siz[a] < siz[b] ) swap(a,b);
        par[b] = a ;
        siz[a] += siz[b];
        property[a] = max( property[a], property[b] ); // query for property[getpar()] ?
        siz[b]=0;
        // if(!vec[b].empty()) for(auto it:vec[b]) vec[a].push_back(it);
        // vec[b].clear();
    }
}


int main()
{
    
}

