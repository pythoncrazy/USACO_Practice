// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
using ll = long long;
#define pb push_back
#define endl '\n';
using namespace std;
constexpr auto n = 12;
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;

vl numbers;
vl teamcnt(4), teamsum(4);
ll ans = 99999999999;

ll elmax() {
    
    vl l = teamsum;
    ll temp = l[0];
    for (int i = 1; i < l.size(); ++i) {
        if (l[i] > temp) {
            temp = l[i];
        }
    }
    return temp;
}

ll elmin() {
    vl l = teamsum;
    ll temp = l[0];
    for (int i = 1; i < l.size(); ++i) {
        if (l[i] < temp) {
            temp = l[i];
        }
    }
    return temp;
}

void updateresult() {
    ll maxel = elmax();
    ll minel = elmin();
    if (maxel - minel < ans) { ans = maxel - minel; }
}

void go(int i) {
    if (i >= n) {
        updateresult();
        return;
    }
    for (int j = 0; j < 4; ++j) {
        if (teamcnt[j] < 3) {
            teamcnt[j]++;
            teamsum[j] += numbers[i];
            
            go(i + 1);
            teamcnt[j]--;
            teamsum[j] -= numbers[i];
        }
    }
}


void solve() {
    ll g;
    vl a;
    for (int i = 0; i < n; ++i) {
        cin >> g;
        numbers.push_back(g);
    }
    go(0);
    cout << ans;
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
