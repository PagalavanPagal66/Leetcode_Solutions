class Solution {
public:
    int findMin(vector<int>& nums) {
    if(nums[0]<nums[nums.size()-1])
        return nums[0];
    int start=0;
    int end=nums.size()-1;
    int ans=INT_MAX;
    while(start<=end)
    {
        int mid=(start)+(end-start)/2;
        if(nums[start] <= nums[mid]){
                ans = min(nums[start], ans);
                start = mid + 1;
        }else{
                ans = min(nums[mid], ans);
                end = mid-1;
        }
    }
    return  ans;
    }
};