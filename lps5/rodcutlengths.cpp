/*
Modify the bottom up dynamic programming code written to solve rod cutting problem  
to print the size of the pieces that we should cut the rod to get maximum revenue.
*/

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class result {
    public:
    int max_profit;
    vector<int> pieces;
};

int maximum(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

result bottom_up_cut_rod(vector<int> &p, int length)
{
    vector<int> r(100,0);
    vector<int> s(100,0);
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        for(i=1;i<=j;i++)
        {
            if(q<p[i-1]+r[j-i])
            {
                q = p[i-1]+r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    result res;
    res.max_profit = r[length];
    int n = length;
    while(n>0)
    {
        res.pieces.push_back(s[n]);
        n = n - s[n];
    }
    return res;
}

int main()
{
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    result res = bottom_up_cut_rod(p,n);
    for(i=0;i<res.pieces.size();i++)
    {
        cout<<res.pieces[i]<<" ";
    }
    cout<<res.max_profit;
}