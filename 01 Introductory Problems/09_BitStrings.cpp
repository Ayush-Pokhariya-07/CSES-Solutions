// ✅ CSES Problem: Bit Strings
// 🔗 https://cses.fi/problemset/task/1617
// 🎯 Goal: Print (2^n) % MOD
// 🧠 Approach:
//     - Use modular exponentiation (because n can be up to 10^6)
//     - Fast power using binary exponentiation (O(log n))
//     - 2 choices at each bit → total = 2^n

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

// ⚡ Modular Exponentiation: calculates (a^b) % MOD efficiently
ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;

    while (b > 0) {
        // If current bit of b is 1 → multiply result with a
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;  // Square the base
        b >>= 1;            // Move to next bit basically b = b / 2;  // cut power in half
    }

    return res;
}

int main() {
    ll n;
    cin >> n;

    // 🧨 Output the result → total bit strings = 2^n % MOD
    cout << power(2, n) << endl;

    return 0;
}
