// Comfortablecows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[500][500];
    cin >> n;
    int x;
    int y;
    for (int j; j < n; j++) {

        for (int i; i < n; i++) {
            cin >> x;
            a[j].push_back(x);
        }
    }

}
