#include <vector>
#include <algorithm>
#include <iostream>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 2000007
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
	int q[maxn][3];
	int a[maxn];
	int n, m, kk;
	cin >> n >> m >> kk;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> q[i][2] >> q[i][0] >> q[i][1];
	}while (kk--) {
		int que; cin >> que;
		for (int i = m - 1; i >= 0; --i) {
			if (q[i][0] > que or q[i][1] < que) {
				continue;
			}if (q[i][2] == 1) {
				if (que == q[i][0]) { 
					que = q[i][1];
				}
				else { 
					que--;

				}
			}
			else {
				que = q[i][1] + q[i][0] - que;
			}
		}
		cout << a[que]<<" ";
	}
}
int main()
{
	int t = 1;
	//cin >> t;
	ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
	while (t--) { solve(); }
}

/*

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int n,m,kk,a[N];
struct change{
	int l,r,t;
}q[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>q[i].t>>q[i].l>>q[i].r;
	while(kk--){
		int query;cin>>query;
		for(int i=m-1;i>=0;i--){
			if(q[i].l>query||q[i].r<query)continue;
			if(q[i].t==1){
				if(query==q[i].l)query=q[i].r;
				else query--;
			}
			else query=q[i].r+q[i].l-query;
		}
		cout<<a[query]<<' ';
	}
}

*/