/*
Problem Description: Median of Two Sorted Arrays
Objective: Given two sorted arrays nums1 and nums2 of size m and n respectively, find the median of the two sorted arrays. The overall run-time complexity should be O(log(min(m,n))).

Input:

Two sorted arrays nums1 and nums2.
Output:

A single number representing the median of the two sorted arrays.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> combineArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> sorted(0);
    int t1=0, t2=0;
    while ( t1<n1 && t2<n2 ){
        if (arr1[t1] < arr2[t2]){
            sorted.push_back(arr1[t1++]);
        }
        else {
            sorted.push_back(arr2[t2++]);
        }
    }
    while (t1<n1)
        sorted.push_back(arr1[t1++]);
    while (t2<n2)
        sorted.push_back(arr2[t2++]);
    return sorted;
}




int main(){
    vector<int> n1 = {1,3,5,9};
    vector<int> n2 = {2,4,6,8};
    vector<int> n3 = combineArrays(n1,n2);
    int n = n1.size() + n2.size();
    cout << n3[((n+1)/2)-1];
    return 0;
}