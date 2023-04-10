// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#include <fstream>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005
bool pos(vector<int> cows, int time,int m, int n,int c) {
    int buses = 1;
    int first = cows[0];
    int index = 0;
    for (int i = 1; i < n; ++i) {
        if (cows[i] - first > time or i+1 - index > c) {
            ++buses;
            first = cows[i];
            index = i;
        }
    }
    return buses <= m;
}

int binarySearch(int low, int high,vector<int> cows,int n,int m, int c) {
    int mid;
    while (low <= high) {
        

        if (low== high)
            return high;

        if (low + 1 == high) {
            if (pos(cows, low,m,n,c)) return low;
            return high;
        }
        mid = (low + high) / 2;
        if (pos(cows,mid,m,n,c)) {
            return binarySearch(low, mid, cows, n, m, c);
        }
        return binarySearch(mid+1, high, cows, n, m, c);
    }

    return -1;
}

int main()
{
    ifstream myfile;
    myfile.open("convention.in");
    ofstream myfile1; 
    myfile1.open("convention.out");
   
        
        
        
        int n, m, c, abc; myfile >> n >> m >> c;
        vector<int> cows;
        vector<int> temp;
        vector<int> a = {};
        vector<vector<int>> bus;
        vector<int> diff;
        bool b = true;
        for (int i = 0; i < n; ++i) {
            myfile >> abc;
            cows.push_back(abc);
        }
        sort(cows.begin(), cows.end());
        myfile1 << binarySearch(0, 1e9, cows, n, m, c);
    
    
}
