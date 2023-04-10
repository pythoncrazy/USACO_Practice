#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
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
vector<vector<int>> adj;
vector<bool> hasVisited;
int N, K;
vector<int> vis;
void dfs(int src){
hasVisited[src] = true;
vis.push_back(src);
for(int j: adj[src]){
	if(!hasVisited[j]){
	dfs(j);
	}
}
}
void solve() {
	int N,K; cin >> N>>K;
	hasVisited.resize(N);
    adj.resize(N);
    //first perform the swaps
    vector<int> arr(N);
    vector<set<int>> myMap(N);
    for(int i = 0; i < N; i++){
      arr[i] = i;
      myMap[i].insert(i);
    }
    vector<pair<int,int>> swaps(K);
    for(int i = 0; i < K; i++){
      int a,b;
      cin >> a >> b;
      a--;
      b--;
      myMap[arr[a]].insert(b);
      myMap[arr[b]].insert(a);
      swap(arr[a], arr[b]);
    }
    for(int i = 0; i < N; i++){
      adj[i].push_back(arr[i]);
    }
    vector<vector<int>> cc;
    for(int i = 0; i < N; i++){
      if(!hasVisited[i]){
        dfs(i);
        cc.push_back(vis);
        vis.clear();
      }
    }
    vector<int> ans;
    vector<int> pr(N);
    for(int i = 0; i < cc.size(); i++){
      set<int> s;
      for(int j: cc[i]){
        s.insert(myMap[j].begin(),myMap[j].end());
      }
      for(int j: cc[i]){
        pr[j] = s.size();
      }
    }
    for(int j: pr){
      cout << j << endl;
    }
  }




int main()
{
	int t = 1;
	//cin >> t;
	ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
	while (t--) { solve(); }
}
