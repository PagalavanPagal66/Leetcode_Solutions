class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int past = 0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr = i+nums[i];
            int diff = nums[i]-i;
            ans = max(ans,past + diff);
            past = max(past,curr);
        }
        return ans;
    }
};