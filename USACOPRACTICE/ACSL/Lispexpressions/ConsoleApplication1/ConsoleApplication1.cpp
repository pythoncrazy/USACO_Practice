// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
int main()
{
    string i1, i2, i3, i4, i5;
    getline(cin, i1);
    string ans;
    for (int i = 0; i < i1.length(); ++i) {
        char y = i1[i];
        if (y != '(' and y != '\'' and y != ')') {
            cout << y;
        }
    }
    getline(cin, i2);
    for (int i = 0; i < i2.length(); ++i) {
        char y = i2[i];

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
