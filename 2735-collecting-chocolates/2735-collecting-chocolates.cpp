typedef long long ll;
class Solution {
public:
    void change(vector<int> &nums) {
        int last = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >=0 ; i--) {
            nums[i+1] = nums[i];
        }
        nums[0] = last;
    }
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> cost(n, LONG_MAX);
        ll mini = LONG_MAX;
        for(int i = 0; i < n; i++) {
            ll totalCost = (ll)(x) * (ll)(i);
            for(int j = 0; j < n; j++) {
                cost[j] = min(cost[j],(ll)nums[j]);
                totalCost+=cost[j];
            }
            mini = min(mini, totalCost);
            change(nums);        
        }
        return mini;  
    }
};