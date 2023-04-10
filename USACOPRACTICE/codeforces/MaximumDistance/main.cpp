#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/
/*
Below code calculates the prefix sum vector using the following notation:
vl a(N);
for (ll& x: a)
	cin >> x;
vl p = psum(a);
where p is the prefix sum vector

*/
ll dist(ll x1,ll y1,ll x2,ll y2){
    ll x = (x2-x1)*(x2-x1);
    ll y = (y2-y1) * (y2-y1);
    return (x+y);
}

void solve() {
    int n;
    cin>>n;
    vpll coord(n);
    ll x,y;
    for(ll i =0; i<n;++i){
        cin>>x;
        coord[i].first = x;
    }
    for(ll i = 0; i<n;++i){
        cin>>y;
        coord[i].second=y;
    }
    ll ans = -1;
    for (ll i = 0; i<n;++i){
        ll x1 = coord[i].first;
        ll y1 = coord[i].second;
        for(ll j = 0; j<n;++j){
            ll x2 = coord[j].first;
            ll y2 = coord[j].second;
            ll distance = dist(x1,y1,x2,y2);
            ans = max(distance,ans);
        }
    }
    cout<<ans<<endl;
}



int main()
{
    int t = 1;
    //cin >> t;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
