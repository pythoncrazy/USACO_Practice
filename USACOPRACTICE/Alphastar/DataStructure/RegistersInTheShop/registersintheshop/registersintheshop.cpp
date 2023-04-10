// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005


void solve() {
    int n; cin >> n;
    string b;
    int c,d;
    
    queue<int> line;
    vector <int> reg[31];
    while (true) {
        cin >> b >> c;
        if (cin.eof() or b == "a") { break; }
        if (b == "a") { break; }
        if (b == "C") {
            line.push(c);
        }
        else if (b == "R") {
            d = line.front();
            line.pop();
            reg[c-1].push_back(d);
        }
        
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout << reg[i].size()<< " ";
        for (int j = 0; j < reg[i].size(); j++)
        {
            cout << reg[i][j]<<" ";
        }
        cout << endl;
    }
    
}



int main()
{
    solve();
}

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    queue <int> line;
    vector <int> reg[31];
    int n, hold, a;
    char type;
    cin >> n;
    while (true)
    {
        cin >> type >> hold;
        if (cin.eof() or type=='a') break;
        if (type == 'C')
        {
            line.push(hold);
        }
        else if (type == 'R')
        {
            a = line.front();
            
            reg[hold - 1].push_back(a);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << reg[i].size();
        for (int j = 0; j < reg[i].size(); j++)
        {
            cout << " " << reg[i][j];
        }
        cout << endl;
    }
}
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
