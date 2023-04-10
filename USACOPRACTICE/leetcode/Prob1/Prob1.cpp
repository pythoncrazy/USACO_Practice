#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


void solve() {
    vector<int> ans;
    vector<vector<int>> nums = { {3,1,2,4,5},{1,2,3,4},{3,4,5,6 } };
    vector<int> used;
    for (int i = 1; i < 1001; ++i) {
        used.push_back(0);
    }
    int rows = nums.size();
    int cols = nums[0].size();
    for (int x = 0; x < rows; ++x) {
        for (std::vector<int>::size_type y = 0; y != nums[x].size(); y++) {
            used[nums[x][y]-1]+=1;
        }
    }
    for (std::vector<int>::size_type i = 0; i != used.size(); i++) {
        if (used[i] == rows) {
            ans.push_back(i+1);
            cout << i+1 << endl;
        }
    }

}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    while (t > 0) { solve(); --t; }
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