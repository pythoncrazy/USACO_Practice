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
ll calories=0;
ll ans;
ll c, a;
ll sum;
vl x;
vl acorns;
void go(int i) {
    ans = max(ans, sum);
    if (i>a) {
        return;
    }
    for (int j = x[i - 1]; j < a; ++j) {
        x[i] = j;
        sum += acorns[j];
        if (sum <= c) {
            go(i + 1);
        }
        sum -= acorns[j];
    }
}

int main()
{
    
    cin >> c >> a;

    ll abc;
    x.resize(a + 1);
    for (int i = 0; i < a; ++i) {
        cin >> abc;
        acorns.push_back(abc);
    }
    x[0] = 0;
    go(1);
    cout << ans;
}