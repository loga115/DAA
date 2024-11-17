#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
using namespace std;

int main() {
    int n;
    freopen("random_50000.txt", "r", stdin);
    clock_t start = clock();
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int minSum = INT_MAX;
    int currentSum = 0;
    int startIndex = 0, tempStart = 0, endIndex = 0, tempEnd = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += arr[i];

        if (currentSum < minSum) {
            minSum = currentSum;
            startIndex = tempStart;
            endIndex = i;
        }
        
        if (currentSum == minSum) { // compare minimum subarray length here
            if (i - tempStart < endIndex - startIndex) {
                startIndex = tempStart;
                endIndex = i;
            }
        }

        if (currentSum > 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    clock_t end = clock();
    cout << "Time taken: " << (double)(end - start) << endl;
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed<<" time" << endl;
    cout << startIndex+1 << endl;
    cout << endIndex+1 << endl;
    cout << minSum << endl;

    return 0;
}