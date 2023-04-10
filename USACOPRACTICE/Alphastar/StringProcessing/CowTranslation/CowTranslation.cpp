#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
void solve() {
    int m, n,ans=0;
    string a,str;
    cin >> m >> n;
    cin.ignore();
    vector<string> book;
    vector<string> messages;
    for (int i = 0; i < m; ++i) {
        getline(cin, a);
        book.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        getline(cin, a);
        messages.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        str = messages[i];
        for (int j = 0; j < m; ++j) {
            if (book[j].compare(0, str.size(), str) != 0) { continue; }
            else { ++ans; break; }
        }
    }
    cout << ans;
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
