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
    ifstream fin("convention2.in");
    int n, m = -1; fin >> n;
    vector<pair<int,pair<int,int>>> cows;
    pair<int, pair<int, int>> lmnop;
    set<pair<int,int>> wait;
    int next = 1;
    ll ans = 0;
    ll finished;
    int abc, bcd;
    
    for (int i = 0; i < n; ++i) {
        fin >> abc >> bcd;
        if (bcd > m) { m = bcd; }
        lmnop.first = abc; lmnop.second.second = bcd; lmnop.second.first = i;
        cows.push_back(lmnop);
    }
    sort(cows.begin(), cows.end());
    finished = cows[0].first + cows[0].second.second;
    m = 0;
    while (next < n or wait.size()> 0) {
        while (next < n and cows[next].first <= finished) {
            wait.insert({ cows[next].second.first,next });
            ++next;
        }
        if (next < n and wait.size() == 0) {
            finished = cows[next].first + cows[next].second.second; ++next;
        }
        else if (wait.size() > 0) {
            set<pair<int, int>>::iterator senior = wait.begin();
            ans = max(ans, finished - cows[senior->second].first);
            finished += cows[senior->second].second.second;
            wait.erase(senior);
        }
    }
    ofstream fout("convention2.out");
    fout << ans<<endl;
}

/*
void solve() {
    int n; cin >> n;
    int m = -1;
    vector<vector<int>> cows, wait;
    vector<int> lmnop(4);
    priority_queue<vector<int>> line;
    priority_queue<vector<int>> linetwo;
    pair<int, int> cowtime;
    int abc, bcd;
    for (int i = 0; i < n; ++i) {
        cin >> abc >> bcd;
        if (bcd > m) { m = bcd; }
        lmnop[0] = abc; lmnop[2] = bcd; lmnop[1] = i;
        cows.push_back(lmnop);
    }
    sort(cows.begin(), cows.end());
    cowtime.first = cows[0][1];
    cowtime.second = cows[0][2];
    for (int i = cows[0][0]; i < m; ++i) {
        for (int j = 0; j < cows.size(); ++j) {
            if (cows[j][0] == i) {
                line.push(cows[j]);
            }
        }
        linetwo = line;
        if (cowtime.second != 0) {
            --cowtime.second;
            if (!line.empty()) {
                for (int i = 0; i < n; ++i) {
                    
                }
            }
        }
        else {
            if (!line.empty()) {
                cowtime.first = line.top()[1]; cowtime.second = line.top()[2];
                line.pop();
            }
        }
    }
}
*/

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