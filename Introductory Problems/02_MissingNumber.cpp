#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int low = 0, high = n - 2;
    int ans = n; // default missing number (if all are in place)

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] != mid + 1) {
            ans = mid + 1;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
