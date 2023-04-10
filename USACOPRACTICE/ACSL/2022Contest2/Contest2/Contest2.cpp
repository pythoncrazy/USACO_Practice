#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
string fibCypher(char key, string msg) {
    int sigma = key;
    char a;
    int b, c;
    vector<int> ans;
    ostringstream oss;
    vector<int> fibnums = { 1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269 };
    for (int i = 0; i < msg.length(); i++)
    {
        a = msg[i];
        b = a;
        c = sigma + fibnums[i];
        while (c > 122) { c -= 26; }
        ans.push_back(b + c);
    }
    copy(ans.begin(), ans.end() - 1,
        std::ostream_iterator<int>(oss, " "));
    oss << ans.back();
    return oss.str();
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { cout<<fibCypher('h',"ACSL c2"); }
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
