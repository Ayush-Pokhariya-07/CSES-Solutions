// ✅ Problem: Apartments
// 🔗 Link: https://cses.fi/problemset/task/1084
// 🧠 Idea: Use two-pointer approach to match applicants with suitable apartments
// 🚀 Time: O(n log n + m log m), Space: O(1) extra

// 🔥 Approach:
// 1. Sort both arrays: applicants & apartments
// 2. Use two pointers to find close enough apartment (within ±k tolerance)
// 3. If difference ≤ k ➝ assign apartment & move both pointers
// 4. Else move the pointer that has the smaller value to try better match

#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& applicants,int n,vector<int>& apartments,int m, int k){
    int cnt = 0;
    int appli = 0;
    int apart = 0;

    while(appli < n && apart < m){
        // 🔁 Apartment too small
        if(apartments[apart] < applicants[appli] - k)   apart++;
        // 🔁 Applicant wants smaller than this apartment 
        if(applicants[appli] < apartments[apart] - k)   appli++;

        if((apartments[apart] == applicants[appli]) || abs(apartments[apart] - applicants[appli]) <= k){
            cnt++;
            apart++;
            appli++;
        }
    }
    return cnt;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicants(n),apartments(m);

    for(int i=0;i<n;i++)    cin>>applicants[i];
    for(int i=0;i<m;i++)    cin>>apartments[i];

    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());

    cout<<count(applicants,n,apartments,m,k);

    return 0;
}