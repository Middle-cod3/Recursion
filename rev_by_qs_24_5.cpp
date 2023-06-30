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
/*
LIST : A list is a contigious container that allows us to inserting and erasing elems in constant time
        and iteratning in both direction.

SET : A set is a container that stores unique elems in perticular order.Every operation on a set
        taker 0(1) complexity in the avg case and takes 0(n) in the worst case.
MULTISET : A multiset is a associative container just like a set but only diff is it can store
            duplicate elems in perticular order.
UNORDERED_SET : A unorder set is a container that stores unique elems in no perticular order.
                And its sequence is last in first out. Every operation takes 0(1) complexity.
                in the avg case and takes 0(n) in the worst case.

MAP : Map is a associative container where each elems consists of a key value and a mapped value.
        Two mapped values can not have a same key value.
MULTMAP : Same as map but only diff is that it can stores duplicate elems.
UNORDERED_MAP : Same as map but diff is two mapped values can not have a same key value.
                The elems can be in any order.


*/
// ----------------------- HASHING -----------------------------------
// 2)Character hashing.(TC/SC)
void charHasing(string s)
{
    int n = s.size();
    // init hasharray 256 cz string can have uppercase or lowercase in ascii there are 256 letter mapped in a number
    int hash[256] = {0};
    for (int i = 0; i < n; i++)
    {

        hash[s[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;

        cout << hash[c] << endl;
    }
}
// TC-->> 0(N),N= length of the string
// SC-->>0(1)

// 3)Character hashing using map.(TC/SC)
void charHashMap(string s)
{
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }
}
// ----------------------- SORTING -----------------------------------
// 4)Selection sort's pseudo code.(TC/SC)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
// TC ---->> near about 0(n^2)
// SC ---->> 0(1)
// 5)Bubble sorts's pseudo code.(TC/SC)
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int k = 0; k <= i - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp = arr[k + 1];
                arr[k + 1] = arr[k];
                arr[k] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}
// TC ---->> near about 0(n^2)
// SC ---->> 0(1)
// 6)Merge sort explain.(TC/SC)
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {

        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
// 7)Quick sort explain.(TC/SC)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1,high);
    }
}
// ----------------------- RECURSION -----------------------------------
// 8)
// 9)
// 10)
// 11)

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
    // charHasing(s);
    // charHashMap(s);
    int n;
    cin >> n;

    vector<int> arr = {22, 11, 77, 99, 55};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // selectionSort(arr, n);
    // bubbleSort(arr, n);

    // mergeSort(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);
    printVector(arr);

    // End code here-------->>
    return 0;
}
