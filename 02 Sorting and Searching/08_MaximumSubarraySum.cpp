// ✅ Problem: Maximum Subarray Sum
// 🔗 Link: https://cses.fi/problemset/task/1643
// 🧠 Idea: Use Kadane’s Algorithm to find max sum in O(n)
// 🚀 Time: O(n), Space: O(1)

// 🔥 Approach:
// 1. Initialize maxSum = arr[0], sum = arr[0]
// 2. For each element:
//    - Either start a new subarray at current index
//    - Or extend the previous subarray
// 3. Update maxSum at each step


#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll findMaxSum(vector<ll>& arr, int n){
    ll sum = arr[0];
    ll maxSum = arr[0];

    for(int i=1;i<n;i++){
        sum = max(sum + arr[i], arr[i]);
        maxSum = max(sum,maxSum);
    }

    return maxSum;
}

int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];

    cout<<findMaxSum(arr,n);

    return 0;
}




// Prefix Sum
// T.C. : O(n^2)
// vector<long long> prefix(n+1, 0);
// for (int i = 0; i < n; ++i)
//     prefix[i+1] = prefix[i] + arr[i];

// long long maxSum = LLONG_MIN;
// for (int i = 0; i < n; ++i) {
//     for (int j = i; j < n; ++j) {
//         long long sum = prefix[j+1] - prefix[i];
//         maxSum = max(maxSum, sum);
//     }
// }
