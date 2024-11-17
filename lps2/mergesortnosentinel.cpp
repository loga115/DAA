#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
#include<limits.h>

void merge(vector<double> &elements, int left, int mid, int right)
{
	vector<double> lsubarray, rsubarray;
	int lsubno,rightsubno,i,leftindex,rightindex,index_full;
	lsubno = mid-left+1;
	rightsubno = right-mid;
	for(i=0;i<lsubno;i++)
		lsubarray.push_back(elements[left+i]);
	for(i=0;i<rightsubno;i++)
		rsubarray.push_back(elements[mid+i+1]);
	leftindex=0;
	rightindex=0;
    index_full = left;
	while (leftindex < lsubno && rightindex < rightsubno)
    {
        if(lsubarray[leftindex]< rsubarray[rightindex])
        {
            elements[index_full] = lsubarray[leftindex];
            leftindex++;
            index_full++;
        }
        else 
        {
            elements[index_full] = rsubarray[rightindex];
            rightindex++;
            index_full++;
        }
    }
    while (leftindex < lsubno)
    {
        elements[index_full] = lsubarray[leftindex];
        leftindex++;
        index_full++;
    }
    while (rightindex < rightsubno) {
        elements[index_full] = rsubarray[rightindex];
        rightindex++;
        index_full++;
    }
}
void mergesort(vector<double> &elements, int left, int right)
{
	int mid;
	if(right == left) {
		 return;
	}

	mid = (left+right)/2;
	mergesort(elements,left,mid);

	mergesort(elements,mid+1,right);

	merge(elements,left,mid,right);
}
int main()
{
	double n,i,ele;
	vector<double> elements;
	freopen("descending_50000.txt", "r", stdin);
	clock_t start = clock();
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}

	mergesort(elements, 0, n-1);
	clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed;
}