// Modify the bottom up dynamic programming algorithm for LCS to print the length of the LCS by maintaining only recent two rows of ‘b’ table
// Input Format
// First line contains the first string, S1
// Next line contains the second string, S2
// Output Format
// Print the length of the longest LCS in the first line
// Example:
// Input:
// ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
// GTCGTTCGGAATGCCGTTGCTCTGTAAA
// Output:
// 20
// Algorithm in Cormen
// void lcs_length(string x, string y, vector<vector<int> >&c, vector<vector<char> > &b)
// {
//     int m,n,i,j;
//     m = x.length();
//     n = y.length();
//     for(i=1;i<=m;i++)
//     {
//         for(j=1;j<=n;j++)
//         {
//             if(x[i-1]==y[j-1])
//             {
//                 c[i][j] = c[i-1][j-1] + 1;
//                 b[i][j] = 'd';
//             }
//             else if(c[i-1][j]>=c[i][j-1])
//             {
//                 c[i][j] = c[i-1][j];
//                 b[i][j] = 'u';
//             }
//             else
//             {
//                 c[i][j] = c[i][j-1];
//                 b[i][j] = 'd';
//             }
//         }
//     }
// }
// void print_LCS(vector<vector<char> > &b, string x,int i, int j)
// {
//     if((i==0)||(j==0))
//         return ;
//     if(b[i][j]=='d')
//     {
//         print_LCS(b,x,i-1,j-1);
//         cout<<x[i-1];
//     }
//     else if(b[i][j]=='u')
//     {
//         print_LCS(b,x,i-1,j);
//     }
//     else
//         print_LCS(b,x,i,j-1);
// }
// int main()
// {
//     string x,y;
//     int i,j;
//     cin>>x>>y;
//     vector<vector<int> > c(x.length()+1,vector<int>(y.length()+1,0));
//     vector<vector<char> > b(x.length()+1,vector<char>(y.length()+1,' '));
//     lcs_length(x,y,c,b);
//     for(i=0;i<x.length()+1;i++)
//     {
//         for(j=0;j<y.length()+1;j++)
//             cout<<c[i][j]<<" ";
//         cout<<endl;
//     }
//     for(i=0;i<x.length()+1;i++)
//     {
//         for(j=0;j<y.length()+1;j++)
//             cout<<b[i][j]<<" ";
//         cout<<endl;
//     }
//     print_LCS(b,x,x.length(),y.length()-1);
// }
    #include<iostream>
    using namespace std;
    #include<limits.h>
    #include<vector>
    int main()
    {
        string x,y;
        int i,j;
        cin>>x>>y;
        vector<vector<int> > c(2,vector<int>(y.length()+1,0));
        vector<vector<char> > b(2,vector<char>(y.length()+1,' '));
        for(i=1;i<=x.length();i++)
        {
            for(j=1;j<=y.length();j++)
            {
                if(x[i-1]==y[j-1])
                {
                    c[1][j] = c[0][j-1] + 1;
                    b[1][j] = 'd';
                }
                else if(c[0][j]>=c[1][j-1])
                {
                    c[1][j] = c[0][j];
                    b[1][j] = 'u';
                }
                else
                {
                    c[1][j] = c[1][j-1];
                    b[1][j] = 'd';
                }
            }
            for(j=0;j<y.length()+1;j++)
            {
                c[0][j] = c[1][j];
                b[0][j] = b[1][j];
            }
        }
        cout<<c[1][y.length()];
    }