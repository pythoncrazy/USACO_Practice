// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 101

int row_num;
int col_num;
bool visited[maxn][maxn];  // keeps track of which nodes have been visited
int curr_size = 0;  // reset to 0 each time we start a new component

void floodfill(int r, int c, int color, vector<vector<int> >grid) {
    if (
        (r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
        || grid[r][c] != color  // wrong color
        || visited[r][c]  // already visited this square
        ) return;

    visited[r][c] = true; // mark current square as visited
    curr_size++; // increment the size for each square we visit

    // recursively call flood fill for neighboring squares
    floodfill(r, c + 1, color,grid);
    floodfill(r, c - 1, color,grid);
    floodfill(r - 1, c, color,grid);
    floodfill(r + 1, c, color,grid);
}

void solve() {
    int n,k;
    cin >> n >> k;
    string nums;
    cin >> nums;
    int g = nums.length();
    vector<vector<int> > grid(n,std::vector<int>(g));
    for (int i = 0; i <n-1; ++i) {
        
        for (int j = 0; j < nums.length(); j++) {
            grid[i][j] = nums[j];
        }
        cin >> nums;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g; j++) {
            if (!visited[i][j]) {
                curr_size = 0;

                floodfill(i, j, grid[i][j],grid);
            }
        }
    }
    for (int i = n-1; i >=0; --i) {
        for (int j = 0; j < g; j++) {
            cout << grid[i][j]<<" ";
        }
        cout << endl;
    }
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
