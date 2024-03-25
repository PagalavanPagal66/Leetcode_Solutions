class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 2*z;
        int mini = min(x,y);
        int maxi = max(x,y);
        ans+=(2*mini);
        ans+= 2*(min(mini+1,maxi));
        return ans;
    }
};