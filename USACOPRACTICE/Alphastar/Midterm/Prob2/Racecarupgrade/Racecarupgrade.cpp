// Template_uno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

struct Part {
    int force;
    int mass;
    float acceleration;
    int index;
};
bool cmp(const Part& a, const Part& b) {
    return a.acceleration > b.acceleration;
}

void solve() {
    int f, m, n;
    cin >> f >> m >> n;
    Part parts[10001];
    for (int i = 0; i < n; i++) {
        int force;
        int mass;
        cin >> force >> mass;
        parts[i].force = force;
        parts[i].mass = mass;
        parts[i].acceleration = float(force) / float(mass);
        parts[i].index = i + 1;
    }
    sort(parts, parts + n, cmp);
    int array[10001];
    int force = f;
    int mass = m;
    float acceleration;
    float last_a = f / m;
    int last_index = -1;
    int i = 0;
    for (; i < n; i++) {
        force += parts[i].force;
        mass += parts[i].mass;
        acceleration = float(force) / mass;
        if (acceleration < last_a) {
            break;
        }
        else if (acceleration > last_a) {
            last_index = i;
        }
        last_a = acceleration;
        array[i] = parts[i].index;
    }
    if (last_index >= 0) {
        sort(array, array + last_index + 1);
        for (int j = 0; j <= last_index; j++) {
            cout << array[j] << endl;
        }
    }
    else {
        cout << "NONE";
    }

}



int main()
{
    int t;
    //cin >> t;
    t = 1;
    ios_base::sync_with_stdio(false); cerr.tie(0); cout.tie(0); cin.tie(0);
    while (t--) { solve(); }
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
