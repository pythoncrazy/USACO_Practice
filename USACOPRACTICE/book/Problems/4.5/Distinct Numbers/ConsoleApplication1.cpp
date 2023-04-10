// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    int n;
    int k;
    int c;
    int d;
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    vector< vector<int> > visited;
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        pos.push_back(i);
    }
    for (int i = 0; i <= k; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        visited[i][0] = i + 1;
    }
    for (int i = 0; i < n * k; i++) {
        c = pos[a[i] - 1];
        d = pos[b[i] - 1];
        pos[a[i] - 1] = d;
        pos[b[i] - 1] = c;
        visited[a[i] - 1].push_back(c);
        visited[b[i] - 1].push_back(d);

    }
    vector<int> g(n);
    for () {
        for()
    }
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
