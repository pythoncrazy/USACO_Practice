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
vector<string> string_split(const string& str) {
    vector<string> result;
    istringstream iss(str);
    for (string s; iss >> s; )
        result.push_back(s);
    return result;
}
void solve() {
    ll n; cin >> n;
    deque<ll> unwashed;
    deque<ll> washed;
    deque<ll> dried;
    for (int i = 1; i <= n; ++i) {
        unwashed.push_front(i);
    }
    string temp, s;
    ll c, d;
    ll a;
    while (!cin.eof() or c==-1) {
        cin >> c >> d;/*
        s = temp;
        cout << temp<<" "<<s;
        vector<string> t=string_split(temp);
        c = stoll(t[0]);
        d = stoll(t[1]);
        */
        if (c == 1) {
            while (d > 0) {
                --d;
                a = unwashed.back();
                unwashed.pop_back();
                washed.push_back(a);
            }
        }
        else if (c == 2) {
            while (d > 0) {
                --d;
                a = washed.back();
                washed.pop_back();
                dried.push_back(a);
            }
        }
        else {
            break;
        }
    }
    for (int i = 0; i < n;++i) {
        cout << dried.back() << endl;
        dried.pop_back();
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
