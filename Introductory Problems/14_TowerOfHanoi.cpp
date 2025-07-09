// ✅ Problem: Tower of Hanoi
// 🔗 Link: https://cses.fi/problemset/task/2165
// 🧠 Idea: Move n-1 disks to helper, move nth to destination, then move n-1 to destination
// 🚀 Time: O(2^n), Space: O(n) (due to recursion)

// 🔥 Approach:
// For n disks and 3 rods: from (source), to (destination), aux (helper)
// Base Case: If n == 0, do nothing
// Recursive Steps:
// 1️⃣ Move (n-1) disks from `from` to `aux`
// 2️⃣ Move the nth disk from `from` to `to`
// 3️⃣ Move (n-1) disks from `aux` to `to`

#include<bits/stdc++.h>
using namespace std;

void toh(int n, int from, int to, int aux) {
    if (n == 0) return;

    toh(n - 1, from, aux, to);           // Move n-1 disks from source to helper
    cout << from << " " << to << "\n";     // Move nth disk from source to destination
    toh(n - 1, aux, to, from);           // Move n-1 disks from helper to destination
}

int main() {
    int n;
    cin >> n;

    // Total number of moves = 2^n - 1
    cout << (1 << n) - 1 << "\n";

    // Perform moves from rod 1 to rod 3 using rod 2
    toh(n, 1, 3, 2);

    return 0;
}
