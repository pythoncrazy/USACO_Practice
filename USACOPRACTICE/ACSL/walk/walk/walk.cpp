// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

std::string to_zero_lead(const string value, const unsigned precision)
{
    std::ostringstream oss;
    oss << std::setw(precision) << std::setfill('0') << value;
    return oss.str();
}


void solve() {
    vector<vector<int>> walk(4);
    string a;
    int c,d;
    pair<int, int> pos;
    for (int i = 0; i < 4; ++i) {
        cin >> a;
        a = to_zero_lead(a, 4);
        for (char b : a) {
            c = b;
            c -= 48;
            walk[i].push_back(c);
        }
    }
    c = 0;
    for (int bcd = 0; bcd < 5; ++bcd) {
        cin >> c >> d;
        c--; d--;
        pos.first = c;
        pos.second = d;
        for (int abc = 0; abc < 6; ++abc) {
            c=walk[pos.second][pos.first];
            ++walk[pos.second][pos.first];
            if (walk[pos.second][pos.first] > 3) {
                walk[pos.second][pos.first] = 0;
            }
            if (c == 0) {
                ++pos.first;
            }
            else if (c == 1) {
                --pos.first;
            }
            else if (c == 2) {
                --pos.second;
            }
            else if (c == 3) {
                ++pos.second;
            }
            if (pos.first > 3) {
                pos.first -= 4;
            }
            if (pos.second > 3) {
                pos.second -= 4;
            }
            if (pos.first < 0) {
                pos.first += 4;
            }
            if (pos.second < 0) {
                pos.second += 4;
            }
            
        }
        cout << pos.first+1 << "," << pos.second+1<<endl;
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
