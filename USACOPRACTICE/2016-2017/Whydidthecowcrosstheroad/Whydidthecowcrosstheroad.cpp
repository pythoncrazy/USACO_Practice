#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
//#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;
#pragma warning(disable : 4996)
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


vl psum(const vl& a) {
    vl psum(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}
*/

void solve() {
    ll c, n;
    cin >> c >> n;
    vl chickens;
    pll temp;
    vpll cows;
    ll x,y;
    for (int i = 0; i < c; ++i) {
        cin >> x;
        chickens.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        temp.first = x;
        temp.second = y;
        cows.push_back(temp);
    }
    ll ans = 0;
    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end());
    
    for (int i = 0; i < n; ++i) {
        ll a = cows[i].first;
        ll b = cows[i].second;
        auto first = lower_bound(chickens.begin(), chickens.end(), a);
        auto second = lower_bound(chickens.begin(), chickens.end(), b);
        int beg = first - chickens.begin();
        int sec = second - chickens.begin();
        //cout << beg << " " << sec << " " << a << " " << b<<" " <<chickens.size()<< endl;

        if (beg< c and a <= chickens[beg] and chickens[beg]<= b) {
            ans++;
            chickens.erase(chickens.begin() + beg);
            --c;
        }
        else if ( sec<c and a <= chickens[sec] and chickens[sec] <= b) {
            ans++;
            chickens.erase(chickens.begin() + sec);
            --c;
        }
    }
    cout << ans << endl;
}



int main()
{
    
    freopen("helpcross.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("helpcross.out", "w", stdout);
    
    int t;
    //cin >> t;
    t = 1;
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