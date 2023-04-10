#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
void solve() {

    int a, b;
    int ans = 0;
    cin >> a >> b;
    while (a != b) {
        if (a > b) {
            if ((a & (a - 1)) == 0) {
                a /= 2;
                ans += 1;
            }
            else if (a > b / 2 and a%2==0) {
                a /= 2;
                ans += 1;
            }
            else {
                a += 1;
                ans += 1;
            }
        }
        else if(a<b){
            if (a<b / 2 and a * 2>b) {
                a *= 2; ans += 1;
            }
            else if (a < b / 2 and a *2 < b) {
                a += 1; ans += 1;
            }
            
            else if (a > b / 2) {
                a += 1; ans += 1; 
            }
            else if (b /2 == a) {
                a *= 2;
                ans += 1;
            }
        }
    }
    cout<<ans<<endl;

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
