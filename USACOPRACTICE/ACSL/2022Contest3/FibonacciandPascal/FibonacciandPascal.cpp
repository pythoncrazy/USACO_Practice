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


void solve() {
    vll fog(5, vl(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j or j == 0) {
                fog[i][j] = 1;
            }
            else {
                fog[i][j] = fog[i - 1][j - 1] + fog[i - 1][j];
            }
        }
    }
    vl ans;
    vl fibnums = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040 };
    int fibNumber=3;
    int start = distance(fibnums.begin(),find(fibnums.begin(), fibnums.end(), fibNumber));
    for (int i = start; i >= 1; --i) {
        if (fog[i][start - i] != 0) {
            ans.push_back(fog[i][start - i]);
        }
    }
    std::stringstream ss;
    for (size_t i = 0; i < ans.size(); ++i)
    {
        if (i != 0)
            ss << " ";
        ss << ans[i];
    }
    std::string s = ss.str();
    cout << s;
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}
/*

DONT GET FIXATED ON ONE IDEA
BINARY SEARCH OR SOLVE ON PIECE OF PAPER
suerte


*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
