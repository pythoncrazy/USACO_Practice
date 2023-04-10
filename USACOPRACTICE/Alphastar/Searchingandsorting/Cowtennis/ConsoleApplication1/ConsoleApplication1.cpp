// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    int n,x,y,d=0;
    int max = 0, min = 0,ans=0;
    cin >> n;
    int cows[1001];
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows, cows + n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) { continue; }
            x = cows[i];
            y = cows[j];
            d = y - x;
            min = y + d, max = y + 2 * d;
            if (upperbound(max, n, cows) - lowerbound(min, n, cows) > 0) {


                ans += upperbound(max, n, cows) - lowerbound(min, n, cows);
            }
        }
    }
    cout << ans;
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
