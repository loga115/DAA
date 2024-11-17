/*
 Design a DCC based algorithm to compute the product of two
 complex numbers aibi and c +id, and analyse the same.
 2. Given an array of integers A, Design a DCC based algorithm to
 compute the maximum integers in the array and analyse them.
2
 3. In a ‘Maximum subarray Problem’, you are given an array A of
 integers and the task is to find the nonnegative contiguous sub
array of A such that the sum of the values in the subarray is
 maximum. Here, there is no restriction on the size of the sub
array that has maximum sum. Based on this, we propose a new
 problem : ‘Maximum value Maximal subarray Problem’ where in
 the array of non-negative integers is taken as an input and the
 task is to return the non-negative contiguous subarray whose sum
 is maximum and the length of the subarray is minimal. Design a
 pseudocode for the Maximum value Maximal subarray Problem.
 4. Q.no.1, discusses the ‘Maximum value Maximal Subarray Prob
lem’. On the same lines,
 (a) Design a pseudocode for ‘Maximum value Minimal Subarray
 Problem’.
 (b) Design a pseudocode for ‘Minimum value Minimal Subarray
 Problem’.
 (c) Design a pseudocode for ‘Minimum value Maximal Subarray
 Problem’.
 5. In a ‘Maximum subarray Problem’, you are given an array A of
 integers and the task is to find the nonnegative contiguous subar
ray of A such that the sum of the values in the subarray is max
imum. Here, the subarray returned by the code is ‘contiguous’
 (cells of the subarray should be adjacent). Based on this, we pro
pose a new problem : ‘Maximum non-contiguous subarray Prob
lem’ where in the array of non-negative integers is taken as an
 input and the task is to return the non-negative non-contiguous
 subarraay whose sum is maximum and the subarray need not be
 contiguous.
 6. Consider an array of A[1,2,3,...,n] be an array of n distinct num
bers. If i < j and A[i] > A[j], then we call the the pair (i,j) as
 an inversion of A. For example, the five inversions in the array
 A :< 2,3,8,6,1 > are (1,5),(2,5),(3,4),(3,5),(4,5). Given an
 array of numbers, design the pseudocode and the corresponding
 code that follows ‘Divide-Conquer-Combine’ strategy for com
puting the number of inversions in the array and analyse the
 same.
3
 7. Given two square matrices of same size, Design an DCC based
 algorithm to compute the product of two matrices and analyse
 the same.
 8. Merge-sort algorithm (discussed in the class) works by partition
ing the input array A recursively into two halves. Here, the par
tition is based on the position in the array. Instead, design a new
 algorithm A’ where partioning is based on the values in the input
 array. Compare the performance of A’ with that of A.
 9. Given n 2-dimensional points (x1,y1),(x2,y2),...,(xn,yn), De
sign an algorithm that follows the ‘Divide-Conquer-Combine’ start
egy to
 (a) arrange the n−points in an increasing order of the x coordi
nates
 (b) arrange the n−points in an increasing order of the y coordi
nates
 (c) arrange the n − points in decreasing order of the value (x −
 coordinate + y −coordinate)/2) coordinate*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Complex
{
    int real;
    int imaginary;
};

Complex product(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

int main()
{
    Complex a, b;
    cout << "Enter the real and imaginary part of first complex number: ";
    cin >> a.real >> a.imaginary;
    cout << "Enter the real and imaginary part of second complex number: ";
    cin >> b.real >> b.imaginary;
    Complex result = product(a, b);
    cout << "Product of the two complex numbers is: " << result.real << " + " << result.imaginary << "i" << endl;
    return 0;
}

// Time Complexity: O(1)

// Space Complexity: O(1)

//q2:
int findMax(const vector<int>& arr, int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);

    return max(leftMax, rightMax);
}

int main()
{
    Complex a, b;
    cout << "Enter the real and imaginary part of first complex number: ";
    cin >> a.real >> a.imaginary;
    cout << "Enter the real and imaginary part of second complex number: ";
    cin >> b.real >> b.imaginary;
    Complex result = product(a, b);
    cout << "Product of the two complex numbers is: " << result.real << " + " << result.imaginary << "i" << endl;

    vector<int> arr;
    int n, element;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> element;
        arr.push_back(element);
    }

    int maxElement = findMax(arr, 0, n - 1);
    cout << "The maximum element in the array is: " << maxElement << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(log n) due to recursion stack
