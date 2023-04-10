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
vl psum(const vl& a) {
    vl psum(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}



void solve() {
    ll n,k;
    cin>>n>>k;
    vl diamonds(n);
    for(ll &x:diamonds){
        cin>>x;
    }
    sort(diamonds.begin(),diamonds.end());
    ll ans = -1;
    for(ll i=0;i<n;++i){
        ll mi = diamonds[i]-k;
        ll ma = diamonds[i]+k;
        ll leftbound = -1;
        ll cnt = 0;
        for(ll j = 0;j<n;++j){
            if(diamonds[j]<mi or diamonds[j]>ma){
                continue;
            }else if (mi<=diamonds[j]<=ma){
                if(leftbound==-1){
                    leftbound=i;
                }
                cnt = j-leftbound+1;
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<endl;
}



int main()
{
    int t = 1;
    //cin >> t;
    //ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    freopen("diamond.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("diamond.out", "w", stdout);
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
