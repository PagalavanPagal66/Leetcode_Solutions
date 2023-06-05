class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        for(int i=1;i<coordinates.size()-1;i++)
        {
            double a=(coordinates[i][1]-coordinates[i-1][1])*(coordinates[i+1][0]-coordinates[i][0]);
            double b=(coordinates[i][0]-coordinates[i-1][0])*(coordinates[i+1][1]-coordinates[i][1]);
            if(a==b)
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};