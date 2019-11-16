
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int ara[] = {1,2,6,7,10,12,15};
    int n = sizeof(ara) / sizeof(n);
    int lioes[n];

    int max= 1;
    int lastindex=0;
    bool odd = false, even = false;

    for (int i = 0; i < n; i++)
        lioes[i] = 1;


    for (int i = 1; i < n; i++)
    {
        cout<<"Step "<<i<<": ";
        for (int i = 0; i < n; i++)
            cout << lioes[i] << " ";

        cout << endl;

        for (int j = 0; j < i; j++)
        {
            if (ara[i] > ara[j] && (ara[i] + ara[j]) % 2 != 0 && lioes[i] < lioes[j] + 1)
            {
                lioes[i] = lioes[j] + 1;
                if (lioes[i] > max)
                {
                    max= lioes[i];
                    lastindex = i;

                }
            }
        }
    }
    cout<<"Step "<<n<<": ";
    for(int i=0; i<n; i++)
        cout<<lioes[i]<<" ";
    cout<<endl;

    cout<<"MaxSize: ";
    cout << max << endl;
    vector<int>vec;

    int value = ara[lastindex];
    int i = lastindex;

    if (ara[i] % 2 == 1)
    {
        odd = true;
        even = false;

    }
    else
    {
        odd = false;
        even = true;
    }
    cout<<endl;
    cout<<"Sequence is: ";

    while (max > 0)
    {
        if ((even &&ara[i]%2==0) && (value > ara[i] || i==lastindex))
        {
            max--;
            vec.push_back(ara[i]);
            value = ara[i];
            even = false;
            odd = true;


        }
        else if ((odd && ara[i]%2==1)&& (value > ara[i] || i==lastindex))
        {
            max--;
            vec.push_back(ara[i]);
            value = ara[i];
            even = true;
            odd = false;

        }
        i--;
    }
    for (int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
