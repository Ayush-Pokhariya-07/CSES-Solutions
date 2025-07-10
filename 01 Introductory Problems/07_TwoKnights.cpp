// ✅ CSES Problem: Two Knights
// 🔗 https://cses.fi/problemset/task/1072
// 🧠 Problem: For each board size i x i (from 1 to n), calculate
//    the number of ways to place 2 knights so that they do NOT attack each other
// 🎯 Key Insight:
//    - Total ways to place 2 knights = C(n^2, 2) = (n^2 * (n^2 - 1)) / 2
//    - Number of attacking positions = 4 * (n - 1) * (n - 2)
// 🧠 Why attacking positions = 4*(n-1)*(n-2)?
//    - 2×3 and 3×2 L-shape rectangles → 4 positions per such rectangle

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        ll n = i * i;

        // 🟢 Total ways to place two knights on i×i board
        ll totalWaysToPlace = (n * (n - 1)) / 2;

        // 🔴 Total ways in which knights attack each other
        //    Only valid for i >= 3 (because L-shapes don't fit on smaller boards)
        ll totalWaysToAttack = 4 * (i - 1) * (i - 2);

        // ✅ Subtract attacking arrangements to get valid ones
        if (i > 2) {
            totalWaysToPlace -= totalWaysToAttack;
        }

        // 🖨️ Print the result for board size i
        cout << totalWaysToPlace << endl;
    }

    return 0;
}
