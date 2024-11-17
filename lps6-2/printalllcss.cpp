#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void findl(const vector<vector<int>>& dp, const string& S1, const string& S2, int i, int j, string current_lcs, set<string>& lcs_set) {
    if (i == 0 || j == 0) {
        lcs_set.insert(current_lcs);
        return;
    }

    if (S1[i - 1] == S2[j - 1]) {
        findl(dp, S1, S2, i - 1, j - 1, S1[i - 1] + current_lcs, lcs_set);
    }
    else {
        if (dp[i - 1][j] == dp[i][j]) {
            findl(dp, S1, S2, i - 1, j, current_lcs, lcs_set);
        }
        if (dp[i][j - 1] == dp[i][j]) {
            findl(dp, S1, S2, i, j - 1, current_lcs, lcs_set);
        }
    }
}

void print_all_lcs(const string& S1, const string& S2) {
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    set<string> lcs_set;
    
    findl(dp, S1, S2, n, m, "", lcs_set);
    
    for (const string& lcs : lcs_set) {
        cout << lcs << endl;
    }
}

int main() {
    string S1, S2;
    cin >> S1 >> S2;
    print_all_lcs(S1, S2);
    
    return 0;
}