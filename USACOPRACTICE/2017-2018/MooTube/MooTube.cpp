#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 5005
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;

void dfs(vpll graph[],vector<bool>& visited, ll node, ll limit, ll& ans) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i].first] == false && graph[node][i].second >= limit) {
			ans++;
			dfs(graph, visited, graph[node][i].first, limit, ans);
		}
	}
}

void solve() {
	vpll graph[maxn];
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}

	//Dfs to search all videos with minimum relevance, output the ans along the way.
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		ll ans = 0;
		vector<bool> visited(n, false);
		dfs(graph, visited, b - 1, a, ans);
		cout << ans << "\n";
	}
}


int main()
{
	int t = 1;
	//cin >> t;
	ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
	
	freopen("mootube.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("mootube.out", "w", stdout);
	
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