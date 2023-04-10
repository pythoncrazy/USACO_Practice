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

bool incheck(int xpos, int ypos, vector<vector<char>> board) {
    return false;
}


void solve() {
    vector<vector<char>> board(8, vector<char>(8));
    string piece;
    int temp=0;
    while (!cin.eof() or piece=="Ma2") {
        cin >> piece;
        temp = int(piece[1]-97);
        board[7-(piece[2] - 49)][temp] = piece[0];
    }
    cout << 1;
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}
