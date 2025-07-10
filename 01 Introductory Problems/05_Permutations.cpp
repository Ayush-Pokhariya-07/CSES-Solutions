// ✅ CSES Problem: Permutations
// 🔗 Link: https://cses.fi/problemset/task/1070
// 📌 Problem:
//     Print any permutation of numbers 1 to n such that
//     no two adjacent numbers in the permutation differ by 1.
//     If not possible, print "NO SOLUTION".
// 🧠 Trick:
//     For n = 1 ✅ -> [1]
//     For n = 2 or 3 ❌ -> No way to avoid adjacent 1-diff
//     For n >= 4 ✅ -> Just print even numbers first, then odd numbers (or reverse)
// 🚀 Time Complexity: O(n), 💾 Space: O(1) (ignoring output)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // ❌ For n = 2 or 3, it's not possible
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    // ✅ Step 1: Print all even numbers first
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    // ✅ Step 2: Then print all odd numbers
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }

    return 0;
}
