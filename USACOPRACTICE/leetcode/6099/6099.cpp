#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#define ld long double
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
    string s = "1001010";
    bitset<1001> b(s);


































































    //string rev (s.rbegin(), s.rend());
    /*
    long long int k = 5;
    int curr = 0;
    long long int total = 0;
    int best = -1;
    int cur = 0;
    for (int start = 0; start < s.size(); ++start) {
        int curr = start;
        cur = 0;
        total = 0;
        
        while (total <= k and curr<s.size()) {
            if (s[curr] == '0') {
                cur += 1;
                curr++;
                continue;

            }
            else if (total == k) {
                if (s[curr] == '1') {
                    curr++;
                    continue;
                  
                }
            }
            else {vnn 
                total += pow(2, curr - start);
                curr++;
                if (total <= k) { cur++; }
            }
        }
        best = max(cur, best);
    }
    cout << best << endl;
    */
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}