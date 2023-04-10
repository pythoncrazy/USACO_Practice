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
    string s; cin >> s;
    bool found = false;
    bool legal = true;
    bool abc = true;
    int i = 0;
    if ((n/2)*2!=n) {
        cout << "illegal" << endl; abc = false;
    }
    else if (s == "><") {
        cout << "legal" << endl; abc = false;
    }
    else if(s[0]=='<'){
        cout << "illegal" << endl; abc = false;
    }
    else if (count(s.begin(), s.end(), '<')!=count(s.begin(), s.end(), '>')) {
        cout << "illegal" << endl; abc = false;
    }
    else {
        while(s.length()!=0) {
            char k = s[i];
            i= 0;
            int j = i;
            found = false;
            while (found != true and legal == true and count(s.begin(),s.end(),'<')!=0 and count(s.begin(), s.end(), '>') != 0) {
                if (j >s.length()) { legal = false; break; }
                if (s[j]=='<') { found = true;  }
                else {
                    ++j;
                }
            }
            s.erase(s.begin()+j);
            s.erase(s.begin() + i);
            if (legal != true) { cout << "illegal" << endl; abc = false; break; }
            if (count(s.begin(), s.end(), '<') == 0 or count(s.begin(), s.end(), '>') == 0 and s.length()>=1) {
                cout << "illegal" << endl; abc = false; break;
            }
            if (s == "<>") {
                cout << "illegal" << endl; abc = false; break;
            }
            if (s == "><") {
                cout << "legal" << endl; abc = false; break;
            }
        }
    }
    
}



int main()
{
    int t;
    cin >> t;
    //t = 1;
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
