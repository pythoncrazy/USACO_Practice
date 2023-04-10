

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
void solve() {
    int n, a;
    cin >> n;
    vector<int> notes;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        notes.push_back(a);
    }
    int c, diff;
    cin >> c;
    vector<int> alpha;
    vector<int> v2;
    vector<int> ans;
    for (int i = 0; i < c; ++i) {
        cin >> a;
        alpha.push_back(a);
    }
    for (int a = 0; a <= n - c; ++a) {
        v2 = vector<int>(notes.begin() + a, notes.begin() + a + c);
        sort(v2.begin(), v2.end());

        for (int b = 0; b < c; ++b) {
            diff = -v2[b] + alpha[b];
            for (auto& item : v2)
            {
                item += diff;
            }
            if (v2 == alpha) {
                ans.push_back(a + 1);
                break;
            }
        }
    }
    cout << size(ans) << endl;
    for (int i : ans) {
        std::cout << i << endl;
    }

}
63
36
44
68
42


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