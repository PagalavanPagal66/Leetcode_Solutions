class Solution {
public:
    int ans = 0;
    void helper(int i, vector<vector<int>>& requests, int req, vector<int>& temp){
        if(i == requests.size()){  
            for(auto x : temp){
                if(x != 0){
                    return;
                }
            }
            ans = max(ans, req);
            return;
        }
        
        helper(i+1, requests, req, temp);
        temp[requests[i][0]]--;
        temp[requests[i][1]]++;
        helper(i+1, requests, req+1, temp);
        temp[requests[i][0]]++;
        temp[requests[i][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n,0);
        helper(0,requests,0,temp);
        return ans;
    }
};