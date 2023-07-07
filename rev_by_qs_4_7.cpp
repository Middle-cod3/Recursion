#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// #####################END QS HERE #######################

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./i.txt", "r", stdin);
    freopen("./o.txt", "w", stdout);
#endif
    // First layout column 2 and then new group--->>>
    // Start code from here ------>>
    int n = 4;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    for (auto it : board)
    {
        cout << it << " ";
    }
    cout << endl;

    // End code here-------->>
    return 0;
}
