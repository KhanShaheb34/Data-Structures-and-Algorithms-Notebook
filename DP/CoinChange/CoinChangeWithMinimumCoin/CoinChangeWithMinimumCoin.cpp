
#include<bits/stdc++.h>
using namespace std;


int minCoins(int coins[], int m, int V)
{
    // m is size of coins array (number of different coins)

    // table[i] will be storing the minimum number of coins
    // required for i value. So table[V] will have result
 
    int table[V + 1];

    //base case
    table[0] = 0;
    // Initialize all table values as a higher value
    for (int i = 1; i <= V; i++)
        table[i] = 1000000;

    // Compute minimum coins required for all
    // values from 1 to V

    for (int i = 0; i < m; i++)
    {   
        // Go through all coins smaller than i
        for (int j = coins[i]; j <= V; j++)
            table[j]=min(table[j-coins[i]]+1 ,table[j]);
    }
    return table[V];
}


int main()
{
    int coins[] = {1, 5, 6,8};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
