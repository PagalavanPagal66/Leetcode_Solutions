class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int r = nums[i]%(n+1);
            nums[r-1] += (n+1); 
        }
        int k=0;
        for(int i=0;i<n;i++){
            int r = nums[i]%(n+1);
            nums[i]-=r;
            if(nums[i]>(2*(n))){
                nums[k++]=i+1;
            }
        }
        for(int i=n-1;i>=k;i--){
            nums.pop_back();
        }
        return nums;
    }
};