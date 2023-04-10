#include <bits/stdc++.h>
#include <iostream>

std::vector<std::vector<std::pair<int,int>>> grid; //the first integer represents the money that this cell has. The second integer represents the directiom, right is 0, down is 1 and trough will be given 7.

int calc(std::vector<std::vector<std::pair<int,int>>> grid){
    int xpos=0;
    int ypos=0;

}

int main()
{
    int n,q;
    std::cin >> n;
    std::string s;
    int a;
    std::vector<std::pair<int,int>> temp(n+1);
    std::pair<int,int> tempp;
    std::vector<char> tempstr(n);
    for(int i=0;i<n;i+=1){
        std::cin>>s>>a;
        std::copy(s.begin(), s.end(), tempstr.begin());
        for(int i = 0; i < n; i+=1){
            tempp.first = 0;
            tempp.second = tempstr[i];
            temp.push_back(tempp);
        }
        temp.push_back({a,7});
        grid.push_back(temp);
    }
}
