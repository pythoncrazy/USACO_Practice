#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 100005
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;
vector <int> v[maxn];

ll ans = -1,n=0;
int dfs(int u, int p)
{
	int res = 0;
	for (auto& x : v[u]) if (x != p) res += dfs(x, u);
	ans += res % 2;
	return res + 1;
}


void solve() {
	cin >> n;
	if (n % 2 == 1) {
		cout << -1 << endl;
		return;
	}
	else {
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	dfs(1, 0); cout << ans << endl;
}



int main()
{
	int t = 1;
	//cin >> t;
	//ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
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