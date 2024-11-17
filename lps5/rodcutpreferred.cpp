#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cut_rod(int n, vector<int>& prices, vector<int>& preferred, vector<int>& mem) {
    if (n == 0) return 0;
    if (mem[n] != -1) return mem[n];

    int max_rev = -n;

    for (int length : preferred) {
        if (length <= n) {
            int current_rev = prices[length - 1] + cut_rod(n - length, prices, preferred, mem);
            max_rev = max(max_rev, current_rev);
        }
    }

    mem[n] = max_rev;
    return mem[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int n1;
    cin >> n1;

    vector<int> preferred(n1);
    for (int i = 0; i < n1; i++) {
        cin >> preferred[i];
    }

    vector<int> mem(n + 1, -1);

    cout << cut_rod(n, prices, preferred, mem) << endl;

    return 0;
}