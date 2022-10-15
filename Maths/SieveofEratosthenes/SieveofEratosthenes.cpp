#include<bits/stdc++.h>
using namespace std;

vector<bool> is_prime;

void init_sieve() {
    int n = 1000000;
    is_prime.assign(n+1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
}

int main() {
    init_sieve();

    int Q;
    cin >> Q;

    while (Q--) {
        int x;
        cin >> x;

        if (is_prime[x]) {
            cout << x << " is a prime number" << endl;
        } else {
            cout << x << " is not a prime number" << endl;
        }
    }
}
