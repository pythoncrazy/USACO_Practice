#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)
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
using namespace std;

vector<int> adj[100000], farm(100000), comp(100000);

bool visited[100000];

int curComp;

// Generate the connected components using DFS

void DFS(int curCow) {
	if (visited[curCow]) {
		return;
	}
	comp[curCow] = curComp;
	visited[curCow] = true;
	for (int adjCow : adj[curCow]) {
		if (farm[curCow] == farm[adjCow]) {
			DFS(adjCow);
		}
	}
}


void solve() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	string cows; 
	cin >> cows;
	for (int i = 0; i < n; i++) {
		farm[i] = (cows[i] == 'H');
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	curComp = 1;
	for (int i = 0; i < n; i++) {
		if (!comp[i]) {
			DFS(i);
			++curComp;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b; char c; cin >> a >> b >> c;
		int curType = (c == 'H');
		--a, --b;
		/* If the first condition is true then there will
			be both an 'H', and 'G' in the current path.
		   The latter condition checks if the current path consists of all "c"s.
		*/
		if ((comp[a] != comp[b]) || (farm[a] == curType)) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	cout << endl;
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