// ✅ CSES Problem: Two Sets
// 🔗 https://cses.fi/problemset/task/1092
// 🎯 Goal: Divide 1 to n into 2 sets with equal sum
// 🧠 Approach:
//     - If total sum is odd → NO
//     - Else, use greedy from n to 1 to pick largest possible number
//       and fill first set until its sum becomes totalSum/2
//     - Remaining elements go to second set


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll totalSum = n * (n + 1) / 2;
    if(totalSum%2){
        cout<<"NO";
        return 0;
    }
    vector<int> v1,v2;
    ll target = totalSum/2;
    
    
    // 🔁 Start from biggest number and pick greedily
    for (int i = n; i > 0; i--) {
        if (target >= i) {
            v1.push_back(i);  // Pick for set1
            target -= i;
        } else {
            v2.push_back(i);  // Else goes to set2
        }
    }


    cout << "YES" << endl;
    ll size1=v1.size();
    ll size2=v2.size();
    cout<<size1<<endl;
    for(int i=0;i<size1;i++)    cout<<v1[i]<<" ";
    cout<<endl;
    cout<<size2<<endl;
    for(int i=0;i<size2;i++)    cout<<v2[i]<<" ";

    return 0;
}