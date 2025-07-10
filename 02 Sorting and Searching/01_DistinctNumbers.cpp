// ✅ Problem: Distinct Numbers
// 🔗 Link: https://cses.fi/problemset/task/1621
// 🧠 Idea: Sort the array and count how many times adjacent elements change
// 🚀 Time: O(n log n), Space: O(1) extra (excluding input array)

// 🔥 Approach:
// 1. Sort the array → duplicates become adjacent
// 2. Traverse the sorted array and count how many times a new number appears


#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& arr,int n){
    sort(arr.begin(),arr.end());

    int cnt=1;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1])  cnt++;
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)     cin>>arr[i];
    
    cout<<count(arr,n);
    
    return 0;
}




// unordered_set approach. TC: O(n)   SC:O(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     unordered_set<int> s;

//     for (int i = 0; i < n; ++i) {
//         int x;
//         cin >> x;
//         s.insert(x); // duplicates will be ignored
//     }

//     cout << s.size(); // number of distinct elements
//     return 0;
// }
