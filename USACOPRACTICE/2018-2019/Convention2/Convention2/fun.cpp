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
    int n, m = -1; cin >> n;
    vector<vector<int>> cows;
    vector<int> lmnop(3);
    vector<vector<int>> wait;
    int next = 1;
    ll ans = 0;
    ll finished;
    int abc, bcd;
    for (int i = 0; i < n; ++i) {
        cin >> abc >> bcd;
        if (bcd > m) { m = bcd; }
        lmnop[0] = abc; lmnop[2] = bcd; lmnop[1] = i;
        cows.push_back(lmnop);
    }
    sort(cows.begin(), cows.end());
    finished = cows[0][0] + cows[0][2];
    m = 0;
    while (next < n or wait.size()> 0) {
        while (next < n and cows[next][0] <= finished) {
            wait.push_back({ cows[next][1],next });
            ++next;
        }
        if (next < n and wait.size() == 0) {
            finished = cows[next][0] + cows[next][2]; ++next;
        }
        else if (wait.size() > 0) {
            for (int i = 0; i < wait.size(); ++i) {
                if (finished - cows[i][0] > ans) { m = i; }
                ans = max(ans, finished - cows[i][0]);

            }
            wait.erase(wait.begin() + m);
        }
    }
    cout << ans << endl;
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