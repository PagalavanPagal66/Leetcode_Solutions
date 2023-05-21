class Solution {
public:
int arr[5]={0,1,0,-1,0};
void dfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>>& q){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || i==m || j<0 || j==n || grid[i][j]!=1) return;
    grid[i][j]=2;
    q.push({i,j});
    for(int k=0;k<4;k++){
        dfs(i+arr[k],j+arr[k+1],grid,q);
    }
    return;
}
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        bool temp=0;
        for(int i=0;i<m && temp==0;i++){
            for(int j=0;j<n && temp==0;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,q);
                    temp=1;
                }
            }
        }
        int ans=0;
        while(q.size()){
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int r=i+arr[k];
                    int c=j+arr[k+1];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]!=2){
                        if(grid[r][c]==1) return ans;
                        grid[r][c]=2;
                        q.push({r,c});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};