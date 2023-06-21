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
        int mid=(start)+(end-start)/2; //(strt+end)/2
        if(nums[start] <= nums[mid]){  // first half is sorted .. first half doesnt mean whole array bu the array we consider for binary search (strt to mid)
                ans = min(nums[start], ans); // since (strt to mid) is sorted we have to take the smallest element from that half 
                start = mid + 1; // we have taken the smallest element in range of(strt to mid). So going to search for minimum element in the other half
        }else{
             // second half is sorted....(mid to end)
                ans = min(nums[mid], ans);
            // smallest element in the second half is mid. Since it lies left in this range of elements(mid to end)
                end = mid-1;
            // we have taken the smallest element in the second half. So going to find minimum in the other half (STRT to MID)
        }
    }
    return  ans;
    }
};