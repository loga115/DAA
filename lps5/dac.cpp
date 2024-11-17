#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int crossing_sum(vector<int>& arr, int left, int mid, int right, int& lcross, int& rcross) {
    int sum = 0;
    int leftsum = INT_MIN;
    int rightsum = INT_MIN;
   
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightsum) {
            rightsum = sum;
            rcross = i;
        }
    }
    sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftsum) {
            leftsum = sum;
            lcross = i;
        }
    }

    

    return leftsum + rightsum;
}

int max_subarraysum(vector<int>& arr, int left, int right, int& start, int& end) {
    if (left == right) {
        start = left;
        end = right;
        return arr[left];
    }

    int mid = (left + right) / 2;
    int leftStart, leftEnd, rightStart, rightEnd, lcross, rcross;

    int leftsum = max_subarraysum(arr, left, mid, leftStart, leftEnd);
    int rightsum = max_subarraysum(arr, mid + 1, right, rightStart, rightEnd);
    int cross_sum = crossing_sum(arr, left, mid, right, lcross, rcross);

    if (leftsum >= rightsum && leftsum >= cross_sum) {
        start = leftStart;
        end = leftEnd;
        return leftsum;
    } else if (rightsum >= leftsum && rightsum >= cross_sum) {
        start = rightStart;
        end = rightEnd;
        return rightsum;
    } else {
        start = lcross;
        end = rcross;
        return cross_sum;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    int max_sum = max_subarraysum(arr, 0, n - 1, start, end);

    cout << start + 1 << endl;  
    cout << end + 1 << endl;    
    cout << max_sum << endl;    
    return 0;
}
