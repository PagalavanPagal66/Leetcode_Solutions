class Solution {
public:
    int subset(int i, vector<int> &v ,vector<int> & nums,int n)
    {
        if (i == n)
        {
            int ans = 0;
            for (auto i : v)
            ans^= i;
            return ans;
        }
        v.push_back(nums[i]);
        int l = subset(i+1, v,nums,n);
        v.pop_back();
        int r = subset(i+1, v,nums,n);
        return l+r;
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> v;
        return subset(0,v,nums,nums.size());
    }
};