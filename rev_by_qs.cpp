#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// #####################START QS HERE #######################
// ----------------------- STL -----------------------------------
// 1) Explain SET,MAP,LIST.
// ----------------------- HASHING -----------------------------------
// 2)Character hashing.(TC/SC)
// 3)Character hashing using map.(TC/SC)
// ----------------------- SORTING -----------------------------------
// 4)Selection sort's pseudo code.(TC/SC)
// 5)Bubble sorts's pseudo code.(TC/SC)
// 6)Merge sort explain.(TC/SC)
// 7)Quick sort explain.(TC/SC)
// ----------------------- RECURSION(TC/SC) -----------------------------------
// 8)Print N to 1 using backtracking
// 9)Sum of first n numbers using parameterise
// 10)Sum of first n numbers using functional
// 11) Check if given string is palindrome or not
// 12) Print Fibonacci number upto n
// 13)Print all subsequences whose sum is K

// #####################END QS HERE #######################
void generatePermutations(vector<int> &arr,  vector<vector<int>> &ans, vector<int> &ds, int freq[])
{
  if (ds.size() == arr.size())
  {
    ans.push_back(ds);
    return;
  }
  for (int i = 0; i < arr.size(); i++)
  {
    if (!freq[i])
    {
      ds.push_back(arr[i]);
      freq[i] = 1;
      generatePermutations(arr, ans, ds, freq);
      ds.pop_back();
      freq[i] = 0;
    }
  }
}
vector<vector<int>> permutation(vector<int> &arr, int n)
{
  vector<vector<int>> ans;
  vector<int> ds;
  int freq[arr.size()];
  for (int i = 0; i < n; i++)
  {
    freq[i] = 0;
  }
  sort(arr.begin(),arr.end());
  generatePermutations(arr,ans, ds, freq);
  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("./i.txt", "r", stdin);
  freopen("./o.txt", "w", stdout);
#endif
  // First layout column 2 and then new group--->>>
  // Start code from here ------>>

  vector<int> arr = {3, 2, 1};
  int n = 3;
  vector<vector<int>> z = permutation(arr, n);
  for (auto it : z)
  {
    cout << "[";
    for (auto y : it)
    {
      cout << y << " ";
    }
    cout << "]";
    cout << endl;
  }

  // End code here-------->>
  return 0;
}
