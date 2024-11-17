#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
#include<limits.h>
#include <cstdio>
#define swap(a,b) {double temp = a; a = b; b = temp;}

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
	
	lsubarray[lsubno] = INT_MAX;
	rsubarray[rightsubno] = INT_MAX;
	for(index_full=left;index_full<=right;index_full++)
	{
		if(lsubarray[leftindex]<=rsubarray[rightindex])
		{
			elements[index_full] = lsubarray[leftindex];
			leftindex++;
		}
		else 
		{
			elements[index_full] = rsubarray[rightindex];
			rightindex++;
		}
	}
}
void mergesort(vector<double> &elements, int left, int right)
{
	int mid;

	//add a condition to check if the size of the array is less than 3, then sort the array using if-else statements
	if(right - left < 2) {
		 if (right > left && elements[right] < elements[left]) {
			swap(elements[right], elements[left]);
		 }
		 return;
	}
	// Find mid of the array
	mid = (left+right)/2;
	// call mergesort for left subarray
	mergesort(elements,left,mid);
	// call mergesort for right subarray
	mergesort(elements,mid+1,right);
	// merge the sorted left and right subarray
	merge(elements,left,mid,right);
}
int main()
{
	int n,i,ele;
	vector<double> elements;
	freopen("ascending_100.txt", "r", stdin);
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