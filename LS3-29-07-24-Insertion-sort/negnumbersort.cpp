/*Insertion sort with Negative numbers
Given a sequence of n numbers (integers), write an algorithm and the corresponding code to arrange the given n numbers are arranged in such a way that 
all the negative numbers (if any) are arranged in a descending order and all the positive numbers are arranged in an increasing order with 
zero (if it is in the input) appearing between the smallest negative number and the smallest positive number.

Input:

5

-5

6

0

-2

1
Output:

-2

-5

0

1

6
*/
#include <cstdio>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    int n, arr[n];
    freopen("asc_neg_10.txt", "r", stdin);
    clock_t start = clock();
    cin >> n;   
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) { // Insertion sort
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    int i = 0;
    while(arr[i] < 0) {
        i++;
    }
    i--;
    //reverse insertion sort for negative numbers
    for(int j = 0; j <= i; j++) {
        int key = arr[j];
        int k = j - 1;
        while(k >= 0 && arr[k] < key) {
            arr[k + 1] = arr[k];
            k = k - 1;
        }
        arr[k + 1] = key;
    }
    //cout<<" Number of shifts "<<num_comp<<endl;
      clock_t end = clock();
      double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed;
   /* for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    */
    
}