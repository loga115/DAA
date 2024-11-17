#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(i + 1);
        }
        dp[0][0]=1;
        if (n==0) return dp[0];
        for (int i=1; i<=n; i++){
            dp[i][0]=1;
            dp[i][i]=1;
            for (int j=1; j<i; j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    vector<int> res = s.getRow(1);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}