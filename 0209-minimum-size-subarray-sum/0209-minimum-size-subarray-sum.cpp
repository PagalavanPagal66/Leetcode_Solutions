class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       int ans=INT_MAX;
       int j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=target){ // valid length . so trying to reduce the length of the caterpillar by reducing the distance between head (i) & tail (j)
                ans=min(ans,(i-j+1));
                // if we found a valid length. so tracking the minimum valid length
                while(sum>=target){
                    
                    sum-=nums[j];
                    // since, we are reducing the length. we dont need the jth value anyone.
                    ans=min(ans,(i-j+1));
                    // tracking the minimum length for answer.
                    j++;
                    // getting the tail near to the head. so that the length will be reduced.
                }
            }
        }
        if(ans==INT_MAX){
            ans=0;
        }
        return ans;
    }
};