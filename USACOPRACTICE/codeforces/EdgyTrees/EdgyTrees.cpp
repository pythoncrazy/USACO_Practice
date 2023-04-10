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
const ll MOD = 1e9 + 7;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;
int n, k, l, r, x, num, vis[maxn];
ll ans;
vector<int>G[maxn];
ll P(int x) {
	ll tmp = 1;
	for (int i = 1; i <= k; i++)
		(tmp *= x) %= MOD;
	return tmp;
}
void dfs(int x) {
	num++;
	vis[x] = 1;
	for (auto u : G[x])
		if (!vis[u]) dfs(u);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> l >> r >> x;
		if (x == 0) {
			G[l].push_back(r);
			G[r].push_back(l);
		}
	}
	ans = P(n);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			num = 0;
			dfs(i);
			ans = (ans - P(num) + MOD) % MOD;
		}
	cout << endl << ans;
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