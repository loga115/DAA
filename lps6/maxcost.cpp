/*
Modify the algorithm developed in problem 4 (matrix chain multiplication problem) to find the way to parenthesize that will have maximum number of multiplications. Print the matrices with parenthesis that will have maximum number of multiplications as well. For example given three matrices and dimension as follows:

4
10 100 5 50

The code must print the m table as 
5000 75000 
25000 

S table as
1 1 
2 

Maximum cost is
75000

Paraenthesization of matrices is 
(A1(A2A3))

Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the maximum cost

Print the parenthesization that will lead to maximum cost

 

Example:

Input:

4

10 100 5 50

Output:

5000 75000

25000

1 1

2

75000

(A1(A2A3))*/

/*
void matrix_chain_mul_top_down(int i, int j, vector<int> &p, vector<vector<int>>& m, vector<vector<int>>& s) {
    if (i == j) {
        m[i][j] = 0;
        return;
    }
    if (m[i][j] != -1) {
        return;
    }
    m[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        matrix_chain_mul_top_down(i, k, p, m, s);
        matrix_chain_mul_top_down(k + 1, j, p, m, s);
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
}
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void matrix_chain_mul_top_down(int i, int j, vector<int> &p, vector<vector<int>>& m, vector<vector<int>>& s) {
    if (i == j) {
        m[i][j] = 0;
        return;
    }
    if (m[i][j] != -1) {
        return;
    }
    m[i][j] = INT_MIN;
    for (int k = i; k < j; k++) {
        matrix_chain_mul_top_down(i, k, p, m, s);
        matrix_chain_mul_top_down(k + 1, j, p, m, s);
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q > m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
}

void print_optimal_parens(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> m(n, vector<int>(n, -1));
    vector<vector<int>> s(n, vector<int>(n, 0));

    matrix_chain_mul_top_down(1, n - 1, p, m, s);

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    cout << m[1][n - 1] << endl;

    print_optimal_parens(s, 1, n - 1);
    cout << endl;

    return 0;
}