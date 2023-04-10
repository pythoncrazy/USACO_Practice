#include <bits/stdc++.h>
#include <unordered_map>
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
    int res = 0;
    string s = "abbca";
    map<char, vector<int>> all_indexes;
    for (int i = 0; i < s.length(); ++i)
        all_indexes[s[i]].push_back(i);

    int sum = 0;
    for (auto p : all_indexes)
    {
        for (int i = 0; i < p.second.size(); ++i)
        {
            int left = (i == 0) ? p.second[i] + 1 : p.second[i] - p.second[i - 1];
            int right = (i == p.second.size() - 1) ? s.length() - p.second[i] : p.second[i + 1] - p.second[i];
            sum += left * right;
        }
    }
    cout<<sum;
}




int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}
