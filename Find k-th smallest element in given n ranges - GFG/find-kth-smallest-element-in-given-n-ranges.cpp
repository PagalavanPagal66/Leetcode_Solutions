//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<int>v;
        sort(range.begin(), range.end());
        int st = range[0][0], end = range[0][1],index = 0;
        for(int i = 1; i < range.size(); i++) {
            if(range[i][0] <= end) {
                end = max(end, range[i][1]);
                range[index][0] = st;
                range[index][1] = end;
                range[i][0] = -1;
            }
            else index = i;
        }
        for(int i = 0; i < queries.size(); i++) {
            int k = queries[i], j;
            for(j = 0; j < range.size(); j++) {
                if(range[j][0] == -1) continue;
                if(range[j][1]-range[j][0] + 1 >= k) {
                    v.push_back(range[j][0]+k-1);
                    break;
                }
                else k = k-range[j][1]-range[j][0] + 1;
            }
            if(j == range.size()) v.push_back(-1);
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends