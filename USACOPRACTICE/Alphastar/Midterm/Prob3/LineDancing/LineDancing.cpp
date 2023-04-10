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
    deque<int> line;
    string command;
    int i = 1,c=0;
    while (!cin.eof() and command!="a") {
        getline(cin,command);
        if (command.find("A L") != string::npos) {
            line.push_front(i);
            ++i;
        }
        else if (command.find("A R")!=string::npos) {
            line.push_back(i);
            ++i;
        }
        else if (command.find("D L") != string::npos) {
            size_t i = 0;
            for (; i < command.length(); i++) { if (isdigit(command[i])) break; }
            command = command.substr(i, command.length() - i);
            c = atoi(command.c_str());
            for (int i = 0; i < c; ++i) {
                line.pop_front();
            }
        }

        else if (command.find("D R") != string::npos) {
            size_t i = 0;
            for (; i < command.length(); i++) { if (isdigit(command[i])) break; }
            command = command.substr(i, command.length() - i);
            c= atoi(command.c_str());

            for (int i = 0; i < c; ++i) {
                line.pop_back();
            }
        }
    }
    while (!line.empty()) {
        cout << line.front()<<endl;
        line.pop_front();
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
