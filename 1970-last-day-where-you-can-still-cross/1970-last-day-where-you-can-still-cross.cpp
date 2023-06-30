class Solution {
public:
    bool help(int n,int m,int k,vector<vector<int>> &g){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int j=0;j<m;j++){
            if(g[0][j]>k){
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        int dir[]={1,0,-1,0,1};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.first>=n-1){
                return 1;
            }
            for(int l=0;l<4;l++){
                int x=p.first+dir[l];
                int y=p.second+dir[l+1];
                if(x>=0 and x<n and y>=0 and y<m and g[x][y]>k and !vis[x][y]){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
        vector<vector<int>> g(row,vector<int> (col,0));
        for(int i=0;i<c.size();i++){
            g[c[i][0]-1][c[i][1]-1]=i+1;
        }
        cout<<1<<" ";
        int l=1,r=row*col,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(help(row,col,mid,g)){
                l=mid+1;
                ans=mid;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};