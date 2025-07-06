// ✅ CSES Problem: Increasing Array
// 🔗 Link: https://cses.fi/problemset/task/1094/
// 📌 Problem Statement:
//     Given an array of `n` integers, make it non-decreasing by only increasing elements.
//     In one move, you can increase any element by 1. 
//     Find the **minimum number of moves** required to make the entire array non-decreasing.
// 🔍 Example:
//     Input:  5
//             3 2 5 1 7
//     Output: 5
//     Explanation:
//         2 → 3 (1 move), 1 → 5 (4 moves). Total = 5 moves.
// 🚀 Time Complexity: O(n), 💾 Space Complexity: O(1) extra

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;                       // 📥 Input the size of the array

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];              // 📥 Input array elements
    }

    long long moves = 0;            // 🧮 Total number of moves needed

    // 🔁 Loop through array starting from index 1
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            // ⚠️ If current element is smaller than the previous,
            // we must increase it to match arr[i - 1]
            moves += arr[i - 1] - arr[i];  // ✅ Count the moves
            arr[i] = arr[i - 1];           // 🔄 Update the element to maintain non-decreasing order
        }
    }

    cout << moves << "\n";  // 🖨️ Final answer: total moves required
    return 0;
}
