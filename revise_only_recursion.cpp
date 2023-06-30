#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Short function start-->>
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
        cout << it << " ";
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
// Short function end-->>
/*
1. Printing all subsequences
P.Statement :-Input: arr=[3,2,1] Output:[{},{1},{2},{2,1},{1},{1,1},{1,2},{1,2,1}]
Ans:- A contigious or non-contigious sequence that follows the order.
Tc :- For every index there are couple of options 2^n * for every subsequences we're using for loop
    to print, so its 0(2^n x n)
Sc :- If you look out recursion tree its going from starting index to ending index not more then
    ending index ,Max recursion calls == size of the array, so its 0(N)
*/
void printAllSubsequences(int ind, int n, int arr[], vector<int> ds)
{
    // Base condition
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // Pick elem
    ds.push_back(arr[ind]);
    printAllSubsequences(ind + 1, n, arr, ds);
    // Not Pick elem
    ds.pop_back();
    printAllSubsequences(ind + 1, n, arr, ds);
}
/*
2. Print all subsequences whose sum is K
P.Statement :-Input: arr=[1,2,1],sum=2 Output:[{1,1},{2}]
Tc :- There'er n indexes so here 2 options either pick neither no pick ,So its 0(2n)
*/
void printAllSubsequencesWhoseSumIsK(int ind, int n, int arr[], vector<int> ds, int sum, int K)
{
    if (ind == n) // Here we dont write or bcz if ind=3 but sum != K then function will not return
    {
        if (sum == K)
        {

            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    // pick elem
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printAllSubsequencesWhoseSumIsK(ind + 1, n, arr, ds, sum, K);
    ds.pop_back();
    sum -= arr[ind];
    printAllSubsequencesWhoseSumIsK(ind + 1, n, arr, ds, sum, K);
}
/*
3. print any subsequences whose sum is K
P.Statement :-Input: arr=[1,2,1],sum=2 Output:[{1,1}]
Tc :- There'er n indexes so here 2 options either pick neither no pick ,So its 0(2n)
*/
bool printAnySubsequencesWhoseSumIsK(int ind, int n, int arr[], vector<int> ds, int sum, int K)
{
    if (ind == n) // Here we dont write or bcz if ind=3 but sum != K then function will not return
    {
        if (sum == K)
        {

            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    // pick elem
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (printAnySubsequencesWhoseSumIsK(ind + 1, n, arr, ds, sum, K) == true)
    {
        return true;
    }
    ds.pop_back();
    sum -= arr[ind];
    if (printAnySubsequencesWhoseSumIsK(ind + 1, n, arr, ds, sum, K) == true)
    {
        return true;
    }
    return false;
}

/*
4. Count subsequences whose sum is K
P.Statement :-Input: arr=[1,2,1],sum=2 Output:2
Tc :- There'er n indexes so here 2 options either pick neither no pick ,So its 0(2n)
*/
int countSubsequencesWhoseSumIsK(int ind, int n, int arr[], int sum, int K)
{
    if (ind == n) // Here we dont write or bcz if ind=3 but sum != K then function will not return
    {
        if (sum == K)
            return 1;
        else
            return 0;
    }
    // pick elem
    sum += arr[ind];
    int l = countSubsequencesWhoseSumIsK(ind + 1, n, arr, sum, K);
    sum -= arr[ind];
    int r = countSubsequencesWhoseSumIsK(ind + 1, n, arr, sum, K);
    return l + r;
}
/*
5. Combination Sum I
P.Statement :-Input: candidates=[2,3,6,7],target=7 Output:[[2,2,3],[7]]
Ans :- Given an array of distinct candidates and a target return a list of all unique combination of
    candidates where the choosen number sum to target. You can return the combinations in any order.
TC :- O(2^t * k) where t is the target, k is the average length.Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
Why not (2^n) but (2^t) (where n is the size of an array)?
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
SC :- O(k*x), k is the average length and x is the no. of combinations
*/

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // Pick elem
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds); // did't increment index bcz elem might be multiple times appear.
        ds.pop_back();
    }
    // Not Pick
    findCombination(ind + 1, target, arr, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &com, int K)
{
    vector<vector<int>> ans; // to return a ans
    vector<int> ds;          // store combination
    findCombination(0, K, com, ans, ds);
    return ans;
}
/*
6. Combination Sum II
P.Statement :-Input: candidates=[10,1,2,7,6,1,5],target=8 Output:[[1,1,6],[1,2,5],[1,7],[2,6]]
Ans :- Given a collection of candidate numbers and a target number.
    Find all unique combination candidates where the candidates number sum up to target.
    (**)Each number in candidates may only be used once in the combination.
TC :- At previous time complexity was 0(2^t x K) and this K was putting a data structure into another data structure.
But now the time taken Klogn because we are putting a data structure K into a set.
Now here n is set size 0(2^t x Klogn)
*/

// This is Bruteforce(using set)--------------->>
void findCombinationBruteforce(int ind, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.insert(ds);
        }
        return;
    }
    if (arr[ind] <= target)
    {
        // Pick
        ds.push_back(arr[ind]);
        findCombinationBruteforce(ind + 1, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    // Not Pick
    findCombinationBruteforce(ind + 1, target, arr, ans, ds);
}
set<vector<int>> combinationSumIIBruteforce(vector<int> &com, int K)
{
    sort(com.begin(), com.end());
    set<vector<int>> ans; // using set it stores unique elems in a perticular order
    vector<int> ds;
    findCombinationBruteforce(0, K, com, ans, ds);
    return ans;
}

// This is Optimal(using pick subsequences)------------------->>
// TC :-
void findCombinationIIoptimal(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombinationIIoptimal(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSumIIoptimal(vector<int> &com, int K)
{
    sort(com.begin(), com.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinationIIoptimal(0, K, com, ans, ds);
    return ans;
}
/*
7. Subset Sum I
P.Statement :-Input: N=2,arr=[2,3] Output:0,2,3,5
Ans :-Given an List(arr) of N int .Print Sum of all subsets in it. Output should be print in a increasing order of sums.
TC :- There're n indexes and i'm having 2 ways for every of them then i can say easily that it will be 2^n for every recursive
solution but there's going to be an extra 2^nlog(2n) this is for using shorting the array. so its 0(2^n+2^Nlog(2n))
SC :- 0(2^N) bec possible subsets are 4.
*/
void subsetSum(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if (ind == N)
    {
        sumSubset.push_back(sum);
        return;
    }
    // Pick
    subsetSum(ind + 1, sum + arr[ind], arr, N, sumSubset);
    // Not Pick
    subsetSum(ind + 1, sum, arr, N, sumSubset);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sumSubset;
    subsetSum(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end()); // For increasing order output
    return sumSubset;
}
/*
8.Subset Sum II
P.Statement :-Input: arr=[1,2,2] Output:[[],[1],[1,2],[1,2,2],[2],[2,2]]
Ans :-Given an integer array nums that may contains duplicates.Return all possible subsets.
    The solution set must not contain duplicates subsets. Return the solution in any order.
TC :-After 2^n recursion,we were using extra time of converting into a
set and then re-converting it back into list of list, we know our subset is 2^n so set size will 
be 2^n when you put all those to set, it will be m*logm m=2^n its 0(2^n+mlogm)
SC :-
*/
// Better Approach--->----->
void subsetSumIIBruteforce(vector<int> &nums, int ind, vector<int> &ds, set<vector<int>> &res)
{
    if (ind == nums.size())
    {
        sort(ds.begin(), ds.end());

        res.insert(ds);
        return;
    }
    // Pick
    ds.push_back(nums[ind]);
    subsetSumIIBruteforce(nums, ind + 1, ds, res);
    // Not Pick
    ds.pop_back();
    subsetSumIIBruteforce(nums, ind + 1, ds, res);
}
vector<vector<int>> subsetSumsIIBruteforce(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> ds;
    set<vector<int>> res; // For filter duplicates
    subsetSumIIBruteforce(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;
}

// Optimal Approach--->----->
/*
TC :-Since we are generating 2^n subset, so it's 2^n for recursive call. We are getting all subset that is DS and we put this DS into another DS so just putting will take some time so assume that the length of every subset is n so its 0(2^n+n)
SC :- At worst 2^n subsets going to store in ans so its 2^n and everyone has a length K so its 0(2^n)*0(K)
*/
void findSubsetsOptimal(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] != nums[i - 1])//We prev sort the nums array, now we're checking duplicates
            continue;
        ds.push_back(nums[i]);
        findSubsetsOptimal(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetSumsIIoptimal(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsetsOptimal(0, nums, ds, ans);
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
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> ds;
    // printAllSubsequences(0, n, arr, ds);
    int K = 2;
    // printAllSubsequencesWhoseSumIsK(0, n, arr, ds, 0, K);
    // printAnySubsequencesWhoseSumIsK(0, n, arr, ds, 0, K);
    cout << countSubsequencesWhoseSumIsK(0, n, arr, 0, K);
    // vector<int> com = {10, 1, 2, 7, 6, 1, 5};
    // vector<int> com = {2, 1, 2};
    // int N = 2;
    // vector<vector<int>> y = combinationSum(com, K);
    // printVectorVector(y);
    // set<vector<int>> z = combinationSumIIBruteforce(com, K);
    // for (auto it : z)
    // {
    //     printVector(it);
    // cout << endl;
    // }
    // vector<vector<int>>z=combinationSumIIoptimal(com,K);
    // printVectorVector(z);
    // vector<int> z = subsetSums(com, N);
    // vector<vector<int>> z = subsetSumsIIBruteforce(com);
    // vector<vector<int>> z = subsetSumsIIoptimal(com);
    // for (auto it : z)
    // {
    //     cout << "[";
    //     printVector(it);
    //     cout << "]";
    //     cout << endl;
    // }

    // End code here-------->>
    return 0;
}
