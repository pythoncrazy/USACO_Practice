// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005




void solve() {
    int n, ans = 0; cin >> n;
    vector<string> a;
    string b, c, ccss, sscc,ss,cc,j;
    for (int i = 0; i < n; ++i) {
        cin >> b >> c;
        a.push_back(b.substr(0, 2)+c);
        ans += count(a.begin(), a.end(), c + b.substr(0, 2));
    }
    /*
    sort(a.begin(), a.end());
    for (int i = 0; i < n;++i) {
        j = a[i];
        ss = j.substr(0, 2);;
        cc = j.substr(2,4);
        if (ss == cc) {
            break;
        }
        ccss = cc + ss;
        ans += upper_bound(a.begin() + i, a.end(), ccss) - lower_bound(a.begin() + i, a.end(), ccss);
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
