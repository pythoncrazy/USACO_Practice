// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;

ll n;


int main()
{
    cin >> n;
    vl bud;
    ll abc,bcd;
    ll min=LONG_MAX-2; ll mindex=-9;
    for(int j=0;j<n;++j){
        cin>>abc>>bcd;
        bud.push_back(bcd);
        if(bcd<min){
            min=bcd; mindex=j;
        }
    }
    ll ans=0;
    for(int i=0;i<n;++i){
        if(i==mindex){
            continue;
        }
        ans+=bud[i];
    }
    cout<<ans<<endl;
}
