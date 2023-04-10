// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define n 3
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vcc = vector<vector<char>>;
#define rep(i,n) for(int i=0;i<n;++i)
#pragma warning(disable : 4834)
bool numapinrow(char let,int row, vcc grid) {
    for (int i = 0; i < n; ++i) {
        if (grid[row][i] == let) {
            return true;
        }
    }
    return false;
}

bool numapincol(char let, int col, vcc grid) {
    for (int i = 0; i < n; ++i) {
        if (grid[i][col] == let) {
            return true;
        }
    }
    return false;
}

void printgrid(vcc grid) {
    rep(i, n) {
        rep(j, n) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void search(int x, int y, vcc grid) {
    vector<char> a = { 'A', 'B', 'C' };
    if (x >= n and y >= n) {
        printgrid(grid);
        return;
    }
    rep(i, n) {
        if (numapincol(a[i], x, grid) or numapincol(a[i], y, grid)) {
            continue;
        }
        else {
            grid[x][y] = a[i];
            if (y + 1 > n) { y = 0; ++x; }
            search(x, y + 1, grid);
            grid[x][y] = ' ';
        }
    }
}

void solve() {
    vcc grid = { {'A',' ',' '},{'A',' ',' '} ,{' ',' ',' '}};
    cout << boolalpha;
    search(0, 0, grid);
    printgrid(grid);
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
