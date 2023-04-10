
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_N = 2e5;
int ans=0;
int des[MAX_N], apartments[MAX_N];
void solve() {

	int a;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> des[i];
	for (int i = 0; i < m; ++i) cin >> apartments[i];
	sort(des, des+n);
	sort(apartments, apartments+m);
	int i = 0, j = 0;
	while (i < n && j < m) {

		if (abs(des[i] - apartments[j]) <= k) {
			++i, ++j;
			++ans;
		}
		else {
			if ((des[i] - apartments[j])>k) {
				++j;
			}
			else {
				++i;
			}
		}
	
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
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
