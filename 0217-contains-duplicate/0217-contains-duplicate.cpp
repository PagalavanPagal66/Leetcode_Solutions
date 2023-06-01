class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int end=nums.size();
        for(int i=0;i<end-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};