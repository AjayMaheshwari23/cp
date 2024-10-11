// Custom Sorted Set 

auto cmp = [](string a, string b)   // PASS BY REFERENCE 
{
    return ...
};

set< int , decltype(cmp) > s(cmp);


/*----------------------------------------------------*/


// Custom Sorted priority Queue

struct cmp
{
  bool operator()( string & a , string &b )
  {
    return ...
  }
}


priority_queue< string  , vector<string> , cmp > pq;


/*-------------------- SOMETHING STRANGE WITH SET --------------------------------*/

// For : 
#include "bits/stdc++.h"
using namespace std;

#define pii pair<int,int>

auto Compare = [](const pii &lhs, const pii &rhs) {
    if( lhs.first == rhs.first ) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
};

int main()
{
    set< pair<int,int> , decltype(Compare) > test;
    test.insert({1,100});
    test.insert({1,200});
    cout << test.size() << "\n";
}

// Output : 2 


/* ---- BUT ---- */


// For : 
#include "bits/stdc++.h"
using namespace std;

#define pii pair<int,int>

auto Compare = [](const pii &lhs, const pii &rhs) {
    // if( lhs.first == rhs.first ) return lhs.second < rhs.second; /* ===== Commented OUT ===== */
    return lhs.first < rhs.first;
};

int main()
{
    set< pair<int,int> , decltype(Compare) > test;
    test.insert({1,100});
    test.insert({1,200});
    cout << test.size() << "\n";
}

// Output : 1 
