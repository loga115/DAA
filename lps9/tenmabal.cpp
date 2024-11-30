/*
Mutual-distinct-digit subset
    Let  D = {0,1,2,3,...9}.  We call 1 is the successor of 0, 2 is a successor of 1, ... and 9 is a successor of 8.
    A number (formed with the digits of D) in which all the digits from the left are in successive order,  
    is called as an LR-successive number (LRS-number).  
    789 is an LR-successive number where as 798 is not an LR-successive number.  
    Similarly, a number in which all the digits from the right  are in successive order,  
    is called as an RL-Successive number (RLS- number).  Two numbers are said to be digit-distinct number
     (dd-number) if there are no digits common between the  numbers. 123 and 789 are dd-numbers. 
      A set  S is said to be mutual-dd set if all the pairs of S are dd-numbers.   
      Given a set S that  consists of  either RLS-numbers or LRS-numbers, design a greedy-based 
     pseudocode to compute the maximum mutual-dd subset of S.  
     The elements of the  maximum mutual-dd subset shoul be returned in an increasing order. 
     There may be more than one maximum-mutual-dd subsets for S.  If  S= {123, 234, 789, 6789,  89}  
      then some maximum mutual-dd subsets of S are  : X1= {89,234}, X2= {89,123}, X3= {123, 789}.     
      In case, if there are more than one maximum mutual-dd subset of S, your code should output the set
       which has the smallest number among  the elements  of  X1,X2,X3.  In case, if the smallest number 
       occurs in more than one mutual-dd subset, your code should output the set  which  has both the smallest
        and the immediate bigger element to the smallest element among  the elements  of  X1,X2,X3. 
        In fact,   Your code should output the elements of X  in an ascending order.  
        Your code should output the cardinality also.  So, for the set S= {123, 234, 789, 6789,  89},
         your code should output, 2, {89,123}. In case, mutual-dd-subset of  the given set is empty,
          your code should output -1.

Input format:

Enter the number of elements of S: n (say)

Enter the first element of S:

Enter the second element of S:

....

....

Enter the n-th element of S :

 

Output format :

Cardinality of the set X:

First element of  X :

Second element of X:

....

last element of X:*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

bool isMutualDD(int a, int b)
{
    set<int> s;
    while (a)
    {
        s.insert(a % 10);
        a /= 10;
    }
    while (b)
    {
        if (s.find(b % 10) != s.end())
            return false;
        b /= 10;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    sort(S.begin(), S.end());
    vector<vector<int>> all_subsets;
    int max_size = 0;
    clock_t start = clock();
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(S[i]);
        for (int j = i + 1; j < n; j++)
        {
            bool mutual_dd = true;
            for (int k = 0; k < temp.size(); k++)
            {
                if (!isMutualDD(temp[k], S[j]))
                {
                    mutual_dd = false;
                    break;
                }
            }
            if (mutual_dd)
                temp.push_back(S[j]);
        }
        if (temp.size() >= max_size)
        {
            if (temp.size() > max_size)
            {
                all_subsets.clear();
                max_size = temp.size();
            }
            all_subsets.push_back(temp);
        }
    }

    if (max_size == 0)
    {
        cout << -1;
    }
    else
    {
        sort(all_subsets.begin(), all_subsets.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a < b;
        });
        vector<int> X = all_subsets[0];
        cout << max_size << endl;
        for (int i = 0; i < max_size; i++)
            cout << X[i] << endl;
    }
    cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}