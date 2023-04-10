// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int n, cnt = 0;
vector<int> x;

bool isvalid() {
    if (count(x.begin(), x.end(), 1) > n - count(x.begin(), x.end(), 1)) {
        return true;
    }
    return false;
}


void go(int c) {
    if (c >= n) {
        if (isvalid()) {
            for (int b : x) {
                cout << b;
            }
            cout << endl;
            ++cnt;
        }
        return;
    }
    x[c] = 0;
    go(c + 1);
    x[c] = 1;
    go(c + 1);
}

void solve() {
    cin >> n;
    x.resize(n);
    go(0);
    cout << cnt;
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}