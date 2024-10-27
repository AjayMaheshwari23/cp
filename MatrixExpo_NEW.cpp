#include "bits/stdc++.h"
using namespace std;

#define ll long long

const ll M = 1e9+7;

class Matrix {
    
public:
    ll n;
    ll m;
    vector< vector<ll> > v;
    
    Matrix(ll n,ll m) : n(n), m(m) {
        v.resize(n, vector<ll> (m));
    }
    
    Matrix(vector<vector<ll>> copy) {
        n = copy.size();
        m = copy[0].size();
        v.resize(n, vector<ll> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) v[i][j] = copy[i][j];
        }
    }
    
    Matrix(Matrix *copy) {
        int n = copy->n;
        int m = copy->m;
        v.resize(n, vector<ll> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) v[i][j] = copy->v[i][j];
        }
    }
    
    
    Matrix operator* (const Matrix &other) {
        assert(this->m == other.n);  // can we ?
        
        vector<vector<ll>> ans(n, vector<ll>(other.m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int col = 0; col < other.m; col++) {
                int matIJ = 0;
                for (int j = 0; j < m; j++) {
                    matIJ = ( matIJ %M + ( v[i][j] * other.v[j][col] ) %M ) %M;
                    matIJ %= M;
                    
                    matIJ += M;
                    matIJ %= M;
                }
                ans[i][col] = matIJ;
            }
        }
        
        return Matrix(ans);
    }
    
    void print() {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout << v[i][j] << " "; cout << "\n";
        }
    }
};


int main()
{
    
}

