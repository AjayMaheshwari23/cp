#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define pii pair<int,int>


int add(int x,int y,int mod) {
    x %= mod; y %= mod;
    
    x += y;
    x %= mod;
    
    if(x < 0) x += mod;
    return x;
}

int mul(int x,int y,int mod) {
    
    int z = (x %mod * 1LL * y %mod ) %mod;
    return z;
}

int mypower(int a , int b , int mod)
{
    int ans = 1 ;
    int nn = b ;
    if(nn<0) nn*=-1;
    while (nn>0)
    {
        if(nn%2==0)
        {
            a = (a%mod * 1LL * a%mod)%mod ;
            nn/=2;
        }else
        {
            ans = (ans%mod * 1LL * a%mod)%mod;
            nn--;
        }
    }
    if(b<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}

class Hashing {
  
private:
    const int N1 = 2e6 + 10;
    const int DEGREE = 1;
    int BASE = 65;
    vector< vector<int> > p;
    vector< vector<int> > inv;
    vector< vector<int> > preHash;

    vector< int > MODS = { 1000000009, 1000000007 };
    vector< int > BASES = { 65 };
    string s;
    
public:
    
    void preCalculate()
    {
        for(int j=0;j<DEGREE;j++)
        {
            int curM = MODS[j];
            
            p[0][j] = 1;
            for(int i=1;i<N1;i++) p[i][j] = mul(p[i-1][j], BASE, MODS[j] );

            int inv_mod = mypower(BASE, curM-2, curM);
            
            inv[0][j] = 1;
            for(int i=1;i<N1;i++)
            {
                inv[i][j] = mul( inv[i-1][j] , inv_mod, curM);
            }
        }
    }
    
    void build() {
        int n = s.length();
        for(int j=0;j<DEGREE;j++)
        {
            for(int i=0;i<n;i++)
            {
                preHash[i][j] =  add( (i-1 >= 0 ? preHash[i-1][j] : 0 ) , mul( p[i][j], s[i] - 'a' + 1, MODS[j] ), MODS[j] );
            }
        }
    }

    void randomise() {
        BASE = BASES[0];
    }
    
    Hashing(string &cur)
        : p(N1, vector<int>(DEGREE, 0)),
          inv(N1, vector<int>(DEGREE, 0)),
          preHash(N1, vector<int>(DEGREE, 0)),
          s(cur)
    {
        randomise();
        preCalculate();
        build();
    }
    
    vector<int> getHash(int i,int j)
    {
        vector<int> hash;
        for(int k=0;k<DEGREE;k++)
        {
            int ret = add( preHash[j][k] , ( i-1 >= 0 ?  -1 * preHash[i-1][k] : 0) , MODS[k] );
            hash.push_back( mul( ret , inv[i][k], MODS[k] ) );
        }
        return hash;
    }
};


signed main()
{
    string s1 = "abcd";
    string s2 = "bcda";
    Hashing* h1 = new Hashing(s1);
    Hashing* h2 = new Hashing(s2);
    
    int n = s1.length();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout << "Hash for [" << i << ", " << j << "] = " << h1->getHash(i, j)[0] << "\n";
        }
    }
    
    cout << " -------- \n";
    
    n = s2.length();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout << "Hash for [" << i << ", " << j << "] = " << h2->getHash(i, j)[0] << "\n";
        }
    }
}
