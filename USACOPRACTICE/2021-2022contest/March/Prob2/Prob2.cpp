#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500
#define sz(x) (int)size(x)
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
using vplll = vector<vector<pair<ll, ll>>>;

int main(){
    string s, t; cin >> s >> t;
    int m[256] = {};
    for (char a = 'a'; a < 's'; ++a){
        auto it1 = s.begin(), it2 = t.begin();
        bool finished = false, bad = false;
        int c[256] = {};
        m[a] = 262143;

        do {
            while (it1 != s.end() && *it1 != a) ++c[(ll)*it1++];
            while (it2 != t.end() && *it2 != a) --c[(ll)*it2++];
            finished = (it1 == s.end() && it2 == t.end());
            bad = !finished && (it1 == s.end() || it2 == t.end());

            if (!bad)
            {
                ++it1;
                ++it2;
                int val = 0;
                for (char x = 'a'; x < 's'; ++x)
                {
                    if (c[(ll)x] == 0) val |= (1 << (x - 'a'));
                }
                m[a] &= val;
            }
            else
            {
                m[a] = 0;
            }
        } while (!finished && !bad);
    }

    ll q;
    cin>>q;
    for (int i=0;i<q;++i ){
        string query;
        cin>>query;
        int val = 262143;
        int used = 0;
        for (char c : query)
        {
            val &= m[(ll)c];
            used |= (1 << (c - 'a'));
        }
        val &= used;
        bool match = (val == used);
        if(match){
            cout<<"Y";
        }else{
            cout<<"N";
        }
    }
}
