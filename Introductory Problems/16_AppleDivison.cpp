// ✅ Problem: Apple Division
// 🔗 Link: https://cses.fi/problemset/task/1623
// 🧠 Idea: Try all subsets and find minimum absolute difference of their sums
// 🚀 Time: O(2^n), Space: O(n) (stack space due to recursion)

// 🔥 Approach:
// At each index, we have 2 choices: put the current weight in group 1 or group 2
// Recursively explore both options and keep track of the minimum |sum1 - sum2|
// Base Case: All items placed ➡️ update minimum difference

#include <bits/stdc++.h>
using namespace std;

long long ans = LLONG_MAX;  // Store minimum difference

void solve(int i, long long sum1, long long sum2, vector<int>& weights) {
    if (i == weights.size()) {
        ans = min(ans, abs(sum1 - sum2));  // Compare both group sums
        return;
    }

    // Option 1: put current apple in group 1
    solve(i + 1, sum1 + weights[i], sum2, weights);

    // Option 2: put current apple in group 2
    solve(i + 1, sum1, sum2 + weights[i], weights);
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    solve(0, 0, 0, weights);
    cout << ans << "\n";

    return 0;
}
