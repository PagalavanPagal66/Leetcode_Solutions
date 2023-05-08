class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
    long count=0;
        int n=nums.size();
        vector<pair<int,int>>ans;
        for(int j=0;j<nums.size();j++)
        {
            ans.push_back({nums[j],j});
        }
        sort(ans.begin(),ans.end());
        count=nums.size();
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i-1].second>ans[i].second)
                count=count+(n-i);
        }
   return count; 
    }
};