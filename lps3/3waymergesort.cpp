#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
 
void merge(vector<double> &array1, int low, int mid1, 
           int mid2, int high, vector<double> &array2) 
{ 
    int i = low, j = mid1, k = mid2, l = low;
    while ((i < mid1) && (j < mid2) && (k < high)) 
    { 
        if(array1[i] < array1[j])
        {
            if(array1[i] < array1[k])
            {
                array2[l++] = array1[i++];
            }
            else
            {
                array2[l++] = array1[k++];
            }
        }
        else
        {
            if(array1[j] < array1[k])
            {
                array2[l++] = array1[j++];
            }
            else
            {
                array2[l++] = array1[k++];
            }
        }
    } 
    while ((i < mid1) && (j < mid2)) 
    { 
        if(array1[i] < array1[j])
        {
            array2[l++] = array1[i++];
        }
        else
        {
            array2[l++] = array1[j++];
        }
    } 
 
    while ((j < mid2) && (k < high)) 
    { 
        if(array1[j] < array1[k])
        {
            array2[l++] = array1[j++];
        }
        else
        {
            array2[l++] = array1[k++];
        } 
    } 
    while ((i < mid1) && (k < high)) 
    { 
        if(array1[i] < array1[k])
        {
            array2[l++] = array1[i++];
        }
        else
        {
            array2[l++] = array1[k++];
        } 
    } 
 
    while (i < mid1) 
        array2[l++] = array1[i++]; 
 
    while (j < mid2) 
        array2[l++] = array1[j++]; 
 
    while (k < high) 
        array2[l++] = array1[k++]; 
} 
 
 
/* Performing the merge sort algorithm on the 
given array of values in the rangeof indices 
[low, high). low is minimum index, high is 
maximum index (exclusive) */
void mergesort(vector<double> &array1, int low,
                      int high, vector<double> &array2) 
{ 
    // If array size is 1 then do nothing 
    if (high - low < 2) 
        return; 
 
    // Splitting array into 3 parts 
    int mid1 = low + ((high - low) / 3); 
    int mid2 = low + 2 * ((high - low) / 3) + 1; 
 
    mergesort(array2, low, mid1, array1); 
    mergesort(array2, mid1, mid2, array1); 
    mergesort(array2, mid2, high, array1); 
  
    merge(array2, low, mid1, mid2, high, array1); 
}
 
void mergesort3(vector<double> &array1, int n) 
{ 
    if (n == 0) 
        return; 
 
    vector<double> fArray(n); 
 
    for (int i = 0; i < n; i++) 
        fArray[i] = array1[i]; 
 
    // sort function 
    mergesort(fArray, 0, n, array1); 
 
    // copy back elements of duplicate array 
    // to given array 
    for (int i = 0; i < n; i++) 
        array1[i] = fArray[i]; 
}

int main()
{
	double n,i,ele;
	vector<double> elements;
    freopen("random_50000.txt", "r", stdin);
    clock_t start = clock();
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}
	mergesort3(elements,n);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed;
}