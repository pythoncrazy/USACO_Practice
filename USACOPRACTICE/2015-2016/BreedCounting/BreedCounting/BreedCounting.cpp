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
using vvl = vector<vector<ll>>;
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
    ifstream fin("bcount.in");
    int n, q,a,b; fin >> n >> q;
    vvl cows;
    vl cow = { 0,0,0 };
    cows.push_back(cow);
    for (int i = 0; i < n; ++i) {
        fin >> b;
        if (b == 1) {
            ++cow[0];
        }
        else if (b == 2) {
            ++cow[1];
        }
        else if (b == 3) {
            ++cow[2];
        }
        cows.push_back(cow);
    }
    ofstream fout("bcount.out");
    for (int i = 0; i < q-1; ++i) {
        fin >> a >> b;
        for (int j = 0; j < 3; ++j) {
            fout << cows[b][j] - cows[a-1][j]<<" ";
        }
        fout << endl;
    }
    fin >> a >> b;
    for (int j = 0; j < 3; ++j) {
        fout << cows[b][j] - cows[a - 1][j] << " ";
    }
    fout << endl;
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
