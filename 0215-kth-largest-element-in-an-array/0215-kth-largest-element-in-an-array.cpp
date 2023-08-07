class Solution {
public:
    int part(vector<int>& nums, int l, int r) {
        int tar = nums[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
            if (nums[j] <= tar)
                swap(nums[j], nums[++i]);
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    
    int random_part(vector<int>& nums, int l, int r) {
        int res = rand() % (r - l + 1) + l;
        swap(nums[res], nums[r]);
        return part(nums, l, r);
    }
    
    int quick_part(vector<int>& nums, int l, int r, int target) {
        int next = random_part(nums, l, r);
        if (next == target) {
            return nums[next];
        } else {
            return (next > target) ? quick_part(nums, l, next - 1, target) : quick_part(nums, next + 1, r, target);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quick_part(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
