#include <vector>
#include <algorithm>
#include <iostream>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 100007
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
    ll n; cin >> n;
    vl s(n);
    for (ll& x : s) {
        cin >> x;
    }
    sort(s.begin(), s.end());
    /*
    for (ll x : s) {
        cout << x<<" ";
    }
    //cout << endl;
    //cout << lower_bound(s.begin(), s.end(), 9/2)-s.begin()<<endl;
    */
    ll ans = n;
    ll cur = 0;
    for (int start = 0; start <n/2; ++start) {
        cur = lower_bound(s.begin()+n/2,s.end(),2*s[start])-s.begin();
        ll curr = upper_bound(s.begin() + n / 2, s.end(), 2 * s[start]) - s.begin();
        if (cur<n and s[start] * 2 <= s[cur]) {
            --ans;
            s[cur] = -1;
        }else if(curr < n and s[start] * 2 <= s[curr]) {
            --ans;
            s[curr] = -1;
        }
            
    }
    cout << ans << endl;
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}