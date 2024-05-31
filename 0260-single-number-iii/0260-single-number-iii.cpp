class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        for(auto i:mp){
            if(i.second==1){
                res.push_back(i.first);
            }
        }
        return res;
    }
};