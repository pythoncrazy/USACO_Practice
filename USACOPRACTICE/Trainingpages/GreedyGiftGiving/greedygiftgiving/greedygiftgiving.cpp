/*
ID: pinakpa1
TASK: gift1
LANG: C++
*/
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
    int np; cin >> np;
    string name, int money=0;
    string abc;
    pair<string, int> names;
    vector<pair<string,int>> people;
    for (int i = 0; i < np; ++i) {
        cin >> name;
        names.first = name;
        names.second = 0;
    }
    ll amount, peopletogiveto;
    while (!cin.eof()) {
        getline(cin,name);
        
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
