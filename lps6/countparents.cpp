
#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
#include <ctime>

using namespace std;

int countParenthesizations(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        return 0;
    }
    clock_t start = clock();
    int ways = countParenthesizations(n - 1);
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "time in sec: " << elapsed << endl;
    cout << ways << endl;
    return 0;
}