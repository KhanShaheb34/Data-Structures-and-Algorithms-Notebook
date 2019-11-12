#include<bits/stdc++.h>
using namespace std;
int M[5][5], S[5][5];

void printBrackets(int i, int j) {
    if(i > j) return;
    int val = S[i][j];
    cout << "(";
    if(val==0) {
        cout << i;
        return;
    }
    else if(val == j-i+1) {
        for (int k = i; k <= j; k++)
        {
            cout << k;
            if(k!=j) cout << "X";
        }
        return;
    }
    else {
        printBrackets(i, i+val-1);
        cout << ")";
        printBrackets(i+val, j);
        cout << ")";
    }

}

int main() {
    int n = 5;
    int p[5] = {5, 4, 6, 2, 7};
    int j, min, q;
    
    memset(M, 0, sizeof(M));
    memset(S, 0, sizeof(S));
    for(int d = 1; d < n-1; d++) {
        for(int i=1; i<n-d; i++) {
            j = i+d;
            int mink = INT_MAX;
            for(int k=i; k<j; k++) {
                int q = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < mink) {
                    mink = q;
                    S[i][j] = k;
                }
            }
            M[i][j] = mink;
        }
    }
    for(int i=0; i<n; i++) {
        for (int k = 0; k < n; k++)
        {
            cout << S[i][k] << "\t";
        }
        cout << endl;
    }
    printBrackets(1,4);
    cout << M[1][n-1] << endl;
}