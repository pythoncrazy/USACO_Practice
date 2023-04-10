#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#define ld long double
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
using pll = pair<ll, ll>;
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/
/*
Below code calculates the prefix sum vector using the following notation:
vl a(N);
for (ll& x: a)
	cin >> x;
vl p = psum(a);
where p is the prefix sum vector

*/
vl psum(const vl& a) {
    vl psum(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}


void solve() {
    ll A,B,n;
    cin>>A>>B>>n;
    vpll power_helth(n,{0,0});
    for(pll&x:power_helth){
        cin>>x.first;
    }
    for(pll&x:power_helth){
        cin>>x.second;
    }
    sort(power_helth.rbegin(),power_helth.rend());
    ll mos_index=0; //denotes the monster the hero is currently fighting
    bool done = false; //Denotes if the human hero is gone :(
    while(mos_index<n){
        ll damage = power_helth[mos_index].first;
        ll helth = power_helth[mos_index].second;
        ll monster_attacks = (B-1) / damage + 1;
        ll human_attacks = (helth-1) / A + 1;
        B -= min(human_attacks,monster_attacks) * damage;
        helth -= min(monster_attacks,human_attacks) * A;
        if(B<0){
            if(mos_index-n==-1 and helth<=0){
                ++mos_index;
                continue;
            }else {
                done = true;
                break;
            }
        }
        ++mos_index;
    }
    if(!done){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}



int main()
{
    int t = 1;
    cin >> t;
    //ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
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