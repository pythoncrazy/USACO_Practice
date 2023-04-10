// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
#define sz(x) (int)size(x)
using vl = vector<ll>;

void solve() {
    int n; cin >> n;
    pair<int, int> coord;
    pair<int, int> pos;
    int mina = 1e9+1, minb = 1e9+1;
    vector<pair<ll, ll>> ins(n);
    int abc, bcd; cin >> abc >> bcd;
    coord.first = abc;
    coord.second = bcd;
    for (int i = 0; i < n; ++i) {
        cin >> abc >> bcd;
        ins[i].first = abc;
        ins[i].second = bcd;
        if (abc < mina) { mina = abc; }
        if (bcd < minb) { minb = bcd; }
    }
    sort(ins.begin(), ins.end());
    while (pos.first != coord.first and pos.second != coord.second and coord.second - pos.second >= minb and coord.first - pos.first >= mina) {
        
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
