// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/

bool visited[5][5];
vector<vector<char>> grid;
vector<char> temp;
char abc;
string word;
vector<string> dict;
bool found;
int ans = 0;
vector<int> rowDir = {-1,0,1,-1,1,-1,0,1 };
vector<int> colDir = {-1,-1,-1,0,0,1,1,1};
bool valid(int row2,int col2,int i) {
    if (row2<0 or row2>=5 or col2<0 or col2>=5) {
        return false;
    }
    if ((visited[row2][col2] == true) or (grid[row2][col2] != word[i + 1])) {
        return false;
    }
    return true;
}

void go(int row,int col,int i){
    if (i >= word.size()) {
        found = true;
    }
    if (found) {
        return;
    }
    for (int i = 0; i < 8; ++i) {
        int row2 = row + rowDir[i];
        int col2 = col + colDir[i];
        if (valid(row2, col2,i)) {
            visited[row2][col2] = true;
            go(row2, col2, i + 1);
            visited[row2][col2];
        }
    }
}


void solve() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> abc;
            temp.push_back(abc);
        }
        grid.push_back(temp);
    }
    while (cin >> word and word!="a") {
        dict.push_back(word);
    }
    for (int j = 0; j < dict.size();++j) {
        word = dict[j];
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                found = false;
                go(row, col, 0);
                if (found) {
                    ++ans;
                }
            }
        }
    }
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
