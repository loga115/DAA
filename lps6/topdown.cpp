    /*
    Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 
    7
    30 35 15 5 10 20 25

    M table should be printed as 

    15750 7875 9375 11875 15125 
    2625 4375 7125 10500 
    750 2500 5375 
    1000 3500 
    5000 
    S table should be printed as 
    1 1 3 3 3 
    2 3 3 3 
    3 3 3 
    4 5 
    5 
    */

    /*recursive code:
    // Recursive matrix chain multiplication
    #include<iostream>
    using namespace std;
    #include<vector>
    #include<limits.h>
    int matrix_chain_mul(int i, int j, vector<int> &p)
    {
        int min_cost = INT_MAX,k,left_cost,right_cost,total_cost;    
        if(i==j)
            return 0;
        for(k=i;k<j;k++)
        {       
            left_cost = matrix_chain_mul(i,k,p);
            right_cost = matrix_chain_mul(k+1,j,p);
            total_cost = left_cost + right_cost + p[i-1] * p[k] * p[j];
            if(total_cost<min_cost)
            {
                min_cost = total_cost;
                
            }
        }
        return min_cost;
    }
    */

    #include<iostream>
    #include<vector>
    #include<limits.h>

    using namespace std;

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
        cout << endl;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
        cout << m[1][n - 1] << endl;
        return 0;
    }