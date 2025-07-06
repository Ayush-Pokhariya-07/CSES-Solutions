// ✅ Problem: Weird Algorithm
// 🔗 Link: https://cses.fi/problemset/task/1068/
// 🧠 Task: Given a number `n`, keep applying the following steps until `n == 1`:
//         - If n is even → divide it by 2
//         - If n is odd → n = 3 * n + 1
//         Output the full sequence.

// 🚀 Time Complexity: O(log n) to O(n), depends on input value

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // 🧾 To store the full sequence (optional, can be printed directly too)
    vector<long long> ans;

    ans.push_back(n); // Add initial number to the answer

    // 🔁 Keep processing until we reach 1
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;              // 🔸 Even case: divide by 2
        } else {
            n = 3 * n + 1;       // 🔹 Odd case: 3n + 1
        }
        ans.push_back(n);        // Add current value to sequence
    }

    // 🖨️ Print the full sequence
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}






//method 2 : without use of vector

// 🚀 Time Complexity: Varies — worst case is not proven, but practically fast for all 64-bit numbers
// 💾 Space Complexity: O(1) (no extra storage)

// ✅ This version prints the result directly without storing the sequence in a vector

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long long n;
//     cin >> n;  // 📥 Input the initial number

//     cout << n << " ";  // 🖨️ Always print the starting number

//     // 🔁 Loop until we reduce n to 1
//     while (n != 1) {
//         if (n % 2 == 0) {
//             n /= 2;         // 🔸 If n is even, divide it by 2
//         } else {
//             n = 3 * n + 1;  // 🔹 If n is odd, apply 3n + 1
//         }

//         cout << n << " ";  // 🖨️ Print the new value in the sequence
//     }

//     return 0;
// }