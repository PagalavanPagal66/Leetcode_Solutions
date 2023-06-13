class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector<int>,int> mp;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
           mp[grid[i]]++;
        }
        for(int i=0;i<grid.size();i++)
        {
            vector<int> vec;
            for(int j=0;j<grid.size();j++)
            {
                vec.push_back(grid[j][i]);
            }
            if(mp.find(vec)!=mp.end() )
            {
                count+=mp[vec];
            }
        }
        
     
        return count;
        
    }
};