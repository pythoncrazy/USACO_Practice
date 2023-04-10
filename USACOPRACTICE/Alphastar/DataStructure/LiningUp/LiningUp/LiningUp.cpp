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
    int n,c;
    cin >> n;
    vector<int> height;
    vector<int> height1(n);
    stack<int> h;

    for (int i = 0; i < n; ++i) {
        cin >> c;
        height.pb(c);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!h.empty() && h.top() <= height[i]) {
            h.pop();
        }
        if (h.empty()) {
            height1[i] = -1;
        }
        else {
            auto it = find(height.begin()+i, height.end(), h.top());
            int index = it - height.begin();
            height1[i] = index;
        }

        h.push(height[i]);
    }

    for (int i = 0; i < n; i++) {
        cout<< height1[i]+1 << endl;
    }
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) {solve();}
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
