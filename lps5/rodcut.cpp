/* A variation of rod cutting problem is one in which length of the rod will be of length greater than or equal to 8 
and you can make cuts of rods of length 3 or 5 only. For each unit of wastage a penalty of Rs.1 should be given.
 Write an recursive algorithm and implement it to find the maximum  revenue that may be generated. */
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int maximum(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int cut_rod(int three, int five, int length)
{
    int q=INT_MIN;
    if(length==0)
        return 0;
    if (length<0)
        return INT_MIN;
    if(length<3)
        return -(length);
    if(length==3)
        return three;
    if(length==5)
        return five;
    q = maximum(q,three+cut_rod(three,five,length-3));
    q = maximum(q,five+cut_rod(three,five,length-5));
    return q;
}

int main()
{
    int three,five,length;
    cin >> length >> three >> five;
    clock_t start = clock();
    int max_profit = cut_rod(three,five,length);
    clock_t end = clock();
    cout << max_profit;
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken: " << elapsed << endl;
    return 0;
}
