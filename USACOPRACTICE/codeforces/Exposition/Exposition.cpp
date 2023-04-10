#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
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


bool myComp(pll lhs, ll rhs) {
    return lhs.first < rhs;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    multiset<pll> h;
    vpll ans;
    
    vl books(n);
    for(ll& x:books){

        cin >> x;
    }
    h.insert({ books[0],0 });
    ans.push_back({ 0,0 });
    ll left = 0;
    ll maxs = 1;
    //right is i
    for (int i = 1; i < n; ++i) {
        h.insert({ books[i],i });
        while ((*prev(h.end())).first - (*h.begin()).first > k and left < i) { 
            h.erase({ books[left], left }), left++;
        }
        if (i - left + 1 > maxs) {
            maxs = i - left + 1;
            ans.clear();
            ans.pb({ left,i });
        }
        else if (i - left + 1 == maxs) {
            ans.push_back({ left,i });
        }
    }
    cout << maxs << " " << ans.size() << endl;
    for (pll x : ans) {
        cout << x.first+1 << " " << x.second+1 << endl;
    }




































    /*
    vpll h;
    pll temp;
    ll x;
    ll i = 0;
    for (int i = 0; i < n;++i) {
        cin >> x;
        temp.first = x;
        temp.second = i;
        h.push_back(temp);
    }

    
    
    sort(h.begin(), h.end());
    for (pll& z : h) {
        x = z.first;
        i = z.second;
        cout << x << " " << i << endl;
    }
    
    for (int start = 0; start < n; ++start) {
        ll x = lower_bound(h.begin(), h.end(), h[start].first + k,myComp) - h.begin();
        if (x > 0) { cout << x; }
    }
    */
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