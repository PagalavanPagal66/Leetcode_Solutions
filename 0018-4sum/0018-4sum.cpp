class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=j+1;
                int right=n-1;
                while(left<right){
                long long int sum=nums[i]+nums[j];
                long long int x=nums[left]+nums[right];
                if(sum+x==target){
                    vector<int>t;
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    res.push_back(t);
                    while(left<n-1 && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right>=1 && nums[right]==nums[right-1]){
                        right--;
                    }
                }
                if(sum+x<target){
                    left++;
                }
                else{
                    right--;
                }
                }
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};