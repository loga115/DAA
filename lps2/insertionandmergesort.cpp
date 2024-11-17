// Merge-sort for right subarrays and Insertion-sort for right subarrays
// modify the mergesort algorithm such that the left side is divided
// down to 1 while the right is untouched and sorted with insertion sort


#include <iostream>
#include <vector>

using namespace std;

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

void insertionsort(vector<double> &elements, int left, int right)
{
    int i,j;
    double key;
    for(i=left+1;i<=right;i++)
    {
        key = elements[i];
        j = i-1;
        while(j>=left && elements[j]>key)
        {
            elements[j+1] = elements[j];
            j = j-1;
        }
        elements[j+1] = key;
    }
}


void mergesort(vector<double> &elements, int left, int right, int depth=0)
{
	int mid;

	
	if(right == left) {
		 return;
	}
	mid = (left+right)/2;
    mergesort(elements, left, mid, depth+1);
    if(depth==0)
        insertionsort(elements, mid+1, right);
    else {
        mergesort(elements, mid+1, right, depth+1);
        merge(elements, left, mid, right);
    }
}

int main() {
    int n,i;
    double ele;
    vector<double> elements;
    freopen("descending_100.txt", "r", stdin);
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

    return 0;
}


/*
6

5

5.5

6

3.723

1.23

8.88

*/