#include <bits/stdc++.h>
using namespace std;

class node
{
    
public:
    int sum;
    int mx;
    int mn;
    node(int x,int y,int z) : sum(x),mx(y),mn(z) {}
    
    node() {
        sum = 0;
        mx = LONG_LONG_MIN;
        mn = LONG_LONG_MAX;
    }
};

node mergelogic(node &a,node &b)
{
    node ans;
    ans.mx = max(a.mx , b.mx);
    ans.mn = min(a.mn , b.mn);
    ans.sum = a.sum + b.sum;
    return ans;
}

node neutral;

class SegmentTree
{
    
public:
    int size;
    vector< node > tree;
    vector<int> v;
    
    SegmentTree(int _size,vector<int> _v) : size(_size) {
        tree.resize(4*_size);
        v = _v;
    };
    
    node base(int idx) {
        return node(v[idx],v[idx],v[idx]);
    }
    
    void build(int cur,int l,int r)
    {
        if(l==r)
        {
            tree[cur] = base(l);
            return;
        }
        
        int mid = (l+r)/2;
        build(2*cur,    l     , mid);
        build(2*cur+1 , mid+1 , r  );
        tree[cur] = mergelogic( tree[2*cur] , tree[2*cur+1] );
    }
    
    void update(int cur,int l,int r,int idx,int delta)
    {
        /* no intersection */
        if( idx<l || idx>r ) return;
        
        /* l==r==idx */
        if( l==idx && r==idx )
        {
            updateNode(cur,delta);
            return;
        }
        int mid = (l+r)/2;
        update(2*cur,    l     , mid, idx , delta);
        update(2*cur+1 , mid+1 , r  , idx , delta);
        tree[cur] = mergelogic( tree[2*cur] , tree[2*cur+1] );
    }
    
    node query(int cur,int l,int r,int lq,int rq)
    {
        /* no intersection */
        if( rq<l || lq > r ) {
            return neutral;
        }
        
        /* query range ke andar */
        if( lq<=l && r<=rq ) return tree[cur];
        
        int mid = (l+r)/2;
        node lft = query(2*cur, l, mid, lq, rq);
        node rgt = query(2*cur+1, mid+1, r, lq, rq);
        node ans = mergelogic( lft,rgt);
        return ans;
        
    }
    
    void updateNode(int cur,int val)        // Depends on how to modify
    {
        tree[cur].mx = tree[cur].mn = val;
        tree[cur].sum += val;
    }
    
};

int main()
{
    SegmentTree st(n, v);

    int cur = 1; // resposible for 0 to n-1
    int resl = 0 , resr = n-1;

    st.build(cur,resl,resr);
    node ret = st.query(cur,resl,resr, l, r);
    st.update(cur,resl,resr, , );

}

