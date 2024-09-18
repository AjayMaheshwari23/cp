#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int mn;
    int mnCnt;
    
    Node(int mn,int mnCnt){
        this->mn = mn;
        this->mnCnt = mnCnt;
    }
    
    Node(){}
};

const int N = 2e5 + 10;
Node ar[4*N+2];
vector<int> v(N);
vector<int> pending(4*N+2,0);

/* --------------------------------------- SOLVE -----------------------------------------*/

void combine(int cur) {
    
    int i1 = 2 * cur + 1;
    int i2 = 2 * cur + 2;
    
    if( ar[i1].mn == ar[i2].mn )
    {
        ar[cur].mn = ar[i1].mn;
        ar[cur].mnCnt = ar[i1].mnCnt + ar[i2].mnCnt;
        
    }else
    {
        if( ar[i1].mn < ar[i2].mn ) {
            ar[cur] = ar[i1];
        }else {
            ar[cur] = ar[i2];
        }
    }
}

void push(int cur)
{
    pending[2*cur+1] += pending[cur];
    pending[2*cur+2] += pending[cur];
}

void apply(int cur)
{
    ar[cur].mn += pending[cur];
    pending[cur] = 0;
}

void build_tree( int cur ,  int l ,int r)
{
    if(l==r)
    {
        ar[cur] = Node(v[l], 1);
        return;
    }
    int md = (l+r)/2 ;
    build_tree(2*cur+1, l, md) ;
    build_tree(2*cur+2, md+1, r) ;
    combine(cur);
}

int query(int l ,int r, int s, int e , int cur)
{
    if(s>e || s>r || e<l) return 0;
    
    if(s!=e) push(cur);
    apply(cur);
    
    if(s>=l && e<=r) {
        return (ar[cur].mn == 0 ? ar[cur].mnCnt : 0 );
    }
    
    int mid = (s+e)/2;
    int p1 = query(l, r, s, mid, 2*cur+1);
    int p2 = query(l, r,mid+1,e, 2*cur+2);
    return p1+p2;
}

// Point Update on something
void Reset(int l ,int r, int idx,int cur)
{
    if(idx>r || idx<l) return;
    
    if(l!=r) push(cur);
    apply(cur);
    
    
    if(idx == l && idx == r ) {
        // RESETTED
        ar[cur].mn = 0;
        ar[cur].mnCnt = 1;
        return;
    }
    
    int mid = (l+r)/2;
    if(idx <= mid) Reset(l,mid, idx,2*cur+1);
    else Reset(mid+1,r,idx,2*cur+2);
}

void update(int cur,int l,int r,int i,int j,int val)
{
    
    if(l!=r) push(cur);
    apply(cur);
    
    int mid=(l+r)/2;
    if(i>r or j<l) return;
    if(i<=l and j>=r)
    {
        // Update as per requirement
        ar[cur].mn += val;
        if(l!=r)
        {
            pending[2*cur+1] += val;
            pending[2*cur+2] += val;
        }
        
        // or
        /*
         pending[cur] = val;
         if(l!=r) push(cur);
         apply(cur);
         */
        
        return;
    }
    update(2*cur+1,l,mid,i,j,val);
    update(2*cur+2,mid+1,r,i,j,val);
    combine(cur);
}

int main()
{
    // vi v(n+1,0); // 1 based
    // build_tree(0,1,n);
    // update(0,1,n, from, to, delta);
    // query(ql, qr, 1, n, 0);
}

