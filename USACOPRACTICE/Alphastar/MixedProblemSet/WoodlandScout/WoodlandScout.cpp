// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
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
vl beads;
ll n, l;
ll ans;
bool test(ll index) {
	ll g = 0;
	for (int i = 0; i < index; ++i) {
		g = 2*(index - i)+i;
		if(g<l){
			if (beads[i] != beads[g]) {
				return false;
			}
		}
	}
	return true;
}


int main()
{
	cin >> n >> l;
	ll x;
	beads.resize(l+1);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		beads[x] = 1;
	}
	for (int i = 1; i < l; ++i) {
		if (test(i)) { ++ans; cout << i << endl; }
	}
	cout << ans << endl;
}
