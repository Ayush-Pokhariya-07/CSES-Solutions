/*
    🧾 Problem: Coin Piles
    🔗 Link: https://cses.fi/problemset/task/1754/
    🧠 Concept: Math-based validation
       - In one move, remove (2,1) coins from both piles.
       - Goal is to empty both piles completely.
    
    ✅ Conditions to solve:
       1️⃣ (a + b) must be divisible by 3 → total coins must allow full moves
       2️⃣ No pile can be more than double the other → otherwise one pile finishes too early
    
    🕒 Time Complexity: O(1) per test case
    ✅ Status: Accepted
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int left,right;
        cin>>left>>right;

        // 🧠 Condition 1: Total coins must be divisible by 3
        // 🧠 Condition 2: No pile should be more than double the other
        if((left + right)%3 == 0 && 2*left >= right && 2*right >= left)     
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}