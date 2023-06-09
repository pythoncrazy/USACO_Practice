// Practiceupperandlower.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int lowerbound(int x,int n, int array[]) {
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
    int n = 9;
    int array[] = { -1,0,3,5,9,12 };
    cout <<lowerbound(9,n,array)<<"\n";
    cout << upperbound(9,n,array) << "\n";
    cout << upperbound(2,n,array) <<" "<< lowerbound(2,n,array) << "\n";
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
