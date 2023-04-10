#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
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

vpll ef[100007], eb[100007];
priority_queue<pll, vpll, greater<pll> > pq;
int df[1007], db[1007];


void Dijkstra(int n, int s, int d[], vector<pll> e[]) {
    memset(d + 1, 0x3f, sizeof(int) * n);
    pq.push(make_pair(d[s] = 0, s));
    while (!pq.empty()) {
        int u, v, c, m;
        m = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (m > d[u]) {
            continue;
        }

        for (vector<pll>::iterator it = e[u].begin(); it != e[u].end(); ++it) {
            const pll& edge = *it;
            v = edge.first;
            c = edge.second;
            int t = d[u] + c;
            if (t < d[v]) {
                pq.push(make_pair(d[v] = t, v));
            }
        }
    }
}

int main() {
    int n, m, x;
    int u, v, c;
    cin >> n >> m >> x;
    while (m--) {
        cin >> u >> v >> c;
        ef[u].push_back(make_pair(v, c));
        eb[v].push_back(make_pair(u, c));
    }
    Dijkstra(n, x, df, ef);
    Dijkstra(n, x, db, eb);
    int ans = 0;
    for (u = 1; u <= n; ++u) {
        ans = max(ans, df[u] + db[u]);
    }
    cout << ans << endl;
    return 0;
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