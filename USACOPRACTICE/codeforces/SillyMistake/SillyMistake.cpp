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
/*
Defines a 2d vector with row_count and column_count
vll fog(ROW_COUNT,vl(COLUMN_COUNT));

*/



void solve() {
    ll n;
    cin >> n;
    vl nums(n);
    bool valid = true;
    for (ll& x : nums) {
        cin >> x;
    }
    vl used(10e6+6);
    vl done(10e6+6);
    vl ans;
    ll sum = 0;
    set <ll> change;
    ll ind = -1;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        if (sum == 0) {
            ans.pb(1);
            ind += 1;
            sum += nums[i];
            if (used[abs(nums[i])]==0 and nums[i]<0) {
                cout << -1 << endl;
                bad = true;
                break;
            }
            else {
                for (ll z : change) {
                    used[abs(nums[z])] = 0;
                    done[abs(nums[z])] = 0;
                }
                used[nums[i]] += 1;
                change.emplace(abs(i));
                change.clear();
            }

        }
        else if (sum != 0) {
            if (done[abs(nums[i])] > 2) {
                cout << -1 << endl;
                bad = true;
                break;
            }
            if (used[abs(nums[i])] == 0 and nums[i] < 0) {
                cout << -1 << endl;
                bad = true;
                break;
            }
            else if(used[abs(nums[i])]==1 and nums[i]>0){
                cout << -1 << endl;
                bad = true;
                break;
            }
            else {
                if (nums[i] > 0) {
                    used[nums[i]] += 1;
                    done[nums[i]] += 1;
                    sum += nums[i];
                    change.emplace(abs(i));
                }
                if (nums[i] < 0) {
                    used[abs(nums[i])] -= 1;
                    done[abs(nums[i])] += 1;
                    sum += nums[i];
                    change.emplace(abs(i));
                }
                ans[ind] += 1;
            }
            
        }
    }
    

    if (!bad) {
        for (int i : used) {
            if (i != 0) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            cout << ans.size() << endl;
            for (ll i : ans) {
                cout << i << " ";
            }
        }
        else {
            cout << -1 << endl;
        }
    }
}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
}