//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int g, vector<int> &hand) {
        // code here
        if(n%g != 0)
        {
            return false;
        }
        if(g == 1)
            return true;
        
        map<int,int>mapp;
        for(int i=0;i<n;i++)
        {
            mapp[hand[i]]++;
        }
        
        
        int zz = n/g;
        while(zz--)
        {
            vector<int>arr;
            arr.push_back(mapp.begin()->first);
            mapp.begin()->second--;
            if(mapp.begin()->second == 0)
                mapp.erase(mapp.begin()->first);
            while(arr.size() != g)
            {
                int ele = arr[arr.size()-1];
                if(mapp.find(ele+1) == mapp.end())
                {
                    return false;
                }
                else
                {
                    arr.push_back(ele+1);
                    mapp[ele+1]--;
                    if(mapp[ele+1] == 0)
                        mapp.erase(ele+1);
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends