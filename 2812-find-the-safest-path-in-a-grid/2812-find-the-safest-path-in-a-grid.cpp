class Solution {
    void computeSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> Queue;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    Queue.push({i, j});
                    grid[i][j] = 0; 
                } else {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!Queue.empty()) {
            int sz = Queue.size();
            for(int i = 0; i < sz; i++) {
                auto [currX, currY] = Queue.front();
                Queue.pop();
                for(auto [dirX, dirY]: dirs) {
                    int nextX = currX + dirX, nextY = currY + dirY;
                    if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n || grid[nextX][nextY] != INT_MAX) continue;
                    grid[nextX][nextY] = grid[currX][currY] + 1;
                    Queue.push({nextX, nextY});
                }
            }
        }
    }
    int computeMaxSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<vector<int>> PQ; 
        PQ.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!PQ.empty()) {
            vector<int> curr = PQ.top();
            if(curr[1] == n - 1 && curr[2] == n - 1) return dist[n - 1][n - 1];
            PQ.pop();
            for(auto [dirX, dirY]: dirs) {
                int nextX = curr[1] + dirX, nextY = curr[2] + dirY;
                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
                int cost = min(curr[0], grid[nextX][nextY]);
                if(dist[nextX][nextY] == INT_MAX) {
                    dist[nextX][nextY] = cost;
                    PQ.push({dist[nextX][nextY], nextX, nextY});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        computeSafenessFactor(grid);
        return computeMaxSafenessFactor(grid);
    }
};