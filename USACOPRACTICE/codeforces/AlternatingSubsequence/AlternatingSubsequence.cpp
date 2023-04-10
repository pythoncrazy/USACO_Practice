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
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/



void solve() {
    ll n = 0, x = 0, prev = 0;
    cin >> n;
    ll index = 0;
    vl max = { 0 };
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        if ((x > 0 and prev > 0) or (x < 0 and prev < 0)) {
            if (x > max[index]) {
                max[index] = x;
            }
            prev = x;
        }
        else {
            prev = x;
            max.pb(x);
            ++index;
        }
    }
    ll sum = 0;
    for (ll i : max) {
        sum += i;
    }
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    //t = 1;
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