// ✅ Problem: Missing Coin Sum
// 🔗 Link: https://cses.fi/problemset/task/2183
// 🧠 Idea: Greedy – Track the smallest sum we can't create with current coins
// 🚀 Time: O(n log n), Space: O(1) extra

// 🔥 Approach:
// 1. Sort the coin values.
// 2. Start with currSum = 0.
// 3. If current coin ≤ currSum + 1 → we can extend reachable sum range.
// 4. If coin > currSum + 1 → there's a gap; return currSum + 1 (unreachable sum).


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findMissing(vector<ll>& arr, int n){
    sort(arr.begin(),arr.end());
    
    // Variable to keep track of the maximum sum we can currently form
    ll currSum = 0;
    for(int i=0;i<n;i++){
        // If the current coin is less than or equal to currSum + 1,
        // we can extend the range of sums we can make
        if(arr[i] <= currSum+1)     currSum+=arr[i];
        
        else{
            // If we find a gap, return the smallest sum we can't form
            return currSum+1;
        }
    }
    return currSum+1;
}

int main(){
    int n;
    cin>>n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];

    cout<<findMissing(arr,n);

    return 0;
}