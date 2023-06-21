class Solution {
public:
    int search(vector<int>& nums, int target) {
        int strt=0;
        int n=nums.size();
        int end=n-1;
        while(strt<=end){
            int mid=strt+(end-strt)/2; //(strt+end)/2
            if(nums[mid]==target){
                return mid; //answer found
            }
            if(nums[strt]<=nums[mid]){ // first half (Strt to mid) is sorted (It can able to form a range)
                if(nums[mid]>=target && nums[strt]<=target){ // checking whether the target will fall on that range (Strt to mid)
                    end=mid-1; // I will surely have to find within that range. So eliminating second half and continue search in the first half (strt to mid)
                }
                else{ //target will not fall on that range 
                    strt=mid+1; // target will never be found within that range (strt to mid)
                }
            }
            else{ //second half is sorted (mid to end) will form a range
                if(nums[mid]<=target && nums[end]>=target){  // we have find whether the target will fall on that range (mid to end)
                    strt=mid+1; // Target is on that range. So searching only the second half
                }
                else{ //Second half (mid to end) forms a range. But it is no the range that the target exists. So searching in second half never produce answer
                    end=mid-1; // moving to first half
                }
            }
        }
        return -1;
    }
};