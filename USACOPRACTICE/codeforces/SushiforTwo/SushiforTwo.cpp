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



void solve() {
    int n;
    cin >> n;
    ll prev = -1;
    vl prefix;
    ll temp = -1;
    ll cnt = -1;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp == prev) {
            prefix[cnt]++;
        }
        else {
            prev = temp;
            prefix.push_back(1);
            ++cnt;
        }
    }
    ll big =0;
    for (int i = 1; i < prefix.size(); ++i) {
        big = max(big,min(prefix[i - 1], prefix[i]));
    }
    cout << big*2<<endl;
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