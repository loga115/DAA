IPS 9

```cpp
void naive_string_matcher(string T, string P)
{
    int n = T.length();
    int m = P.length();
    
    // Iterate through the text
    for(int s = 0; s <= n - m; )
    {
        // Check for pattern match from the current position
        bool found = true;
        for(int i = 0; i < m; i++)
        {
            if(T[s+i] != P[i])
            {
                found = false;
                break;
            }
        }
        
        // If pattern found, print index and skip pattern length
        if(found)
        {
            cout << s << endl;
            s += m;
        }
        else
        {
            // Move to next position if no match
            s++;
        }
    }
}
```
