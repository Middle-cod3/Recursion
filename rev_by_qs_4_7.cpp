#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it<<" ";
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
// #####################START QS HERE #######################
// ----------------------- STL -----------------------------------
// 1) Explain SET,MAP,LIST.
// ----------------------- HASHING -----------------------------------
// 2)Character hashing.(TC/SC)

// 3)Character hashing using map.(TC/SC)
// ----------------------- SORTING -----------------------------------
// 4)Selection sort's pseudo code.(TC/SC)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n-2; ++i)
    {

        int mini = i;
        for (int j = i; j <= n-1; ++j)
        {

            if (arr[j]<arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./i.txt", "r", stdin);
    freopen("./o.txt", "w", stdout);
#endif
    // First layout column 2 and then new group--->>>
    // Start code from here ------>>
    // string s = "AyanRana";
    // charHashing(s);
    int n = 5;
    int arr[5] = {3, 6, 9, 2, 4};
    selectionSort(arr, n);
    printArray(arr,n);

    // End code here-------->>
    return 0;
}
