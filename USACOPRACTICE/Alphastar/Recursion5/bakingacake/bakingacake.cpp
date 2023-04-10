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
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;

vll m;
vl x;
vl total;
int v;
vl minr;
int g;
vl res;
void updateResult(int i) {

}
void go(int i) {
    if (i > res.size()) {
        return;
    }
    updateResult(i);
    for (int j = x[i - 1] + 1; j <= g; ++j) {
        x[i] = j;
        for (int k = 0; k < v; ++k) {
            total[k] += m[j][k];
        }
        go(i + 1);
        for (int k = 0; k < v; ++k) {
            total[k] -= m[j][k];
        }
    }
}

void solve() {
    cin >> v;
    int gh;
    for (int i = 0; i < v; ++i) {
        cin >> gh;
        minr.push_back(gh);
    }
    cin >> g;
    vl temp;
    for (int i = 0; i < g; ++i) {
        
        for (int j = 0; j < v; ++j) {
            cin >> gh;
            temp.push_back(gh);
        }
        m.push_back(temp);
    }
    x.resize(v + 1);
    x[0] = 0;
    for (int i = 0; i < g; ++i) {
        res.pb(i);
    }
    go(1);
    cout << res.size()<<" ";
    for (int i : res) {
        cout << i << " ";
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
