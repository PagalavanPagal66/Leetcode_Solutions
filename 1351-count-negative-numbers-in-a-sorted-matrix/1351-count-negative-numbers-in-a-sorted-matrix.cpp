class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            res+=upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
        }
        return res;
    }
};