// ✅ Problem: Collecting Numbers
// 🔗 Link: https://cses.fi/problemset/task/2216
// 🧠 Idea: Count how many times the sequence (1...n) breaks in the input
// 🚀 Time: O(n), Space: O(n)

// 🔥 Approach:
// 1. Store the position (index) of each number in the input array.
// 2. Traverse numbers 2 to n, and count how many times the current number
//    comes before the previous number in the input → this means a new round is needed.


#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& v, int n){
    int cnt = 1;
    vector<int> pos(n+1);

    for(int i=0;i<n;i++){
        pos[v[i]] = i;
    }

    for(int i=2;i<=n;i++){
        if(pos[i] < pos[i-1])   cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    cout<<count(v,n);

    return 0;
}