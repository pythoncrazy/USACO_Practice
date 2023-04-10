// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string a;
    int n=0;
    cin >> n;
    vector<string> ag(n);
    vector<string> ans(n);
    
    for (int i=0; i < n;i++) {
        cin >> a;
        ag[i] = a;
    }
    for (int i=0; i < n; ++i) {
        if (ag[i].size() > 10) {
            ans[i] = ag[i].at(0) + to_string(ag[i].size() - 2) + ag[i].back();
        }
        else { ans[i] = ag[i]; }
    }
    for (int i=0; i < n; ++i) {
        cout << ans[i] << "\n";
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
