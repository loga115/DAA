/*
Coin Change Problem:

Given a set of coin denominations and a total amount of money, 
find the minimum number of coins needed to make up that amount. 
You can use an unlimited number of each coin.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
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
}*/

int denoms(int i, vector<int> &cdenoms, int money){
    if (money == 0 || i == n)
        return money == 0;
    int stay=0, next= denoms(i+1, cdenoms, money);
    if (arr[i] <= money)
        stay = 1 + denoms(i,cdenoms,money-arr[i]);
    




    else 

}

int main(){
    vector<int> coin_denoms;
    int money;

}