// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define N 9
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/
void multiply(int a[][9], int b[][9], int res[][9])
{
    int mul[9][9];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < N; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res[i][j] = mul[i][j];
}
void power(int G[N][N], int res[N][N], int n)
{
    if (n == 1) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = G[i][j];
        return;
    }
    power(G, res, n / 2);
    multiply(res, res, res);
    if (n % 2 != 0)
        multiply(res, G, res);
}



void solve1() {
    string s;
    ll graph[9][9];
    ll ans=0;
    ll abc, bcd;
    while (!cin.eof()) {
        cin >> s;
        if (s == "aa") {
            break;
        }
        abc = s[0]-49;
        bcd = s[1]-49;
        graph[abc][bcd] = 1;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (graph[i][j] == graph[j][i] and graph[i][j] == 1) {
                ++ans;
                graph[i][j] = 0; graph[j][i] = 0;
            }
        }
    }
    cout << ans << endl;
}

void solve2() {
    string s;
    vll graph(9, vl(9, 0));
    ll ans = 0;
    ll abc, bcd;
    while (!cin.eof()) {
        cin >> s;
        if (s == "aa") {
            break;
        }
        abc = s[0] - 49;
        bcd = s[1] - 49;
        graph[abc][bcd] = 1;
    }
    vl totst(9);
    vl count(9);
    for (ll i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (graph[i][j]) {
                totst[i] += 10 * (i + 1) + j+1; count[i] += 1;
            }
        }
    }
    ll m = 0;
    ll index;
    for (int i = 0; i < 9; ++i) {
        if (count[i] > m) {
            m = totst[i];
            index = i;
        }
    }
    cout << totst[index] << endl;
}

void solve3() {
    string s;
    vll graph(9, vl(9, 0));
    ll ans = 0;
    ll abc, bcd;
    while (!cin.eof()) {
        cin >> s;
        if (s == "aa") {
            break;
        }
        abc = s[0] - 49;
        bcd = s[1] - 49;
        graph[abc][bcd] = 1;
    }
    vll answer(9, vl(9, 0)); 
    power(graph, answer, 9);
    
}



int main()
{
    int t;
    int j;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { 
        cin >> j;
        if (j == 1) {
            solve1();
        }
        else if (j == 2) {
            solve2();
        }
        else {
            solve3();
        }
    }
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
