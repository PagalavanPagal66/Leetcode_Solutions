class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        //created a map
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second>1){
                return true;
            }
        }
        return false;
        //space complexity - n , time complexity - n 
    }
};