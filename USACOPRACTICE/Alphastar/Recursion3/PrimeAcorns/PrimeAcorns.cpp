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

ll n;
ll num = 0;
vl digits = { 1,2,3,7,9 };
bool isPrime(ll K) {
    if (K < 2) {
        return false;
    }if (K == 2) {
        return true;
    }if (K % 2 == 0) {
        return false;
    }
    for (int l = 3; l * l < K; l+=2) {
        if (K % l == 0) return false;
    }
    return true;
}

void go(int i,int num) {
    if (to_string(num).length() >= n) {
        cout << num << endl;
        return;
    }
    for (int j = 0; j < digits.size();++j) {
        num = num * 10 + digits[j];
        if (isPrime(num)) {
            go(i + 1,num);
        }
        
        num = num / 10;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    cin >> n;
    go(n, num);
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
