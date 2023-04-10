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
int upperbound(int x, int n, int array[]) {
    int L = 0;
    int r = n;
    while (L < r) {
        int mid = (r + L) / 2;
        if (x >= array[mid]) {
            L = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return L;
}

int lowerbound(int x, int n, int array[]) {
    int L = 0;
    int r = n;
    while (L < r) {
        int mid = (r + L) / 2;
        if (x <= array[mid]) {
            r = mid;
        }
        else {
            L = mid + 1;
        }
    }
    return L;
}
template <class T>
auto make_clusters(std::vector<T>& v) -> std::vector<std::vector<T>>
{
    std::vector<std::vector<T>> clusters;

    auto cluster_begin = v.begin();
    while (cluster_begin != v.end())
    {
        auto elem = *cluster_begin;

        auto cluster_end = std::find_if(cluster_begin, v.end(),
            [&](int e) { return e != elem; });
        clusters.emplace_back(std::distance(cluster_begin, cluster_end), elem);

        cluster_begin = cluster_end;
    }

    return clusters;
}

void solve() {
    int n,k; cin >> n; vl a;
    int ans=0;
    int count;
    cin >> k; a.push_back(k);
    int prev=0;
    bool l = false;
    for (int i = 0; i < n-1; ++i) {
        cin >> k; a.push_back(k);
        
    }
    ll g = *max_element(begin(a),end(a));
    


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
