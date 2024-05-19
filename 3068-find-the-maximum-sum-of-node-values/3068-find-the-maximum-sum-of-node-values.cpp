class Solution {

public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long ans = 0;
        int smallestdifferent = INT_MAX;
        int numberofflips = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int xorednumber = nums[i] xor k;
            if (xorednumber > nums[i])
            {
                int diff = xorednumber - nums[i];
                smallestdifferent = min(smallestdifferent, diff);
                nums[i] = xorednumber;
                numberofflips++;
            }
            else
            {
                int diff = nums[i] - xorednumber;
                smallestdifferent = min(smallestdifferent, diff);
            }
            ans += nums[i];
        }
        if (smallestdifferent == INT_MAX)
        {
            return ans;
        }
        if (numberofflips % 2 == 1)
            ans -= smallestdifferent;
        return ans;
    }
};