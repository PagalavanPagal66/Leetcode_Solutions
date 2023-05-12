class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0;
        int rmax=0;
        int res=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            rmax=max(rmax,nums[i]+i);
            if(i==end){
                end=rmax;
                res++;
            }
        }
        return res;
    }
};