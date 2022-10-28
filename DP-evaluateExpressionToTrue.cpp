#include <bits/stdc++.h>
using namespace std;
// for memoization we can use 3D DP
// but we prefer map
unordered_map<string, int> mp;
int solve(string &s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == true)
        {
            if (s[i] == 'T')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (s[i] == 'F')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    // creating the key for map
    string temp = to_string(i);
    temp.push_back('_');
    temp.append(to_string(j));
    temp.push_back('_');
    temp.append(to_string(isTrue));
    // key creation done

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue = solve(s, i, k - 1, true);
        int leftFalse = solve(s, i, k - 1, false);
        int rightTrue = solve(s, k + 1, j, true);
        int rightFalse = solve(s, k + 1, j, false);
        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans = ans + (leftTrue * rightTrue);
            }
            else
            {
                ans = ans + (leftTrue * rightFalse) + (leftFalse * rightFalse) + (leftFalse * rightTrue);
            }
        }
        if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans = ans + (leftTrue * rightFalse) + (leftTrue * rightTrue) + (leftFalse * rightTrue);
            }
            else
            {
                ans = ans + (leftFalse * rightFalse);
            }
        }
        if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans = ans + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else
            {
                ans = ans + (leftFalse * rightFalse) + (leftTrue * rightTrue);
            }
        }
    }
    return mp[temp] = ans;
}
int main()
{
    mp.clear();
    string s = "T^F|F";
    int n = s.size();
    bool isTrue = true;
    cout << solve(s, 0, n - 1, isTrue) << endl;
    return 0;
}
