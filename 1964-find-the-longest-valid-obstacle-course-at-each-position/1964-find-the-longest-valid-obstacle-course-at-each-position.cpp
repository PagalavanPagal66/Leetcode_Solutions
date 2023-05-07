class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> result(n, 1);
        vector<int> LIS;

        
        for(int i = 0; i<n; i++) {
            
            int idx = upper_bound(begin(LIS), end(LIS), obstacles[i]) - begin(LIS);
            
            if(idx == LIS.size()) {
                LIS.push_back(obstacles[i]);
            } else {
                LIS[idx] = obstacles[i];
            }
            
            result[i] = idx+1;
            
        }
        
        return result;
    }
};