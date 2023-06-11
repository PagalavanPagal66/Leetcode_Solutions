class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int strt=0;
        int end=nums.size()-1;
        while(strt<=end){
            int mid=(strt+end)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[strt]==nums[mid] && nums[mid]==nums[end]){
                strt++;
                end--;
                continue;
            }
            if(nums[mid]>=nums[strt]){
                if(target>=nums[strt] && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    strt=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target <=nums[end]){
                    strt=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};