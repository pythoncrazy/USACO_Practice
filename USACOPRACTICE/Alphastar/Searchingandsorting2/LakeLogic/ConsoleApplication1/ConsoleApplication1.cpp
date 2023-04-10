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
    int r, c,res=0,row2,col2;
    cin >> r >> c;
    int lake[51][51];
    for (int a_ = 0; a_ < r; ++a_) {
        for (int b_ = 0; b_ < c; ++b_) {
            cin >> lake[a_][b_];
        }
    }
    int rowD[4] = { -1, 0, 1, 1 };
    int colD[4] = { 1, 1, 1, 0 };
    for (int row = 0; row < r; ++row) {
        for (int col = 0; col < c; ++col) {
            if (lake[row][col] == 0) {
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                row2 = row + rowD[i];
                col2 = col + colD[i];
                if (0 <= row2 < r and 0 < col2 < c and lake[row][col] != lake[row2][col2]) {
                    continue;
                }
                res = max(res, lake[row][col]);
            }
        }
    }
    cout << res;
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
/*
For row=0 to R-1
    For col = 0 to C-1
        If (lake[row][col] == 0)
            Continue;
        //test each neighbour
        For i=0 to 3
            Row2 = row + rowD[i]
            Col2 = col + colD[i]
            If (row2, col2) not in the lake OR
                Lake[row][col] != lake[row2][col2])
                Continue
            Res = max(res, lake[row][col]
Output res



*/