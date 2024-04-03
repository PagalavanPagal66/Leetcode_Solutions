class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxi = 0;
        int n=flips.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int seen = i+1;
            maxi = max(maxi,flips[i]);
            if(maxi==seen){
                ans++;
            }
        }
        return ans;
    }
};