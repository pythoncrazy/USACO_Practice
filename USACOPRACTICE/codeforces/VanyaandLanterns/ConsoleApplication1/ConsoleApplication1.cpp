#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> lanterns(n);
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
        cin >> lanterns[i];
    }
    sort(begin(lanterns), end(lanterns));
    for (int i = 0; i < n; ++i) {
        if (i == 0 && lanterns[0] != 0) {
            diff[i] = (lanterns[0] - 0) * 2;
        }
        else {
            if (i != 0) {
                diff[i] = lanterns[i] - lanterns[i - 1];
            }
        }
    }
    diff.push_back(2*(l - lanterns[n - 1]));
    double ans = *max_element(diff.begin(), diff.end());
    cout.precision(20);
    cout << ans / 2;
}