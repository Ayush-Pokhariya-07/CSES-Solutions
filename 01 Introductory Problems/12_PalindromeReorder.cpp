/*
    🧾 Problem: Palindrome Reorder
    🔗 https://cses.fi/problemset/task/1755/
    🎯 Fix: Middle character with odd frequency should go in center, not full in s1

    ✅ Time: O(n)
    ✅ Space: O(1) (fixed 26-length array)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> freq(26,0);

    for(int i=0;i<s.size();i++){
        freq[s[i]-'A']++;
    }

    // Check if more than one character has odd frequency
    bool flag = false;

    for(int i=0;i<26;i++){
        if(freq[i]%2 != 0){    //odd
            if(!flag)   flag = true;  // one odd found
            else{
                cout<<"NO SOLUTION";
                return 0;
            }
        }
    }

    // Construct two halves (s1, s2) 
    string s1, s2;
    int oddCnt = 0;
    char oddChar;

    for(int i=0;i<26;i++){
        int cnt = freq[i];
        char ch = i+'A';
        if(cnt % 2){     
            oddCnt = cnt;
            oddChar = ch;
            continue;
        }
        else{
            while(cnt){
                s1.push_back(ch);
                cnt--;

                s2.push_back(ch);
                cnt--;
            }
        }
    }
    // Add odd character to middle (if it exists)
    while(oddCnt--){
        s1.push_back(oddChar);
    }

    // Complete the palindrome by reversing s2
    reverse(s2.begin(),s2.end());

    // Final result
    cout<<s1 + s2;

    return 0;
}