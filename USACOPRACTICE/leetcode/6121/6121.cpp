#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
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

class Solution {
public:
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

#define ll long long
		vector<int> ans;
		for (auto x : queries) {
			ll k = x[0];
			ll trim = x[1];
			vector<pair<ll, ll>> numint(nums.size()); //first is the actual number, second is the number in the original vector
			for (int i = 0; i < nums.size(); ++i) {
				numint[i] = make_pair(stoll(nums[i].substr(nums[i].size() - trim)), i);
			}
			sort(numint.begin(), numint.end());
			ans.push_back(numint[k - 1].second);
		}
		return ans;
	}
};
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