class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        auto go = [&](int x) {
            int cnt = 0;
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i + 1] - nums[i] <= x) {
                    i += 1;
                    cnt += 1;
                }
            }
            return (cnt >= p);
        };
        int low = 0, high = nums.back() - nums[0];
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (go(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }
};