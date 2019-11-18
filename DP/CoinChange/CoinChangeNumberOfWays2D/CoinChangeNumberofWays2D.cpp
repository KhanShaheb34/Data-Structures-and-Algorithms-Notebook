#include <bits/stdc++.h>
using  namespace std ;

int table [100][100];

int count( int S[], int m, int n )
{
    table[0][0] = 1;
    
    //we started i from 1 in the loop beacuse we have to use the previous row that is row 0
    //to complete row 1
    //j is from 0 taka to the target taka

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= S[i - 1])
                table[i][j] = table[i - 1][j] + table[i][j - S[i - 1]];
            else
                table[i][j] = table[i - 1][j];
        }
    }

    return table[m][n];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 5;
    // n is the target value we want to make
    int ans = count(arr, m, n);
    cout << ans << endl;
    return 0;
}
