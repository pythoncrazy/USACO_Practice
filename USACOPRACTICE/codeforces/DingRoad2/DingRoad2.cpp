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

bool intersects(int l1, int r1, int l2, int r2) {
	return !(
		(l1 <= l2 && r1 >= r2) ||
		(l2 <= l1 && r2 >= r1) ||
		(l1 >= r2 && l1 >= l2) ||
		(r1 <= l2 && r1 <= r2) ||
		(r2 <= r1 && l1 <= l2 && r2 <= l2)
		);
}
string ans;
void dfs(int v, int color, vl& c, vll& g) {
	if (c[v] != -1 && c[v] != color)
		ans = "Impossible";
	else if (c[v] == -1) {
		c[v] = color;
		for (auto u : g[v])
			dfs(u, 1 - color, c, g);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vll g(m, vl{});
	vpll e{};
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		int x = min(a, b);
		int y = max(b, a);
		for (int j = 0; j < e.size(); ++j) {
			if (intersects(x, y, e[j].first, e[j].second)) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		e.push_back({ x,y });
	}
	vl c(m, -1);
	for (int i = 0; i < m and ans != "Impossible"; ++i) {
		if (c[i] == -1) {
			dfs(i, 0, c, g);
		}
	}
	if (ans != "Impossible") {
		for (int i = 0; i < m; ++i) {
			if (c[i] == 0) {
				ans.push_back('i');
			}
			else {
				ans.push_back('o');
			}
		}
	}
	cout << ans << endl;
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