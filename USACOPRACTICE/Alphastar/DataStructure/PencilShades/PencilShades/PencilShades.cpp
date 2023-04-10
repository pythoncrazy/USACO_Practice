// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
using namespace std;


struct point {
    int x, val;
};



void solve() {
    int n; cin >> n;
    int a; string b;
    int pos=0;
    point p;
    vector<point> points(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (b == "R") {
            p.x = pos;
            p.val = 1;
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    int ans=0,pos=0;
    int aj; string ak;
    pair<int, int>p;
    vector<pair<int,int>> reg;
    for (int i = 0; i < n; ++i) {
        cin >> aj >> ak;
        if (ak == "R") {
            p = make_pair(pos, pos + aj);
            reg.push_back(p);
            pos += aj;
        }
        else{
            p = make_pair(pos-aj, pos);
            reg.push_back(p);
            pos -= aj;
        }
    }
    /*
    int left, right = reg[1].first;
    for (int i = 0; i < reg.size(); ++i) {
        if (reg[i].first >= right) {
            left = reg[i].first;
            right = reg[i].second;
        }
        else {
            ans += min(right, reg[i].second) - reg[i].first;
            left = min(right, reg[i].second);
            right = max(reg[i].second, right);
        }
    }
    */

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
