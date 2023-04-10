#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define endl '\n'
using namespace std;
#define maxn 500005
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/

void solve() {
    ll n;
    cin >> n;
    vpll badges;
    ll x;
    pair<ll, ll> y;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        y.first = x-1;
        y.second = 0;
        badges.push_back(y);
    }
    ll index;
    for (int p = 0; p < n; ++p) {
        index = p;
        while (badges[index].second < 2) {
            badges[index].second += 1;
            index = badges[index].first;
        }
        cout << index+1 << endl;
        for (int i = 0; i < n; ++i) {
            badges[i].second = 0;
        }
    }
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}