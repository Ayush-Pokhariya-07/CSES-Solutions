// ✅ Problem: Gray Code
// 🔗 Link: https://cses.fi/problemset/task/2205
// 🧠 Idea: Generate n-bit Gray codes by reflecting and prefixing
// 🚀 Time: O(2^n), Space: O(2^n)

// 🔥 Approach:
// Start with 1-bit Gray codes: {"0", "1"}
// For each additional bit:
// 1. Reflect the existing list (reverse it), prefix '1' to reflected items
// 2. Prefix '0' to original list
// This maintains the Gray code property (adjacent codes differ by 1 bit)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<string> gray = {"0", "1"};
    
    for(int i=2;i<=n;i++){
        int size = gray.size();

        // 🔁 Reflect and prefix '1' to the reflected part
        for(int j=size-1;j>=0;j--){
            gray.push_back("1" + gray[j]);
        }
        
        // 🔁 Prefix '0' to the first half (original list)
        for(int j=0;j<size;j++){
            gray[j] = "0" + gray[j];
        }
    }

    for(int i=0;i<gray.size();i++){
        cout<<gray[i]<<'\n';
    }
    return 0;
}

