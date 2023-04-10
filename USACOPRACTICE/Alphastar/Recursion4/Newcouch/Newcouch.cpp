// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int n;
vector<int> num;

bool isvalid(int a, int b) {
    while (a > 0 and b > 0) {
        int digita = a % 10;
        int digitb = b % 10;
        if (digita + digitb > 9) {
            return false;
        }
        a /= 10;
        b /= 10;

    }
    return true;
}


int best = 0;
void go(int x, int sum, int count)
{
    best=max(best, count);
    if (x >= n || count + n - x <= best) return;
    if (isvalid(sum, num[x]))
       go(x + 1, sum + num[x], count + 1);
    go(x + 1, sum, count);
}


void solve() {
    cin >> n;
    int c;
    for (int i = 0; i < n;++i) {
        cin >> c;
        num.push_back(c);
    }
    go(0, 0,0);
    cout << best;
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
