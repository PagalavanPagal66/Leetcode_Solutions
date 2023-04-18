class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v(2);
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           int dif=target-nums[i];
            if(mp.find(dif)!=mp.end()){
                v[0]=i;
                v[1]=mp[dif];
                return v;
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};