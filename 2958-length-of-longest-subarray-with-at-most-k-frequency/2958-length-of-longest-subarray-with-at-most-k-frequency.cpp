class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ml=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(i<n){
            while(i>=j && mp[nums[i]]==k){
                mp[nums[j]]--;
                j++;
            }
            mp[nums[i]]++;
            i++;
            ml=max(ml,i-j+1);
        }
        return ml-1;
    }
};