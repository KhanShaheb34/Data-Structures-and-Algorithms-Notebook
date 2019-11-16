
#include <bits/stdc++.h>
using  namespace std ;

int table [100][100];

int count( int S[], int m, int n )
{


    table[0][0] = 1;
    for(int i=0;i<=n;i++)
        cout<<i<<" ";
    cout<<endl;

    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(j>=S[i-1])
              table[i][j]= table[i-1][j]+table[i][j-S[i-1]];
            else
             table[i][j]= table[i-1][j];
        }
    }
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<table[i][j]<<" ";

        cout<<endl;
    }


return table[m][n];
}



int main()
{
    int arr[] = {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 5;
    int ans=count(arr, m, n);
    cout <<ans<<endl;
    return 0;
}
