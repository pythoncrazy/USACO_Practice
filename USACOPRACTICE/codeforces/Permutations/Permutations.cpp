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

void solve() {
    int n;
    cin >> n;
    ll x;
    vl nums(n);
    ll maxs = 0;
    ll maxval = 0;
    vl cnt(10e5,0);
    vl ans(10e5);
    bool possible = true;
    ll maxele = 0;
    for (ll& i:nums) {
        cin >> i;
        if (i > maxele) {
            maxele = i;
        }
    }
    for (ll i = 0; i < nums.size();++i) {
        ll element = nums[i];
        ++cnt[element - 1];
        ans[i] = cnt[element-1];
        if (maxs < cnt[element - 1]) {
            maxs = cnt[element - 1];
            maxval = max(maxval,element);
        }
    }
    for (int i = maxele; i > 0; --i) {
        if (cnt[i] > cnt[i - 1]) {
            possible = false;
        }
    }
    if (!possible) {
        cout << -1;
    }
    else {
        cout << maxs << endl;
        for (ll j : ans) {
            if (j != 0) {
                cout << j << " ";
            }
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file