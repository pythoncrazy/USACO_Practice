#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int n, s, x, min = 0, max = 0, ans = 0, a, b;
    cin >> n >> s;
    int arr[100001];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        x = arr[i];
        max = s - x;

        a = upperbound(max, n, arr);
        if (a - i > 0) {
            ans += a - i-1;
        }
    }
    cout << ans;
}