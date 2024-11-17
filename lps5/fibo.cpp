#include <iostream>
#include <vector>

using namespace std;

int fiba(int n, vector<int> &arr) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;
    if(arr[n] != -1) return arr[n];
    arr[n] = fiba(n-1, arr) + fiba(n-2, arr) + fiba(n-3, arr);
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1, -1);
    cout << fiba(n, arr) << endl;
    return 0;
}