#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

bool isChild(string m, string f, string child) {
    for (int i = 0; i < 25; ++i) {
        if (m[i] != child[i] and f[i] != child[i]) {
            return false;
        }
    }
    return true;
}


void solve() {
    int M,F;
    string a;
    cin >> M >> F;
    vector<string> males;
    vector<string> females;
    for (int i = 0; i < M; ++i) {
        cin >> a;
        males.push_back(a);
    }
    for (int i = 0; i < F; ++i) {
        cin >> a;
        females.push_back(a);
    }
    vector< vector<int>> res(M, vector<int>(F));
    for (int m = 0; m < M; ++m) {
        for (int f = 0; f < F; ++f) {
            for (int mm = 0; mm < M; ++mm) {
                if (mm == m) {
                    continue;
                }
                if (isChild(males[0], females[0], males[mm])) { res[m][f]++; }
            }
            for (int ff = 0; ff < F; ++ff) {
                if (ff == f) { continue; }
                if (isChild(males[0], females[0], females[ff])) { res[m][f]++; }
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < F; ++j) {
            cout << res[i][j];
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
