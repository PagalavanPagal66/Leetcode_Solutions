class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        map<int , vector<pair<int, int>>> m;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++) m[mat[i][j]].push_back({i, j});
        }
        vector<int> maxinrow(rows, 0);
        vector<int> maxincol(cols, 0);

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(auto &[val, coords]: m){
            for(auto &coord: coords){
                int r = coord.first;
                int c = coord.second;
                dp[r][c] = max(maxinrow[r], maxincol[c]) + 1;
            }
            for(auto &coord: coords){
                int r = coord.first;
                int c = coord.second;
                maxinrow[r] = max(maxinrow[r], dp[r][c]);
                maxincol[c] = max(maxincol[c], dp[r][c]);
            }
        }

        return *max_element(maxinrow.begin(), maxinrow.end());
    }
};