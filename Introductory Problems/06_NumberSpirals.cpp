// ✅ CSES Problem: Number Spiral
// 🔗 https://cses.fi/problemset/task/1071
// 👨‍💻 Author: Ayush Pokhariya
// 🧠 Logic: Based on the maximum of row (y) or column (x)
// 📌 Formula:
//     - If y >= x (row is max):
//         - Odd row:  Answer = n*n - x + 1
//         - Even row: Answer = (n-1)^2 + x
//     - Else (column is max):
//         - Odd column:  Answer = (n-1)^2 + y
//         - Even column: Answer = n*n - y + 1
// 🚀 Time Complexity: O(1) per test case

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int x,y;
        cin>>x>>y;

        long long n = max(x,y);

        if(n == y){
            if(n%2){
                cout<< n*n-x+1 << endl;
            }
            else{
                cout<< (n-1)*(n-1)+x << endl;
            }
        }
        else{
            if(n%2){
                cout<< (n-1)*(n-1)+y << endl;
            }
            else{
                cout<< n*n-y+1 << endl;
            }
        }
    }
    return 0;
}