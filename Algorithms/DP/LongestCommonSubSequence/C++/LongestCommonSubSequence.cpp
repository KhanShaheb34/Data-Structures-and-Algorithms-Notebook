#include <bits/stdc++.h>
using namespace std;

int lcs(char *a, char *b, int m, int n)
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    char lcss[index + 1];
    lcss[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcss[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << lcss << endl;

    return L[m][n];
}

int main()
{
    int n, m;
    cin >> m >> n;
    char a[m], b[n];
    cin >> a >> b;
    cout << lcs(a, b, m, n) << endl;
    return 0;
}
