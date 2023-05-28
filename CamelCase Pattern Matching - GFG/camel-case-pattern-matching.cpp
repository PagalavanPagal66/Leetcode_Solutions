//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
                vector<string> ans;
        int k = 0;
        for(int i = 0; i<N; i++){
            string temp = Dictionary[i];
            int S = temp.size();
            for(int j = 0; j<S; j++){
                if( isupper(temp[j]) ){
                    if(temp[j] != Pattern[k])
                        break;
                    k++;
                }
            }
            if( k == Pattern.length() )
                ans.push_back(temp);
            k = 0;
        }
        if(ans.size() == 0)
            ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends