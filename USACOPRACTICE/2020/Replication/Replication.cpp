#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
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


const ll N = 3232;

ll n, m, k, q, x, y, z, seen[N][N], par[N][N];

vector<ll> G1[N];

map<pair<pair<ll, ll>, ll>, bool> A;

void solve()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		G1[x].push_back(y);
		G1[y].push_back(x);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y >> z;

		A[{ {x, y}, z}] = 1;
	}

	queue<pair<ll, ll>> q;
	q.push({ 1, 1 });
	seen[1][1] = 1;

	ll v, p;
	while (q.size())
	{
		auto b = q.front(); q.pop();

		p = b.first; v = b.second;

		if (v == n) break;

		for (ll u : G1[v])
		{
			if (seen[v][u] || A[{b, u}]) continue;

			seen[v][u] = 1;
			par[v][u] = p;
			q.push({ v, u });
		}
	}

	if (v != n)
	{
		cout << -1;
		return;
	}

	vector<ll> ans;
	pair<ll, ll> b = { p, v };
	while (b.second != 1)
	{
		ans.pb(b.second);
		b = { par[b.first][b.second], b.first };
	}
	ans.push_back(1);

	reverse(ans.begin(),ans.end());

	cout << ans.size() - 1 << endl;
	for (ll v : ans) cout << v << " ";
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