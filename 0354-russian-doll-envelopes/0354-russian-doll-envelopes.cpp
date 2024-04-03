class Solution {
public:
    int rec(vector<vector<int>>&env,int ind,vector<int>&dp,int pastx,int pasty){
        int n=env.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int a = rec(env,ind+1,dp,pastx,pasty);
        int b = 0;
        if(env[ind][1]<pasty){
            b=1+(env,ind+1,dp,env[ind][0],env[ind][1]);
        }
        return dp[ind]=max(a,b);
    }

    static bool cmp(vector<int>a,vector<int>b){
        if(a[1] == b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),cmp);
        int n=env.size();
        vector<int> ans;
        ans.push_back(env[0][0]);
        for(int i=1;i<env.size();i++){
            if(ans.back()<env[i][0]){
                ans.push_back(env[i][0]);
            }else{
                int idx=lower_bound(ans.begin(),ans.end(),env[i][0])-ans.begin();
                ans[idx]=env[i][0];
            }
        }
        return ans.size();
    }
};