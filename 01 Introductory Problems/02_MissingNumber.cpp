// 🔥 Ayush's CSES Solution Vault: MISSING NUMBER (All Methods in One File)
// 🔗 CSES Link: https://cses.fi/problemset/task/1083
// 🧠 Problem: Given n-1 integers from 1 to n, find the missing number.
// 📦 Note: Only ONE number is missing. No duplicates.

#include <bits/stdc++.h>
using namespace std;

#define sep cout << "\n------------------------------------------\n";

// 👇👇👇 UNCOMMENT ANY ONE METHOD TO RUN 👇👇👇





/* 
// ✅ METHOD 1: Using Sum Formula
// 🧠 Logic: The sum of first n natural numbers is n*(n+1)/2. 
//          Subtract the sum of the given numbers from this total to find the missing one.
// 🚀 Time Complexity: O(n), Space: O(1)
// ✅ Best for large inputs (up to 1e6+)

int main() {
    int n;
    cin >> n;

    long long total_sum = 1LL * n * (n + 1) / 2; // Total expected sum of 1 to n
    long long sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x; // Calculate sum of given numbers
    }

    cout << (total_sum - sum) << "\n"; // Missing number is the difference
    return 0;
}
*/







/*
// ✅ METHOD 2: Frequency Array
// 🧠 Logic: Mark each number's presence using an array.
//          After scanning input, the index which remains 0 is the missing number.
// 🚀 Time Complexity: O(n), Space: O(n)
// ⚠️ Slightly more space usage, but useful for understanding.

int main() {
    int n;
    cin >> n;

    vector<int> freq(n + 1, 0); // +1 to make indexing easy (1-based)

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        freq[x] = 1; // Mark number as present
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            cout << i << "\n"; // The number not marked is missing
            break;
        }
    }

    return 0;
}
*/







/*
// ✅ METHOD 3: Using unordered_map
// 🧠 Logic: Same as frequency array, but uses a hash map to store existence of numbers.
// 🚀 Time Complexity: O(n), Space: O(n) (average case)
// ⚠️ More flexible for unknown input range, but overhead for such a simple task.

int main() {
    int n;
    cin >> n;

    unordered_map<int, bool> present;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        present[x] = true; // Mark number as seen
    }

    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            cout << i << "\n"; // Not seen = missing
            break;
        }
    }

    return 0;
}
*/








/*
// ✅ METHOD 4: Sorting + Binary Search
// 🧠 Logic: After sorting, ideally arr[i] == i+1 (because input is from 1 to n).
//          If at any index arr[i] != i+1, then i+1 is the missing number.
// 🚀 Time Complexity: O(n log n) due to sorting, Space: O(1) extra
// ⚠️ Not optimal, but great for practicing search logic.

int main() {
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // Sort the array to apply binary search logic

    int low = 0, high = n - 2;
    int ans = n; // Default missing is n if all others are correct

    // Binary search for the first place where arr[i] != i+1
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] != mid + 1) {
            ans = mid + 1;      // Possible missing number
            high = mid - 1;     // Search in the left half
        } else {
            low = mid + 1;      // Search in the right half
        }
    }

    cout << ans << "\n";
    return 0;
}
*/







/*
// ✅ METHOD 5: XOR Method
// 🧠 Logic: XOR all numbers from 1 to n and XOR all given numbers.
//          Since a^a = 0 and a^0 = a, missing = XOR(1...n) ^ XOR(array)
// 🚀 Time Complexity: O(n), Space: O(1)
// ⚡ Cool trick, often used in interviews.

int main() {
    int n;
    cin >> n;

    int xor_all = 0;   // XOR of 1 to n
    int xor_arr = 0;   // XOR of input array

    for (int i = 1; i <= n; i++) {
        xor_all ^= i;
    }

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        xor_arr ^= x;
    }

    cout << (xor_all ^ xor_arr) << "\n"; // Final XOR gives missing number
    return 0;
}
*/

