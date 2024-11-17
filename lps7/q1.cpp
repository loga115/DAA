// 1)Naive string matching without Overlapping
// Given a text T and a pattern P, implement the naive algorithm to print the non-overlapping positions of P in T. For example, if T is "aaaaaaaa" and pattern is "aa" then the code should print 0, 2, 4, 6 (programming indices - non-over lapping)
// Input Format
// First line contains the text, T
// Next line contains the pattern, P
// Output Format
// Print non-overlapping indices, one value in one line
// Example:
// Input:
// aaaaaaaa
// aa
// Output:
// 0
// 2
// 4
// 6

#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void naivestringmatcher(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m;) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << i << endl;
            i += m;
        } else {
            i++;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    clock_t start = clock();
    naivestringmatcher(text, pattern);
    clock_t end = clock();
    cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}