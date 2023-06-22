//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        int c5=0,c10=0,c20=0,c=0;
        for (int i=0;i<n;i++){
            if(bills[i]==5){
                c5++;
            }
            else if(bills[i]==10){
                c10++;
                c5=c5-1;
            }
            else if(bills[i]==20){
                c20++;
                if(c10>0){
                    c10=c10-1;
                    c5=c5-1;
                }
                else
                c5=c5-3;
            }
            if(c5<0||c10<0)
            c++;
        }
        if(c>0){
            return false;
        }
        else return true;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends