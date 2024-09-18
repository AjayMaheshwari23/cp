#include <bits/stdc++.h>
using namespace std;

//const int N = 20 , LOG = 5;
const int N = 2e5+10 , LOG = 20;
int par[N][LOG],t_int[N],t_out[N] , tym = 0 ;
vector<int> adj[N] , vis(N,0),depth(N,0) ;

void preprocess(int node,int p)
{
    par[node][0]=p;
    for(int j=1;j<LOG;j++)
    {
        if(par[node][j-1] == -1) par[node][j] = -1;
        else
        {
            par[node][j] = par[par[node][j-1]][j-1];
        }
    }
}

void dfs(int node , int p)
{
    vis[node]=1;
    t_int[node] = ++tym;
    if(p!=-1) depth[node]=1+depth[p];
    preprocess(node,p);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it, node);
        }
    }
    t_out[node]=++tym;
}

bool is_anc_of(int a, int b) { if(a==-1) return true; return (t_int[a]<=t_int[b] && t_out[a]>=t_out[b]); }

int kth_anc(int node,int k)
{
    if(k==0) return node;
    if(k==1) return par[node][0];
    for(int i=LOG-1;i>=0;i--)
    {
        if( (k & (1 << i)))
        {
            node = par[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}


int lca(int a, int b)
{
    if(is_anc_of(a, b)) return a;
    if(is_anc_of(b, a)) return b;
    for(int i =LOG-1;i>=0;i--)
    {
        int node = par[a][i];
        if( node != -1 && !is_anc_of(node, b))
        {
            a=node;
        }
    }
    return par[a][0];
}


int main()
{
    
}

