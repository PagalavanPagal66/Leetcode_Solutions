class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int leftm=height[0];
        int rightm=height[n-1];
        int res=0;
        while(left<right){
            if(height[left]<=height[right]){
                 res+=max(0,leftm-height[left]);
                 leftm=max(leftm,height[left]);
                 left++;
            }
            else{
                res+=max(0,rightm-height[right]);
                rightm=max(rightm,height[right]);
                right--;
            }
        }
        return res;
    }
};