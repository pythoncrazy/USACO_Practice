#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
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
    vl boxers(n);
    for (ll& i : boxers) {
        cin >> i;
    }
    ll ans = 0;
    ll previndex = 0;
    sort(boxers.begin(), boxers.end());
    boxers.push_back(boxers[n - 1]+2);
    if (boxers[0] > 1) {
        boxers[0]--;
    }
    for (int i = 1; i < n + 1; ++i) {
        if (boxers[i] > boxers[previndex] + 1 and boxers[i]>1) {
            boxers[i] -= 1;
            ++ans;
            previndex = i;
        }
        else if (boxers[i] > boxers[previndex]) {
            ++ans;
            previndex = i;
        }
        else if (boxers[i] == boxers[previndex]) {
            boxers[i] += 1;
            ++ans;
            previndex = i;
        }
        else {
            continue;
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