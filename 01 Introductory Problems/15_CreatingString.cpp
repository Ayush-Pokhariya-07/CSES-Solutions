// ✅ Problem: Creating Strings I
// 🔗 Link: https://cses.fi/problemset/task/1622
// 🧠 Idea: Generate all unique permutations of a string using backtracking
// 🚀 Time: O(n! * n), Space: O(n!)

// 🔥 Approach:
// Use recursion with backtracking to explore all permutations
// To avoid duplicates, store permutations in a set
// At each recursive call, swap current char with every index >= current
// After recursive call, backtrack by swapping back




// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     sort(s.begin(), s.end());  // Sort the string to get permutations in lex order

//     vector<string> permutations;

//     do {
//         permutations.push_back(s);
//     } while (next_permutation(s.begin(), s.end()));

//     cout << permutations.size() << "\n";
//     for (auto &str : permutations) {
//         cout << str << "\n";
//     }

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

set<string> ans;

void permute(string s, int len){
    if(s.size() == len){
        ans.insert(s);
        return;
    }
    for (int i = len; i < s.size(); i++) {
        swap(s[len], s[i]);
        permute(s, len + 1);
        swap(s[len], s[i]);  // Backtrack
    }
}
int main(){
    string s;
    cin>>s;

    permute(s,0);

    cout<<ans.size()<<endl;
    for(auto& it:ans){
        cout<<it<<endl;
    }
}