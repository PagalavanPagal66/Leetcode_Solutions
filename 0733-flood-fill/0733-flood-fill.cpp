class Solution {
public:
    int valid(int val,int n,int m,int i,int j,vector<vector<int>>im,int clr){
        if(i<0 || j<0 || i>=n || j>=m || val!=im[i][j] || im[i][j]==clr){
            return 0;
        }
        return 1;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        while(!q.empty()){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                image[row][col]=color;
                int toprow=row-1;
                int leftcol=col-1;
                int rightcol=col+1;
                int bottomrow=row+1;
                if(valid(val,n,m,toprow,col,image,color)==1){
                    q.push({toprow,col});
                }
                if(valid(val,n,m,bottomrow,col,image,color)==1){
                    q.push({bottomrow,col});
                }
                if(valid(val,n,m,row,leftcol,image,color)==1){
                    q.push({row,leftcol});
                }
                if(valid(val,n,m,row,rightcol,image,color)==1){
                    q.push({row,rightcol});
                }
        }
        return image;
    }
};