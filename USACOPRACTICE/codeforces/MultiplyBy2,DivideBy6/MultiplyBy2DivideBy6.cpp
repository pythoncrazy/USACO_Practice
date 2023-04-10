// Problem: B. Multiply by 2, divide by 6
// Contest: Codeforces - Codeforces Round #653 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1374/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	ll n = 0;
	cin >> n;
	
	ll bad = false;
	ll two_count = 0;
	ll three_count = 0;
	ll ans = 0;
	
	while(n%2==0){
		n/=2;
		two_count++;
	}while(n%3==0){
		n/=3;
		three_count++;
	}
	if(n!=1){
		bad=true;
	}
	if(two_count>three_count){
		bad = true;
	}else{
		
		ans += (three_count - two_count);
		ans += three_count;
	}
	if(!bad){
		cout<<ans<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	
}



int main()
{
    int t = 1;
    cin >> t;
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
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