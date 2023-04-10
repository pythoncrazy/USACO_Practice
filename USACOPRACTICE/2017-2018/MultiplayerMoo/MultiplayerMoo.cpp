#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#define ld long double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 251
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

int grid[maxn][maxn];
int n;
ll curr_size = 0;  // reset to 0 each time we start a new component
bool visited_one[maxn][maxn]; 
bool visited_two[maxn][maxn];
void floodfill(int r, int c, int color,bool visited[maxn][maxn]){
	if (
		(r < 0 || r >= n || c < 0 || c >= n)  // if out of bounds
		|| grid[r][c] != color  // wrong color
		|| visited[r][c]  // already visited this square
	) return;

	visited[r][c] = true; // mark current square as visited
	curr_size++; // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color,visited);
	floodfill(r, c - 1, color,visited);
	floodfill(r - 1, c, color,visited);
	floodfill(r + 1, c, color,visited);
}



void solve() {
	cin >> n;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> grid[r][c];
		}
	}
	ll max_size=-1;
	ll max_num = 0;
	ll max_two_size = -1;
	ll max_two_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited_one[i][j]) {
				curr_size = 0;
				
				
				floodfill(i, j, grid[i][j],visited_one);
				if (max_size < curr_size) {
					max_size = curr_size;
					max_num = grid[i][j];
				}
				else if (curr_size >= max_two_size and grid[i][j]!=max_num) {
					max_two_size = curr_size;
					max_two_num = grid[i][j];
				}
			}
		}
	}
	cout<<max_size<<endl;


	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			if (grid[i][j] == max_two_num) {
				grid[i][j] = max_num;
			}
		}
	}
	ll two_max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited_two[i][j]) {
				curr_size = 0;


				floodfill(i, j, grid[i][j],visited_two);
				two_max = max(curr_size, two_max);
			}
		}
	}
	cout << two_max << endl;
}



int main()
{
	int t = 1;
	//cin >> t;
	//ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
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