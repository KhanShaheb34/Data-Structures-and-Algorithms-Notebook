#include <bits/stdc++.h>
using namespace std;

int editDistance(char *a, char *b, int m, int n)
{
    int D[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                D[i][j] = j;
            else if (j == 0)
                D[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1]) + 1);
            else
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + 1;
        }
    }
    return D[m][n];
}

int main()
{
    int n, m;
    cin >> m >> n;
    char a[m], b[n];
    cin >> a >> b;
    cout << editDistance(a, b, m, n) << endl;
    return 0;
}
