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
    ll n; cin >> n;
    vl a(n,0);
    ll x;
    for (ll& i : a) {
        cin >> i;
    }
    bool done = false;
    cin >> x;
    ll diff = a[0]-x;
    if (diff < 0) {
        if (!done) {
            cout << "NO" << endl;
        }
        done = true;
    }
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (diff < 0 or a[i] - x < 0) {
            if (!done) {
                cout << "NO" << endl;
            }
            done = true;
            continue;
        }
        if (diff == a[i] - x) {
            continue;
        }
        else if (x == 0) {
            continue;
        }
        else {
            if (!done){
                cout << "NO" << endl;
            }
            done = true;
            continue;
        }
        
    }
    if (!done) {
        cout << "YES" << endl;
    }
    
}



int main()
{
    int t;
    cin >> t;
    //t = 1;
    //ios_base::sync_with_stdio(false); 
    while (t--) { solve(); }
}