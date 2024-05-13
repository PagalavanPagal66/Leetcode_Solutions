class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=!grid[i][j];
                }
            }
        }
        int zc=0;
        int oc=0;
        //vector<string>bin;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]==0)zc++;
                else oc++;
            }
            if(zc>oc){
                for(int j=0;j<n;j++){
                    grid[j][i]=!grid[j][i];
                }
            }
            zc=0;
            oc=0;
        }
        int res=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<m;j++){
                temp+=to_string(grid[i][j]);
            }
            res+=stoi(temp,0,2);
        }
        return res;
    }
};