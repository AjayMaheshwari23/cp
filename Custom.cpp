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
