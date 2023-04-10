#include <bits/stdc++.h>
#define ld double
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
#define maxn 500005

void solve() {
    string temp, s = "";
    while (!cin.eof()) {
        getline(cin, temp);
        if (temp == "ssssssssssssssssssssssssssssssssssssssss") {
            break;
        }
        s += temp + '\n';
    }
    string abcd = s;
    int j = 0;
    vector<int> pos;
    for (int i = 0; i < s.size(); i++) {

        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[j] = s[i];
            j++;
            pos.push_back(i);
        }
    }
    string str =s.substr(0, j);
    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::tolower(c); });
    int maxLength = 1;
    int start = 0;
    int n = str.length();

    int low, high;
    for (int i = 1; i < n; ++i)
    {
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    
    int end = low + maxLength - 1;
    cout << maxLength << endl;
    cout << low << endl;
    for (int i = low; i <= end; ++i)
    {
        cout << abcd[i];
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
/*

    Longest_Palindrome_SLOW(string S) {
        string S' = S with a bogus character (eg. '|') inserted between each character (including outer boundaries)
        array PalindromeRadii = [0,...,0] // The radius of the longest palindrome centered on each place in S'
        // note: length(S') = length(PalindromeRadii) = 2 × length(S) + 1

        Center = 0
        while Center < length(S') {
            // Determine the longest palindrome starting at Center-Radius and going to Center+Radius
            Radius = 0
            while Center-(Radius+1) >= 0 and Center+(Radius+1) < length(S') and S'[Center-(Radius+1)] = S'[Center+(Radius+1)] {
                Radius = Radius+1
            }

            // Save the radius of the longest palindrome in the array
            PalindromeRadii[Center] = Radius

            Center = Center+1
        }

        longest_palindrome_in_S' = 2*max(PalindromeRadii)+1
        longest_palindrome_in_S = (longest_palindrome_in_S'-1)/2
        return longest_palindrome_in_S
    }

*/