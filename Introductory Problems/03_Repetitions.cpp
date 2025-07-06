// ✅ Problem: Repetitions
// 🌐 Link: https://cses.fi/problemset/task/1069/
// 🧠 Task: Find the length of the longest consecutive repetition of any character in the string

// 🚀 Time Complexity: O(n)
// 💾 Space Complexity: O(1)

// 🔥 Example:
// Input:  ATTCGGGA
// Output: 3   --> (GGG is the longest repetition)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.size();
    int ans = 1;                    // 🎯 Final answer: longest repetition found so far
    int cnt = 1;                    // 🧮 Current streak of repeated characters

    // 🔁 Iterate from the 2nd character to the end
    for(int i = 1; i < len; i++) {
        if(s[i] == s[i - 1]) {
            cnt++;                  // 🧱 Same as previous char, continue the streak
        } else {
            ans = max(ans, cnt);    // ✅ Update answer if current streak is longer
            cnt = 1;                // 🔄 Reset counter for new character
        }
    }

    ans = max(ans, cnt);            // ⚠️ Edge case: longest streak might be at the end
    cout << ans;

    return 0;
}
