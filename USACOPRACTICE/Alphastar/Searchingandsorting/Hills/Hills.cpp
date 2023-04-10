// Hills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max = 101;
    int min = -1;
    int ans = 100000000;
    int n;
    int a = 0;
    int cost = 0;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        
    }
    sort(begin(A), end(A));
    max = *max_element(begin(A), end(A));
    min=*min_element(begin(A), end(A));
    for (int i = min; i + 17 <= max; ++i) {
        cost = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] < i) {
                cost += pow((-A[j] + i), 2);
            }
            else if (A[j] > i + 17) {
                cost +=((A[j] - (i + 17)))* ((A[j] - (i + 17)));
            }
        }
        if (ans > cost) {
            ans = cost;
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
