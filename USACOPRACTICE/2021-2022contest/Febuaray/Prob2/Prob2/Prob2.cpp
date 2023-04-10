// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#include <unordered_map>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
#define sz(x) (int)size(x)
using vl = vector<ll>;

int LCS(vl& firstArr,
    vl& secondArr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < firstArr.size(); i++) {
        mp[firstArr[i]] = i + 1;
    }
    vector<int> tempArr;
    for (int i = 0; i < secondArr.size(); i++) {
        if (mp.find(secondArr[i]) != mp.end()) {

            tempArr.push_back(mp[secondArr[i]]);
        }
    }
    vector<int> tail;

    tail.push_back(tempArr[0]);

    for (int i = 0; i < tempArr.size(); i++) {

        if (tempArr[i] > tail.back())
            tail.push_back(tempArr[i]);

        else if (tempArr[i] < tail[0])
            tail[0] = tempArr[i];

        else {
            auto it = lower_bound(tail.begin(),
                tail.end(),
                tempArr[i]);
            *it = tempArr[i];
        }
    }
    return (int)tail.size();
}
void solve() {
    int n, k; cin >> n; vl a; vl b;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k; a.push_back(k);
    }
    for (int i = 0; i < n; ++i) {
        cin >> k; b.push_back(k);
    }
        cout << n - LCS(a, b);
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
