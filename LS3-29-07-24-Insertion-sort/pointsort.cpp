/*Given a sequence of n letters from English alphabet (only lower case) where all the lowercase alphabet a,b,c,….z are assigned with values 1,2,3,…,26 respectively. 
Write an insertion-sort based algorithm to arrange the given n letters, in an increasing order of their values.
Enter the n-th alphabet
Output format:
Alphabet in the increasing order of their values
Example:
Input:
5

t

h

e

r

e

Output:

e

e

h

t

r

*/

#include <iostream>
using namespace std;

int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i < n; i++)
    {
        int key_x = x[i];
        int key_y = y[i];
        int j = i - 1;
        while (j >= 0 && (x[j] > key_x || (x[j] == key_x && y[j] > key_y)))
        {
            x[j + 1] = x[j];
            y[j + 1] = y[j];
            j = j - 1;
        }
        x[j + 1] = key_x;
        y[j + 1] = key_y;
    }
    int min_x = x[0], min_y = y[0];
    for (int i = 1; i < n; i++)
    {
        int key_x = x[i];
        int key_y = y[i];
        int j = i - 1;
        while (j >= 0 && dist(min_x, min_y, x[j], y[j]) > dist(min_x, min_y, key_x, key_y))
        {
            x[j + 1] = x[j];
            y[j + 1] = y[j];
            j = j - 1;
        }
        x[j + 1] = key_x;
        y[j + 1] = key_y;
    }
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl << y[i] << endl;
    }
    return 0;
}