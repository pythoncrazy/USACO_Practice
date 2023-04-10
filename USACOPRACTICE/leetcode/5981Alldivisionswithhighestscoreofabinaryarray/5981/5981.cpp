#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

template<typename T>
auto find_maximums(const std::vector<T>& v) {
    std::vector<size_t> indexes;

    for (auto it_max = std::max_element(v.begin(), v.end()); it_max != v.end();
        it_max = std::find(it_max + 1, v.end(), *it_max))
    {
        auto index = std::distance(v.begin(), it_max);
        indexes.push_back(index);
    }

    return indexes;
}



void solve() {
    vector<int> nums = { 0,0,1,0 };
    int n = size(nums);
    vector<int> ans;
    vector<int> v1;
    vector<int> v2;
    int a = 0;
    for (int i = 0; i <= n; ++i) {
        v1 = std::vector<int>(nums.begin(),nums.begin()+i);
        v2 = std::vector<int>(nums.begin()+i, nums.end());
        a=count(v1.begin(), v1.end(), 0);
        a += count(v2.begin(), v2.end(), 1);
        ans.push_back(a);
    }
    for (int i = 0; i <= n; ++i) {
        cout << ans[i];
    }
    auto max_indexes = find_maximums(ans);
    for (auto idx : max_indexes)
        std::cout << idx << ' ';
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
