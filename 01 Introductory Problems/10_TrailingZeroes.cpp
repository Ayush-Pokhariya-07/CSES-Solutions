// ✅ CSES Problem: Trailing Zeros
// 🔗 https://cses.fi/problemset/task/1618
// 🎯 Count number of trailing zeros in n!
// 🧠 Idea: Count how many times 5 is a factor in n!

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;

//  10 = 2 * 5
//  2 comes more often than 5 in factorial.
//  So, number of 5s determines number of 10s 
//  and thus, trailing zeros.

    for (long long i = 5; i <= n; i *= 5) { // 
        ans += n / i;
        // 📌 Add n/5 + n/25 + n/125 + ...
    }

    cout << ans << endl;
    return 0;
}
