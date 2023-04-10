

#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

struct Seat {
   int row, col, dist;
};
bool cmp(Seat seat1, Seat seat2) {
    if (seat1.dist != seat2.dist) {
        if (seat1.dist < seat2.dist) {
            return true;
        }
        else {
            return false;
        }
    }else if(seat1.row!=seat2.row){
        if (seat1.row > seat2.row) {
            return true;
        }
        else { return false; }
    }
    else {
        if (seat1.col < seat2.col) {
            return true;
        }
        else {
            return false;
        }
    }
}
void solve() {
    int w, r,d;
    Seat a;
    cin >> w >> r;
    vector<Seat> seats;
    for (int row = 1; row <= r; ++row) {
        for (int col = 1; col <= w; ++col) {
            d = (row - r) * (row - r) + (col - (w / 2 + 1)) * (col - (w / 2 + 1));
            a.row = row;
            a.col = col;
            a.dist = d;


            seats.pb(a);
        }
    }
    sort(seats.begin(), seats.end(), cmp);
    int seatNum = 1;
    int cinema[51][102];
    for (int i = 0; i < w * r; ++i) {
        a = seats[i];
        cinema[a.row][a.col] = seatNum;
        ++seatNum;
    }
    for (int row = 1; row <= r; ++row) {
        for (int col = 1; col <= w; ++col) {
            cout << cinema[row][col]<<" ";
        }
        cout << endl;
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

