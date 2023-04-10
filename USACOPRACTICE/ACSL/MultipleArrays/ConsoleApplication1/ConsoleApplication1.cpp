// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;

vector<int> split(string s) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, ' ')) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}



void solve() {
    vector<int> arrone;
    vector<int> arrtwo;
    vector<int> arrthree;
    vector<int> ans;
    string abc;
    int a=0;
    bool one = true,two=true,three=true;
    getline(cin, abc);
    arrone = split(abc);
    getline(cin, abc);
    arrtwo = split(abc);
    getline(cin, abc);
    arrthree = split(abc);
    int length = max(arrthree.size(),max(arrone.size(), arrtwo.size()));
    for (int i = 0; i < length; ++i) {
        if (i > arrone.size()-1) { one = false; }
        if (i > arrtwo.size()-1) { two = false; }
        if (i > arrthree.size()-1) { three = false; }
        if (one and two and three) {
            ans.push_back( max(max(arrone[i], arrtwo[i]), arrthree[i]) );
        }
        else if (one and two) {
            ans.push_back(max(arrone[i], arrtwo[i]));
        }
        else if (one and three) {
            ans.push_back(max(arrone[i], arrthree[i]));
        }
        else if (two and three) {
            ans.push_back(max(arrtwo[i], arrthree[i]));
        }
        else if (one) {
            ans.push_back(arrone[i]);
        }
        else if (three) {
            ans.push_back(arrthree[i]);
        }
        else if (two) {
            ans.push_back(arrtwo[i]);
        }
    }
    for (int i : ans) {
        a += i;
    }
    cout<<a;
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
