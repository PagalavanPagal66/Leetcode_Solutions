class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int strt=0;
        int end=nums.size()-1;
        while(strt<end){
            int mid=(strt+end)/2;
            if(nums[mid]<nums[mid+1]){
                strt=mid+1;
            }
            else{
                end=mid;
            }
        }
        return strt;
    }
};