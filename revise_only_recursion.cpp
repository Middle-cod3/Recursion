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
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
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
P.Statement :-Input: arr=[3,2,1] Output:[{},{1},{2},{2,1},{3},{3,1},{3,2},{3,2,1}]
Ans:- A contigious or non-contigious sequence that follows the order.
Tc :- For every index there are couple of options 2^n * for every subsequences we're using for loop
    to print, so its 0(2^n x n)
Sc :- If you look out recursion tree its going from starting index to ending index not more then
    ending index ,Max recursion calls == size of the array, so its 0(N)
*/
vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            // check if the ith bit is set or not
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        if (sub.length() > 0)
        {
            ans.push_back(sub);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
void printAllSubsequencesOptimal(int ind, int N, int arr[], vector<int> ds)
{
    if (ind == N)
    {
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // Pick
    ds.push_back(arr[ind]);
    printAllSubsequencesOptimal(ind + 1, N, arr, ds);
    // Not Pick
    ds.pop_back();
    printAllSubsequencesOptimal(ind + 1, N, arr, ds);
}

/*
2. Print all subsequences whose sum is K
P.Statement :-Input: arr=[1,2,1],sum=2 Output:[{1,1},{2}]
Tc :- There'er n indexes so here 2 options either pick neither no pick ,So its 0(2n)
*/
void printAllSubsequencesWhoseSumIsK(int ind, int sum, int N, int arr[], vector<int> ds, int K)
{
    if (ind == N)
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
    // Pick
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printAllSubsequencesWhoseSumIsK(ind + 1, sum, N, arr, ds, K);
    // Not Pick
    ds.pop_back();
    sum -= arr[ind];
    printAllSubsequencesWhoseSumIsK(ind + 1, sum, N, arr, ds, K);
}
/*
3. print any subsequences whose sum is K
P.Statement :-Input: arr=[1,2,1],sum=2 Output:[{1,1}]
Tc :- There'er n indexes so here 2 options either pick neither no pick ,So its 0(2n)
*/
bool printAnySubsequencesWhoseSumIsK(int ind, int sum, int N, int arr[], vector<int> ds, int K)
{
    if (ind == N)
    {
        if (sum == K)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            return true;
        }
        return false;
    }
    // Pick
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (printAnySubsequencesWhoseSumIsK(ind + 1, sum, N, arr, ds, K) == true)
    {
        return true;
    }
    // Not Pick
    ds.pop_back();
    sum -= arr[ind];
    if (printAnySubsequencesWhoseSumIsK(ind + 1, sum, N, arr, ds, K) == true)
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
int countSubsequencesWhoseSumIsK(int ind, int sum, int N, int arr[], int K)
{
    if (ind == N)
    {
        if (sum == K)
        {
            return 1;
        }
        return 0;
    }
    // Pick
    sum += arr[ind];
    int l = countSubsequencesWhoseSumIsK(ind + 1, sum, N, arr, K);
    // Not Pick
    sum -= arr[ind];
    int r = countSubsequencesWhoseSumIsK(ind + 1, sum, N, arr, K);
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
void findCombinationSumI(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // Pick
    if (arr[ind] <= target) // We can take same elem so not incrementing index thats why we are looping it
    {

        ds.push_back(arr[ind]);
        findCombinationSumI(ind, arr, ans, ds, target - arr[ind]);
        ds.pop_back();
    }
    // Not Pick
    findCombinationSumI(ind + 1, arr, ans, ds, target);
}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinationSumI(0, arr, ans, ds, target);
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
void findCombinationSumIIBruteforce(int ind, vector<int> &arr, int target, set<vector<int>> &ans, vector<int> &ds)
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
        ds.push_back(arr[ind]);
        findCombinationSumIIBruteforce(ind + 1, arr, target - arr[ind], ans, ds);
        ds.pop_back();
    }
    findCombinationSumIIBruteforce(ind + 1, arr, target, ans, ds);
}
set<vector<int>> combinationSumIIBruteforce(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;
    vector<int> ds;
    findCombinationSumIIBruteforce(0, arr, target, ans, ds);
    return ans;
}
// This is Optimal(using pick subsequences)------------------->>
// TC :-
void findCombinationSumIIoptimal(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds)
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
        findCombinationSumIIoptimal(i + 1, arr, target - arr[i], ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSumIIoptimal(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinationSumIIoptimal(0, arr, target, ans, ds);
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
void findSubsetsI(int ind, vector<int> &arr, int sum, int N, vector<int> &ans)
{
    if (ind == N)
    {
        ans.push_back(sum);
        return;
    }
    findSubsetsI(ind + 1, arr, sum + arr[ind], N, ans);
    findSubsetsI(ind + 1, arr, sum, N, ans);
}
vector<int> subsetSumI(vector<int> &arr, int N)
{
    vector<int> ans;
    findSubsetsI(0, arr, 0, N, ans);
    sort(ans.begin(), ans.end());
    return ans;
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
void findSubsetsIIBetter(int ind, vector<int> &arr, int N, set<vector<int>> &ans, vector<int> &ds)
{
    if (ind == N)
    {
        ans.insert(ds);

        return;
    }
    ds.push_back(arr[ind]);
    findSubsetsIIBetter(ind + 1, arr, N, ans, ds);
    ds.pop_back();
    findSubsetsIIBetter(ind + 1, arr, N, ans, ds);
}

vector<vector<int>> subsetSumIIBetter(vector<int> &arr, int N)
{
    set<vector<int>> ans;
    vector<int> ds;
    vector<vector<int>> res;
    findSubsetsIIBetter(0, arr, N, ans, ds);
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        res.push_back(*it);
    }
    return res;
}
// Optimal Approach--->----->
void findSubsetsIIOptimal(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        findSubsetsIIOptimal(i + 1, arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> subsetSumIIOptimal(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findSubsetsIIOptimal(0, arr, ans, ds);
    return ans;
}

/*
TC :-Since we are generating 2^n subset, so it's 2^n for recursive call. We are getting all subset that is DS and we put this DS into another DS so just putting will take some time so assume that the length of every subset is n so its 0(2^n+n)
SC :- At worst 2^n subsets going to store in ans so its 2^n and everyone has a length K so its 0(2^n)*0(K)
*/
/*
9. Print All Permutation of Array
Ans:-Given a array nums of distinct integer. Return all possible permutations. You can return answer in any order.
    Input :- vector<int>z={1,2,3}; Output :-[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
TC:-
Sc:-
*/
// Approach 1(Using extra space for remember elem picked)-------->>
// TC :- We know there're n! permutations generating & we loop from 0->n so its 0(n!*n)
// SC :- If we ignore that ans store n! permutations then we're usign 0(n) for the DS and 0(n) for map array
// This map is extra so 0(n)+0(n) ;Also if you ignore auxiliary sapce that's 0(n) for recursion call bcz its depth of recursion.
void generatePermutations(vector<int> &arr, int freq[], vector<vector<int>> &ans, vector<int> &ds)
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        for (auto it : ans)
        {
            for (auto e : it)
            {
                cout << "Answer-- " << e;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        // if (i == 1)
        //     break;
        if (!freq[i])
        {

            ds.push_back(arr[i]);
            freq[i] = 1;
            generatePermutations(arr, freq, ans, ds);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
vector<vector<int>> printPermutations(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()];
    for (int i = 0; i < arr.size(); i++)
    {
        freq[i] = 0;
    }
    generatePermutations(arr, freq, ans, ds);
    return ans;
}
// Approach 2 (using swap technique)-------->>
// TC :-  We know there're n! permutations generating & we loop from 0->n so its 0(n!*n)
// SC :-We're not using any ds nither any map.Only using auxiliary space of the recursion depth 0(n),so its 0(1)
void generatePermutaionsAp2(int ind, vector<int> &arr, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = ind; i < arr.size(); i++)

    {
        swap(arr[ind], arr[i]);
        generatePermutaionsAp2(ind + 1, arr, ans);
        swap(arr[ind], arr[i]);
    }
}
vector<vector<int>> printPermutationAp2(vector<int> &arr)
{
    vector<vector<int>> ans;
    generatePermutaionsAp2(0, arr, ans);
    return ans;
}

/*
10. N Queen Peoblem
Ans :- PLacing N Queens on n*n chessboard such that no two queens can attack each other.
Given n,return all distinct solution to the n-queens puzzle.
TC :- Exponential in nature since we're trying out al ways, to be precise it si 0(N!*N)
SC :- 0(N^2)
*/
// Approach 1 using
bool isSafe(int row, int col, vector<string> board, int n)
{ // check upper left corner
    int duprow = row, dupcol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')

            return false;
        row--;
        col--;
    }
    // check for left mid
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')

            return false;
        col--;
    }
    // check for lower left corner
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')

            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{                 // here we take col=0 insted of ind=0 bcz col start with 0 but row is changing like going top to bottom
    if (col == n) // If we complete to go start to end
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {                                   // Going for every row and check that can we place Q here
        if (isSafe(row, col, board, n)) // only checking that at perticuler place there already Q have or not then Also for 3 direction
        {
            board[row][col] = 'Q';         // fill q
            solve(col + 1, board, ans, n); // going to next column
            board[row][col] = '.';         // if we can't place q here then place .
        }
    }
}
vector<vector<string>> solveNqueens(int n)
{
    vector<vector<string>> ans; // return ans
    vector<string> board(n);    // creating board
    string s(n, '.');           // fill with ....,....,....,....
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n); // call for solving
    return ans;
}
// Approach 2 using Hashing to maintain a list to check wheather this position is right or not
/*
TC :- Exponential in nature since we're trying out al ways, to be precise it si 0(N!*N)
SC :- 0(N)
*/
void solveAp2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) // checking in perticiler spot that is it 0 or 1
        {
            // first place Q then
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solveAp2(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNqueensAp2(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); // init diff sizes vectors fill with 0 || 2n-1=2*4-1=7 bcz at max row+col=7
    solveAp2(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
/*
11. Sudoku Solve
Ans :- Write a program to solve a sudoku puzzle by filling the empty sell.
Rule are i) Each digit 1-9 must occure exactly once in each row and column
ii)Each of digit must iccure in 3x3 sub-boxes in grid
TC :-
SC :-
*/
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

/*
12. M coloring problem (skipping for now)
*/
/*
13. Palindrome Pertionaing
ANS :-Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s. A palindrome string is a string that reads the same backwards as forward.
TC :- O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure,
where k  is the average length of the palindrome list.Time Complexity: O( (2^n) *k*(n/2) )
SC :- The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer.
The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n). Space Complexity: O(k * x)
*/
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void partitionHelper(int ind, string s, vector<string> &path, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = ind; i < s.size(); i++) // we're tying partition like a|a|b|b| so its a loop
    {
        // when can you partition? when elem is palindrom you can like a|abb substring  a itself is a palindrome
        if (isPalindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1)); // a=(0,0) | a=(0,1) | b=(0,2) | b=(0,3)
            partitionHelper(i + 1, s, path, ans);       // Go for next partition
            path.pop_back();                            // remove elem from path other wise for next recursion call same elem along with new elem will addred bcz we are usng refrence of path
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> path;
    partitionHelper(0, s, path, ans);
    return ans;
}
/*
13. Permutation sequence
AND :- Given n & K return Kth permutation set.
Input : int n=3,K=3;
Output :"2 1 3";
*/
// Generate all possible permutations and store in another ds then sort it and return kth position permutation--->>
void permutationHelper(string &s, int index, vector<string> &res)
{
    if (index == s.size())
    {
        res.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
    }
}
string getPermutation(int n, int k)
{
    string s;
    vector<string> res;
    // create string
    for (int i = 1; i <= n; i++)
    {
        s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    // sort the generated permutations
    sort(res.begin(), res.end());
    // make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
}

// Approach 2 practice it carefully and understand it
/*
14. Rat in a maze
Ans :-
*/
void findPathHelper(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    // right
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (m[0][0] == 1)
        findPathHelper(0, 0, m, n, ans, "", vis);
    return ans;
}

// Coding Ninjas qs=================>>
// Good Numbers
// ANS: A number is called good if it's every digit (except the rightmost digit) is larger than the sum of digits on the right side of that digit.
// Find all the good numbers in the range from 'a' to 'b' (both inclusive), such that none of them contains 'digit' as a digit.
// Example :
// Input: 'a' = 840, 'b' = 850 and 'digit' = 6 Output: Good numbers = [840, 841, 842, 843, 850]
// Explanation: Consider 841:
// 8 > (4 + 1)
// 4 > 1
// Since each digit is greater than the sum of digits on right (except 1, which does not have any digit on its right), 841 is a good number. Similarly, all these numbers are good.
// Time complexity: O(b * log(b) - a * log(a))
// Space complexity: O(1)
bool goodWithoutDigit(int n, int digit)
{
    if (n % 10 == digit)
        return false;

    int sum = n % 10;
    n = n / 10;

    while (n > 0)
    {
        if (n % 10 == digit || n % 10 <= sum)
            return false;

        sum += n % 10;
        n /= 10;
    }

    return true;
}

vector<int> goodNumbers(int a, int b, int digit)
{
    vector<int> ans;

    for (int i = a; i <= b; i++)
    {
        if (goodWithoutDigit(i, digit))
            ans.push_back(i);
    }

    return ans;
}

// ============================EXTRA============================>>
/*
Pow(x, n)
ANS :
*/
// Bruteforce:
// TC: O(N)
// SC:
double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
    }
    long num = abs(n);
    double pow = 1;
    while (num)
    {
        cout << "Num " << num << endl;
        cout << "X " << x << endl;
        cout << "Pow " << pow << endl;
        if (num & 1)
            pow *= x;
        x *= x;
        num >>= 1;
    }
    return pow;
}
// Better:
// TC:
// SC:
// Optimal:
// TC:
// SC:

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    // First layout column 2 and then new group--->>>
    // Start code from here ------>>
    // int arr[] = {1, 2,3};
    // int N = 3;
    // int K = 2;
    // vector<int> ds;
    // printAllSubsequencesOptimal(0, N, arr, ds);
    // printAllSubsequencesWhoseSumIsK(0, 0, N, arr, ds, K);
    // printAnySubsequencesWhoseSumIsK(0, 0, N, arr, ds, K);
    // cout << countSubsequencesWhoseSumIsK(0, 0, N, arr, K);
    // vector<int> arr = {1, 2, 3};
    // int target = 2;
    // vector<vector<int>> z = combinationSum(arr, target);
    // set<vector<int>> z = combinationSumIIBruteforce(arr, target);
    // vector<vector<int>> z = combinationSumIIoptimal(arr, target);
    // for (auto it : z)
    // {
    //     cout << "[";
    //     for (auto y : it)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "]";
    //     cout << endl;
    // }
    // vector<int> z = subsetSumI(arr, target);
    // printVector(z);
    // vector<vector<int>> z = subsetSumIIBetter(arr, target);
    // vector<vector<int>> z = subsetSumIIOptimal(arr);
    // vector<vector<int>> z = printPermutations(arr);
    // vector<vector<int>> z = printPermutationAp2(arr);
    // printVectorVector(z);
    // N-queen problem
    // int n = 4; // bcz we're using n*n chessboard

    // vector<vector<string>> ans = solveNqueens(n);
    // vector<vector<string>> ans = solveNqueensAp2(n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << "Arrangments " << i + 1 << "\n";
    //     for (int j = 0; j < ans[0].size(); j++)
    //     {
    //         cout << ans[i][j];
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // Sudoku puzzle solve
    // vector<vector<char>> board{
    //     {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
    //     {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
    //     {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
    //     {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
    //     {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
    //     {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
    //     {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
    //     {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
    //     {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    // solveSudoku(board);

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //         cout << board[i][j] << " ";
    //     cout << "\n";
    // }
    // Palindrom paertitioning
    // string s = "aabb";
    // vector<vector<string>> z = partition(s);
    // for (auto it : z)
    // {
    //     cout << "[";
    //     for (auto y : it)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "]";
    //     cout << endl;
    // }
    // Permutation sequence
    // int n = 3, K = 3;
    // string ans = getPermutation(n, K);

    // cout << ans;
    // Rat in a maze
    // int n = 4;
    // vector<vector<int>> m = {{1, 0, 0, 0},
    //                          {1, 1, 0, 1},
    //                          {1, 1, 0, 0},
    //                          {0, 1, 1, 1}};
    // vector<string> result = findPath(m, n);
    // if (result.size() == 0)
    // {
    //     cout << -1;
    // }
    // else
    // {
    //     for (int i = 0; i < result.size(); i++)
    //     {
    //         cout << result[i] << " ";
    //     }
    //     cout << endl;
    // }
    // vector<int> ans = goodNumbers(840, 850, 6);
    // printVector(ans);
    // cout << "POW " << myPow(2, 10);

    // End code here-------->>
    return 0;
}
