class Solution {
public:
    int findMaxK(vector<int>& nums) {
       int maxi = -1;
       unordered_map<int, int> mp;
       for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
       }
       for(int i = 0; i < nums.size() ;i++){
            if(nums[i] > 0){
                if(nums[i] > maxi && mp.find(-nums[i]) != mp.end()){
                    maxi = nums[i];
                }
            }
       }
       return maxi;
    }
};