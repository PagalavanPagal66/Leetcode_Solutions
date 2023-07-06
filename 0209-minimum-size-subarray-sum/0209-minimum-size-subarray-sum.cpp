class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       int ans=n+1;
       int j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=target){
                ans=min(ans,(i-j+1));
                while(sum>=target){
                    sum-=nums[j];
                    ans=min(ans,(i-j+1));
                    j++;
                }
            }
        }
        if(ans==n+1) ans=0;
        return ans;
    }
};