// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
#define n 7
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
using pll = pair<ll, ll>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/
/*
Below code calculates the prefix sum vector using the following notation:
vl a(N);
for (ll& x: a)
    cin >> x;
vl p = psum(a);
where p is the prefix sum vector

*/
vl psum(const vl& a) {
    vl psum(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}

pll numtopair(int g) {
    ll xcoord=g-1;
    ll ycoord=0;
    while (xcoord >= n) {
        ++ycoord;
        xcoord -= n;
    }
    return(make_pair(xcoord, ycoord));
}

vl lookup(vll grid,vll board, pll circ2) {
    ll xcoord=circ2.first;
    ll ycoord=circ2.second;
    vl ans;
    while (ycoord > 0) {
        --ycoord;
        if (grid[ycoord][xcoord] == 0) {
            ans.push_back(board[ycoord][xcoord]);
        }
        else {
            return ans;
        }
    }
    return ans;
}

vl lookdown(vll grid, vll board, pll circ2) {
    ll xcoord = circ2.first;
    ll ycoord = circ2.second;
    vl ans;
    while (ycoord <n-1) {
        ++ycoord;
        if (grid[ycoord][xcoord] == 0) {
            ans.push_back(board[ycoord][xcoord]);
        }
        else {
            return ans;
        }
    }
    return ans;
}

vl lookleft(vll grid, vll board, pll circ2) {
    ll xcoord = circ2.first;
    ll ycoord = circ2.second;
    vl ans;
    while (xcoord >0) {
        --xcoord;
        if (grid[ycoord][xcoord] == 0) {
            ans.push_back(board[ycoord][xcoord]);
        }
        else {
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }reverse(ans.begin(), ans.end());
    return ans;
}

vl lookright(vll grid, vll board, pll circ2) {
    ll xcoord = circ2.first;
    ll ycoord = circ2.second;
    vl ans;
    while (xcoord < n-1) {
        ++xcoord;
        if (grid[ycoord][xcoord] == 0) {
            ans.push_back(board[ycoord][xcoord]);
        }
        else {
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    vll grid(n, vl(n));
    vll board;
    for (int i = 0; i < n; i++) {
        vl temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(i*n+j + 1);
        }
        board.push_back(temp);
    }
    ll x;
    pll circ1, circ2, block;
    cin >> x;
    circ1 = numtopair(x);
    grid[circ1.second][circ1.first] = 2;
    cin >> x;
    circ2 = numtopair(x);
    while (true) {
        cin >> x;
        if (x == 0) { break; }
        block = numtopair(x);
        grid[block.second][block.first] = 1;
    }
    vl up, down, left, right;
    up = lookup(grid, board, circ2);
    down=lookdown(grid, board, circ2);
    left = lookleft(grid, board, circ2);
    right = lookright(grid, board, circ2);
    ll z = max(max(max(up.size(), down.size()), left.size()),right.size());
    if (z == 0) {
        cout << "NONE";
    }else if (left.size() == z) {
        for (int i : left) {
            cout << i << " ";
        }
    }
    else if (right.size() == z) {
        for (int i : right) {
            cout << i << " ";
        }
    }
    else if (up.size() == z) {
        for (int i : up) {
            cout << i << " ";
        }
    }
    else if (down.size() == z) {
        for (int i : down) {
            cout << i << " ";
        }
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
