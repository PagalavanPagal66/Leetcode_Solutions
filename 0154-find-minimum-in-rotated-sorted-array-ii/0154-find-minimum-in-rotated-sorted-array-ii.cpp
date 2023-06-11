class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (nums[low] == nums[mid] and nums[mid] == nums[high])
            {
                ans = min(ans, nums[low]);
                low++, high--;
            }
            else if (nums[low] <= nums[mid]) 
            {
                ans = min(ans, nums[low]);
                low = mid + 1; 
            }
            else if (nums[mid] <= nums[high]) 
            {
                ans = min(ans, nums[mid]);
                high = mid - 1; 
            }
        }

        return ans;
    }
};