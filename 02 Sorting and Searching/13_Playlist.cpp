// ✅ Problem: Distinct Numbers in a Subarray (Longest Subarray with All Distinct Elements)
// 🔗 Link: https://cses.fi/problemset/task/2181
// 🧠 Idea: Use sliding window + frequency map to find the longest subarray with all unique elements
// 🚀 Time: O(n), Space: O(n)

// 🔥 Approach:
// 1. Use two pointers (`left` and `right`) to define a sliding window.
// 2. Use a frequency map to track the count of each element in the current window.
// 3. If we encounter a duplicate, shrink the window from the left until all elements are unique again.
// 4. Update the answer with the maximum window length found.



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    map<int, int> freq;
    int left = 0;
    int ans = 0;
    
    for(int right = 0; right < n; right++){
        while(freq[v[right]] > 0){
            freq[v[left]]--;
            left++;
        }
        freq[v[right]]++;
        ans = max(ans, right - left + 1);
    }

    cout<<ans;
    return 0;
}








// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     vector<int> v(n);
//     for(int i=0;i<n;i++)    cin>>v[i];

//     // unordered_set<int> set;           Gives TLE as this uses hashing and collision may increase T.C. os wordt time for set is O(n).

//     int left = 0;
//     int ans = 0;
    
//     for(int right = 0; right < n; right++){
//         while(set.count(v[right])){
//             set.erase(v[left]);
//             left++;
//         }
//         set.insert(v[right]);

//         ans = max(ans, right-left+1);
//     }

//     cout<<ans;
//     return 0;
// }



