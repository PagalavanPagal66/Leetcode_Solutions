class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>v(n,vector<int>(n,1));
        for(auto i:mines){
            v[i[0]][i[1]]=0;
        }
        vector<vector<int>>l,r,b,t;
        l=r=b=t=v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=n-1-i;
                int y=n-j-1;
                if(b[x][y] && x<n-1)b[x][y]+=b[x+1][y];
                if(r[x][y] && y<n-1)r[x][y]+=r[x][y+1];
                if(l[i][j] && j>0)l[i][j]+=l[i][j-1];
                if(t[i][j] && i>0)t[i][j]+=t[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({l[i][j],r[i][j],b[i][j],t[i][j]}));
            }
        }
        return ans;
    }
};