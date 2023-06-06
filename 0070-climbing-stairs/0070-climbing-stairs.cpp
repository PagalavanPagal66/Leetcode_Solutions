class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int>res(n+1,0);
        res[n]=1;
        res[n-1]=1;
        for(int i=n-2;i>=0;i--){
            res[i]+=res[i+1]+res[i+2];
        }
        return res[0];
    }
};