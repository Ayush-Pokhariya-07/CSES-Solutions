// ✅ Problem: Sum of Two Values
// 🔗 Link: https://cses.fi/problemset/task/1640






// 🧠 Idea: Sort the array with original indices, then use two pointers
// 🚀 Time: O(n log n), Space: O(n)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, target;
    cin >> n >> target;

    vector<pair<ll, int>> arr(n);  // {value, original_index}
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;  // 1-based index
    }

    sort(arr.begin(), arr.end());  // 🔍 Sort by value

    int left = 0, right = n - 1;

    while (left < right) {
        ll sum = arr[left].first + arr[right].first;

        if (sum == target) {
            cout << arr[left].second << " " << arr[right].second << "\n";  // 🎯 Found
            return 0;
        } else if (sum < target) {
            left++;  // ➕ Need a bigger sum
        } else {
            right--; // ➖ Need a smaller sum
        }
    }

    cout << "IMPOSSIBLE\n";  // 🚫 No valid pair found
    return 0;
}










// 🧠 Idea: For each number, check if its complement (target - current) exists in map
// 🚀 Time: O(n), Space: O(n)

// 🔥 Approach:
// 1. Iterate through the array while maintaining a hash map of seen elements.
// 2. For each `arr[i]`, check if `target - arr[i]` exists in the map.
//    - If yes, print indices (1-based) and return
//    - Otherwise, store arr[i] with its index in the map

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main(){
//     ll n, target;
//     cin>>n>>target;

//     vector<ll> arr(n);
//     for(int i=0;i<n;i++)    cin>>arr[i];

//     unordered_map<ll,ll> map;

//     for(int i=0;i<n;i++){
//         int remaining = target - arr[i];
//         if(map.find(remaining) != map.end()){
//             cout<<map[remaining]+1<<" "<<i+1;
//             return 0;
//         }
//         map[arr[i]] = i;
//     }
//     cout<<"IMPOSSIBLE";

//     return 0;
// }