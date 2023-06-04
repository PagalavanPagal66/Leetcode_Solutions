class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>col(n);
        vector<int>row(n);
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                temp=max(temp,grid[i][j]);
            }
            row[i]=temp;
        }
        for(int i=0;i<n;i++){
            int ma=0;
            for(int j=0;j<n;j++){
                ma=max(ma,grid[j][i]);
            }
            col[i]=ma;
        }
        /*
        for(int i=0;i<n;i++){
            cout<<row[i]<<" ";
        }
        cout<<endl;
        for(auto i:col){
            cout<<i<<" ";
        }
        */
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=max(0,min(col[j],row[i])-grid[i][j]);
            }
        }
        cout<<endl;
        return res;
    }
};