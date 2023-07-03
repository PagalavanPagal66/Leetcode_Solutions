//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int maxDiff;
        int i, j;
        int LMin[n];
        int RMax[n];
        LMin[0] = arr[0];
        for (i = 1; i < n; ++i) LMin[i] = min(arr[i], LMin[i - 1]);
        RMax[n - 1] = arr[n - 1];
        for (j = n - 2; j >= 0; --j) RMax[j] = max(arr[j], RMax[j + 1]);
        i = 0, j = 0, maxDiff = -1;
        while (j < n && i < n) {
            if (LMin[i] <= RMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j = j + 1;
            } else
                i = i + 1;
        }
    
        return maxDiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends