class Solution {
public:
    int search(vector<int>& nums, int target) {
        int strt=0;
        int n=nums.size();
        int end=n-1;
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[strt]<=nums[mid]){
                if(nums[mid]>=target && nums[strt]<=target){
                    end=mid-1;
                }
                else{
                    strt=mid+1;
                }
            }
            else{
                 if(nums[mid]<=target && nums[end]>=target){
                    strt=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};