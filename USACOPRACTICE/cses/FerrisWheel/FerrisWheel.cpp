#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
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
	int n, x;
	cin >> n>> x;
	vl p(n);
	for (ll& x : p) {
		cin >> x;
	}
	sort(p.begin(), p.end());
	ll index = 0;
	ll gond = 0;
	while (index <= n - 1) {
		if (index < n - 1) {
			if (p[index] + p[index + 1] <= x) {
				++gond;
				index += 2;
			}
			else {
				++gond;
				++index;
			}
		}
		else if (index == n - 1) {
			++gond;
			++index;
		}
	}
	cout << gond << endl;
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