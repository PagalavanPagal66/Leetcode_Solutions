class Solution {
public:

    int dp[201][201];

    int solve(int i, int j, int n, vector<vector<int>> &grid) {

        if(i == n - 1) {

            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;

        for(int k = 0; k < n; k++) {

            if(k != j) {

                ans = min(ans, grid[i][j] + solve(i + 1, k, n, grid));
            }
        }

        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {

        int ans = 1e9;

        int n = grid.size();

        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++) {

            ans = min(ans, solve(0, i, n, grid));
        }

        return ans;
        
    }
};