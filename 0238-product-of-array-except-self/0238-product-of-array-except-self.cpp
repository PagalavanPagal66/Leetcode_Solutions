class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCnt = count(nums.begin(), nums.end(), 0); //O(n)
        if(zeroCnt > 1) return vector<int>(nums.size(),0);               
        for(auto i : nums) 
            if(i!=0) {
                prod *= i;
        }
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(zeroCnt==1){
                if(nums[i]==0){
                    nums[i]=prod;
                }
                else{
                    nums[i]=0;
                }
            }
            else nums[i] = prod / nums[i];                                       
        return nums;
    }
};